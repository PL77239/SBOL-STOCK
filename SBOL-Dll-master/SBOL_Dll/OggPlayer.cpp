#include "oggplayer.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void OggPlayer::getOggInfo()
{
	vorbis_comment *vc = ov_comment(&vf, -1);
	if (vc != nullptr) {
		for (int i = 0; i < vc->comments; i++) {
			char* findLoopStart = strstr(vc->user_comments[i], "loopstart");
			char* findLoopCount = strstr(vc->user_comments[i], "loopcount");
			char* findFade = strstr(vc->user_comments[i], "fade");
			char* findTrackName = strstr(vc->user_comments[i], "TITLE");
			if (findLoopStart != NULL && (vc->comment_lengths[i] > 10)) { // Account for variable name length with '='
				loopStart = _atoi64(findLoopStart + 10);
			}
			else if (findLoopCount != NULL && (vc->comment_lengths[i] > 10)) { // Account for variable name length with '='
				loopCount = atoi(findLoopCount + 10);
			}
			else if (findFade != NULL && (vc->comment_lengths[i] > 5)) { // Account for variable name length with '='
				fade = _atoi64(findFade + 5);
				if (fade < 0 || fade > vf.pcmlengths[1]) fade = 0;
			}
			else if (findTrackName != NULL && (vc->comment_lengths[i] > 6)) { // Account for variable name length with '='
				trackName = (char*)calloc(1, vc->comment_lengths[i] + 1);
				snprintf(trackName, vc->comment_lengths[i] + 1, findTrackName + 6);
			}
		}
	}
}
OggPlayer::OggPlayer(int _vol, bool _shuffle)
{
	bFileOpened = false;
	bInitialized = false;
	bReleaseXA2 = false;
	pXAudio2 = NULL;
	pMasteringVoice = nullptr;
	pSourceVoice = nullptr;
	currentDiskReadBuffer = 0;
	oggRunning = false;
	bDone = false;
	bNearlyDone = false;
	bIsMuted = false;
	loopCount = 0;
	loopStart = 0;
	fade = 0;
	currentLoop = 0;
	trackName = nullptr;
	lastSampleCount = 0;
	sampleCount = 0;
	volume = _vol;
	playingPlaylist = false;
	shufflePlaylist = _shuffle;
	currentPlaylist = 0;
	currentPlaylistTrack = 0;
	hwnd = NULL;

	CoInitializeEx(NULL, COINIT_MULTITHREADED);
}
OggPlayer::~OggPlayer()
{
	oggRunning = false;
	if (pSourceVoice != nullptr)
	{
		pSourceVoice->Stop(0);
		pSourceVoice->DestroyVoice();
	}

	if (pMasteringVoice != nullptr)
		pMasteringVoice->DestroyVoice();

	SAFE_RELEASE(pXAudio2);

	if (bFileOpened)
		Close();

	CoUninitialize();
}
bool OggPlayer::InitXAudio2(HWND hWnd)
{
	HRESULT hr;

	if (FAILED(hr = XAudio2Create(&pXAudio2)))
		return bInitialized = false;

	if (FAILED(hr = pXAudio2->CreateMasteringVoice(&pMasteringVoice)))
		return bInitialized = false;;

	bReleaseXA2 = true;
	hwnd = hWnd;
	return bInitialized = true;
}
void OggPlayer::OpenPlaylist(int _playlist)
{
	if (_playlist >= 0 &&
		_playlist < (sizeof(playlists) / sizeof(Playlist)) &&
		playlists[_playlist].trackCount > 0) {
		playingPlaylist = true;
		currentPlaylist = _playlist;
		srand((unsigned int)time(NULL));
		currentPlaylistTrack = (shufflePlaylist ? (rand() % playlists[_playlist].trackCount) : 0);
	}
}
void OggPlayer::GeneratePlaylist(char * _folder, char * _files, int _playlist)
{
	if (playlists[_playlist].trackCount > 0) {
		for (int i = 0; i < playlists[_playlist].trackCount; i++)
		{
			if(playlists[_playlist].filename[i])
				free(playlists[_playlist].filename[i]);
		}
		if (playlists[_playlist].folder)
			free(playlists[_playlist].folder);
		playlists[_playlist].trackCount = 0;
	}

	WIN32_FIND_DATAA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError = 0;
	char szDir[MAX_PATH];

	StringCchCopyA(szDir, MAX_PATH, _folder);
	StringCchCatA(szDir, MAX_PATH, "\\");
	StringCchCatA(szDir, MAX_PATH, _files);

	playlists[_playlist].folder = (char*)calloc(1, strlen(_folder) + 1);
	StringCchCopyA(playlists[_playlist].folder, strlen(_folder) + 1, _folder);

	// Get number of files
	hFind = FindFirstFileA(szDir, &ffd);

	playlists[_playlist].trackCount = 0;

	do
	{
		if (!(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			playlists[_playlist].trackCount++;
		}
	}
	while (FindNextFileA(hFind, &ffd) != 0);

	// Allocate pointers for tracknames
	playlists[_playlist].filename = (char**)calloc(1, playlists[_playlist].trackCount * sizeof(char*));
	
	
	// Reset count and this time populate the tracknames
	playlists[_playlist].trackCount = 0;
	hFind = FindFirstFileA(szDir, &ffd);

	do
	{
		if (!(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			playlists[_playlist].filename[playlists[_playlist].trackCount] = (char*)calloc(1, strlen(ffd.cFileName) + 1);
			StringCchCopyA(playlists[_playlist].filename[playlists[_playlist].trackCount], strlen(ffd.cFileName) + 1, ffd.cFileName);
			playlists[_playlist].trackCount++;
		}
	} while (FindNextFileA(hFind, &ffd) != 0);

	FindClose(hFind);
}
int OggPlayer::GetTrackCount()
{
	if (playingPlaylist)
	{
		return playlists[currentPlaylist].trackCount;
	}
	return 0;
}
bool OggPlayer::OpenOgg(char *filename)
{
	if (!bInitialized)
		return false;

	if (bFileOpened)
		Close();

	oggRunning = false;
	currentDiskReadBuffer = 0;
	if (pSourceVoice != nullptr)
	{
		pSourceVoice->DestroyVoice();
		pSourceVoice = nullptr;
	}

	HRESULT hr = S_OK;

	if(ov_fopen(filename, &vf)) 
		return false; // Failed to open file.
	vorbis_info *vi = ov_info(&vf, -1);

	// Get custom comments for loop and fade settings
	getOggInfo();

	// set the wave format
	WAVEFORMATEX wfm = { 0 };

	wfm.cbSize			= sizeof(wfm);
	wfm.nChannels		= vi->channels;
	wfm.wBitsPerSample	= 16;                    // ogg vorbis is always 16 bit
	wfm.nSamplesPerSec	= vi->rate;
	wfm.nAvgBytesPerSec	= wfm.nSamplesPerSec*wfm.nChannels * 2;
	wfm.nBlockAlign		= 2 * wfm.nChannels;
	wfm.wFormatTag		= 1;

	DWORD   pos = 0;
	int     sec = 0;
	int     ret = 1;

	ZeroMemory(&buffers[currentDiskReadBuffer], BUFSIZE);

	while (ret && pos < BUFSIZE)
	{
		ret = ov_read(&vf, buffers[currentDiskReadBuffer] + pos, BUFSIZE - pos, 0, 2, 1, &sec);
		pos += ret;
	}

	if (FAILED(hr = pXAudio2->CreateSourceVoice(&pSourceVoice, &wfm)))
	{
		MessageBox(NULL, TEXT("Error loading OGG File"), TEXT("Error"), MB_OK | MB_ICONERROR);
		exit(1000);
	}

	XAUDIO2_BUFFER buffer = { 0 };
	buffer.pAudioData = (BYTE*)&buffers[currentDiskReadBuffer];
	buffer.AudioBytes = BUFSIZE;
	if (FAILED(hr = pSourceVoice->SubmitSourceBuffer(&buffer)))
	{
		pSourceVoice->DestroyVoice();
		MessageBox(NULL, TEXT("Error loading OGG File"), TEXT("Error"), MB_OK | MB_ICONERROR);
		exit(1001);
	}
	currentDiskReadBuffer++;
	return bFileOpened = true;
}
void OggPlayer::Close()
{
	bFileOpened = false;
	oggRunning = false;
	lastSampleCount = 0;
	sampleCount = 0;
	if (trackName)
		free(trackName);
	trackName = nullptr;
	
	if (pSourceVoice != nullptr)
	{
		pSourceVoice->Stop();
		pSourceVoice->DestroyVoice();
		pSourceVoice = nullptr;
	}
	ov_clear(&vf);
}
void OggPlayer::QueueTrack()
{
	char szDir[MAX_PATH];
	StringCchCopyA(szDir, MAX_PATH, playlists[currentPlaylist].folder);
	StringCchCatA(szDir, MAX_PATH, "\\");
	StringCchCatA(szDir, MAX_PATH, playlists[currentPlaylist].filename[currentPlaylistTrack]);
	OpenOgg(szDir);
}
void OggPlayer::Play()
{
	if (playingPlaylist) {
		if (GetTrackCount() == 0) return;
		QueueTrack();
	}
	if (!bInitialized)
		return;

	if (!bFileOpened)
		return;

	if (pSourceVoice == nullptr)
		return;

	// Set volume
	if (fade)
		pSourceVoice->SetVolume(0.0f);
	else
		SetVolume(volume);

	oggRunning = true;
	pSourceVoice->Start(0);

#ifdef _DEBUG
	char details[0x200];
	if (trackName)
		snprintf(details, sizeof(details), "Playing track: %s.\n", trackName);
	else
		snprintf(details, sizeof(details), "Playing track: %s.\n", playlists[currentPlaylist].filename[currentPlaylistTrack]);
	OutputDebugStringA(details);
#endif

	bDone = false;
	bNearlyDone = false;
}
void OggPlayer::Stop()
{
	currentLoop = 0;

	if (!bInitialized)
		return;

	if (!bFileOpened)
		return;
	
	oggRunning = false;
	playingPlaylist = false;

	if (pSourceVoice != nullptr)
	{
		pSourceVoice->Stop();
		pSourceVoice->DestroyVoice();
		pSourceVoice = nullptr;
	}
}
void OggPlayer::Next()
{
	currentLoop = 0;

	if (!bInitialized)
		return;

	if (!bFileOpened)
		return;

	oggRunning = false;
	if (pSourceVoice != nullptr)
	{
		pSourceVoice->Stop();
		pSourceVoice->DestroyVoice();
		pSourceVoice = nullptr;
	}

	if (playingPlaylist) {
		currentPlaylistTrack = (shufflePlaylist ? (rand() % playlists[currentPlaylist].trackCount) : currentPlaylistTrack + 1);
		currentPlaylistTrack %= playlists[currentPlaylist].trackCount;
		QueueTrack();
		Play();
	}
}
void OggPlayer::Prev()
{
	currentLoop = 0;

	if (!bInitialized)
		return;

	if (!bFileOpened)
		return;

	oggRunning = false;
	if (pSourceVoice != nullptr)
	{
		pSourceVoice->Stop();
		pSourceVoice->DestroyVoice();
		pSourceVoice = nullptr;
	}

	if (playingPlaylist) {
		if(currentPlaylistTrack > 0) currentPlaylistTrack = (shufflePlaylist ? (rand() % playlists[currentPlaylist].trackCount) : currentPlaylistTrack - 1);
		else currentPlaylistTrack = (shufflePlaylist ? (rand() % playlists[currentPlaylist].trackCount) : playlists[currentPlaylist].trackCount - 1);
		currentPlaylistTrack %= playlists[currentPlaylist].trackCount;
		QueueTrack();
		Play();
	}
}
void OggPlayer::Update()
{
	if (pSourceVoice != nullptr && oggRunning == true) {
		XAUDIO2_VOICE_STATE state;
		pSourceVoice->GetState(&state);

		if (state.BuffersQueued < MAX_BUFFER_COUNT - 1)
		{
			if (bDone)
			{
				if (playingPlaylist)
					Next();
				else
					Stop();
			}

			if (bNearlyDone)
				bDone = true;

			ZeroMemory(&buffers[currentDiskReadBuffer], BUFSIZE);

			DWORD   pos = 0;
			int     sec = 0;
			int     ret = 1;

			while (ret && pos < BUFSIZE)
			{
				ret = ov_read(&vf, buffers[currentDiskReadBuffer] + pos, BUFSIZE - pos, 0, 2, 1, &sec);
				pos += ret;
			}

			// Check for end of track and if so is looping set in the file
			if (!ret &&
				((loopCount == -1) ||
				(currentLoop < loopCount)))
			{
				currentLoop++;
				ret = 1;
				ov_pcm_seek(&vf, loopStart);
				sampleCount = loopStart;
				while (ret && pos < BUFSIZE)
				{
					ret = ov_read(&vf, buffers[currentDiskReadBuffer] + pos, BUFSIZE - pos, 0, 2, 1, &sec);
					pos += ret;
				}
			}
			else if (!ret)
			{
				bNearlyDone = true;
			}
			XAUDIO2_BUFFER buffer = { 0 };
			buffer.pAudioData = (BYTE*)&buffers[currentDiskReadBuffer];
			buffer.AudioBytes = BUFSIZE;

			HRESULT hr;
			if (pSourceVoice == nullptr || FAILED(hr = pSourceVoice->SubmitSourceBuffer(&buffer))) return;
			
			currentDiskReadBuffer++;
			currentDiskReadBuffer %= MAX_BUFFER_COUNT;
		}
	}
}
void OggPlayer::SetVolume(int _vol)
{
	if (_vol > 30) _vol = 30;
	else if (_vol < 0) _vol = 0;

	volume = _vol;

	if (pSourceVoice != nullptr) {
		pSourceVoice->SetVolume(_vol * (1.0f / 30.0f));
	}
}
void OggPlayer::Mute()
{
	float vol = 0.0f;
	if (!pSourceVoice)
		return;
	pSourceVoice->GetVolume(&vol);
	if (vol > 0.0f)
		pSourceVoice->SetVolume(0.0f);

	bIsMuted = true;
}
void OggPlayer::Unmute()
{
	float vol = 0.0f;
	if (!pSourceVoice)
		return;
	pSourceVoice->GetVolume(&vol);
	if (vol == 0.0f)
		pSourceVoice->SetVolume(volume * (1.0f / 30.0f));

	bIsMuted = false;
}
bool OggPlayer::IsPlaying()
{
	if(pSourceVoice != nullptr && oggRunning == true)
	{
		if (bIsMuted == false)
		{
			XAUDIO2_VOICE_STATE state;
			pSourceVoice->GetState(&state);
			sampleCount += state.SamplesPlayed - lastSampleCount;
			lastSampleCount = state.SamplesPlayed;
			int64_t offset = sampleCount;
			float vol = 0.0f;
			pSourceVoice->GetVolume(&vol);

			// Fade Up
			if (fade != 0 &&
				offset < vf.pcmlengths[1] - fade &&
				vol < (((volume * (1.0f / 30.0f))))) {
				float fadevol = min(((float)(volume * (1.0f / 30.0f)) / fade) * (max(1, offset)), 1.0f);
				pSourceVoice->SetVolume(fadevol);
#ifdef _DEBUG_DISABLE
				char debug[0x100];
				snprintf(debug, sizeof(debug), "Volume adjusting up %0.3f. Offset %llu\n", fadevol, offset);
				OutputDebugStringA(&debug[0]);
#endif
			}

			// Fade Down
			else if (fade != 0 &&
				offset > vf.pcmlengths[1] - fade &&
				(currentLoop == loopCount || loopCount == 0)) {
				float fadevol = max(((float)(volume * (1.0f / 30.0f)) / fade) * (max(1, vf.pcmlengths[1] - offset)), 0.0f);
				pSourceVoice->SetVolume(fadevol);
#ifdef _DEBUG_DISABLE
				char debug[0x100];
				snprintf(debug, sizeof(debug), "Volume adjusting down %0.3f. Offset %llu\n", fadevol, offset);
				OutputDebugStringA(&debug[0]);
#endif
			}
		}

		// Allow user to skip track using media keys (if they have them) or Page up and down
		if ((GetAsyncKeyState(VK_MEDIA_NEXT_TRACK) & 0x01 || GetAsyncKeyState(VK_NEXT) & 0x01) && playingPlaylist && GetForegroundWindow() == hwnd && GetTrackCount() > 1)
		{
			Next();
			Sleep(100);
		}
		else if ((GetAsyncKeyState(VK_MEDIA_PREV_TRACK) & 0x01 || GetAsyncKeyState(VK_PRIOR) & 0x01) && playingPlaylist && GetForegroundWindow() == hwnd && GetTrackCount() > 1)
		{
			Prev();
			Sleep(100);
		}

		// Mute sound if window doesn't have focus
		if (GetForegroundWindow() != hwnd) Mute();
		else Unmute();
	}
	return (bDone && !playingPlaylist) ? false : true;
}

char * OggPlayer::GetTrackName()
{
	if (trackName)
		return trackName;
	else
		 return playlists[currentPlaylist].filename[currentPlaylistTrack];
	return "None";
}
