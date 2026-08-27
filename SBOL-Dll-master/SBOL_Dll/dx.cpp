#include "dx.h"
#include "asm.h"
#include <string>
#include <sstream>
#include <iomanip>

extern int resW;
extern int virtualResW;
extern int resH;
extern float UIscale;
extern OggPlayer* op;
extern LPDIRECT3DDEVICE8 dx;
extern DXFont* BGMTrackFont;
extern DXFont* PositionFont;
extern bool drawStrings;
extern int _EAX, _ECX, _EDX, _EBX, _EDI, _ESI;

HRESULT __stdcall directxCustom()
{
	if (dx)
	{
		if (BGMTrackFont->CheckDevice() != S_OK)
		{
			HRESULT hr = BGMTrackFont->InitDeviceObjects(dx);
#ifdef _DEBUG
			if (hr != S_OK)
				OutputDebugStringA("Failed to create font!\n");
#endif
			//return hr;
		}
		else if (PositionFont->CheckDevice() != S_OK)
		{
			HRESULT hr = PositionFont->InitDeviceObjects(dx);
#ifdef _DEBUG
			if (hr != S_OK)
				OutputDebugStringA("Failed to create font!\n");
#endif
			//return hr;
		}
		else if (drawStrings)
		{
			// Current track string on UI
			if (*(int*)0x006EC81C != NULL)
			{
				drawBGMString();
			}
#ifdef _DEBUG
			// Position debug string
			if (*(int*)0x006EBE4C != NULL) // Pointer set if in course
			{
				drawPositionString();
			}
#endif
			drawStrings = false;
		}
		return dx->EndScene();
	}
	return D3DERR_INVALIDDEVICE;
}
void drawBGMString()
{
	if (*(int*)0x006EC81C != NULL && *(int*)(0x006F4E48) != 2)
	{
		char battleStatus = *(char*)(*(int*)0x006EC81C + 0xF0);
		if (battleStatus == 0 ||
			battleStatus == 6 ||
			battleStatus == 7) // If not in battle
		{
			float posy = 331.0f;
			float posx = 8.0f;
			auto yOffset = 0.0f;

			if (*(int*)(0x006F4E48) == 2)
				posy = 464.0f;

			yOffset = -((480.0f - posy) * UIscale);
			posy = (float)resH + yOffset;
			posx = posx * UIscale;

			std::stringstream bgmInfo;
			bgmInfo << "CURRENT TRACK: " << op->GetTrackName();
			HRESULT hr = S_OK;
			BGMTrackFont->SetFontFlags(D3DFONT_ZENABLE);
			if (BGMTrackFont->CheckDevice() == S_OK)
				hr = BGMTrackFont->DrawTextScaled(posx, posy, 0.01f, UIscale, UIscale, 0xFFBBBB99, bgmInfo.str().c_str(), 0);
#ifdef _DEBUG
			if (hr != S_OK)
			{
				std::stringstream ss;
				auto lasterror = GetLastError();
				ss << "Failed draw text. Error: " << lasterror << std::endl;
				OutputDebugStringA(ss.str().c_str());
			}
#endif
		}
	}
}
void drawPositionString()
{
	if (*(int*)0x006EC81C != NULL && *(int*)(0x006F4E48) != 2)
	{
		char battleStatus = *(char*)(*(int*)0x006EC81C + 0xF0);
		if (battleStatus == 0 ||
			battleStatus == 6 ||
			battleStatus == 7) // If not in battle
		{
			unsigned short location1 = *(unsigned short*)(*(int*)(*(int*)(*(int*)0x006EBE4C + 0x118) + 0x3EC) + 0x20);
			unsigned short junction = *(unsigned short*)(*(int*)(*(int*)(*(int*)0x006EBE4C + 0x118) + 0x3EC) + 0x18);
			unsigned short distance = *(unsigned short*)(*(int*)(*(int*)(*(int*)0x006EBE4C + 0x118) + 0x3EC) + 0x1C);

			float posy = 232.0f;
			float posx = 8.0f;
			auto yOffset = 0.0f;

			if (*(int*)(0x006F4E48) == 2)
				posy = 448.0f;

			yOffset = -((480.0f - posy) * UIscale);
			posy = (float)resH + yOffset;
			posx *= UIscale;

			std::stringstream posInfo;
			posInfo << "POSITION: " << std::hex << std::uppercase << std::setfill('0') << std::setw(4) << location1 << ":" << std::setw(4) << junction << ":" << std::setw(4) << distance;
			HRESULT hr = S_OK;
			PositionFont->SetFontFlags(D3DFONT_ZENABLE);
			if (PositionFont->CheckDevice() == S_OK)
				hr = PositionFont->DrawTextScaled(posx, posy, 0.01f, UIscale, UIscale, 0xFFBBBB99, posInfo.str().c_str(), 0);
			if (hr != S_OK)
			{
				std::stringstream ss;
				auto lasterror = GetLastError();
				ss << "Failed draw text. Error: " << lasterror << std::endl;
				OutputDebugStringA(ss.str().c_str());
			}
		}
	}
}

void __cdecl endScene()
{
	directxCustom();
}