#include <windows.h>
#include <iomanip>
#include <algorithm>
#include "patch.h"
#include "globals.h"
#include "structures.h"
#include "resolution.h"
#include "strings.h"
#include "debugapi.h"
#include "pachettables.h"
#include "tables.h"

extern char clientVer[4];
extern char logItBuf[0x400];
extern int resW;
extern int virtualResW;
extern int resH;
extern float SWFscale;
extern float SWFscaleX;
extern float SWFscaleY;
extern float drawDistanceMultiplier;
extern float UIscale;
extern int fullScreen;
extern int skipWarning;
extern unsigned char* itemFile;
extern int itemFileSize;
extern float UIdividerX;
extern float UIdividerY;
extern float UIscaleX;
extern float UIscaleVirtualX;
extern float UIscaleY;
extern int itemUseDialogX;
extern int itemUseDialogY;
extern bool closeCheck;
extern bool runGameLoop;
extern HWND* hwnd;
extern int screenWidth;
extern int screenHeight;

extern SHAREDSPACE SharedSpace;

// BGM Values
extern OggPlayer* op;
extern int shuffleBGM;
extern char* BGMVol;
extern char lastBGMVol;
extern int lastBGM;
extern bool changeOgg;
extern int changeToPlaylist;

// DINPUT Values
extern char deadZonePercent;

// DirectX 8 Values
extern LPDIRECT3DDEVICE8 dx;
extern DXFont* BGMTrackFont;
extern bool drawStrings;

typedef void (__stdcall* Func_GameLoop)();
Func_GameLoop GameLoop = (Func_GameLoop)(0x00418F80);

void patchClient()
{
	// FPS (60 Default)
	//*(char*)0x0041BD84 = 60;

	// Car Detail
	//*(char*)0x00503C1C = 0x03;

#ifdef _DEBUG
	// Enable debuging of SWF
	* (int32_t*)(0x006F7A24) = 0xFFFFFFFF;
#endif

	// Force Shift-JIS
	ForceShiftJIS();
	
	// Window Style
	*(int*)0x0041C512 = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
	*(int*)0x0041C49D = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
	// Stop resizing window
	insertFunction(0x00418E69, GetSupportedResolution, 5, FT_CALL);
	
	// Version - We replace the sprintf function and ignore the values pushed and use our own and return the buffer from sprintf in VerString function.
	insertFunction(0x0043B919, VerString, 5, FT_CALL);
	//*(char*)0x43963d = clientVer[2]; // 2.3 requires more work as it pushes a xor'd register ebx
	//*(char*)0x0043B90C = clientVer[1];
	//*(char*)0x0043B90E = clientVer[0];

	// Connection Version Change from SB 0x7B to TM 0x01
	//*(char*)0x0043C4F7 = 'T';
	//*(char*)0x004AB7A4 = 'T';
	//*(char*)0x0043C502 = 'M';
	//*(char*)0x004AB7AF = 'M';
	//*(char*)0x0043C50B = 0x01;
	//*(char*)0x004AB7B8 = 0x01;

	// Server IP
	*(char**)0x0042818D = defaultIP;
	*(char**)0x00428192 = defaultIP + 0x04;
	*(char**)0x00428198 = defaultIP + 0x08;
	*(char**)0x004281A5 = defaultIP + 0x0C;
	*(char**)0x004281FB = defaultServerName;

	// Use registry to check for full screen and skip warning
	//insertFunction(0x00418DF1, notFullScreenMode, 10, FT_CALL);
	insertFunction(0x00418DF1, disabledLegacyFullScreen, 10, FT_CALL);
	insertFunction(0x00426FA5, skipBootWarning, 8, FT_CALL);
	NOPSpace(0x00426F9B, 5);

	// Multiclient
	*(unsigned char*)0x0041C0BE = 0xEB;

	// Log and close Bug Fix
	_beginthread(windowMonitorThread, 0, NULL);
	//insertFunction((int)0x0041C1C7, exitFix, 6, FT_JUMP);

	// Use Icon from Game EXE
	*(int*)0x0041C58C = 0x104;
	*(int*)0x0041C5A0 = (int)clientName;
	*(int*)0x0041C5BF = 0x104;
	*(int*)0x0041C5D5 = (int)clientName;
	
	// Speed Limit (111.11f by default) - (Speed * 60 * 60) / 1000 - 2 values both are needed
	// Player speed limit
	*(float*)0x0060652C = 166.67f;
	// Player speed limit
	*(float*)0x0060C3D4 = 166.67f;

	// Item dat file
	*(unsigned char**)0x004388B9 = itemFile;
	*(unsigned char**)0x0045E5A7 = itemFile;
	*(unsigned char**)0x00496D42 = itemFile;
	*(unsigned char**)0x00496D49 = itemFile;
	*(unsigned char**)0x00496DCD = itemFile;
	*(unsigned char**)0x00496DD4 = itemFile;
	*(unsigned char**)0x004DB9FF = itemFile;
	*(unsigned char**)0x004DBA06 = itemFile;
	*(unsigned char**)0x00503208 = itemFile;
	*(unsigned char**)0x0050322B = itemFile;
	*(unsigned char**)0x00503232 = itemFile;

	*(unsigned char**)0x00438893 = itemFile + 0x04;
	*(unsigned char**)0x004388A3 = itemFile + 0x636;

	*(unsigned char**)0x0045F161 = itemFile + 0x07;

	*(unsigned char**)0x0042568F = itemFile + 0x0A;
	*(unsigned char**)0x004256E5 = itemFile + 0x0A;
	*(unsigned char**)0x00425723 = itemFile + 0x0A;

	*(unsigned char**)0x00425689 = itemFile + 0x0B;
	*(unsigned char**)0x004256DE = itemFile + 0x0B;

	*(unsigned char**)0x0049692F = itemFile + 0x0E;
	*(unsigned char**)0x00496CFE = itemFile + 0x0E;

	*(unsigned char**)0x00503216 = itemFile + itemFileSize;

	// Increase Type Limit in part ticket exchange (default is 6)
	*(unsigned char*)0x00466367 = 0x0A;
	// Increase Type Limit in part shop (default is 6)
	*(unsigned char*)0x0045EBB9 = 0x0A;

	// DX Windows hook
	insertFunction((int)0x0044BF11, DxWindow, 5, FT_CALL);
	insertFunction((int)0x0044E5CD, DxWindow, 5, FT_CALL);
	insertFunction((int)0x004502CA, DxWindow, 5, FT_CALL);
	insertFunction((int)0x00452BE1, DxWindow, 5, FT_CALL);
	insertFunction((int)0x00452CEC, DxWindow, 5, FT_CALL);
	insertFunction((int)0x00453E89, DxWindow, 5, FT_CALL);
	insertFunction((int)0x00453EE7, DxWindow, 5, FT_CALL);
	insertFunction((int)0x00453F4E, DxWindow, 5, FT_CALL);
	insertFunction((int)0x0045538F, DxWindow, 5, FT_CALL);
	insertFunction((int)0x004571CB, DxWindow, 5, FT_CALL);
	insertFunction((int)0x00458C48, DxWindow, 5, FT_CALL);
	insertFunction((int)0x004631B4, DxWindow, 5, FT_CALL);
	insertFunction((int)0x00464F3D, DxWindow, 5, FT_CALL);
	insertFunction((int)0x00480E69, DxWindow, 5, FT_CALL);
	insertFunction((int)0x0048201D, DxWindow, 5, FT_CALL);
	insertFunction((int)0x004879F5, DxWindow, 5, FT_CALL);
	insertFunction((int)0x004904A2, DxWindow, 5, FT_CALL);
	insertFunction((int)0x004ACC81, DxWindow, 5, FT_CALL);
	insertFunction((int)0x004B011C, DxWindow, 5, FT_CALL);

#ifdef DEBUG_LOG
	//NOPSpace(0x00512744, 5);
	//insertFunction((int)0x0051FA04, debugLog, 5, FT_CALL);
	//insertFunction((int)0x0041C2AA, debugIt, 5, FT_CALL);
	//insertFunction((int)0x0041C364, debugIt, 5, FT_CALL);
	//insertFunction((int)0x0041BE19, debugIt, 5, FT_CALL); // FPS
	//insertFunction((int)0x0042720B, debugIt, 5, FT_CALL);
	//insertFunction((int)0x0042FE39, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00430B57, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00430BAB, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00437616, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00437968, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00446C12, debugIt, 5, FT_CALL);
	//insertFunction((int)0x0044A810, debugIt, 5, FT_CALL);
	//insertFunction((int)0x0044A8FC, debugIt, 5, FT_CALL);
	//insertFunction((int)0x0044A9FB, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00492C42, debugIt, 5, FT_CALL);
	//insertFunction((int)0x004C0406, debugIt, 5, FT_CALL);
	//insertFunction((int)0x004CCECA, debugIt, 5, FT_CALL);
	//insertFunction((int)0x004D06CB, debugIt, 5, FT_CALL);
	//insertFunction((int)0x004D6B58, debugIt, 5, FT_CALL);
	//insertFunction((int)0x004CCECA, debugIt, 5, FT_CALL);
	//insertFunction((int)0x004D8C5C, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00526590, debugIt, 5, FT_CALL);
	//insertFunction((int)0x005275DD, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00527712, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00527931, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00527AA2, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00527BB8, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00527D00, debugIt, 5, FT_CALL);
	//setFunction(0x6F7A24, Log);
	//*(int*)(0x6F7A24) = (int)Log;
	//*(char*)0x006F7710 = 0; // enable log 1 - Action Script
	//*(char*)0x006F7711 = 0; // enable log 2 - General
#endif

	// BGM Stuff
	insertFunction((int)(0x004F2530 + 0x9B), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x128), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x197), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x206), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x241), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x2C4), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x2F3), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x322), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x351), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x384), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x3C5), setBGM, 5, FT_CALL);
	*(int*)(0x004F29F0) = (int)stopBGMasm;
	// Create playlists
	op->GeneratePlaylist("data\\bgm", "freerun*.ogg", 0);
	op->GeneratePlaylist("data\\bgm", "battle_*.ogg", 1);
	op->GeneratePlaylist("data\\bgm", "battlewin*.ogg", 2);
	op->GeneratePlaylist("data\\bgm", "battleend*.ogg", 3);
	op->GeneratePlaylist("data\\bgm", "battlelose*.ogg", 4);
	op->GeneratePlaylist("data\\bgm", "mainmenu*.ogg", 5);
	op->GeneratePlaylist("data\\bgm", "garage*.ogg", 6);
	op->GeneratePlaylist("data\\bgm", "parking*.ogg", 7);
	_beginthread(oggThread, 0, NULL);

	// Login Screen BGM
	//*(char*)0x0043DC24 = 0x07; // Mainmenu.wav (0x0C Default)
	//*(int*)0x004F20A7 = 0x0C;
	//*(int*)0x004F209D = 0x0C;
	//*(int*)0x04F29F0 = 0x004F2806;

	//*(char*)0x0043B4FB = 0x50; // LoadInterface first screen is 0x1f

	// Ignore S.DAT modifications
	//*(unsigned char*)0x00595C09 = 0xEB;

	// Change shop to use P.dat file again for tire and brakes
	//*(int*)(0x004A80D0) = (int)getTireBrakePrice;
	//*(int*)(0x004A80D4) = (int)getTireBrakePrice;
	//*(int*)(0x005312E0) = (int)getTireBrakePrice;
	//*(int*)(0x005312E4) = (int)getTireBrakePrice;
	// Base Shop Prices
	*(int*)(0x00531802) = 100; // 100;
	*(int*)(0x00531816) = 102; // 102;
	*(int*)(0x0053181E) = 118; // 104;
	*(int*)(0x00531826) = 134; // 106;
	*(int*)(0x0053182E) = 150; // 108;
	*(int*)(0x00531836) = 166; // 110;
	*(int*)(0x0053183E) = 182; // 112;
	*(int*)(0x00531846) = 150; // 115;
	*(int*)(0x0053184E) = 198; // 117;
	*(int*)(0x005317FA) = 214; // 120;

	// Number of cars?
	//*(int*)0x004A444E = 165;
	//*(int*)0x004A4AF0 = 165;
	//*(int*)0x004A4CAF = 165;
	//*(int*)0x004A80EA = 165;
	//*(int*)0x004A815A = 165;
	//*(int*)0x004C142B = 165;
	//*(int*)0x004C5521 = 165;
	//*(int*)0x004C556F = 165;
	//*(int*)0x004C568A = 165;

	// Additional Items
	// Sign limit (image in UI is in SWF so can't edit that)
	*(char*)0x004396ED = 27; // 24;
	// Item Label Sprites brought table into DLL so I can add more
	for (int i = 0; i < sizeof(itemSpriteSmallID) / sizeof(int*); i++)		*(int*)(itemSpriteSmallID[i]) = (int)(&itemSpritesSmall);
	for (int i = 0; i < sizeof(itemSpriteSmallSprite) / sizeof(int*); i++)	*(int*)(itemSpriteSmallSprite[i]) = (int)(&itemSpritesSmall) + 4;
	for (int i = 0; i < sizeof(itemSpriteSmallEnd) / sizeof(int*); i++)		*(int*)(itemSpriteSmallEnd[i]) = (int)(&itemSpritesSmall) + sizeof(itemSpritesSmall);
	for (int i = 0; i < sizeof(itemSpriteBigID) / sizeof(int*); i++)		*(int*)(itemSpriteBigID[i]) = (int)(&itemSpritesBig);
	for (int i = 0; i < sizeof(itemSpriteBigSprite) / sizeof(int*); i++)	*(int*)(itemSpriteBigSprite[i]) = (int)(&itemSpritesBig) + 4;
	for (int i = 0; i < sizeof(itemSpriteBigEnd) / sizeof(int*); i++)		*(int*)(itemSpriteBigEnd[i]) = (int)(&itemSpritesBig) + sizeof(itemSpritesBig);

	// CP Clipping on race hud fix
	*(char*)0x004D5D46 = 24;

	// Custom DirectX Stuff
	//insertFunction((int)0x004C769C, directxCustom, 14, FT_CALL); // Outside Car
	//insertFunction((int)0x004C8A12, directxCustom, 7, FT_CALL); // Inside Car
	insertFunction(0x004D94F1, DrawStrings, 5, FT_CALL);

	// Direct Input
	//insertFunction((int)0x0040B464, adjustXAxis, 7, FT_CALL);

	// Axis Range (DIPROP_RANGE)
	*(short*)0x0040B18C = -1000; // lMin
	*(short*)0x0040B18E = 1000; // lMax

	// Axis Deadzones (DIPROP_DEADZONE)
	*(char*)0x0040B1AF = deadZonePercent; // Default 5%

	// Direct Input SetCooperativeLevel
	*(char*)0x0040AEEE = DISCL_BACKGROUND | DISCL_NONEXCLUSIVE;

	// Allow the window to be moved without freezing the game
	*(uint8_t*)0x0041C1CB = 0x8D; // ECX=>local_44,[EBP + -0x40] : Window Message
	*(uint8_t*)0x0041C1CC = 0x4D;
	*(uint8_t*)0x0041C1CD = 0xC0;
	*(uint8_t*)0x0041C1CE = 0x51; // PUSH ECX (Message)
	insertFunction((int)0x0041C1CF, HandleMessageHook_Ptr, 0x0041C212 - 0x0041C1CF, FT_CALL);
	

	// Add pointer to shared space for communication between dlls
	*(void**)(SHARED_SPACE_PTR_ADDR) = (void*)&SharedSpace;

#pragma region Custom Packets and alterations
	// 0x0480 / 0x1480 - Packet handling
	setFunction((int)0x00449ABA, packetHandle04001400);
	setFunction((int)0x00449AEB, packetHandle04001400);

	// 0x0482 - Enter rival shop
	NOPSpace(0x0044A707, 0x19);
	*(uint8_t*)0x0044A707 = 0x56; // PUSH ESI
	*(uint8_t*)0x0044A708 = 0x8B; // MOV ECX,EDI
	*(uint8_t*)0x0044A709 = 0xCF; // MOV ECX,EDI
	insertFunction((int)0x0044A70A, Packet0482, 5, FT_CALL);

	// 0x0100 - Packet handling
	*(uint32_t*)0x0043CB33 = (uint32_t)Packet0100Table;
	*(uint8_t*)0x0043CB29 = 0x10; // Set the 0100 packet count so 0x190 can be handled. Packets between 0x0184 - 0x018F are handled like 0x0181 packet.B

	// Fullscreen Stuff
	setFunction(0x00412BAA, (void*)&SetWindowPosHook_Ptr);

	// Summer event garage offset fix
	*(uint32_t*)0x00456D0F = 0;
	
#pragma endregion
}
void patchBugs()
{
	// Fix pointer for reward items. Game incorrectly pushes Item.dat pointer and not players inventory to sort function
	*(int*)0x0045E5A7 = PTR_ITEMBOX_STORAGE;
}
int notFullScreenMode()
{
	return fullScreen ? 0 : 1;
}
int disabledLegacyFullScreen()
{
	return 1;
}
int skipBootWarning()
{
	return skipWarning ? 1 : 0;
}
void setStrings()
{
	*(char**)0x0041C517 = windowTitle;
	//*(char**)0x0043B914 = versionStr; // Now in VerString Function

	for (int i = 0; i < sizeof(strings) / sizeof(STRINGENTRY); i++)
	{
		if (strings[i].ptr)
		{
			if (strings[i].mutli == TRUE)
			{
				char* currPtr = (char*)strings[i].ptr;
				while (*(int*)currPtr)
				{
					*(int*)(*(int*)currPtr) = (int)strings[i].str;
					currPtr += 4;
				}
			}
			else
				*(char**)strings[i].ptr = strings[i].str;
		}
	}
	std::string languagefilepath = "data\\lang-" + language + ".json";

	ReplaceStrings(languagefilepath.c_str());
	ReplaceRivalStrings(languagefilepath.c_str());

	ITEMDETAILENTRY* items = nullptr;
	int itemsCount = sizeof(itemDetails) / sizeof(ITEMDETAILENTRY);
	itemDetailsJson = LoadItemStrings(languagefilepath.c_str(), &itemsCount);

	if (itemDetailsJson)
		items = itemDetailsJson;
	else
		items = (ITEMDETAILENTRY*)&itemDetails;

	// Item Descriptions brought table into DLL so I can add more
	for (int i = 0; i < sizeof(itemIDNumber) / sizeof(int*); i++)			*(int*)(itemIDNumber[i]) = (int)items;
	for (int i = 0; i < sizeof(itemIDName) / sizeof(int*); i++)				*(int*)(itemIDName[i]) = (int)(items) + 4;
	for (int i = 0; i < sizeof(itemIDDescription) / sizeof(int*); i++)		*(int*)(itemIDDescription[i]) = (int)(items) + 8;
	for (int i = 0; i < sizeof(itemIDEnd) / sizeof(int*); i++)				*(int*)(itemIDEnd[i]) = (int)(items) + (itemsCount * sizeof(ITEMDETAILENTRY));
	for (int i = 0; i < sizeof(itemIDMid) / sizeof(int*); i++)				*(int*)(itemIDMid[i]) = (int)(items) + ((2035 * 12) + 8);
	for (int i = 0; i < sizeof(itemIDMid2) / sizeof(int*); i++)				*(int*)(itemIDMid2[i]) = (int)(items) + (2072 * 12);

	for (int i = 0; i < sizeof(replaceStrings) / sizeof(STRINGREPLACEENTRY); i++)
	{
		if (replaceStrings[i].ptr)
		{
			if (replaceStrings[i].strlen == 0)
			{
				memcpy(replaceStrings[i].ptr, replaceStrings[i].str, strlen(replaceStrings[i].str));
				*(char*)(replaceStrings[i].ptr + strlen(replaceStrings[i].str)) = 0;
			}
			else
			{
				int len = strlen(replaceStrings[i].str);
				if (len >= replaceStrings[i].strlen)
					len = replaceStrings[i].strlen - 1;
				memcpy(replaceStrings[i].ptr, replaceStrings[i].str, len);
				while (len < replaceStrings[i].strlen)
				{
					*(char*)(replaceStrings[i].ptr + len++) = '\0';
				}
			}
		}
	}
	*(const char**)0x00695674 = CHAT_SEPARATOR;
	
	//CreateFontA Size overrides
	
	// AUTO RUN: x
	*(char*)0x004D5DD9 = 8;   // X
	*(int*)0x004D5DD4  = 239; // Y
	*(char*)0x004D5DB1 = 12;  // Width
	*(char*)0x004D5DB3 = 6;   // Height

	// AUTO RUN: x
	*(char*)0x004D5E28 = 8;   // X
	*(int*)0x004D5E23  = 239; // Y
	*(char*)0x004D5DFA = 12;  // Width
	*(char*)0x004D5E02 = 6;   // Height

	// CP: x and LV: x
	*(char*)0x004D5D7B = 44;  // X
	*(int*)0x004D5D76  = 267; // Y
	*(char*)0x004D5D4D = 12;  // Width
	*(char*)0x004D5D4F = 6;   // Height

	// COURSE NAME: x
	*(char*)0x004D5D04 = 8;   // X
	*(int*)0x004D5CFF  = 295; // Y
	*(char*)0x004D5CD6 = 12;  // Width
	*(char*)0x004D5CD8 = 6;   // Height

	// PERSONS IN COURSE: x
	*(char*)0x004D5CB2 = 8;   // X
	*(int*)0x004D5CAD  = 307; // Y
	*(char*)0x004D5C8A = 12;  // Width
	*(char*)0x004D5C8C = 6;   // Height

	// NETWORK: x
	*(char*)0x004ABF82 = 8;   // X
	*(int*)0x004ABF7D  = 319; // Y
	*(char*)0x004ABF57 = 12;  // Width
	*(char*)0x004ABF5C = 6;   // Height

	// Time attack - Y Increases by 10 each loop
	*(int*)0x004D5F12  = 490; // X
	*(int*)0x004D5ED0  = 203; // Y
	*(char*)0x004D5EF1 = 12;  // Width
	*(char*)0x004D5EF3 = 6;   // Height	
}
void setDrawDistance()
{
	for (int i = 0; i < sizeof(drawDistance) / sizeof(float); i++)
	{
		if(drawDistance[i] != nullptr) *drawDistance[i] *= drawDistanceMultiplier;
	}
}
void setResolution()
{
#pragma region Resolution
	// Disable window size check. If I do this full screen will break on unsupported resolutions by the monitor. So I'll leave it as default.
	//insertFunction(0x00412AE6, checkResolution, 286, FT_JUMP);
	//*(char*)(0x00418E77) = 2;
	//NOPSpace(0x00412AE6, 2);

	// 

	for (int i = 0; i < sizeof(resWidth) / sizeof(int); i++)
	{
		if(resWidth[i] != nullptr) *resWidth[i] = resW;
	}
	for (int i = 0; i < sizeof(resHeight) / sizeof(int); i++)
	{
		if(resHeight[i] != nullptr) *resHeight[i] = resH;
	}
	for (int i = 0; i < sizeof(resWidthF) / sizeof(float); i++)
	{
		if(resWidthF[i] != nullptr) *resWidthF[i] = (float)resW;
	}
	for (int i = 0; i < sizeof(resHeightF) / sizeof(float); i++)
	{
		if(resHeightF[i] != nullptr) *resHeightF[i] = (float)resH;
	}
#pragma endregion
#pragma region Positioning
	/*
	for (int i = 0; i < sizeof(centerJust) / sizeof(int); i++)
	{
		if(centerJust[i] != nullptr) *centerJust[i] = (resW / 2) - (320 - (*centerJust[i]));
	}
	for (int i = 0; i < sizeof(centerJustV) / sizeof(int); i++)
	{
		if(centerJustV[i] != nullptr) *centerJustV[i] = (resH / 2) - (240 - (*centerJustV[i]));
	}
	for (int i = 0; i < sizeof(rightJust) / sizeof(int); i++)
	{
		if(rightJust[i] != nullptr) *rightJust[i] = resW - (640 - *rightJust[i]);
	}
	for (int i = 0; i < sizeof(bottomJust) / sizeof(int); i++)
	{
		if(bottomJust[i] != nullptr) *bottomJust[i] = resH - (480 - *bottomJust[i]);
	}
	for (int i = 0; i < sizeof(centerJustF) / sizeof(float); i++)
	{
		if(centerJustF[i] != nullptr) *centerJustF[i] = (resW / 2) - (320 - (*centerJustF[i]));
	}
	for (int i = 0; i < sizeof(rightJustF) / sizeof(float); i++)
	{
		if(rightJustF[i] != nullptr) *rightJustF[i] = resW - (640.0f - *rightJustF[i]);
	}
	for (int i = 0; i < sizeof(bottomJustF) / sizeof(float); i++)
	{
		if(bottomJustF[i] != nullptr) *bottomJustF[i] = resH - (480.0f - *bottomJustF[i]);
	}
	*/

	/*
	for (int i = 0; i < sizeof(repositionAddr) / sizeof(int); i++)
	{
		insertFunction((int)repositionAddr[i], positionUIElement, 5, FT_CALL);
	}
	*/

	
	for (int i = 0; i < sizeof(adjustFloatAddr) / sizeof(ADJUSTFLOATS); i++)
	{
		if (adjustFloatAddr[i].function != nullptr) adjustFloatAddr[i].AdjustFloats();
	}
	for (int i = 0; i < sizeof(adjustIntAddr) / sizeof(ADJUSTINTS); i++)
	{
		if (adjustIntAddr[i].function != nullptr) adjustIntAddr[i].AdjustInts();
	}
	for (int i = 0; i < sizeof(replaceFunctionAddr) / sizeof(REPLACEFUNCTION); i++)
	{
		if (replaceFunctionAddr[i].address != nullptr)
		{
			int nopcount = 5;
			if ((int)replaceFunctionAddr[i].address & 0xFF000000)
				nopcount += ((unsigned int)replaceFunctionAddr[i].address >> 24);
			if (nopcount > 0xFF)
				setFunction((int)replaceFunctionAddr[i].address & 0x00FFFFFF, replaceFunctionAddr[i].function);
			else
				insertFunction((int)replaceFunctionAddr[i].address & 0x00FFFFFF, replaceFunctionAddr[i].function, nopcount, FT_CALL);
		}
	}
	//insertFunction(0x0045F6C8, positionUIElement3, 5, FT_CALL);

	//for (int i = 0; i < sizeof(repositionIntAddr) / sizeof(int); i++)
	//{
	//	insertFunction((int)repositionIntAddr[i], logPositionUIElement, 5, FT_CALL);
	//}
	//for (int i = 0; i < sizeof(repositionIntAddr) / sizeof(int); i++)
	//{
	//	insertFunction((int)repositionIntAddr[i], positionUIElement2, 5, FT_CALL);
	//}
#pragma endregion
#pragma region Aspect Ratio
	// Course Aspect
	*(float*)0x005F404C = (float)resW / (float)resH;

	// Shops and UI Aspects - Looks bad when UI is stretched so will leave it scretched in shops.
	*(float*)0x004A4232 = (float)resW / (float)resH; // Garage and shop car FOV
	//*(float*)0x004E100F = (float)resW / (float)resH;
	*(float*)0x00501928 = (float)resW / (float)resH; // New game car selection
	//*(float*)0x0050195A = (float)resW / (float)resH;
#pragma endregion
#pragma region Scaling Patches
	//insertFunction((int)0x00508470, scaleUIElement, 0x7F, FT_JUMP);
	UIdividerX = ((640.0f / (float)resW) * 20.0f);
	UIdividerY = ((480.0f / (float)resH) * 20.0f);
	UIscaleX = ((0.05f / 640.0f) * (float)resW);
	UIscaleVirtualX = ((0.05f / 640.0f) * (float)virtualResW);
	UIscaleY = ((0.05f / 480.0f) * (float)resH);
	itemUseDialogX = (resW / 2) - (320 - itemUseDialogX);
	itemUseDialogY = (resH / 2) - (240 - itemUseDialogY);

	// Unknown
	//*(float**)0x00416DC0 = &UIdividerX;
	//*(float**)0x00416DCE = &UIdividerY;

	// Shadows in Garage effected
	//*(float**)0x004587D3 = &UIdividerX;
	//*(float**)0x004587EE = &UIdividerY;

	// UI Selection Position effected (buttons and input boxes)
	//*(float**)0x0051C9B2 = &UIscaleVirtualX;
	//*(float**)0x0051C9D3 = &UIdividerY;

	// Unknown
	//*(float**)0x005084AA = &UIscaleX;
	//*(float**)0x005084C2 = &UIscaleY;

	// Unknown
	//*(float**)0x0050977F = &UIscaleX;
	//*(float**)0x0050978E = &UIscaleY;

	// Unknown
	//*(float**)0x00511A1F = &UIscaleX;
	//*(float**)0x00511A35 = &UIscaleY;

	// Unknown
	//*(float**)0x00511A4B = &UIscaleX;
	//*(float**)0x00511A61 = &UIscaleY;

	// UI GameSWF Menus
	*(float**)0x00512332 = &UIscaleVirtualX;
	*(float**)0x0051236F = &UIscaleY;
	
	// UI GameSWF Black boxes
	*(float**)0x0051249F = &UIscaleVirtualX;
	*(float**)0x005124D6 = &UIscaleY;

	// Unknown
	//*(float**)0x00512A3B = &UIscaleX;
	//*(float**)0x00512A64 = &UIscaleY;

	// Unknown
	//*(float**)0x005133D5 = &UIscaleX;
	//*(float**)0x005133E8 = &UIscaleY;

	// Unknown
	//*(float**)0x005133FB = &UIscaleX;
	//*(float**)0x00513407 = &UIscaleY;

	// Unknown
	//*(float**)0x005155A6 = &UIscaleY;
	//*(float**)0x005155D6 = &UIscaleX;

	// Unknown
	//*(float**)0x0051576C = &UIscaleY;
	//*(float**)0x0051577A = &UIscaleX;

	// Input fields affected
	//*(float**)0x00516035 = &UIscaleY;
	//*(float**)0x0051604E = &UIscaleX;

	// UI interaction
	//insertFunction(0x00512BE4, adjustUI, 5, FT_CALL);

	// Set dialog positions and such
	//insertFunction(0x0045C7E0, setTexturePositions, 5, FT_CALL);
	//insertFunction(0x0045C7E5, setItemUsePosition, 14, FT_CALL);
	//insertFunction(0x0045FFE4, setTexturePositions, 5, FT_CALL);
	//insertFunction(0x00466124, setTexturePositions, 5, FT_CALL);
	//insertFunction(0x0046AA84, setTexturePositions, 5, FT_CALL);
	//insertFunction(0x0046D794, setTexturePositions, 5, FT_CALL);
	//insertFunction(0x004833E4, setTexturePositions, 5, FT_CALL);
	//insertFunction(0x00483BD4, setTexturePositions, 5, FT_CALL);
	//insertFunction(0x0048DDEE, setTexturePositions, 5, FT_CALL);

	// Custom draw string

	for (int i = 0; i < sizeof(drawStringAddr) / sizeof(int); i++)
	{
	//	insertFunction((int)drawStringAddr[i], drawString, 5, FT_CALL);
	}
#pragma endregion
}
void fixResolutionChoice()
{
	// If windowed mode we'll assume we'll create the window at that resolution only fullscreen could break things
	if (notFullScreenMode())
	{
		return;
	}
	// If an unsupported resolution is set use the closest supported resolution
	int supportedResolutions[2][30] = { 0 };
	int lastResolution[2] = { 0 };
	DEVMODE dm = { 0 };
	dm.dmSize = sizeof(dm);
	int settingCount = 0;

	// Get supported resolutions
	for (int i = 0; EnumDisplaySettings(NULL, i, &dm) != 0; i++)
	{
		if (settingCount == 30) break;
		if (lastResolution[0] != dm.dmPelsWidth && lastResolution[1] != dm.dmPelsHeight)
		{
			supportedResolutions[0][settingCount] = dm.dmPelsWidth;
			supportedResolutions[1][settingCount] = dm.dmPelsHeight;
			settingCount++;
		}
		lastResolution[0] = dm.dmPelsWidth;
		lastResolution[1] = dm.dmPelsHeight;
	}

	// Check if set resolution matches a supported one found. If so return
	for (int i = 0; i < settingCount; i++)
	{
		if (supportedResolutions[0][i] == resW && supportedResolutions[1][i] == resH)
			return;
	}

	// Resolution set isn't supported so use the closest supported resolution
	for (int i = 0; i < settingCount; i++)
	{
		if (supportedResolutions[0][i] > resW && i == 0)
		{
			resW = supportedResolutions[0][i];
			resH = supportedResolutions[1][i];
			virtualResW = (int)((float)resH * SCREEN_RATIO_4_3);
			SWFscaleX = (float)virtualResW / 640.0f;
			SWFscaleY = (float)resH / 480.0f;
			SWFscale = (float)resH / 480.0f;
			break;
		}
		else if (supportedResolutions[0][i] > resW)
		{
			resW = supportedResolutions[0][i - 1];
			resH = supportedResolutions[1][i - 1];
			virtualResW = (int)((float)resH * SCREEN_RATIO_4_3);
			SWFscaleX = (float)virtualResW / 640.0f;
			SWFscaleY = (float)resH / 480.0f;
			SWFscale = (float)resH / 480.0f;
			break;
		}
		else  if (i == settingCount - 1)
		{
			resW = supportedResolutions[0][i];
			resH = supportedResolutions[1][i];
			virtualResW = (int)((float)resH * SCREEN_RATIO_4_3);
			SWFscaleX = (float)virtualResW / 640.0f;
			SWFscaleY = (float)resH / 480.0f;
			SWFscale = (float)resH / 480.0f;
			break;
		}
	}
}
void __cdecl windowMonitorThread(void* parg)
{
	bool running = true;
	while (running)
	{
		if ((*(void**)(0x006EAAE0)) && dx != (LPDIRECT3DDEVICE8)(*(void**)(0x006EAAE0)))
		{
			dx = (LPDIRECT3DDEVICE8)(*(void**)(0x006EAAE0));
		}
		if (closeCheck)
		{
			if (hwnd && IsWindowVisible(*hwnd) == false)
			{
				// Add game save before close
				SharedSpace.savegame.LockMaster();
				while (SharedSpace.savegame.IsMasterLocked())
				{
					Sleep(10);
				}
				running = false;
				break;
			}
		}
		if (runGameLoop)
		{
			try
			{
				GameLoop();
			}
			catch (...)	{ }
		}
		else
			Sleep(10);
	}
	OutputDebugStringA("Game exited due to window not found.");
#ifdef _DEBUG
	//__debugbreak();
#endif
	_Exit(0);
}
void readRegistry()
{
	DWORD value = 0;
	char strvalue[256]{};
	DWORD BufferSize = 4;
	HKEY hKey;

	if (RegOpenKeyExA(HKEY_CURRENT_USER, ("Software\\Genki\\SBOL"), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS)
	{
		BufferSize = sizeof(DWORD);
		if (RegQueryValueExA(hKey, ("RES_WIDTH"), NULL, NULL, reinterpret_cast<LPBYTE>(&value), &BufferSize) == ERROR_SUCCESS)
		{
			if ((resW = value) < 640)
				resW = 640;
		}
		else
		{
			resW = 640;
			RegSetValueExA(hKey, ("RES_WIDTH"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&resW), BufferSize);
		}

		BufferSize = sizeof(DWORD);
		if (RegQueryValueExA(hKey, ("RES_HEIGHT"), NULL, NULL, reinterpret_cast<LPBYTE>(&value), &BufferSize) == ERROR_SUCCESS)
		{
			if ((resH = value) < 480)
				resH = 480;
			virtualResW = (int)((float)resH * SCREEN_RATIO_4_3);
			SWFscaleX = (float)virtualResW / 640.0f;
			SWFscaleY = (float)resH / 480.0f;
			SWFscale = (float)resH / 480.0f;
		}
		else
		{
			resH = 480;
			virtualResW = (int)((float)resH * SCREEN_RATIO_4_3);
			SWFscaleX = (float)virtualResW / 640.0f;
			SWFscaleY = (float)resH / 480.0f;
			SWFscale = (float)resH / 480.0f;
			RegSetValueExA(hKey, ("RES_HEIGHT"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&resH), BufferSize);
		}

		BufferSize = sizeof(DWORD);
		if (RegQueryValueExA(hKey, ("FULLSCREEN"), NULL, NULL, reinterpret_cast<LPBYTE>(&value), &BufferSize) == ERROR_SUCCESS)
		{
			fullScreen = value ? 1 : 0;
		}
		else
		{
			fullScreen = 0;
			RegSetValueExA(hKey, ("FULLSCREEN"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&fullScreen), BufferSize);
		}

		BufferSize = sizeof(DWORD);
		if (RegQueryValueExA(hKey, ("DRAWDISTANCE"), NULL, NULL, reinterpret_cast<LPBYTE>(&value), &BufferSize) == ERROR_SUCCESS)
		{
			drawDistanceMultiplier = ((float)(*(int*)&value) / 100.0f);
			if (drawDistanceMultiplier > 3.0f || drawDistanceMultiplier < 0.05f)
				drawDistanceMultiplier = 1.0f;
		}
		else
		{
			drawDistanceMultiplier = 1.0f;
			int drawdistance = 100;
			RegSetValueExA(hKey, ("DRAWDISTANCE"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&drawdistance), BufferSize);
		}

		BufferSize = sizeof(DWORD);
		if (RegQueryValueExA(hKey, ("UISCALE"), NULL, NULL, reinterpret_cast<LPBYTE>(&value), &BufferSize) == ERROR_SUCCESS)
		{
			UIscale = ((float)(*(int*)&value) / 100.0f);
			if (UIscale == 0.0f)
				UIscale = 1.0f;
		}
		else
		{
			UIscale = 1.0f;
			int uiscale = 100;
			RegSetValueExA(hKey, ("UISCALE"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&uiscale), BufferSize);
		}

		BufferSize = sizeof(DWORD);
		if (RegQueryValueExA(hKey, ("SKIPWARNING"), NULL, NULL, reinterpret_cast<LPBYTE>(&value), &BufferSize) == ERROR_SUCCESS)
		{
			skipWarning = value ? 1 : 0;
		}
		else
		{
			skipWarning = 0;
			RegSetValueExA(hKey, ("SKIPWARNING"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&skipWarning), BufferSize);
		}

		BufferSize = sizeof(DWORD);
		if (RegQueryValueExA(hKey, ("SHUFFLEBGM"), NULL, NULL, reinterpret_cast<LPBYTE>(&value), &BufferSize) == ERROR_SUCCESS)
		{
			shuffleBGM = value ? 1 : 0;
		}
		else
		{
			shuffleBGM = 0;
			RegSetValueExA(hKey, ("SHUFFLEBGM"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&shuffleBGM), BufferSize);
		}

		BufferSize = sizeof(DWORD);
		if (RegQueryValueExA(hKey, ("AXIS_DEADZONE"), NULL, NULL, reinterpret_cast<LPBYTE>(&value), &BufferSize) == ERROR_SUCCESS)
		{
			deadZonePercent = static_cast<char>(value);
			if (deadZonePercent < 0 || deadZonePercent > 100)
			{
				deadZonePercent = 5;
				RegSetValueExA(hKey, ("AXIS_DEADZONE"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&deadZonePercent), BufferSize);
			}
		}
		else
		{
			deadZonePercent = 5;
			RegSetValueExA(hKey, ("AXIS_DEADZONE"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&deadZonePercent), BufferSize);
		}

		BufferSize = sizeof(strvalue);
		if (RegGetValueA(HKEY_CURRENT_USER, ("Software\\Genki\\SBOL"), ("LANGUAGE"), RRF_RT_REG_SZ, NULL, strvalue, &BufferSize) == ERROR_SUCCESS)
		{
			language = strvalue;
			if (language.size() != 2)
			{
				language = "en";
				RegSetValueExA(hKey, ("LANGUAGE"), 0, REG_SZ, (LPBYTE)language.c_str(), language.size() + 0);
			}
		}
		else
		{
			language = "en";
			RegSetValueExA(hKey, ("LANGUAGE"), 0, REG_SZ, (LPBYTE)language.c_str(), language.size() + 1);
		}
	}
	else
	{
		int drawdistance = 100;
		int uiscale = 100;
		resW = 640;
		resH = 480;
		virtualResW = (int)((float)resH * SCREEN_RATIO_4_3);
		SWFscaleX = (float)virtualResW / 640.0f;
		SWFscaleY = (float)resH / 480.0f;
		SWFscale = (float)resH / 480.0f;
		fullScreen = 0;
		drawDistanceMultiplier = 1.0f;
		skipWarning = 0;
		shuffleBGM = 0;
		deadZonePercent = 5;
		language = "en";

		if (RegCreateKeyExA(HKEY_CURRENT_USER, ("Software\\Genki\\SBOL"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL) == ERROR_SUCCESS)
		{
			BufferSize = sizeof(DWORD);
			RegSetValueExA(hKey, ("RES_WIDTH"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&resW), BufferSize);
			RegSetValueExA(hKey, ("RES_HEIGHT"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&resH), BufferSize);
			RegSetValueExA(hKey, ("FULLSCREEN"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&fullScreen), BufferSize);
			RegSetValueExA(hKey, ("DRAWDISTANCE"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&drawdistance), BufferSize);
			RegSetValueExA(hKey, ("UISCALE"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&uiscale), BufferSize);
			RegSetValueExA(hKey, ("SKIPWARNING"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&skipWarning), BufferSize);
			RegSetValueExA(hKey, ("SHUFFLEBGM"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&shuffleBGM), BufferSize);
			RegSetValueExA(hKey, ("AXIS_DEADZONE"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&deadZonePercent), BufferSize);
			RegSetValueExA(hKey, ("LANGUAGE"), 0, REG_SZ, (LPBYTE)language.c_str(), language.size());
		}
	}

	RegCloseKey(hKey);
}
int VerString(char* str, const char* format, ...)
{
	return sprintf(str, versionStr, clientVer[0], clientVer[1], clientVer[2], clientVer[3]);
}

void __fastcall DxWindow(void* _this, void* edx, int x1, int y1, int x2, int y2)
{
	if (x1 == 0 && y1 == 0 && x2 == 640 && y2 == 480)
	{
		x2 = resW;
		y2 = resH;
	}
	else
	{
		float xScale = ((1.0f / 640.0f) * (float)resW);
		float yScale = ((1.0f / 480.0f) * (float)resH);
		x1 = (int)((float)x1 * xScale);
		y1 = (int)((float)y1 * xScale);
		x2 = (int)((float)x2 * xScale);
		y2 = (int)((float)y2 * xScale);
	}
	*(int*)((int)_this + 0xd9a8) = x1;
	*(int*)((int)_this + 0xd9ac) = y1;
	*(int*)((int)_this + 0xd9b0) = x2;
	*(int*)((int)_this + 0xd9b4) = y2;
}

void ForceShiftJIS()
{
	SetThreadLocale(0x0411);
	setlocale(LC_ALL, ".932");
	_setmbcp(932);
	SetConsoleOutputCP(932);
	SetConsoleCP(932);

	setFunction(0x00555027, (void*)&MultiByteToWideCharHook_Ptr);
	setFunction(0x00554FC2, (void*)&MultiByteToWideCharHook_Ptr);
	setFunction(0x00554F67, (void*)&MultiByteToWideCharHook_Ptr);
	setFunction(0x00554C43, (void*)&MultiByteToWideCharHook_Ptr);
	setFunction(0x0055312F, (void*)&MultiByteToWideCharHook_Ptr);
	setFunction(0x005530D9, (void*)&MultiByteToWideCharHook_Ptr);
	setFunction(0x0054FEB3, (void*)&MultiByteToWideCharHook_Ptr);
	setFunction(0x0054FE73, (void*)&MultiByteToWideCharHook_Ptr);
	setFunction(0x0054D320, (void*)&MultiByteToWideCharHook_Ptr);
	setFunction(0x0054D2C8, (void*)&MultiByteToWideCharHook_Ptr);
	setFunction(0x0054445B, (void*)&MultiByteToWideCharHook_Ptr);
	setFunction(0x00544434, (void*)&MultiByteToWideCharHook_Ptr);
	setFunction(0x005443D8, (void*)&MultiByteToWideCharHook_Ptr);
	setFunction(0x0054113A, (void*)&MultiByteToWideCharHook_Ptr);
	setFunction(0x005408AF, (void*)&MultiByteToWideCharHook_Ptr);

	setFunction(0x00552343, (void*)&GetUserDefaultLCIDHook_Ptr);

	setFunction(0x00551d1f, (void*)&GetLocaleInfoAHook_Ptr);
	setFunction(0x005524b2, (void*)&GetLocaleInfoAHook_Ptr);
	setFunction(0x00554b95, (void*)&GetLocaleInfoAHook_Ptr);
	setFunction(0x00554be1, (void*)&GetLocaleInfoAHook_Ptr);
	setFunction(0x00554c22, (void*)&GetLocaleInfoAHook_Ptr);
	setFunction(0x00554ca8, (void*)&GetLocaleInfoAHook_Ptr);
	setFunction(0x00554ccf, (void*)&GetLocaleInfoAHook_Ptr);

	setFunction(0x00554b82, (void*)&GetLocaleInfoWHook_Ptr);
	setFunction(0x00554bbc, (void*)&GetLocaleInfoWHook_Ptr);
	setFunction(0x00554c95, (void*)&GetLocaleInfoWHook_Ptr);
	setFunction(0x00554cf8, (void*)&GetLocaleInfoWHook_Ptr);
	setFunction(0x00554d3b, (void*)&GetLocaleInfoWHook_Ptr);

	setFunction(0x0054c927, (void*)&GetACPHook_Ptr);

	setFunction(0x0054c79c, (void*)&GetCPInfoHook_Ptr);
	setFunction(0x0054c9b2, (void*)&GetCPInfoHook_Ptr);
	setFunction(0x00551b45, (void*)&GetCPInfoHook_Ptr);
	setFunction(0x00554ee8, (void*)&GetCPInfoHook_Ptr);

	setFunction(0x004C466F, (void*)&CreateFontAHook_Ptr);

	setFunction(0x0051D4d6, (void*)&CreateFontIndirectAHook_Ptr);
	setFunction(0x00408866, (void*)&CreateFontIndirectAHook_Ptr);

	setFunction(0x00408891, (void*)&GetTextMetricsAHook_Ptr);
	setFunction(0x0051D501, (void*)&GetTextMetricsAHook_Ptr);

	setFunction(0x004FDF19, (void*)&TextOutAHook_Ptr);

	setFunction(0x004F48CA, (void*)&CreateRectRgnHook_Ptr);
	setFunction(0x004FC10F, (void*)&CreateRectRgnHook_Ptr);
	
	setFunction(0x0040D1EF, (void*)&PtInRegionHook_Ptr);

	*(byte*)0x00408850 = SHIFTJIS_CHARSET;
	*(byte*)0x0051D4C0 = SHIFTJIS_CHARSET;
}
void PrintItems()
{
	std::stringstream ss;
	for (int i = 0; i < sizeof(itemDetails) / sizeof(ITEMDETAILENTRY); i++)
	{
		std::string name = itemDetails[i].name;
		std::replace(name.begin(), name.end(), ' ', '_');
		std::string desc = itemDetails[i].description;
		std::replace(desc.begin(), desc.end(), ' ', '_');
		ss << name << "_" << desc;
		ss << " = 0x" << std::setw(4) << std::setfill('0') << std::uppercase << std::hex << itemDetails[i].itemid << "," << std::endl;
		/*
		ss << itemDetails[i].name;
		int namelen = strnlen(itemDetails[i].name, 64);
		for (int j = 0; j < 64 - namelen; j++)
			ss << " ";
		ss << " " << itemDetails[i].description;
		int desclen = strnlen(itemDetails[i].description, 128);
		for (int j = 0; j < 128 - desclen; j++)
			ss << " ";
		ss << " = 0x" << std::setw(4) << std::setfill('0') << std::uppercase << std::hex << itemDetails[i].itemid << "," << std::endl;
		*/
	}
	OutputDebugStringA(ss.str().c_str());
}
void SaveItemsStrings()
{
	std::ofstream fs("items.json", std::ios::out | std::ios::binary);
	if (!fs.is_open()) return;
	fs << "{" << "\r\n";
	fs << "\t\"items\" : \r\n\t[\r\n";
	auto itemcount = 2132; // sizeof(itemDetails) / sizeof(ITEMDETAILENTRY);
	const ITEMDETAILENTRY* items = itemDetailsInternal2;
	for (int i = 0; i < itemcount; i++)
	{
		std::string name = items[i].name;
		name.erase(std::remove(name.begin(), name.end(), '\t'), name.end());
		name = "\"" + name + "\", ";
		std::string desc = items[i].description;
		desc.erase(std::remove(desc.begin(), desc.end(), '\t'), desc.end());
		fs << "\t\t[ " << std::right << std::setfill(' ') << std::setw(4) << items[i].itemid << ", " << std::left << std::setfill(' ') << std::setw(64) << name << "\"" << desc << "\" ]";
		if (i + 1 == itemcount)
			fs << "\r\n";
		else
			fs << ",\r\n";
	}
	fs << "\t]\r\n}";
	fs.close();
}
ITEMDETAILENTRY* LoadItemStrings(const char* filename, int* count)
{
	try
	{
		nlohmann::json itemstringsjson;
		std::ifstream file(filename);
		if (!file.is_open())
			return nullptr;
		file >> itemstringsjson;
		file.close();
		const auto& items_array = itemstringsjson["items"];
		int stringcount = items_array.size();
		if (stringcount < 2132)
			return nullptr;
		ITEMDETAILENTRY* items = (ITEMDETAILENTRY*)malloc(stringcount * sizeof(ITEMDETAILENTRY));
		if (items)
		{
			int namelen = 0;
			int desclen = 0;
			for (int i = 0; i < stringcount; i++)
			{
				namelen = strnlen(items_array[i][1].get<std::string>().c_str(), 64);
				desclen = strnlen(items_array[i][2].get<std::string>().c_str(), 128);
				char* name = (char*)calloc(namelen + 1, 1);
				char* desc = (char*)calloc(desclen + 1, 1);
				if (!name || !desc)
					continue;
				memcpy(name, items_array[i][1].get<std::string>().c_str(), namelen);
				memcpy(desc, items_array[i][2].get<std::string>().c_str(), desclen);
				items[i].itemid = items_array[i][0];
				items[i].name = name;
				items[i].description = desc;
			}
		}
		*count = stringcount;
		return items;
	}
	catch (std::exception e)
	{
		std::stringstream ss;
		ss << "Failed to load " << filename << ". Exception: " << e.what() << std::endl;
		OutputDebugStringA(ss.str().c_str());
		return nullptr;
	}
}
void removeEscape(std::string& str) {
	size_t pos = 0;
	while ((pos = str.find_first_of("\r\n\t", pos)) != std::string::npos) {
		switch (str[pos]) {
		case '\r': str.replace(pos, 1, "\\r"); break;
		case '\n': str.replace(pos, 1, "\\n"); break;
		case '\t': str.replace(pos, 1, "\\t"); break;
		}
		pos += 2; // Move past the newly inserted "\\" and the character
	}
}
void addEscape(std::string& str) {
	size_t pos = 0;
	while ((pos = str.find_first_of("\\", pos)) != std::string::npos) {
		switch (str[pos]) {
		case '\\r': str.replace(pos, 2, "\r"); break;
		case '\\n': str.replace(pos, 2, "\n"); break;
		case '\\t': str.replace(pos, 2, "\t"); break;
		}
		pos += 1;
	}
}
void SaveStrings()
{
	std::ofstream fs("strings.json", std::ios::out | std::ios::binary);
	if (!fs.is_open()) return;
	fs << "{" << "\r\n";
	fs << "\t\"strings\" : \r\n\t[\r\n";
	auto stringcount = (sizeof(stringaddresses) / sizeof(STATICSTRING));
	const STATICSTRING* strings = stringaddresses;
	for (unsigned int i = 0; i < stringcount; i++)
	{
		std::string string = strings[i].ptr;
		removeEscape(string);
		string = "\"" + string + "\"";
		fs << "\t\t[ " << i << ", " << string << " ]";
		if (i + 1 == stringcount)
			fs << "\r\n";
		else
			fs << ",\r\n";
	}
	fs << "\t]\r\n}";
	fs.close();
}
void ReplaceStrings(const char* filename)
{
	try
	{
		nlohmann::json stringsjson;
		std::ifstream file(filename);
		if (!file.is_open())
			return;
		file >> stringsjson;
		file.close();
		const auto& string_array = stringsjson["strings"];
		int stringcount = string_array.size();
		
		for (int i = 0; i < stringcount; i++)
		{
			int idx = string_array[i][0].get<int>();
			if (idx >= (sizeof(stringaddresses) / sizeof(STATICSTRING)) || idx < 0)
				continue;
			std::string string = string_array[i][1].get<std::string>();
			addEscape(string);
			int limit = stringaddresses[idx].limit;
			char* stringaddress = stringaddresses[idx].ptr;

			int stringlen = strnlen(string.c_str(), limit -1);
			memcpy(stringaddress, string.c_str(), stringlen);
			stringaddress[stringlen] = '\0';
		}
	}
	catch (std::exception e)
	{
		std::stringstream ss;
		ss << "Failed to load " << filename << ". Exception: " << e.what() << std::endl;
		OutputDebugStringA(ss.str().c_str());
		return;
	}
}
void SaveRivalStrings()
{
	std::ofstream fs("rivals.json", std::ios::out | std::ios::binary);
	if (!fs.is_open()) return;
	fs << "{" << "\r\n";
	fs << "\t\"teamnames\" : \r\n\t[\r\n";

	char** teamnames = (char**)rivalTeamNameTable;
	char** handles = (char**)rivalHandleTable;
	int i = 0;
	while (*teamnames != nullptr)
	{
		std::string teamname = *teamnames;
		removeEscape(teamname);
		teamname = "\"" + teamname + "\"";
		fs << "\t\t[ " << i << ", " << teamname << " ]";
		if (*(teamnames + 1) == nullptr)
			fs << "\r\n";
		else
			fs << ",\r\n";
		i++;
		teamnames++;
	}
	i = 0;
	fs << "\t],\r\n";
	fs << "\t\"teamhandles\" : \r\n\t[\r\n";
	while (*handles != nullptr)
	{
		std::string handle = *handles;
		removeEscape(handle);
		handle = "\"" + handle + "\"";
		fs << "\t\t[ " << i << ", " << handle << " ]";
		if (*(handles + 1) == nullptr)
			fs << "\r\n";
		else
			fs << ",\r\n";
		i++;
		handles++;
	}
	fs << "\t]\r\n}";
	fs.close();
}
void ReplaceRivalStrings(const char* filename)
{
	try
	{
		char** teamnames = (char**)rivalTeamNameTable;
		char** handles = (char**)rivalHandleTable;

		nlohmann::json stringsjson;
		std::ifstream file(filename);
		if (!file.is_open())
			return;
		file >> stringsjson;
		file.close();
		const auto& teamnames_array = stringsjson["teamnames"];
		int teamnamecount = teamnames_array.size();

		for (int i = 0; i < teamnamecount; i++)
		{
			int idx = teamnames_array[i][0].get<int>();
			if (idx >= 45 || idx < 0)
				continue;
			std::string teamname = teamnames_array[i][1].get<std::string>();
			addEscape(teamname);
			char* teamnameptr = (char*)calloc(teamname.size() + 1, 1);
			if (teamnameptr)
			{
				memcpy(teamnameptr, (char*)teamname.c_str(), teamname.size());
				teamnames[idx] = teamnameptr;
			}
		}

		const auto& teamhandles_array = stringsjson["teamhandles"];
		int teamhandlecount = teamhandles_array.size();

		for (int i = 0; i < teamhandlecount; i++)
		{
			int idx = teamhandles_array[i][0].get<int>();
			if (idx >= 336 || idx < 0)
				continue;
			std::string handle = teamhandles_array[i][1].get<std::string>();
			addEscape(handle);
			char* teamhandleptr = (char*)calloc(handle.size() + 1, 1);
			if (teamhandleptr)
			{
				memcpy(teamhandleptr, handle.c_str(), handle.size());
				handles[idx] = teamhandleptr;
			}
		}
	}
	catch (std::exception e)
	{
		std::stringstream ss;
		ss << "Failed to load " << filename << ". Exception: " << e.what() << std::endl;
		OutputDebugStringA(ss.str().c_str());
		return;
	}
}
void SaveAllStrings()
{
	std::ofstream fs("lang-jp.json", std::ios::out | std::ios::binary);
	if (!fs.is_open()) return;
	fs << "{" << "\r\n";

	fs << "\t\"items\" : \r\n\t[\r\n";
	auto itemcount = 2132; // sizeof(itemDetails) / sizeof(ITEMDETAILENTRY);
	const ITEMDETAILENTRY* items = itemDetailsInternal2;
	for (int i = 0; i < itemcount; i++)
	{
		std::string name = items[i].name;
		name.erase(std::remove(name.begin(), name.end(), '\t'), name.end());
		name = "\"" + name + "\", ";
		std::string desc = items[i].description;
		desc.erase(std::remove(desc.begin(), desc.end(), '\t'), desc.end());
		fs << "\t\t[ " << std::right << std::setfill(' ') << std::setw(4) << items[i].itemid << ", " << std::left << std::setfill(' ') << std::setw(64) << name << "\"" << desc << "\" ]";
		if (i + 1 == itemcount)
			fs << "\r\n";
		else
			fs << ",\r\n";
	}
	fs << "\t],\r\n";

	fs << "\t\"strings\" : \r\n\t[\r\n";
	auto stringcount = (sizeof(stringaddresses) / sizeof(STATICSTRING));
	const STATICSTRING* strings = stringaddresses;
	for (unsigned int i = 0; i < stringcount; i++)
	{
		std::string string = strings[i].ptr;
		removeEscape(string);
		string = "\"" + string + "\"";
		fs << "\t\t[ " << i << ", " << string << " ]";
		if (i + 1 == stringcount)
			fs << "\r\n";
		else
			fs << ",\r\n";
	}
	fs << "\t],\r\n";

	fs << "\t\"teamnames\" : \r\n\t[\r\n";
	char** teamnames = (char**)rivalTeamNameTable;
	char** handles = (char**)rivalHandleTable;
	int i = 0;
	while (*teamnames != nullptr)
	{
		std::string teamname = *teamnames;
		removeEscape(teamname);
		teamname = "\"" + teamname + "\"";
		fs << "\t\t[ " << i << ", " << teamname << " ]";
		if (*(teamnames + 1) == nullptr)
			fs << "\r\n";
		else
			fs << ",\r\n";
		i++;
		teamnames++;
	}
	i = 0;
	fs << "\t],\r\n";
	fs << "\t\"teamhandles\" : \r\n\t[\r\n";
	while (*handles != nullptr)
	{
		std::string handle = *handles;
		removeEscape(handle);
		handle = "\"" + handle + "\"";
		fs << "\t\t[ " << i << ", " << handle << " ]";
		if (*(handles + 1) == nullptr)
			fs << "\r\n";
		else
			fs << ",\r\n";
		i++;
		handles++;
	}

	fs << "\t]\r\n}";
	fs.close();
}
int __cdecl GetSupportedResolution(int deviceid, int unknown2, int width, int height, int unknown3)
{
	/* The game will check to see if the window is running at a supported resolution and if not return -1 */
	/* This function sets all supported resolutions to the set resolution */
	void* unknownobject;
	void* dxobject;
	typedef struct st_supportedresolution {
		int width;
		int height;
		int fps;
		int unknown2;
		int unknown3;
	} SUPPORTED_RESOLUTION;
	SUPPORTED_RESOLUTION* supportedResolution;
	int supportedResolutionCount;

	dxobject = (void*)0x006EAAC8;
	unknownobject = (void*)(*(int*)(*(int*)((int)dxobject + 4) + 0x18 + deviceid * 0x24));
	if (*(int*)((int)unknownobject + 0xE0) == 0) {
		supportedResolutionCount = 0;
	}
	else {
		supportedResolutionCount = (*(int*)((int)unknownobject + 0xE4) - *(int*)((int)unknownobject + 0xE0)) / 0x14;
	}
	supportedResolution = *(SUPPORTED_RESOLUTION**)((int)unknownobject + 0xE0);
	if (supportedResolution == nullptr) return -1;
	for (int i = 0; i < supportedResolutionCount; i++)
	{
		supportedResolution[i].width = resW;
		supportedResolution[i].height = resH;
		supportedResolution[i].unknown2 = unknown2;
		supportedResolution[i].unknown3 = unknown3;
	}
	return 0;
}
void __cdecl DrawStrings(void* unknown1, void* unknown2, int unknown3)
{
	using UnknownFunc = void(__cdecl*)(void*, void*, int);
	UnknownFunc UnknownFuncOrig = (UnknownFunc)(0x004035C0);
	UnknownFuncOrig(unknown1, unknown2, unknown3);
	drawStrings = true;
}
int __stdcall MultiByteToWideCharHook(UINT CodePage, DWORD dwFlags, LPCCH lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar)
{
	int res = MultiByteToWideChar(932, dwFlags, lpMultiByteStr, cbMultiByte, lpWideCharStr, cchWideChar);
	return res;
}

LCID __stdcall GetUserDefaultLCIDHook()
{
	return 0x0411;
}

int __stdcall GetLocaleInfoAHook(LCID Locale, LCTYPE LCType, LPSTR lpLCData, int cchData)
{
	int res = GetLocaleInfoA(0x0411, LCType, lpLCData, cchData);
	return res;
}

int __stdcall GetLocaleInfoWHook(LCID Locale, LCTYPE LCType, LPWSTR lpLCData, int cchData)
{
	int res = GetLocaleInfoW(0x0411, LCType, lpLCData, cchData);
	return res;
}

UINT __stdcall GetACPHook()
{
	return 932;
}

BOOL __stdcall GetCPInfoHook(UINT CodePage, LPCPINFO lpCPInfo)
{
	BOOL res = GetCPInfo(932, lpCPInfo);
	return res;
}

HFONT __stdcall CreateFontAHook(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision, DWORD iQuality, DWORD iPitchAndFamily, LPCSTR pszFaceName)
{
	HFONT res = CreateFontA(
		cHeight,
		cWidth,
		cEscapement,
		cOrientation,
		cWeight,
		bItalic,
		bUnderline,
		bStrikeOut,
		SHIFTJIS_CHARSET,
		iOutPrecision,
		iClipPrecision,
		CLEARTYPE_QUALITY, //iQuality,
		FIXED_PITCH, //| FF_MODERN, //iPitchAndFamily,
		"Courier New" //pszFaceName
	);
	return res;
}

HFONT __stdcall CreateFontIndirectAHook(LOGFONTA* lplf)
{
	/*
	std::stringstream ss;
	ss << "Font - Height: " << lplf->lfHeight << " Width: " << lplf->lfWidth << std::endl;
	OutputDebugStringA(ss.str().c_str());
	*/

	HFONT res = CreateFontA(
		lplf->lfHeight,
		lplf->lfWidth,
		lplf->lfEscapement,
		lplf->lfOrientation,
		lplf->lfWeight,
		lplf->lfItalic,
		lplf->lfUnderline,
		lplf->lfStrikeOut,
		lplf->lfCharSet,
		lplf->lfOutPrecision,
		lplf->lfClipPrecision,
		CLEARTYPE_QUALITY, // lplf->lfQuality, // 
		FIXED_PITCH, // | FF_MODERN, //lplf->lfPitchAndFamily,
		"Courier New" //lplf->lfFaceName
	);
	return res;
}

BOOL __stdcall GetTextMetricsAHook(HDC hdc, LPTEXTMETRICA lptm)
{
	BOOL res = GetTextMetricsA(hdc, lptm);
	return res;
}

void __stdcall HandleMessages(LPMSG lpMsg)
{
	if (!runGameLoop)
	{
		runGameLoop = true;
	}
	bool running = true;
	bool isCursorVisible = true;
	ULONGLONG lastMoveTime = GetTickCount64();
	const ULONGLONG hideDelay = 2000; // 2 seconds
	UINT count = 0;
	while (running)
	{
		if (PeekMessageA(lpMsg, NULL, 0, 0, PM_REMOVE))
		{
			switch (lpMsg->message)
			{
			case WM_QUIT:
				running = false;
				break;
			case WM_MOUSEMOVE:
				lastMoveTime = GetTickCount64();
				while (ShowCursor(TRUE) < 0) {}
				break;
			}
			TranslateMessage(lpMsg);
			DispatchMessageA(lpMsg);
		}
		// Check if the mouse has been still for too long
		if ((GetTickCount64() - lastMoveTime > hideDelay)) {
			while (ShowCursor(FALSE) > 0) {}
		}
		Sleep(1);
	}
	runGameLoop = false;
	return;
}

BOOL __stdcall TextOutAHook(HDC hdc, int x, int y, LPCSTR lpString, int c)
{
	BOOL res = TextOutA(
		hdc,
		x,
		y,
		lpString,
		c);
	return res;
}

HRGN __stdcall CreateRectRgnHook(int x1, int y1, int x2, int y2)
{
	auto width = x2 - x1;
	auto height = y2 - y1;
	return CreateRectRgn(x1, y1, x2, y2);
}

BOOL __stdcall PtInRegionHook(HRGN hrgn, int x, int y)
{
	RECT rect{};
	GetRgnBox(hrgn, &rect);
	auto width = rect.right - rect.left;
	auto height = rect.bottom - rect.top;
	return PtInRegion(hrgn, x, y);
}

BOOL __stdcall SetWindowPosHook(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags)
{
	if (fullScreen)
	{
		DWORD style = WS_POPUP | WS_VISIBLE;
		DWORD exStyle = WS_EX_TOPMOST;
		SetWindowLongPtr(hWnd, GWL_STYLE, style);
		SetWindowLongPtr(hWnd, GWL_EXSTYLE, exStyle);
		auto res = SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, screenWidth, screenHeight, SWP_FRAMECHANGED | SWP_SHOWWINDOW);
		//SetProcessDPIAware();
		return res;
	}
	else
		return SetWindowPos(hWnd, hWndInsertAfter, X, Y, cx, cy, uFlags);
}

void __fastcall Packet0482(void* _this, void* edx, void* mps)
{
	using mpsLockFunc = void* (__fastcall*)(void*, void*);
	using mpsUnlockFunc = void* (__fastcall*)(void*, void*);
	using readUInt32Func = void*(__fastcall*)(void*, void*, int*);
	mpsLockFunc mpsLock = (mpsLockFunc)0x00591700;
	mpsLockFunc mpsUnlock = (mpsLockFunc)0x00591750;
	void* mpsPacket = mpsLock(mps, edx);
	int shopType = 0;
	readUInt32Func readUInt32 = *(readUInt32Func*)(*(int*)mpsPacket + 0x1C);
	
	readUInt32(mpsPacket, edx, &shopType);
	mpsUnlock(mps,edx);

	*(float*)(0x006F4F38 + 0x128C) = 1.0f;
	*(uint16_t*)(0x006F4F38 + 0x1284) = 0xffff;
	*(uint16_t*)(0x006F4F38 + 0x1286) = 0xffff;
	*(uint8_t*)(0x006F4F38 + 0x1288) = 0;
	*(uint8_t*)(0x006F4F38 + 0x1290) = 0;

	*(uint32_t*)0x006F64C0 = shopType;

	using WarpToScreenFunc = void* (__fastcall*)(void*, void*, int, int);
	WarpToScreenFunc WarpToScreen = (WarpToScreenFunc)0x004272F0;
	WarpToScreen(*(void**)0x006EBDD0, edx, 0x14, 0x1A);
}

void __fastcall packetHandle04001400(void* _this, void* edx, void* mps)
{
	using PACKET_IN_0400_0700_1400Func = void* (__fastcall*)(void*, void*, void*);
	PACKET_IN_0400_0700_1400Func PACKET_IN_0400_0700_1400 = (PACKET_IN_0400_0700_1400Func)0x0044A6C0;
	using PACKET_IN_148XFunc = void* (__fastcall*)(void*, void*, void*);
	PACKET_IN_148XFunc PACKET_IN_1480 = (PACKET_IN_148XFunc)0x004EBF40;
	PACKET_IN_148XFunc PACKET_IN_1481 = (PACKET_IN_148XFunc)0x004EC1A0;
	PACKET_IN_148XFunc PACKET_IN_1482 = (PACKET_IN_148XFunc)0x004EBFC0;
	PACKET_IN_148XFunc PACKET_IN_1483 = (PACKET_IN_148XFunc)0x004EC090;
	PACKET_IN_148XFunc PACKET_IN_1484 = (PACKET_IN_148XFunc)0x004EC270;

	uint16_t pType = *(uint16_t*)((int)mps + 6);
	if (pType == 0x0480)
	{
		*(void**)((int)_this + 0x2650) = PACKET_IN_0400_0700_1400;
		*(int*)((int)_this + 0x2654) = 0;
		PACKET_IN_0400_0700_1400(_this, edx, mps);
	}
	else if (pType == 0x0482)
		Packet0482(_this, edx, mps);
	else if (pType == 0x1480)
		PACKET_IN_1480((void*)0x006EE3DC, edx, mps);
	else if (pType == 0x1481)
		PACKET_IN_1481((void*)0x006EE3DC, edx, mps);
	else if (pType == 0x1482)
		PACKET_IN_1482((void*)0x006EE3DC, edx, mps);
	else if (pType == 0x1483)
		PACKET_IN_1483((void*)0x006EE3DC, edx, mps);
	else if (pType == 0x1484)
		PACKET_IN_1484((void*)0x006EE3DC, edx, mps);
	return;
}

__declspec(naked) void Packet0190Handler()
{
	__asm
	{
		mov ecx, dword ptr[esp + 0x000000B8]
		pushad
		push edx
		push ecx
		call Packet0190
		add esp, 8
		popad
		mov eax, 0x0043D39E
		jmp eax
	}
}

void Packet0190(void* mps, void* edx)
{
	uint16_t packettype = *(uint16_t*)((int)mps + 0x06);
	if (packettype == 0x0190)
	{
		using mpsLockFunc = void* (__fastcall*)(void*, void*);
		using mpsUnlockFunc = void* (__fastcall*)(void*, void*);
		using readBufferFunc = uint32_t (__fastcall*)(void*, void*, char*, uint32_t, uint32_t, int32_t);
		mpsLockFunc mpsLock = (mpsLockFunc)0x00591700;
		mpsLockFunc mpsUnlock = (mpsLockFunc)0x00591750;
		readBufferFunc readBuffer = (readBufferFunc)0x00592DB0;
		void* mpsPacket = mpsLock(mps, edx);
		TIMEATTACK timeattack{};
		uint32_t res = readBuffer(mpsPacket, edx, reinterpret_cast<char*>(&timeattack), sizeof(TIMEATTACK), 0, 2);
		mpsUnlock(mps, edx);
		GetTimeAttackRecordFromPacket(timeattack);
	}
}

void GetTimeAttackRecordFromPacket(TIMEATTACK& timeattack)
{
	using UnknownFunc = void(__fastcall*)(void*, void*, int);
	UnknownFunc unknownFunc = (UnknownFunc)0x005030F0;
	void* dummyEdx = nullptr;

	char* base6F64D4 = (char*)0x006F64D4;

	auto getValidTime = [](int time) { return (time != 0) ? time : -1; };

	for (int i = 0; i < 6; i++)
	{
		int offset = i * 0x1B8; // 440 bytes

		// Set LAPTYPE and BESTTYPE dynamically based on record availability
		char lapTypeVal = 0;
		if (timeattack.record[i].carclass[0].lap.time > 0 ||
			timeattack.record[i].carclass[1].lap.time > 0 ||
			timeattack.record[i].carclass[2].lap.time > 0)
		{
			lapTypeVal = 1;
		}

		base6F64D4[offset] = lapTypeVal;
		base6F64D4[offset + 1] = 0;

		// Loop through the 3 car classes (0, 1, 2) dynamically
		for (int c = 0; c < 3; c++)
		{
			auto& car = timeattack.record[i].carclass[c];
			int classOffset = c * 0x28; // 40-byte offset per class in the binary

			// 1. Write Top Speeds (spaced 4 bytes apart)
			uintptr_t topSpeedAddr = 0x006F6668 + offset + (c * 4);
			*(int*)topSpeedAddr = car.topspeed;

			// 2. Write Splits & Lap Times (Explicit Pointer Additions)
			uintptr_t timeBase = 0x006F6578 + offset + classOffset;

			// LAP0 defaults to 0 if a lap time exists, otherwise -1
			*(int*)(timeBase + 0x00) = (car.lap.time > 0) ? 0 : -1;

			// Direct dereferencing using raw calculated addresses to avoid indexing traps
			*(int*)(timeBase + 0x04) = getValidTime(car.firstsplit.time);
			*(int*)(timeBase + 0x08) = getValidTime(car.secondsplit.time);
			*(int*)(timeBase + 0x0C) = getValidTime(car.thirdsplit.time);
			*(int*)(timeBase + 0x10) = getValidTime(car.lap.time);

			// 3. Write Sector & Lap Speeds
			uintptr_t speedBase = 0x006F65F0 + offset + classOffset;
			*(int*)(speedBase + 0x00) = car.startspeed;
			*(int*)(speedBase + 0x04) = car.firstsplit.speed;
			*(int*)(speedBase + 0x08) = car.secondsplit.speed;
			*(int*)(speedBase + 0x0C) = car.thirdsplit.speed;
			*(int*)(speedBase + 0x10) = car.lap.speed;
		}

		// Boundary checks
		if (base6F64D4[offset] > 1)     base6F64D4[offset] = 1;
		if (base6F64D4[offset + 1] > 1) base6F64D4[offset + 1] = 1;

		// Call game's internal update function with correct __thiscall registers
		unknownFunc((void*)0x006F4F38, dummyEdx, i);
	}
}