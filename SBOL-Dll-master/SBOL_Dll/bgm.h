#pragma once
#ifndef BGM_HEADER
#define BGM_HEADER
#include <Windows.h>
#include "asm.h"
#include "OggPlayer.h"

void __cdecl oggThread(void* parg);
int setBGM(int _bgm, int unknown1, int unknown2);
void stopBGM();
void stopBGMasm();
#endif