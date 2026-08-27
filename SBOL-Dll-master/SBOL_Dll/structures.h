#pragma once
#include "stdint.h"
#include "globals.h"

#pragma pack(push, 1)
typedef struct stringEntry {
	int mutli;
	char* ptr;
	char* str;
} STRINGENTRY;
typedef struct staticString {
	char* ptr;
	int limit;
} STATICSTRING;
typedef struct stringReplaceEntry {
	stringReplaceEntry(char* setptr, char* setstr) { ptr = setptr; str = setstr; strlen = 0; }
	stringReplaceEntry(char* setptr, char* setstr, int setstrlen) { ptr = setptr; str = setstr; strlen = setstrlen; }
	char* ptr;
	char* str;
	int strlen;
} STRINGREPLACEENTRY;
typedef struct itemDetailsEntry {
	int itemid;
	char* name;
	char* description;
} ITEMDETAILENTRY;
typedef struct itemSprite {
	int itemid;
	int sprite;
} ITEMSPRITE;
typedef struct st_SharedSpace {
	typedef struct st_Entity {
		bool IsMasterLocked() { return (master == SHARED_SPACE_LOCK); }
		void LockMaster() { master = SHARED_SPACE_LOCK; }
		void UnlockMaster() { master = SHARED_SPACE_UNLOCK; }
		bool IsSlaveLocked() { return (slave == SHARED_SPACE_LOCK); }
		void LockSlave() { slave = SHARED_SPACE_LOCK; }
		void UnlockSlave() { slave = SHARED_SPACE_UNLOCK; }
		uint32_t master = SHARED_SPACE_UNLOCK;
		uint32_t slave = SHARED_SPACE_UNLOCK;
		void* sharedptr = nullptr;
	} ENTITY;
	const uint32_t magic = 0x55464F54;
	ENTITY savegame;
	ENTITY reserved2;
	ENTITY reserved3;
	ENTITY reserved4;
	ENTITY reserved5;
	ENTITY reserved6;
	ENTITY reserved7;
	ENTITY reserved8;
} SHAREDSPACE;

typedef struct st_replacefunction {
	void* function = nullptr;
	int* address = nullptr;
} REPLACEFUNCTION;
typedef struct st_adjustfloats {
	adjustFloatsFunc* function = nullptr;
	float* x = nullptr;
	float* y = nullptr;
	void AdjustFloats()
	{
		if (function)
			function(x, y);
	}
} ADJUSTFLOATS;
typedef struct st_adjustints {
	adjustIntsFunc* function = nullptr;
	int* x = nullptr;
	int* y = nullptr;
	void AdjustInts()
	{
		if (function)
			function(x, y);
	}
} ADJUSTINTS;
typedef struct st_d3dmatrix {
	float ScaleX;
	float SkewY;
	float unknown3;
	float unknown4;
	float SkewX;
	float ScaleY;
	float unknown7;
	float unknown8;
	float unknown9;
	float unknown10;
	float ScaleZ;
	float unknown11;
	float TransX;
	float TransY;
	float unknown14;
	float W;
} D3D_MATRIX;
typedef struct st_swfuipage {
	char raw_data[4000]; // Orig 4000
} SWFUIPAGE;
typedef struct st_swfui {
	float ScaleX;
	float SkewX;
	float TransX;
	float SkewY;
	float ScaleY;
	float TransY;
	char buf1[92];
	char is_active;
	char is_visible;
	char padding[2];
	float horizontonal_speed;
	float vertical_speed;
	char buf2[4188];
	int mouse_x;
	LPDIRECT3DVERTEXBUFFER8 pVertexBuffer;
	int StartVertex;
	int mouse_delta_y;
	LPDIRECT3DDEVICE8 pDevice;
	char buf3[52];
	int active_element_count;
	char input_locked;
	char padding2[3];
	char input_buf[224];
	char ui_renderer_obj[24];
	SWFUIPAGE pages[23];
	int page_indices[23];
} SWFUI;
struct TransformedVertex {
	float x, y, z, rhw;
	DWORD color;
	float u, v; // Texture coordinates (adjust this structure if the game uses a different FVF)
};
struct TIMESECTION {
	uint32_t time;
	uint32_t speed;
};
struct TIMEATTACKRECORD {
	uint32_t unknown1;
	uint32_t unknown2;
	uint32_t topspeed;
	uint32_t startspeed;
	uint32_t unknown3;
	uint32_t unknown4;
	TIMESECTION firstsplit;
	TIMESECTION secondsplit;
	TIMESECTION thirdsplit;
	TIMESECTION lap;
};
struct TIMEATTACKRECORDS {
	TIMEATTACKRECORD carclass[3];
};
struct TIMEATTACK {
	TIMEATTACKRECORDS record[6];
};
#pragma pack(pop)