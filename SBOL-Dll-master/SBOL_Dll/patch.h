#pragma once
#ifndef PATCH_HEADER
#define PATCH_HEADER
#define DIRECTINPUT_VERSION			0x0800
#include "asm.h"
#include "bgm.h"
#include "dx.h"
#include "DXFont.h"
#include "OggPlayer.h"
#include <clocale>
#include <debugapi.h>
#include <dinput.h>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <mbctype.h>
#include <nlohmann/json.hpp>
#include <process.h>
#include <Psapi.h>
#include <sstream>
#include <string>
#include <Windows.h>

extern DXFont* BGMTrackFont;
extern DXFont* PositionFont;
extern std::string language;

void patchClient();
void patchBugs();
int disabledLegacyFullScreen();
int notFullScreenMode();
int skipBootWarning();
void setStrings();
void setDrawDistance();
void setResolution();
void fixResolutionChoice();
void windowMonitorThread(void* parg);
void readRegistry();
int VerString(char* str, const char* format, ...);
void __fastcall DxWindow(void* _this, void* edx, int x1, int y1, int x2, int y2);
void ForceShiftJIS();
void PrintItems();
void SaveItemsStrings();
ITEMDETAILENTRY* LoadItemStrings(const char* filename, int* count = nullptr);
void removeEscape(std::string& str);
void addEscape(std::string& str);
void SaveStrings();
void ReplaceStrings(const char* filename);
void SaveRivalStrings();
void ReplaceRivalStrings(const char* filename);
void SaveAllStrings();

int __cdecl GetSupportedResolution(int deviceid, int unknown2, int width, int height, int unknown3);
void __cdecl DrawStrings(void*, void*, int);
int __stdcall MultiByteToWideCharHook(UINT CodePage, DWORD dwFlags, LPCCH lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar);
constexpr void* MultiByteToWideCharHook_Ptr = (void*)(&MultiByteToWideCharHook);
LCID __stdcall GetUserDefaultLCIDHook();
constexpr void* GetUserDefaultLCIDHook_Ptr = (void*)(&GetUserDefaultLCIDHook);
int __stdcall GetLocaleInfoAHook(LCID Locale, LCTYPE LCType, LPSTR lpLCData, int cchData);
constexpr void* GetLocaleInfoAHook_Ptr = (void*)(&GetLocaleInfoAHook);
int __stdcall GetLocaleInfoWHook(LCID Locale, LCTYPE LCType, LPWSTR lpLCData, int cchData);
constexpr void* GetLocaleInfoWHook_Ptr = (void*)(&GetLocaleInfoWHook);
UINT __stdcall GetACPHook();
constexpr void* GetACPHook_Ptr = (void*)(&GetACPHook);
BOOL __stdcall GetCPInfoHook(UINT CodePage, LPCPINFO lpCPInfo);
constexpr void* GetCPInfoHook_Ptr = (void*)(&GetCPInfoHook);
HFONT __stdcall CreateFontAHook(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision, DWORD iQuality, DWORD iPitchAndFamily, LPCSTR pszFaceName);
constexpr void* CreateFontAHook_Ptr = (void*)(&CreateFontAHook);
HFONT __stdcall CreateFontIndirectAHook(LOGFONTA* lplf);
constexpr void* CreateFontIndirectAHook_Ptr = (void*)(&CreateFontIndirectAHook);
BOOL __stdcall GetTextMetricsAHook(HDC hdc, LPTEXTMETRICA lptm);
constexpr void* GetTextMetricsAHook_Ptr = (void*)(&GetTextMetricsAHook);
void __stdcall HandleMessages(LPMSG lpMsg);
constexpr void* HandleMessageHook_Ptr = (void*)(&HandleMessages);
BOOL __stdcall TextOutAHook(HDC hdc, int x, int y, LPCSTR lpString, int c);
constexpr void* TextOutAHook_Ptr = (void*)(&TextOutAHook);
HRGN __stdcall CreateRectRgnHook(int x1, int y1, int x2, int y2);
constexpr void* CreateRectRgnHook_Ptr = (void*)(&CreateRectRgnHook);
BOOL __stdcall PtInRegionHook(HRGN hrgn, int x, int y);
constexpr void* PtInRegionHook_Ptr = (void*)(&PtInRegionHook);
BOOL __stdcall SetWindowPosHook(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags);
constexpr void* SetWindowPosHook_Ptr = (void*)(&SetWindowPosHook);

// Packets
void __fastcall packetHandle04001400(void* _this, void* edx, void* mps);
void __fastcall Packet0482(void* _this, void* edx, void* mps);
void Packet0190Handler();
void Packet0190(void* mps, void* edx);
void GetTimeAttackRecordFromPacket(TIMEATTACK& timeattack);
#endif