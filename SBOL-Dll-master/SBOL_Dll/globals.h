#pragma once
#define MAX_MESG_LEN	4096
#define DEBUG_LOG

// Used to store the pointer to the save game function - Unused space hopefully - Only used with offline.dll
#define SHARED_SPACE_PTR_ADDR		0x005B53CC
#define SHARED_SPACE_LOCK			0x4B434F4C
#define SHARED_SPACE_UNLOCK			0x00000000

#define SCREEN_RATIO_4_3			1.333333333333333f
#define PIXELS_TO_TWIPS				20.0f

#define PTR_ITEMBOX_STORAGE			0x006F5434

using adjustFloatsFunc = void(float*, float*);
using adjustIntsFunc = void(int*, int*);
