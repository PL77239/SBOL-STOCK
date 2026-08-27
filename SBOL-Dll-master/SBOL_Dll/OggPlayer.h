#pragma once
#include    <windows.h>
#include	<stdio.h>
#include	<strsafe.h>
#include    <mmreg.h>
#include	<XAudio2.h>
#include    <vorbis/codec.h>
#include    <vorbis/vorbisfile.h>
#include	<time.h>
#define     BUFSIZE				65536*10
#define		MAX_BUFFER_COUNT	3

//--------------------------------------------------------------------------------------
// Helper macros
//--------------------------------------------------------------------------------------
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#endif
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }
#endif

class OggPlayer
{
protected:
	HWND hwnd;
	bool bInitialized;							// Is XAudio2 initialized
	bool bFileOpened;							// Is OGG file open?
	bool bReleaseXA2;							// release XAudio2
	IXAudio2* pXAudio2;							// the XAudio2 object
	IXAudio2MasteringVoice* pMasteringVoice;	// Mastering voice
	IXAudio2SourceVoice* pSourceVoice;			// Source voice
	char buffers[MAX_BUFFER_COUNT][BUFSIZE];	// Used to store OGG buffer
	DWORD currentDiskReadBuffer;				// Which buffer is active in buffers
	bool oggRunning;							// Is a OGG playing
	OggVorbis_File vf;							// for the vorbisfile interface
	bool bDone;									// done playing
	bool bNearlyDone;							// loaded last data into buffer for playing
	bool bIsMuted;								// Is volume muted

	int64_t loopStart;							// Sample offset in which to start the loop
	int loopCount;								// Loop count specified in OGG file
	int64_t fade;								// Sample offset in which to fade the volume
	int currentLoop;							// Current loop of a looping OGG
	char* trackName;							// Name of track specified in OGG comments
	int64_t lastSampleCount;					// Used to calculate how many samples have been played and to rewind if the track loops
	int64_t sampleCount;						// Samples played of current file

	int volume;									// Current volume

	bool playingPlaylist;						// Is playing a playlist
	bool shufflePlaylist;						// Are tracks to be shuffled in playlist
	int currentPlaylist;						// Current playlist
	int currentPlaylistTrack;					// Current track in playlist

	void getOggInfo();							// Retrieves user comments from OGG for looping and fading

	struct Playlist {
		int trackCount;
		char** filename;
		char* folder;
	};
	Playlist playlists[20];
public:
	OggPlayer(int _vol = 15, bool _shuffle = false);
	~OggPlayer();
	bool								// initialize XAudio2
		InitXAudio2(HWND hWnd);
	bool                                // Load OGG into buffer
		OpenOgg(char *filename);
	void								// play OGG's in playlist
		OpenPlaylist(int _playlist);
	void								// look in folder for files and add to playlist
		GeneratePlaylist(char * _folder, char * _files, int _playlist);
	int									// Get track count in current playlist
		GetTrackCount();
	void                                // Close file and destroy pSourceVoice
		Close();
	void                                // Play OGG loaded in buffer
		Play();
	void								// queue track in playlist
		QueueTrack();
	void                                // stop current track
		Stop();
	void								// Next Track in playlist
		Next();
	void								// Previous Track in playlist
		Prev();
	void                                // load next OGG data into buffer
		Update();
	void								// Set volume of pSourceVoice
		SetVolume(int _vol);
	void								// Mute sound
		Mute();
	void								// Unmute sound
		Unmute();
	bool								// Is pSourceVoice playing audio
		IsPlaying();
	char*								// Get Name of playing track
		GetTrackName();
};

