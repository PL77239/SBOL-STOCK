#include "bgm.h"

extern int shuffleBGM;
extern char* BGMVol;
extern char lastBGMVol;
extern int lastBGM;
extern bool changeOgg;
extern int changeToPlaylist;
extern OggPlayer* op;
extern HWND* hwnd;
extern bool closeCheck;
extern int _EAX, _ECX, _EDX, _EBX, _EDI, _ESI;
extern float float1, float2, float3, float4, float5;
extern int int1, int2;
extern float *_a1;
extern float *_a2;
extern float *_a3;
extern char textBuf[0x1000];
extern unsigned int isClosed;

int setBGM(int bgm, int unknown1, int unknown2)
{
	int ret = 0;
	if (bgm == lastBGM || (bgm < 4 && lastBGM < 4 && lastBGM != -1)) return ret;
	lastBGM = bgm;
	switch (bgm)
	{
	case 0:
	case 1:
	case 2:
	case 3:
		ret = 1;
		changeToPlaylist = 0;
		changeOgg = true;
		break;
	case 4:
		changeToPlaylist = 1;
		changeOgg = true;
		break;
	case 5:
		changeToPlaylist = 2;
		changeOgg = true;
		break;
	case 6:
		changeToPlaylist = 3;
		changeOgg = true;
		break;
	case 7:
		changeToPlaylist = 4;
		changeOgg = true;
		break;
	case 8:
		changeToPlaylist = 5;
		changeOgg = true;
		break;
	case 9:
		changeToPlaylist = 6;
		changeOgg = true;
		break;
	case 10:
		changeToPlaylist = 7;
		changeOgg = true;
		break;
	default:
		op->Stop();
		break;
	}
	return ret;
}
void stopBGM()
{
	lastBGM = -1;
	op->Stop();
}
void __declspec(naked) stopBGMasm()
{
	__asm
	{
		SaveECX();
		call stopBGM;
		RestoreECX();
		mov edx, dword ptr ds : [006F46C8h];
		mov eax, dword ptr ds : [006EBB5Ch];
		push edx;
		push eax;
		call_imm(004F2470h);
		add esp, 08h;
		or eax, 0FFh;
		mov dword ptr ds : [006EBB5Ch], eax;
		jmp_imm(004F2928h);
	}
}
void __cdecl oggThread(void* parg)
{
	while (op)
	{
		if (!hwnd && *(HWND*)0x6EBB80 && op)
		{
			hwnd = (HWND*)0x6EBB80;
			op->InitXAudio2(*hwnd);
			closeCheck = true;
		}
		if (lastBGMVol != *BGMVol && op)
		{
			lastBGMVol = *BGMVol;
			op->SetVolume(*BGMVol + 15);
		}

		if (changeOgg && op)
		{
			op->OpenPlaylist(changeToPlaylist);
			op->Play();
			changeOgg = false;
		}

		if (op && op->IsPlaying()) {
			op->Update();
		}
		Sleep(1);
	}
}