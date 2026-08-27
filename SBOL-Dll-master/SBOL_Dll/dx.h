#pragma once
#include <Windows.h>
#include <d3dx8.h>
#include <d3d8types.h>
#include "DXFont.h"
#include "OggPlayer.h"

HRESULT __stdcall directxCustom();
void drawBGMString();
void drawPositionString();
/* Hook inside course loop for custom strings 0x004D94F1 */
void __cdecl endScene();
