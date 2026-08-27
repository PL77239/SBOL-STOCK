#include "asm.h"

extern int resW;
extern int virtualResW;
extern int resH;
extern int fullScreen;
extern float SWFscale;
extern float SWFscaleX;
extern float SWFscaleY;
extern int skipWarning;
extern unsigned char* itemFile;
extern int itemFileSize;
extern float UIdividerX;
extern float UIdividerY;
extern float UIscaleX;
extern float UIscaleVirtualX;
extern float UIscaleY;
extern float UIscale;
extern int itemUseDialogX;
extern int itemUseDialogY;
extern char logItBuf[0x400];

extern int screenWidth;
extern int screenHeight;

extern int _EAX, _ECX, _EDX, _EBX, _EDI, _ESI;
extern float float1, float2, float3, float4, float5;
extern int int1, int2;
extern float *_a1;
extern float *_a2;
extern float *_a3;
extern char textBuf[0x1000];
extern unsigned int isClosed;

extern HWND* hwnd;

placeStringFunc placeStringGame = (placeStringFunc)(0x004FD760);
createUIElementObjectFunc createUIElementObjectOrig = (createUIElementObjectFunc)(0x004FD760);
createUIElementFunc createUIElementOrig = (createUIElementFunc)(0x00404250);
positionUIElementFunc positionUIElementOrig = (positionUIElementFunc)(0x004042F0);
interactionUIElementFunc interactionUIElementOrig = (interactionUIElementFunc)(0x004F49E0);
positionInteractionUIFunc positionInteractionUIOrig = (positionInteractionUIFunc)(0x004F48E0);

void __fastcall createUIElementObject(void* _this, void* edx, int posx, int posy)
{
	D3DSURFACE_DESC desc;
	using GetDescFunc = void(__stdcall*)(void*, int, void*);
	GetDescFunc GetDesc = *(GetDescFunc*)((**(int**)((int)_this + 0x60)) + 0x38);

	posx = (int)(((float)posx / 640.0f) * (float)resW);
	posy = (int)(((float)posy / 480.0f) * (float)resH);
	*(int*)((int)_this + 0x6C) = posx;
	*(int*)((int)_this + 0x70) = posy;

	GetDesc(*(int**)((int)_this + 0x60), 0, &desc);

	auto width = (((float)desc.Width / 640.0f) * resW);
	auto height = (((float)desc.Height / 480.0f) * resH);

	createUIElementOrig((void *)((int)_this + 0x78), edx, (float)posx, (float)posy, width, height, 0, -1, -1);
}
void __fastcall createUIElementObject_43(void* _this, void* edx, int posx, int posy)
{
	D3DSURFACE_DESC desc;
	using GetDescFunc = void(__stdcall*)(void*, int, void*);
	GetDescFunc GetDesc = *(GetDescFunc*)((**(int**)((int)_this + 0x60)) + 0x38);

	posx = (int)(((float)posx / 640.0f) * (float)virtualResW);
	posy = (int)(((float)posy / 480.0f) * (float)resH);

	posx += (int)((resW - virtualResW) / 2);

	*(int*)((int)_this + 0x6C) = posx;
	*(int*)((int)_this + 0x70) = posy;

	GetDesc(*(int**)((int)_this + 0x60), 0, &desc);

	auto width = (((float)desc.Width / 640.0f) * (float)virtualResW);
	auto height = (((float)desc.Height / 480.0f) * (float)resH);

	createUIElementOrig((void*)((int)_this + 0x78), edx, (float)posx, (float)posy, width, height, 0, -1, -1);
}
void __fastcall createUIElementObject_AutoScale(void* _this, void* edx, int posx, int posy)
{
	D3DSURFACE_DESC desc;
	using GetDescFunc = void(__stdcall*)(void*, int, void*);
	GetDescFunc GetDesc = *(GetDescFunc*)((**(int**)((int)_this + 0x60)) + 0x38);

	*(int*)((int)_this + 0x6C) = posx;
	*(int*)((int)_this + 0x70) = posy;

	GetDesc(*(int**)((int)_this + 0x60), 0, &desc);

	auto width = (((float)desc.Width / 640.0f) * (float)resW);
	auto height = (((float)desc.Height / 480.0f) * (float)resH);

	createUIElementOrig((void*)((int)_this + 0x78), edx, (float)posx, (float)posy, width, height, 0, -1, -1);
}
void __fastcall createUIElementObject_AutoScale_43(void* _this, void* edx, int posx, int posy)
{
	D3DSURFACE_DESC desc;
	using GetDescFunc = void(__stdcall*)(void*, int, void*);
	GetDescFunc GetDesc = *(GetDescFunc*)((**(int**)((int)_this + 0x60)) + 0x38);

	*(int*)((int)_this + 0x6C) = posx;
	*(int*)((int)_this + 0x70) = posy;

	GetDesc(*(int**)((int)_this + 0x60), 0, &desc);

	auto width = (((float)desc.Width / 640.0f) * (float)virtualResW);
	auto height = (((float)desc.Height / 480.0f) * (float)resH);

	createUIElementOrig((void*)((int)_this + 0x78), edx, (float)posx, (float)posy, width, height, 0, -1, -1);
}
void __fastcall createUIElementObject_Scale(void* _this, void* edx, int posx, int posy)
{
	D3DSURFACE_DESC desc;
	using GetDescFunc = void(__stdcall*)(void*, int, void*);
	GetDescFunc GetDesc = *(GetDescFunc*)((**(int**)((int)_this + 0x60)) + 0x38);

	*(int*)((int)_this + 0x6C) = posx;
	*(int*)((int)_this + 0x70) = posy;

	GetDesc(*(int**)((int)_this + 0x60), 0, &desc);

	auto width = ((float)desc.Width * UIscale);
	auto height = ((float)desc.Height * UIscale);

	createUIElementOrig((void*)((int)_this + 0x78), edx, (float)posx, (float)posy, width, height, 0, -1, -1);
}
void __fastcall createUIElementObject_Scale_Reposition(void* _this, void* edx, int posx, int posy)
{
	D3DSURFACE_DESC desc;
	using GetDescFunc = void(__stdcall*)(void*, int, void*);
	GetDescFunc GetDesc = *(GetDescFunc*)((**(int**)((int)_this + 0x60)) + 0x38);

	posx = (int)((float)posx * UIscale);
	posy = (int)((float)posy * UIscale);
	*(int*)((int)_this + 0x6C) = posx;
	*(int*)((int)_this + 0x70) = posy;

	GetDesc(*(int**)((int)_this + 0x60), 0, &desc);

	auto width = ((float)desc.Width * UIscale);
	auto height = ((float)desc.Height * UIscale);

	createUIElementOrig((void*)((int)_this + 0x78), edx, (float)posx, (float)posy, width, height, 0, -1, -1);
}
void __fastcall createUIElementObject_Scale_Reposition_BottomLeft(void* _this, void* edx, int posx, int posy)
{
	auto yOffset = -((480.0f - posy) * UIscale);
	D3DSURFACE_DESC desc;
	using GetDescFunc = void(__stdcall*)(void*, int, void*);
	GetDescFunc GetDesc = *(GetDescFunc*)((**(int**)((int)_this + 0x60)) + 0x38);

	posx = (int)((float)posx * UIscale);
	posy = resH + (int)yOffset;
	*(int*)((int)_this + 0x6C) = posx;
	*(int*)((int)_this + 0x70) = posy;

	GetDesc(*(int**)((int)_this + 0x60), 0, &desc);

	auto width = ((float)desc.Width * UIscale);
	auto height = ((float)desc.Height * UIscale);

	createUIElementOrig((void*)((int)_this + 0x78), edx, (float)posx, (float)posy, width, height, 0, -1, -1);
}
void __fastcall createUIElementObject_Scale_Reposition_BottomRight(void* _this, void* edx, int posx, int posy)
{
	auto yOffset = -((480.0f - posy) * UIscale);
	auto xOffset = -((640.0f - posx) * UIscale);
	D3DSURFACE_DESC desc;
	using GetDescFunc = void(__stdcall*)(void*, int, void*);
	GetDescFunc GetDesc = *(GetDescFunc*)((**(int**)((int)_this + 0x60)) + 0x38);

	posx = resW + (int)xOffset;
	posy = resH + (int)yOffset;
	*(int*)((int)_this + 0x6C) = posx;
	*(int*)((int)_this + 0x70) = posy;

	GetDesc(*(int**)((int)_this + 0x60), 0, &desc);

	auto width = ((float)desc.Width * UIscale);
	auto height = ((float)desc.Height * UIscale);

	createUIElementOrig((void*)((int)_this + 0x78), edx, (float)posx, (float)posy, width, height, 0, -1, -1);
}
void __fastcall createUIElement(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	posx = (posx / 640.0f) * (float)resW;
	posy = (posy / 480.0f) * (float)resH;
	width = (width / 640.0f) * (float)resW;
	height = (height / 480.0f) * (float)resH;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_43(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	posx = (posx / 640.0f) * (float)virtualResW;
	posy = (posy / 480.0f) * (float)resH;
	width = (width / 640.0f) * (float)virtualResW;
	height = (height / 480.0f) * (float)resH;
	
	posx += (float)((resW - virtualResW) / 2);

	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_Scale_Reposition(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	auto xOffset = -((640.0f - posx) * UIscale);
	auto yOffset = -((480.0f - posy) * UIscale);
	width *= UIscale;
	height *= UIscale;
	posx = ((posx / 640.0f) * (float)resW) + xOffset;
	posy = ((posy / 480.0f) * (float)resH) + yOffset;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_Scale_Reposition_TopLeft(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	posx *= UIscale;
	posy *= UIscale;
	width *= UIscale;
	height *= UIscale;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_Scale_Reposition_BottomLeft(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	auto yOffset = -((480.0f - posy) * UIscale);
	width *= UIscale;
	height *= UIscale;
	posx *= UIscale;
	posy = (float)resH + yOffset;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_Scale_Reposition_BottomRight(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	auto xOffset = -((640.0f - posx) * UIscale);
	auto yOffset = -((480.0f - posy) * UIscale);
	width *= UIscale;
	height *= UIscale;
	posx = (float)resW + xOffset;
	posy = (float)resH + yOffset;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_AutoScale(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	width = (width / 640.0f) * (float)resW;
	height = (height / 480.0f) * (float)resH;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_AutoScale_43(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	width = (width / 640.0f) * (float)virtualResW;
	height = (height / 480.0f) * (float)resH;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_AutoScale_Handle(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	width = (width / 640.0f) * (float)virtualResW;
	height = (height / 480.0f) * (float)resH;
	posx -= ((1.0f / 640.0f) * ((((float)virtualResW - 640.0f) * 44.0f) + (float)virtualResW));
	posy -= (2.0f / 480.0f) * (float)resH;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_AutoScale_TeamName(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	width = (width / 640.0f) * (float)virtualResW;
	height = (height / 480.0f) * (float)resH;
	posx -= ((1.0f / 640.0f) * ((((float)virtualResW - 640.0f) * 44.0f) + (float)virtualResW));
	posy -= (4.0f / 480.0f) * (float)resH;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_Scale(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	width *= UIscale;
	height *= UIscale;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall positionUIElement(void* _this, void* edx, float posx, float posy, int type)
{
	posx = (posx / 640.0f) * (float)resW;
	posy = (posy / 480.0f) * (float)resH;
	positionUIElementOrig(_this, edx, posx, posy, type);
}
void __fastcall positionUIElement_Reposition(void* _this, void* edx, float posx, float posy, int type)
{
	posx = posx * UIscale;
	posy = posy * UIscale; 
	positionUIElementOrig(_this, edx, posx, posy, type);
}
void __fastcall positionUIElement_Reposition_43(void* _this, void* edx, float posx, float posy, int type)
{
	posx = ((float)posx / 640.0f) * (float)virtualResW;
	posy = ((float)posy / 480.0f) * (float)resH;
	posx += ((float)resW - (float)virtualResW) / 2.0f;
	positionUIElementOrig(_this, edx, posx, posy, type);
}
void __fastcall interactionUIElement(void* _this, void* edx, int posx, int posy, int width, int height)
{
	posx = (int)(((float)posx / 640.0f) * (float)resW);
	posy = (int)(((float)posy / 480.0f) * (float)resH);
	width = (int)(((float)width / 640.0f) * (float)resW);
	height = (int)(((float)height / 480.0f) * (float)resH);

	uiInteractBoundary(_this, edx, posx, posy, width, height);
	createUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, (float)width, (float)height, 0, -1, -1);
}
void __fastcall interactionUIElement_43(void* _this, void* edx, int posx, int posy, int width, int height)
{
	posx = (int)(((float)posx / 640.0f) * (float)virtualResW);
	posy = (int)(((float)posy / 480.0f) * (float)resH);
	width = (int)(((float)width / 640.0f) * (float)virtualResW);
	height = (int)(((float)height / 480.0f) * (float)resH);
	posx += (int)(((float)resW - (float)virtualResW) / 2.0f);
	
	uiInteractBoundary(_this, edx, posx, posy, width, height);
	createUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, (float)width, (float)height, 0, -1, -1);
}
void __fastcall interactionUIElement_Scale(void* _this, void* edx, int posx, int posy, int width, int height)
{
	width = (int)((float)width * UIscale);
	height = (int)((float)height * UIscale);
	
	uiInteractBoundary(_this, edx, posx, posy, width, height);
	createUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, (float)width, (float)height, 0, -1, -1);
}
void __fastcall interactionUIElement_Scale_Reposition(void* _this, void* edx, int posx, int posy, int width, int height)
{
	auto xOffset = -((640 - posx) * UIscale);
	auto yOffset = -((480 - posy) * UIscale);
	width = (int)((float)width * UIscale);
	height = (int)((float)height * UIscale);
	posx = (int)((((float)posx / 640.0f) * (float)resW) - xOffset);
	posy = (int)((((float)posy / 480.0f) * (float)resH) - yOffset);
	
	uiInteractBoundary(_this, edx, posx, posy, width, height);
	createUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, (float)width, (float)height, 0, -1, -1);
}
void __fastcall interactionUIElement_Scale_Reposition_TopLeft(void* _this, void* edx, int posx, int posy, int width, int height)
{
	width = (int)((float)width * UIscale);
	height = (int)((float)height * UIscale);
	posx = (int)((float)posx * UIscale);
	posy = (int)((float)posy * UIscale);
	
	uiInteractBoundary(_this, edx, posx, posy, width, height);
	createUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, (float)width, (float)height, 0, -1, -1);
}
void __fastcall interactionUIElement_Scale_Reposition_BottomRight(void* _this, void* edx, int posx, int posy, int width, int height)
{
	auto xOffset = -((640 - posx) * UIscale);
	auto yOffset = -((480 - posy) * UIscale);
	width = (int)((float)width * UIscale);
	height = (int)((float)height * UIscale);
	posx = resW + (int)xOffset;
	posy = resH + (int)yOffset;
	
	uiInteractBoundary(_this, edx, posx, posy, width, height);
	createUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, (float)width, (float)height, 0, -1, -1);
}
void __fastcall moveUIElement(void* _this, void* edx, int posx, int posy)
{
	auto _virtualResW = virtualResW;
	auto _resH = resH;
	auto _resW = resW;
	auto XScale = 1.0f;
	auto YScale = 1.0f;
	if (fullScreen)
	{
		_virtualResW = (int)((float)screenHeight * (640.0f / 480.0f));
		_resH = screenHeight;
		_resW = screenWidth;
		XScale *= ((float)_resW / (float)resW);
		YScale *= ((float)_resH / (float)resH);
	}
	posx = (int)(((float)posx / 640.0f) * (float)resW);
	posy = (int)(((float)posy / 480.0f) * (float)resH);
	auto posx2 = (int)(posx * XScale);
	auto posy2 = (int)(posy * YScale);

	positionInteractionUIOrig(_this, edx, posx2, posy2);
	positionUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, 1);
}
void __fastcall moveUIElement_43(void* _this, void* edx, int posx, int posy)
{
	auto _virtualResW = virtualResW;
	auto _resH = resH;
	auto _resW = resW;
	auto XScale = 1.0f;
	auto YScale = 1.0f;
	if (fullScreen)
	{
		_virtualResW = (int)((float)screenHeight * (640.0f / 480.0f));
		_resH = screenHeight;
		_resW = screenWidth;
		XScale *= ((float)_resW / (float)resW);
		YScale *= ((float)_resH / (float)resH);
	}
	posx = (int)(((float)posx / 640.0f) * (float)virtualResW);
	posy = (int)(((float)posy / 480.0f) * (float)resH);

	posx += (int)(((float)resW - (float)virtualResW) / 2.0f);

	auto posx2 = (int)(posx * XScale);
	auto posy2 = (int)(posy * YScale);

	positionInteractionUIOrig(_this, edx, posx2, posy2);
	positionUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, 1);
}
void __fastcall moveUIElement_Position(void* _this, void* edx, int posx, int posy)
{
	auto _virtualResW = virtualResW;
	auto _resH = resH;
	auto _resW = resW;
	auto XScale = 1.0f;
	auto YScale = 1.0f;
	if (fullScreen)
	{
		_virtualResW = (int)((float)screenHeight * (640.0f / 480.0f));
		_resH = screenHeight;
		_resW = screenWidth;
		XScale *= ((float)_resW / (float)resW);
		YScale *= ((float)_resH / (float)resH);
	}
	posx = (int)((float)posx * UIscale);
	posy = (int)((float)posy * UIscale);

	auto posx2 = (int)(posx * XScale);
	auto posy2 = (int)(posy * YScale);

	positionInteractionUIOrig(_this, edx, posx2, posy2);
	positionUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, 1);
}
void __fastcall positionInteractionUI(void* _this, void* edx, int posx, int posy)
{
	int oldX = *(int*)((int)_this + 0x10);
	int oldY = *(int*)((int)_this + 0x14);
	adjustints43Center(&posx, &posy);
	positionInteractionUIOrig(_this, edx, posx, posy);
}
void __fastcall placeUIElement(void* _this, void* edx, char* uiElementLabel, float width, float height, int param_4)
{
	using placeUIElementFunc = void(__fastcall*)(void*, void*, char*, float, float, int);
	placeUIElementFunc placeUIElementOrig = (placeUIElementFunc)0x00416D00;

	float adjustedWidth = ((width / 640.0f) * (float)virtualResW);
	float adjustedHeight = ((height / 480.0f) * (float)resH);

	placeUIElementOrig(_this, edx, uiElementLabel, adjustedWidth, adjustedHeight, param_4);
}
void __fastcall uiInteractBoundary(void* _this, void* edx, int posx, int posy, int width, int height)
{
	auto _virtualResW = virtualResW;
	auto _resH = resH;
	auto _resW = resW;
	auto XScale = 1.0f;
	auto YScale = 1.0f;
	if (fullScreen)
	{
		_virtualResW = (int)((float)screenHeight * (640.0f / 480.0f));
		_resH = screenHeight;
		_resW = screenWidth;
		XScale *= ((float)_resW / (float)resW);
		YScale *= ((float)_resH / (float)resH);
	}
	width = (int)((float)width * XScale);
	height = (int)((float)height * YScale);
	posx = (int)((float)posx * XScale);
	posy = (int)((float)posy * YScale);
	HRGN hrgn;
	*(int*)((int)_this + 0x10) = posx;
	*(int*)((int)_this + 0x14) = posy;
	*(int*)((int)_this + 0x18) = width;
	*(int*)((int)_this + 0x1c) = height;
	hrgn = CreateRectRgn(posx, posy, width + posx, height + posy);
	if (*(HGDIOBJ*)((int)_this + 4) != NULL) {
		DeleteObject(*(HGDIOBJ*)((int)_this + 4));
		*(HRGN*)((int)_this + 4) = hrgn;
	}
	else
		*(HRGN*)((int)_this + 4) = hrgn;
}
void __fastcall uiSetInteractArea(void* _this, void* edx, int posx, int posy, int width, int height)
{
	using setUIElementFunc = void(__fastcall*)(void*);
	setUIElementFunc setUIElement = (setUIElementFunc)0x004FDAA0;

	int calculatedWidth = *(int*)((int)_this + 0x38);
	int calculatedHeight = *(int*)((int)_this + 0x3C);

	uiInteractBoundary((void*)((int)_this + 0xD8), edx, posx, posy, calculatedWidth, calculatedWidth);
	createUIElementObjectOrig(_this, edx, posx, posy);
	setUIElement(_this);
	return;
}
void __fastcall uiSetInteractArea_43(void* _this, void* edx, int posx, int posy, int width, int height)
{
	using setUIElementFunc = void(__fastcall*)(void*);
	setUIElementFunc setUIElement = (setUIElementFunc)0x004FDAA0;

	auto scaleValueX = [](int a) { return ((int)(((float)a / 640.0f) * ((float)resH * SCREEN_RATIO_4_3))) + ((resW - virtualResW) / 2); };
	auto scaleValueY = [](int a) { return (int)(((float)a / 480.0f) * (float)resH);	};

	int calculatedWidth = scaleValueX(*(int*)((int)_this + 0x38));
	int calculatedHeight = scaleValueY(*(int*)((int)_this + 0x3C));

	uiInteractBoundary((void*)((int)_this + 0xD8), edx, posx, posy, calculatedWidth, calculatedHeight);
	createUIElementObjectOrig(_this, edx, posx, posy);
	setUIElement(_this);
	return;
}
void __fastcall createTextbox(void* _this, void* edx, float posx, float posy)
{
	HRGN handle = *(HRGN*)((int)_this + 0xE10);

	posx = (posx / 640.0f) * (float)resW;
	posy = (posy / 480.0f) * (float)resH;

	if (handle != NULL)
		OffsetRgn(handle, (int)posx, (int)posy);
	createUIElementObject_AutoScale((void*)((int)_this + 0xB3C), edx, (int)posx, (int)posy);
}
void __fastcall createTextbox_43(void* _this, void* edx, float posx, float posy)
{
	HRGN handle = *(HRGN*)((int)_this + 0xE10);

	posx = (posx / 640.0f) * (float)virtualResW;
	posy = (posy / 480.0f) * (float)resH;

	posx += (float)((resW - virtualResW) / 2);

	if (handle != NULL)
		OffsetRgn(handle, (int)posx, (int)posy);
	createUIElementObject_AutoScale_43((void*)((int)_this + 0xB3C), edx, (int)posx, (int)posy);
}
void __fastcall createTextbox_Scale_Reposition_TopLeft(void* _this, void* edx, float posx, float posy)
{
	HRGN handle = *(HRGN*)((int)_this + 0xE10);
	posy = posy * UIscale;
	posx = posx * UIscale;

	if (handle != NULL)
		OffsetRgn(handle, (int)posx, (int)posy);

	createUIElementObject_Scale((void*)((int)_this + 0xB3C), edx, (int)posx, (int)posy);
}
void __fastcall createTextboxCarat(void* _this, void* edx, int caratpos)
{
	using UnknownFunc = void(__fastcall*)(void*);
	UnknownFunc unknownfunction = *(UnknownFunc*)0x004FB790;
	
	int positioninstring;
	int stringlength;
	void* object = (void*)((int)_this + 0x68);
	float characterwidth = (float)*(int*)((int)_this + 0xb7c);
	int posx = *(int*)((int)_this + 0xba8);
	int posy = *(int*)((int)_this + 0xbac);
	int height = *(int*)((int)_this + 0xb54);
	
	if (*(int*)0x00696178 != caratpos) {
		*(int*)0x00696178 = caratpos;
	}
	stringlength = caratpos - *(int*)((int)_this + 0xE0C);
	if (stringlength < 0) {
		*(int*)((int)_this + 0xE0C) = *(int*)((int)_this + 0xE0C) - stringlength;
		stringlength = 0;
		unknownfunction(_this);
	}
	positioninstring = *(int*)((int)_this + 0xE08);
	if (positioninstring < stringlength) {
		*(int*)((int)_this + 0xE0C) = *(int*)((int)_this + 0xE0C) + (stringlength - positioninstring);
		unknownfunction(_this);
		stringlength = positioninstring;
	}
	
	characterwidth = (characterwidth / 640.0f) * (float)virtualResW;
	auto calculatedposx = (characterwidth * (float)stringlength) + (float)posx;
	createUIElement_AutoScale_43(object, edx, calculatedposx, (float)posy, 1.0, (float)height, 0, -1, -1);
}
void __fastcall colourUIElement(void* _this, void* edx, unsigned int newcolour, unsigned int colourmask)
{
	using colourUIElementFunc = void(__fastcall*)(void*, void*, unsigned int, unsigned int);
	colourUIElementFunc colourUIElementOrig = (colourUIElementFunc)0x00404200;
	if(colourmask == 0)
		newcolour = TranslateGameColour(newcolour);
	colourUIElementOrig(_this, edx, newcolour, colourmask);
}
void __fastcall SwfMatrixConstruct(SWFUI* _this, void* edx, D3D_MATRIX* d3dMatrix, float localX, float localY, float layerZ)
{
	using matrixMultiplyFunc = void(__stdcall*)(D3D_MATRIX*, float, float, float);
	matrixMultiplyFunc matrixMultiply = (matrixMultiplyFunc)0x00556B74;
	using unknownFunc = void(__stdcall*)(D3D_MATRIX*, D3D_MATRIX*, D3D_MATRIX*);
	unknownFunc unknownfunc = (unknownFunc)0x0055623E;

	memset(d3dMatrix, 0, sizeof(D3D_MATRIX));
	D3D_MATRIX stackMatrix = { 0 };
	
	stackMatrix.W = 1.0;
	stackMatrix.ScaleZ = 1.0;
	stackMatrix.ScaleY = 1.0;
	stackMatrix.ScaleX = 1.0;

	d3dMatrix->W = 1.0;
	d3dMatrix->ScaleZ = 1.0;
	d3dMatrix->ScaleY = 1.0;
	d3dMatrix->ScaleX = 1.0;
	
	d3dMatrix->ScaleX = _this->ScaleX;
	d3dMatrix->SkewY = _this->SkewY;
	d3dMatrix->SkewX = _this->SkewX;
	d3dMatrix->ScaleY = _this->ScaleY;
	d3dMatrix->TransX = _this->TransX;
	d3dMatrix->TransY = _this->TransY;
	
	matrixMultiply(&stackMatrix, localX, localY, layerZ);
	unknownfunc(d3dMatrix, d3dMatrix, &stackMatrix);
}
void __fastcall SwfMatrixConstruct_Stretch(SWFUI* _this, void* edx, D3D_MATRIX* d3dMatrix, float localX, float localY, float layerZ)
{
	using matrixMultiplyFunc = void(__stdcall*)(D3D_MATRIX*, float, float, float);
	matrixMultiplyFunc matrixMultiply = (matrixMultiplyFunc)0x00556B74;
	using unknownFunc = void(__stdcall*)(D3D_MATRIX*, D3D_MATRIX*, D3D_MATRIX*);
	unknownFunc unknownfunc = (unknownFunc)0x0055623E;
	
	memset(d3dMatrix, 0, sizeof(D3D_MATRIX));
	D3D_MATRIX stackMatrix = { 0 };

	float scaledUiWidth = (640.0f * SWFscaleY);
	float xOffsetTwips = (((float)resW - scaledUiWidth) / 2.0f) * PIXELS_TO_TWIPS;
	float adjustedLocalX = localX * SWFscaleY;
	float adjustedLocalY = localY * SWFscaleY;

	d3dMatrix->TransX = (_this->TransX * SWFscaleY) + xOffsetTwips;
	d3dMatrix->TransY = (_this->TransY * SWFscaleY);
	
	float screenX = d3dMatrix->TransX + (localX * SWFscaleY);
	float uiLeft = xOffsetTwips;
	float uiRight = xOffsetTwips + (640.0f * PIXELS_TO_TWIPS * SWFscaleY);

	d3dMatrix->ScaleX = _this->ScaleX;
	d3dMatrix->ScaleY = _this->ScaleY;
	d3dMatrix->ScaleZ = 1.0f;
	d3dMatrix->SkewX = _this->SkewX;
	d3dMatrix->SkewY = _this->SkewY;
	d3dMatrix->W = 1.0f;

	stackMatrix.ScaleX = 1.0f;
	stackMatrix.ScaleY = 1.0f;
	stackMatrix.ScaleZ = 1.0f;
	stackMatrix.W = 1.0f;

	matrixMultiply(&stackMatrix, adjustedLocalX, adjustedLocalY, layerZ);
	unknownfunc(d3dMatrix, d3dMatrix, &stackMatrix);
}
void __fastcall SwfMatrixConstruct_Centered(SWFUI* _this, void* edx, D3D_MATRIX* d3dMatrix, float localX, float localY, float layerZ)
{
	using matrixMultiplyFunc = void(__stdcall*)(D3D_MATRIX*, float, float, float);
	matrixMultiplyFunc matrixMultiply = (matrixMultiplyFunc)0x00556B74;
	using unknownFunc = void(__stdcall*)(D3D_MATRIX*, D3D_MATRIX*, D3D_MATRIX*);
	unknownFunc unknownfunc = (unknownFunc)0x0055623E;

	memset(d3dMatrix, 0, sizeof(D3D_MATRIX));
	D3D_MATRIX stackMatrix = { 0 };

	float xOffsetTwips = (((float)resW - (640.0f * SWFscaleY)) / 2.0f) / UIscaleY;
	
	stackMatrix.W = 1.0;
	stackMatrix.ScaleZ = 1.0;
	stackMatrix.ScaleY = 1.0;
	stackMatrix.ScaleX = 1.0;

	d3dMatrix->W = 1.0;
	d3dMatrix->ScaleZ = 1.0;
	d3dMatrix->ScaleY = 1.0;
	d3dMatrix->ScaleX = 1.0;

	d3dMatrix->ScaleX = _this->ScaleX;
	d3dMatrix->SkewY = _this->SkewY;
	d3dMatrix->SkewX = _this->SkewX;
	d3dMatrix->ScaleY = _this->ScaleY;

	d3dMatrix->TransX = _this->TransX + xOffsetTwips;
	d3dMatrix->TransY = _this->TransY;

	matrixMultiply(&stackMatrix, localX, localY, layerZ);
	unknownfunc(d3dMatrix, d3dMatrix, &stackMatrix);
}
void __fastcall SwfDrawPrimitive(void* _this, void* edx, LPDIRECT3DDEVICE8 pDevice, D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
	D3DVIEWPORT8 originalViewport;
	bool viewportModified = false;
	if (SUCCEEDED(pDevice->GetViewport(&originalViewport)))
	{
		D3DVIEWPORT8 uiViewport = originalViewport;
		uiViewport.X = (DWORD)((resW - virtualResW) / 2.0f);
		uiViewport.Width = (DWORD)virtualResW;

		pDevice->SetViewport(&uiViewport);
		viewportModified = true;
	}

	pDevice->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);

	if (viewportModified)
		pDevice->SetViewport(&originalViewport);
}
void __fastcall SwfDrawPrimitive_Stretch(void* _this, void* edx, LPDIRECT3DDEVICE8 pDevice, D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
	if (PrimitiveCount == 0)
	{
		SwfDrawPrimitive(_this, edx, pDevice, PrimitiveType, StartVertex, PrimitiveCount);
		return;
	}
	LPDIRECT3DVERTEXBUFFER8 pStreamData = nullptr;
	UINT stride = 0;
	float offsetX = ((float)resW - (640.0f * SWFscaleY)) / 2.0f;

	if (SUCCEEDED(pDevice->GetStreamSource(0, &pStreamData, &stride)))
	{
		if (stride == sizeof(TransformedVertex) && pStreamData != nullptr)
		{
			BYTE* pVertices = nullptr;
			if (SUCCEEDED(pStreamData->Lock(0, 0, &pVertices, D3DLOCK_NOOVERWRITE)))
			{
				UINT vertexCount = PrimitiveCount * 3; // Assuming triangles; adjust based on PrimitiveType
				if (PrimitiveType == D3DPT_TRIANGLESTRIP || PrimitiveType == D3DPT_TRIANGLEFAN)
					vertexCount = PrimitiveCount + 2;
				
				TransformedVertex* vertices = (TransformedVertex*)pVertices;
				for (UINT i = StartVertex; i < (StartVertex + vertexCount); ++i)
				{
					vertices[i].x = (vertices[i].x * SWFscaleX) + offsetX;
					vertices[i].y *= SWFscaleY;
				}
				pStreamData->Unlock();
			}
		}
		pStreamData->Release();
	}

	SwfDrawPrimitive(_this, edx, pDevice, PrimitiveType, StartVertex, PrimitiveCount);
}
void __fastcall SwfGetMouseState(void* _this, void* edx, int* pOutX, int* pOutY, int* pOutClickState)
{
	auto _virtualResW = virtualResW;
	auto _resH = resH;
	auto _resW = resW;
	auto _UIscaleX = UIscale;
	auto _UIscaleY = UIscale;
	auto _SWFscale = SWFscale;
	if (fullScreen)
	{
		_UIscaleX = (_UIscaleX / resW) * _resW;
		_UIscaleY = (_UIscaleY / resH) * _resH;
		_virtualResW = (int)((float)screenHeight * (640.0f / 480.0f));
		_resH = screenHeight;
		_resW = screenWidth;
		_SWFscale = (float)_resH / 480.0f;
	}
	using GetMouseStateFunc = void(__fastcall*)(void*, void*, int*, int*, int*);
	GetMouseStateFunc GetMouseStateOrig = (GetMouseStateFunc)0x005075D0;
	GetMouseStateOrig(_this, edx, pOutX, pOutY, pOutClickState);

	if (pOutX != nullptr && pOutY != nullptr)
	{
		float leftWall = (float)(_resW - _virtualResW) / 2.0f;
		float shiftedX = (float)(*pOutX) - leftWall;
		*pOutX = (int)(shiftedX / _SWFscale);
		*pOutY = (int)((float)(*pOutY) / _SWFscale);
	}
}
unsigned int __fastcall ButtonInteract(void* _this, void* edx, int MouseX, int MouseY, int Width, int Height)
{
	int relativeMouseX;
	int relativeMouseY;

	if (Width == -1)
		Width = *(int*)(*(int*)(*(int*)((int)_this + 0x200C) + 100) + 0x08);
	if (Height == -1)
		Height = *(int*)(*(int*)(*(int*)((int)_this + 0x200C) + 100) + 0x0C);

	relativeMouseX = MouseX - *(short*)_this;
	relativeMouseY = MouseY - *(short*)((int)_this + 2);

	if ((((-1 < relativeMouseX) && (relativeMouseX < Width)) && (-1 < relativeMouseY)) && (relativeMouseY < Height))
	{
		return (unsigned int)((*(byte*)((int)_this + (relativeMouseX >> 3) + 4 + ((Width + 7) >> 3) * relativeMouseY) & (byte)(1 << ((byte)relativeMouseX & 7))) != 0);
	}
	return (unsigned int)_this & 0xFFFFFF00;
}
bool __fastcall ButtonInteract43(void* ButtonPtr, void* edx, int32_t MouseX, int32_t MouseY, int32_t Width, int32_t Height)
{
	float scaleX = (float)virtualResW / 640.0f;
	float scaleY = (float)resH / 480.0f;
	uint8_t* btn = static_cast<uint8_t*>(ButtonPtr);
	if (Width == -1 || Height == -1)
	{
		uint8_t* level1 = *reinterpret_cast<uint8_t**>(btn + 0x200C);
		uint8_t* imageData = *reinterpret_cast<uint8_t**>(level1 + 100);
		if (Width == -1)
			Width = *reinterpret_cast<int32_t*>(imageData + 8);   // Width
		if (Height == -1)
			Height = *reinterpret_cast<int32_t*>(imageData + 0x0C); // Height
	}
	if (fullScreen)
	{
		MouseX = (int32_t)(((float)MouseX / (float)screenWidth) * (float)resW);
		MouseY = (int32_t)(((float)MouseY / (float)screenHeight) * (float)resH);
	}
	int16_t btnX = *reinterpret_cast<int16_t*>(btn + 0);
	int16_t btnY = *reinterpret_cast<int16_t*>(btn + 2);
	int32_t highResLocalX = MouseX - btnX;
	int32_t highResLocalY = MouseY - btnY;
	int32_t relativeMouseX = static_cast<int32_t>((float)highResLocalX / scaleX);
	int32_t relativeMouseY = static_cast<int32_t>((float)highResLocalY / scaleY);
	if (relativeMouseX >= 0 && relativeMouseX < Width && relativeMouseY >= 0 && relativeMouseY < Height)
	{
		int32_t bytesPerRow = (Width + 7) >> 3;
		uint8_t* hitMask = btn + 4;
		int32_t byteOffset = (relativeMouseX >> 3) + (bytesPerRow * relativeMouseY);
		uint8_t targetByte = hitMask[byteOffset];
		uint8_t bitMask = 1 << (relativeMouseX & 7);
		return (targetByte & bitMask) != 0;
	}
	return false;
}
bool __fastcall ButtonInteract43_Object(void* ButtonPtr, void* edx, int16_t MouseX, int16_t MouseY)
{
	float scaleX = (float)virtualResW / 640.0f;
	float scaleY = (float)resH / 480.0f;

	// The exact formula that fixed the standard buttons
	if (fullScreen)
	{
		MouseX = (int16_t)(((float)MouseX / (float)screenWidth) * (float)resW);
		MouseY = (int16_t)(((float)MouseY / (float)screenHeight) * (float)resH);
	}

	uint8_t* btn = static_cast<uint8_t*>(ButtonPtr);
	int16_t btnX = *reinterpret_cast<int16_t*>(btn + 0x5C);
	int16_t btnY = *reinterpret_cast<int16_t*>(btn + 0x5E);

	int16_t highResLocalX = MouseX - btnX;
	int16_t highResLocalY = MouseY - btnY;

	int16_t localX = static_cast<int16_t>((float)highResLocalX / scaleX);
	int16_t localY = static_cast<int16_t>((float)highResLocalY / scaleY);

	uint8_t* imageInfo = *reinterpret_cast<uint8_t**>(btn + 0x10);
	uint8_t* imageData = *reinterpret_cast<uint8_t**>(imageInfo + 100);
	int32_t imgWidth = *reinterpret_cast<int32_t*>(imageData + 8);
	int32_t imgHeight = *reinterpret_cast<int32_t*>(imageData + 0x0C);

	if (localX >= 0 && localX < imgWidth && localY >= 0 && localY < imgHeight)
	{
		int32_t bytesPerRow = (imgWidth + 7) >> 3;
		uint8_t* hitMask = btn + 0x60;
		int32_t byteOffset = (localX >> 3) + (localY * bytesPerRow);
		uint8_t targetByte = hitMask[byteOffset];
		uint8_t bitMask = 1 << (localX & 7);
		return (targetByte & bitMask) != 0;
	}
	return false;
}
void adjustfloats(float* x, float* y)
{
	if (x)
		*x = (*x / 640.0f) * resW;
	if (y)
		*y = (*y / 480.0f) * resH;
}
void adjustfloats43(float* x, float* y)
{
	if (x)
		*x = (*x / 640.0f) * (resH * SCREEN_RATIO_4_3);
	if (y)
		*y = (*y / 480.0f) * resH;
}
void adjustfloatsN(float* x, float* y)
{
	if (x)
		*x *= UIscale;
	if (y)
		*y *= UIscale;
}
void adjustfloatsNBR(float* x, float* y)
{
	if (x)
	{
		auto xOffset = -((640.0f - *x) * UIscale);
		*x = resW + xOffset;
	}
	if (y)
	{
		auto yOffset = -((480.0f - *y) * UIscale);
		*y = resH + yOffset;
	}
}
void adjustints(int* x, int* y)
{
	if (x)
		*x = (int)(((float)*x / 640.0f) * (float)resW);
	if (y)
		*y = (int)(((float)*y / 480.0f) * (float)resH);
}
void adjustints43(int* x, int* y)
{
	if (x)
		*x = (int)(((float)*x / 640.0f) * ((float)resH * SCREEN_RATIO_4_3));
	if (y)
		*y = (int)(((float)*y / 480.0f) * (float)resH);
}
void adjustints43Center(int* x, int* y)
{
	if (x)
	{
		*x = (int)(((float)*x / 640.0f) * ((float)resH * SCREEN_RATIO_4_3));
		*x += (resW - virtualResW) / 2;
	}
	if (y)
		*y = (int)(((float)*y / 480.0f) * (float)resH);
}
void adjustintsN(int* x, int* y)
{
	if (x)
		*x = (int)((float)*x * UIscale);
	if (y)
		*y = (int)((float)*y * UIscale);
}
void adjustintsNTC(int* x, int* y)
{
	if (x)
		*x = (int)((float)*x * UIscale);
	if (y)
		*y = (int)((float)*y * UIscale);
}
void adjustbytesN(int* x, int* y)
{
	if (x)
		*(byte*)x = (byte)((float)*(byte*)x * UIscale);
	if (y)
		*(byte*)y = (byte)((float)*(byte*)y * UIscale);
}
void __fastcall addressbookArea(void* _this, void* edx, int posx, int posy)
{
	using scrollbarFunc = void(__fastcall*)(void*, void*, int, int);
	using textboxFunc = void(__fastcall*)(void*, void*, float, float);
	using setInteractAreaFunc = void(__fastcall*)(void*, void*, int, int, int, int);
	scrollbarFunc scrollbar = (scrollbarFunc)0x004FCB40;
	textboxFunc textbox = (textboxFunc)0x004FBB10;
	setInteractAreaFunc setInteractArea = (setInteractAreaFunc)0x004FDA00;

	int* interactObjectPosx = (int*)((int)_this + 0xAD94);
	int* interactObjectPosy = (int*)((int)_this + 0xAD98);
	int* interactObjectWidth = (int*)((int)_this + 0xAD9C);
	int* interactObjectHeight = (int*)((int)_this + 0xADA0);
	void* interactObject = (void*)((int)_this + 0xADA4);
	void* scrollbarObject = (void*)((int)_this + 0xA75C);
	void* textboxObject = (void*)((int)_this + 0x97C4);
	void* interactAreaObject = (void*)((int)_this + 0xA5EC);

	int* interactAreaWidth = (int*)((int)interactAreaObject + 0x38);
	int* interactAreaHeight = (int*)((int)interactAreaObject + 0x3C);

	auto scaleValueX = [](int a) { return ((int)(((float)a / 640.0f) * ((float)resH * SCREEN_RATIO_4_3))) + ((resW - virtualResW) / 2); };
	auto scaleValueY = [](int a) { return (int)(((float)a / 480.0f) * (float)resH);	};
	auto scaleValueFX = [](float a) { return (((a / 640.0f) * ((float)resH * SCREEN_RATIO_4_3))) + (float)((resW - virtualResW) / 2); };
	auto scaleValueFY = [](float a) { return ((a / 480.0f) * (float)resH); };

	*interactObjectPosx = posx + 479;
	*interactObjectPosy = posy + 25;
	uiInteractBoundary(interactObject, edx, scaleValueX(482), scaleValueY(25), *interactObjectWidth, *interactObjectHeight);
	scrollbar(scrollbarObject, edx, 623, 25); // Scroll bar - Scaled using the other functions so will leave it default.
	textbox(textboxObject, edx, scaleValueFX(487.0f), scaleValueFY(3.0f));
	uiSetInteractArea_43(interactAreaObject, edx, scaleValueX(487), scaleValueY(3), 128, 16);
}
void __fastcall addAddressbookEntry(void* object, void* edx)
{
	int width;
	int posx;
	int posy;
	int height;

	posy = (*(int*)((int)object + 0x608) - *(int*)((int)object + 0x610)) -  *(int*)((int)object + 0x604);
	if (posy < 1) {
		posy = 0;
	}
	else {
		posy = ((*(int*)((int)object + 0x614) - *(int*)((int)object + 0x620)) * *(int*)((int)object + 0x60c)) / posy;
	}
	height = *(int*)((int)object + 0x614) - *(int*)((int)object + 0x620);
	if (height < posy) {
		posy = height;
	}

	posx = *(int*)((int)object + 0x618);
	posy = *(int*)((int)object + 0x61C) + posy;
	width = *(int*)(*(int*)((int)object + 0x55C) + 0x08);
	height = *(int*)(*(int*)((int)object + 0x55C) + 0x0C);
	
	interactionUIElement_43((void*)((int)object + 0x3d0), edx, posx, posy, width, height);
	createUIElement_43((void*)((int)object + 0x494), edx, (float)posx, (float)posy, (float)width, (float)height, 0, -1, -1);
	createUIElement_43((void*)((int)object + 0x4f8), edx, (float)posx, (float)posy, (float)width, (float)height, 0, -1, -1);

	adjustints43Center(&posx, &posy);
	adjustints43(&width, &height);

	auto pPosx = (int*)((int)object + 0x3C0);
	auto pPosy = (int*)((int)object + 0x3C4);
	auto pWidth = (int*)((int)object + 0x3C8);
	auto pHeight = (int*)((int)object + 0x3CC);

	*pPosx = posx;
	*pPosy = posy;
	*pWidth = width;
	*pHeight = height;
}
void __cdecl SetViewport(D3DVIEWPORT8* pViewport)
{
	D3DVIEWPORT8* NavimapViewport = (D3DVIEWPORT8*)0x006E1D20;
	NavimapViewport->X = pViewport->X;
	NavimapViewport->Y = pViewport->Y;
	NavimapViewport->Width = pViewport->Width;
	NavimapViewport->Height = pViewport->Height;
	NavimapViewport->MinZ = pViewport->MinZ;
	NavimapViewport->MaxZ = pViewport->MaxZ;
	dx->SetViewport(pViewport);
}
void __cdecl SetViewport_Scale_Reposition_BottomLeft(D3DVIEWPORT8* pViewport)
{
	D3DVIEWPORT8* NavimapViewport = (D3DVIEWPORT8*)0x006E1D20;
	auto yOffset = -(int)((480.0f - (float)pViewport->Y) * UIscale);
	pViewport->Width = (int)((float)pViewport->Width * UIscale);
	pViewport->Height = (int)((float)pViewport->Height * UIscale);
	pViewport->X = (int)((float)pViewport->X * UIscale);
	pViewport->Y = resH + yOffset;
	NavimapViewport->X = pViewport->X;
	NavimapViewport->Y = pViewport->Y;
	NavimapViewport->Width = pViewport->Width;
	NavimapViewport->Height = pViewport->Height;
	NavimapViewport->MinZ = pViewport->MinZ;
	NavimapViewport->MaxZ = pViewport->MaxZ;
	dx->SetViewport(pViewport);
}
void __cdecl SetViewport_Scale_Centered(D3DVIEWPORT8* pViewport)
{
	auto tempviewport = *pViewport;
	D3DVIEWPORT8* g_Viewport = (D3DVIEWPORT8*)0x006E1D20;
	if (tempviewport.Width == 640 && tempviewport.Height == 480)
	{
		tempviewport.Width = resW;
		tempviewport.Height = resH;
	}
	else if (tempviewport.Width == resW && tempviewport.Height == resH) {} // Fullscreen leave alone
	else if (tempviewport.X == 192 && tempviewport.Y == 82 && tempviewport.Width == 256 && tempviewport.Height == 64)
	{	// Mirror
		auto width = tempviewport.Width;
		auto height = tempviewport.Height;
		tempviewport.Width = (int)(((float)tempviewport.Width / 640.0f) * (float)virtualResW);
		tempviewport.Height = (int)(((float)tempviewport.Height / 480.0f) * (float)resH);
		tempviewport.X = (resW - tempviewport.Width) / 2;
		tempviewport.Y = (int)(((float)tempviewport.Y / 480.0f) * (float)resH);
	}
	else
	{
		auto width = tempviewport.Width;
		tempviewport.Width = (int)((float)tempviewport.Width * 0.75f); // 4:3
		tempviewport.X += (width - tempviewport.Width) / 2;
	}
	g_Viewport->X = tempviewport.X;
	g_Viewport->Y = tempviewport.Y;
	g_Viewport->Width = tempviewport.Width;
	g_Viewport->Height = tempviewport.Height;
	g_Viewport->MinZ = tempviewport.MinZ;
	g_Viewport->MaxZ = tempviewport.MaxZ;
	dx->SetViewport(&tempviewport);
}
void __cdecl SetViewport_Scale_Centered1(D3DVIEWPORT8* pViewport)
{
	SetViewport_Scale_Centered(pViewport);
}
void __fastcall gameCreateRectRgn(void* _this, void* edx, int posx, int posy, int width, int height)
{
	HRGN hgrn;

	if (*(HGDIOBJ*)((int)_this + 0xe10) != (HGDIOBJ)0x0) {
		DeleteObject(*(HGDIOBJ*)((int)_this + 0xe10));
	}
	hgrn = CreateRectRgn(posx, posy, width + posx, height + posy);
	*(HRGN*)((int)_this + 0xe10) = hgrn;
}
void __fastcall setRect1(void* _this, void* edx, int param_1, int param_2, int param_3)
{
	using SetRectFunc = void(__fastcall*)(void*, void*, int, int, int);
	SetRectFunc SetRectFunc1 = (SetRectFunc)0x004FE090;
	int* left = (int*)((int)_this + 0x58);
	int* top = (int*)((int)_this + 0x5C);
	int* right = (int*)((int)_this + 0x14);
	int* bottom = (int*)((int)_this + 0x44);
	SetRectFunc1(_this, edx, param_1, param_2, param_3);
}
void __fastcall setRect2(void* _this, void* edx, int param_1, int param_2, int param_3)
{
	using SetRectFunc = void(__fastcall*)(void*, void*, int, int, int);
	SetRectFunc SetRectFunc2 = (SetRectFunc)0x0051DAD0;
	int* left = (int*)((int)_this + 0x58);
	int* top = (int*)((int)_this + 0x5C);
	int* right = (int*)((int)_this + 0x14);
	int* bottom = (int*)((int)_this + 0x44);
	SetRectFunc2(_this, edx, param_1, param_2, param_3);
}
void __declspec(naked) positionUIElement2()
{
	__asm {
		mov eax, [esp + 08h];
		push esi;
		mov esi, ecx;
		push eax;
		mov ecx, [esp + 0Ch];
		push ecx;
		mov ecx, esi;
		call_imm(004F48E0h);
		SaveECX();
		mov eax, dword ptr[esp + 0Ch];
		mov int1, eax;
		mov eax, dword ptr[esp + 08h];
		mov int2, eax;
	}

	adjustInts(&int2, &int1);

	__asm {
		RestoreECX();
		mov eax, int2;
		mov dword ptr[esp + 08h], eax;
		mov eax, int1;
		mov dword ptr[esp + 0Ch], eax;
		fild dword ptr[esp + 0Ch];
		push 01h;
		push ecx;
		fstp dword ptr[esp];
		fild dword ptr[esp + 10h];
		push ecx;
		lea ecx, [esi + 24h];
		fstp dword ptr[esp];
		call_imm(004042F0h);
		pop esi;
		ret 0008h;
	}
}
void __declspec(naked) positionUIElement3()
{
	__asm {
		SaveECX();
		mov eax, dword ptr[esp + 04h];
		mov float1, eax;
		mov eax, dword ptr[esp + 08h];
		mov float2, eax;
	}

	adjustFloats(&float1, &float2);

	__asm {
		mov eax, float1;
		mov dword ptr ds : [esp + 04h], eax;
		mov eax, float2;
		mov dword ptr ds : [esp + 08h], eax;
		RestoreECX();
		fld dword ptr ds : [esp + 04h];
		fsub dword ptr ds : [005B542Ch];
		fld dword ptr ds : [esp + 08h];
		fsub dword ptr ds : [005B542Ch];
		mov eax, ecx;
		mov ecx, dword ptr ds : [esp + 0Ch];
		cmp ecx, 04h;
		fstp dword ptr ds : [esp + 08h];
		je _00404326;
		lea ecx, dword ptr ds : [ecx + ecx * 2];
		fsub dword ptr ds : [eax + ecx * 8];
		fld dword ptr ds : [esp + 08h];
		fsub dword ptr ds : [eax + ecx * 8 + 04h];
		lea ecx, dword ptr ds : [eax + ecx * 8];
		jmp _00404343;
	_00404326:
		fld dword ptr ds : [eax + 48h];
		fadd dword ptr ds : [eax];
		fmul dword ptr ds : [005B542Ch];
		fsubp st(1), st(0);
		fld dword ptr ds : [eax + 4Ch];
		fadd dword ptr ds : [eax + 04h];
		fmul dword ptr ds : [005B542Ch];
		fsubr dword ptr ds : [esp + 08h];
	_00404343:
		mov ecx, 00000004;
	_00404348:
		fld st(1);
		fadd dword ptr ds : [eax];
		add eax, 18h;
		dec ecx;
		fstp dword ptr ds : [eax - 18h];
		fld st(0);
		fadd dword ptr ds : [eax - 14h];
		fstp dword ptr ds : [eax - 14h];
		jne _00404348;
		fstp st(0);
		fstp st(0);
		ret 000Ch;
	}
}
void __declspec(naked) adjustUI()
{
	__asm {
		push esi;
		push edi;
		mov edi, [esp + 0Ch];
		mov esi, ecx;
		fld dword ptr[edi];
		fmul dword ptr[edi + 10h];
		fld dword ptr[edi + 04h];
		fmul dword ptr[edi + 0Ch];
		fsubp st(1), st(0);
		fcom dword ptr ds : [005B53ECh];
		fnstsw ax;
		test ah, 40h;
		je _00512C4E;
		fstp st(0);
		call_imm(00512800h);
		fld dword ptr[edi + 08h];
		fchs;
		fstp dword ptr[esi + 08h];
		fld dword ptr[edi + 14h];
		mov _a1, edi;
		add _a1, 08h;
		mov _a2, edi;
		add _a2, 14h;
		SaveEAX();
		SaveECX();
		SaveEDX();
	}

	//sprintf(&textBuf[0], "%.2f, %.2f\n", *_a1, *_a2);
	//OutputDebugStringA(&textBuf[0]);

	__asm {
		RestoreEAX();
		RestoreECX();
		RestoreEDX();
		fchs;
		fstp dword ptr[esi + 14h];
		pop edi;
		pop esi;
		ret 0004h;
	_00512C4E:
		fdivr dword ptr ds : [005B53E8h];
		fld st(0);
		fmul dword ptr[edi + 10h];
		fstp dword ptr[esi];
		fld st(0);
		fmul dword ptr[edi];
		fstp dword ptr[esi + 10h];
		fld st(0);
		fmul dword ptr[edi + 04h];
		fchs;
		fstp dword ptr[esi + 04h];
		fmul dword ptr[edi + 0Ch];
		fchs;
		fstp dword ptr[esi + 0Ch];
		fld dword ptr[esi + 04h];
		fmul dword ptr[edi + 14h];
		fld dword ptr[edi + 08h];
		fmul dword ptr[esi];
		faddp st(1), st(0);
		fchs;
		fstp dword ptr[esi + 08h];
		fld dword ptr[esi + 10h];
		fmul dword ptr[edi + 14h];
		fld dword ptr[edi + 08h];
		fmul dword ptr[esi + 0Ch];
		pop edi;
		faddp  st(1), st(0);
		fchs;
		fstp dword ptr[esi + 14h];
		mov _a1, esi;
		add _a1, 08h;
		mov _a2, esi;
		add _a2, 14h;
		mov _a3, esi;
		add _a3, 0Ch;
		SaveEAX();
		SaveECX();
		SaveEDX();
	}

	//sprintf(&textBuf[0], "%.2f, %.2f, %.2f\n", *_a1, *_a2, *_a3);
	//OutputDebugStringA(&textBuf[0]);

	__asm {
		RestoreEAX();
		RestoreECX();
		RestoreEDX();
		pop esi;
		ret 0004h;
	}
}
void __declspec(naked) scaleUIElement()
{
	SaveECX();
	SaveEDX();
	__asm {
		mov eax, dword ptr ds : [esp + 0Ch];
		mov int1, eax;
		mov eax, dword ptr ds : [esp + 10h];
		mov int2, eax;
		mov eax, dword ptr ds : [ecx + 000000C4h];
		mov float1, eax;
		mov eax, dword ptr ds : [ecx + 000000CCh];
		mov float2, eax;
	}
	adjustInts(&int2, &int1);
	adjustFloats(&float2, &float1);
	RestoreECX();
	RestoreEDX();
	__asm {
		mov eax, int1;
		mov dword ptr ds : [esp + 0Ch], eax;
		mov eax, int2;
		mov dword ptr ds : [esp + 10h], eax;
		mov eax, float1;
		mov dword ptr ds : [ecx + 000000C4h], eax;
		mov eax, float2;
		mov dword ptr ds : [ecx + 000000CCh], eax;
		mov eax, dword ptr ds : [esp + 04h];
		mov edx, dword ptr ds : [esp + 08h];
		fild dword ptr[esp + 0Ch]; // X
		mov[ecx + 000000ACh], eax;
		mov eax, [esp + 0Ch]; // X
		mov[ecx + 000000B0h], edx;
		mov edx, [esp + 10h];	// Y
		mov[ecx + 000000B4h], eax;
		mov[ecx + 000000B8h], edx;
		fld dword ptr[ecx + 000000C4h]; // X * 20
		fsub dword ptr[ecx + 000000C0h];
		fmul dword ptr ds : [00605590h];
		fdivp st(1), st(0);
		fild dword ptr[esp + 10h]; // Y
		fld dword ptr[ecx + 000000CCh]; // Y * 20
		fsub dword ptr[ecx + 000000C8h];
		fmul dword ptr ds : [00605590h];
		fdivp st(1), st(0);
		fstp dword ptr[esp + 0Ch]; // X
		fcom dword ptr[esp + 0Ch];
		fnstsw ax;
		test ah, 01h;
		je _005084E6;
		mov eax, [esp + 0Ch];
		fstp st(0);
		mov[ecx + 000000BCh], eax;
		ret 0010h;
	_005084E6:
		fstp dword ptr[ecx + 000000BCh];
		ret 0010h;
	}
}
void __declspec(naked) exitFix()
{
	__asm
	{
		mov eax, dword ptr ds : [ebp - 3Ch];
		cmp eax, WM_CLOSE;
		je _sbolexit;
		cmp eax, WM_QUIT;
		je _sbolexit;
		cmp eax, WM_DESTROY;
		je _sbolexit;
		cmp eax, WM_NCLBUTTONDOWN;
		je _countClose;
		mov isClosed, 0;
	_loop:
		jmp_imm(0041C1CDh);
	_sbolexit:
		jmp_imm(0041C214h);
	_countClose:
		mov eax, isClosed;
		inc eax;
		mov isClosed, eax;
		cmp eax, 30;
		je _sbolexit;
		jmp _loop;
	}
}
void __declspec(naked) getTireBrakePrice()
{
	__asm
	{
		movsx eax, byte ptr ds : [esi + 6];
		push eax;
		mov ecx, edi;
		call getPFileTireBrakePriceMultipler;
		movsx ecx, bl;
		push ecx;
		mov ecx, edi;
		mov ebp, eax;
		call getPFileTireBrakePrice;
		movsx edx, byte ptr ds : [esi + 6];
		xor ecx, ecx;
		pop edi;
		mov cx, word ptr ds : [eax + edx * 2];
		pop esi;
		mov eax, ecx;
		imul eax, ebp;
		pop ebp;
		pop ebx;
		ret;
	}
}
void __declspec(naked) getPFileTireBrakePriceMultipler()
{
	__asm
	{	// Default multiplier for tires and brakes is 0 in file so hardcoding return of 1. Can edit P.DAT in future
		//mov eax, dword ptr ds : [ecx + 04h];
		//lea ecx, dword ptr ds : [eax + eax * 4];
		//lea ecx, dword ptr ds : [eax + ecx * 8];
		//lea edx, dword ptr ds : [ecx + ecx * 4];
		//mov ecx, dword ptr ds : [esp + 04];
		//lea eax, dword ptr ds : [eax + edx * 4];
		//lea edx, dword ptr ds : [ecx + eax * 2];
		//mov ecx, dword ptr ds : [006FB758h];
		//mov ax, word ptr ds : [ecx + edx * 2 + 00000C70h];
		mov eax, 00000001h;
		ret 0004h;
	}
}
void __declspec(naked) getPFileTireBrakePrice()
{
	__asm
	{
		mov eax, dword ptr ds : [ecx + 04];
		lea ecx, dword ptr ds : [eax + eax * 4];
		lea ecx, dword ptr ds : [eax + ecx * 8];
		lea edx, dword ptr ds : [ecx + ecx * 4];
		lea ecx, dword ptr ds : [eax + edx * 4];
		mov eax, dword ptr ds : [esp + 04]; // Selection
		mov edx, 0Ah; // TireBrake Entry Size
		imul eax, edx;
		mov edx, eax;
		mov eax, dword ptr ds : [006FB758h];
		lea edx, dword ptr ds : [eax + edx];
		lea eax, dword ptr ds : [edx + ecx * 4 + 000000C70h]; // TireBrake Offset
		ret 0004;
	}
}
void __declspec(naked) setTexturePositions()
{
	SaveECX();
	__asm {
		mov eax, [esp + 04h];
		mov int1, eax;
		mov eax, [esp + 08h];
		mov int2, eax;
	}
	int1 = (resW / 2) - (320 - (int1));
	int2 = (resH / 2) - (240 - (int2));
	RestoreECX();
	__asm {
		mov eax, int1;
		push esi;
		mov esi, ecx;
		mov ecx, int2;
		mov dword ptr ds : [esi + 18h], ecx;
		mov dword ptr ds : [esi + 14h], eax;
		add ecx, 00000090h;
		add eax, 0Ch;
		push ecx;
		mov ecx, dword ptr ds : [esi + 00015CB4h];
		push eax;
		call_imm(004FD760h);
		mov eax, dword ptr ds : [esi + 18h];
		mov ecx, dword ptr ds : [esi + 14h];
		add eax, 000000A0h;
		add ecx, 0Ch;
		push eax;
		push ecx;
		mov ecx, dword ptr ds : [esi + 00015CB8h];
		call_imm(004FD760h);
		push 000000F8h;
		push 38h;
		lea ecx, dword ptr ds : [esi + 00018760h];
		call_imm(0045B600h);
		pop esi;
		ret 0008h;
	}
}
void __declspec(naked) setItemUsePosition()
{
	__asm {
		mov eax, itemUseDialogY;
		push eax;
		mov eax, itemUseDialogX;
		push eax;
		mov ecx, ebp;
		call_imm(0045D6B0h);
		ret;
	}
}
void __declspec(naked) drawString()
{
	__asm {
		sub esp, 28h;
		mov eax, dword ptr ds : [esp + 2Ch];
		push esi;
		mov esi, ecx;
		mov ecx, dword ptr ds : [esp + 34h];
		mov dword ptr ds : [esi + 6Ch], eax;
		mov eax, dword ptr ds : [esi + 60h];
		mov dword ptr ds : [esi + 70h], ecx;
		lea ecx, dword ptr ds : [esp + 0Ch];
		mov edx, dword ptr ds : [eax];
		push ecx;
		push 00h;
		push eax;
		call dword ptr[edx + 38h];
		mov edx, dword ptr ds : [esp + 28h];
		mov eax, dword ptr ds : [esp + 24h];
		push 0FFh;
		mov dword ptr ds : [esp + 08h], edx;
		mov dword ptr ds : [esp + 0Ch], 00000000;
		push 0FFh;
		fild qword ptr[esp + 0Ch];
		push 00h;
		push ecx;
		mov dword ptr ds : [esp + 14h], eax;
		mov dword ptr ds : [esp + 18h], 00000000;
		fstp dword ptr[esp];
		fild qword ptr[esp + 14h];
		push ecx;
		fstp dword ptr[esp];
		fild dword ptr[esi + 70h];
		push ecx;
		fstp dword ptr[esp];
		fild dword ptr[esi + 6Ch];
		push ecx;
		lea ecx, dword ptr ds : [esi + 78h];
		fstp dword ptr[esp];
		call createUIElement;
		pop esi;
		add esp, 28h;
		ret 0008h;
	}
}
void __declspec(naked) directxScene()
{
	_asm {
		mov edx, dword ptr ds : [00630E08h]; // Clear colour
		mov eax, dword ptr ds : [006EAAE0h]; // Direct 3D Device
		push 00h;
		push 3F800000h;
		mov ecx, dword ptr ds : [eax];
		push edx;
		push 03h;
		push 00h;
		push 00h;
		push eax;
		call dword ptr ds : [ecx + 00000090h];
		mov eax, dword ptr ds : [006EAAE0h];
		push eax;
		mov ecx, dword ptr ds : [eax];
		call dword ptr ds : [ecx + 00000088h];
		test eax, eax;
		jnge _cleanup;
		SaveECX();
	}
	directxCustom();
	//call directxCustom;
	__asm {
		RestoreECX();
		mov ecx, dword ptr ds : [006EBA30h];
		call_imm(00416A90h);
		mov ecx, dword ptr ds : [006EBBF4h];
		call_imm(004E8F30h);
		mov ecx, dword ptr ds : [006EBBF0h];
		call_imm(004E1910h);
		call_imm(00404FD0h);
		mov eax, dword ptr ds : [006EAAE0h];
		push eax;
		mov edx, dword ptr ds : [eax];
		call dword ptr[edx + 0000008Ch];
	_cleanup:
		call_imm(00405020h);
		mov ecx, dword ptr ds : [esp + 04h];
		call_imm(0041BA10h);
		push 00h;
		push 02h;
		push 006F7FD0h;
		call_imm(0051FA90h);
		add esp, 0Ch;
		ret;
	}
}
void __declspec(naked) adjustXAxis()
{
	__asm {
		mov eax, dword ptr ds : [eax + ecx + 00000248h];
		mov int1, eax;
	}
	adjustXAxisValue(&int1);
	__asm {
		mov eax, int1;
		ret;
	}
}
void __declspec(naked) directxReturn()
{
	__asm {
		call_imm(00404FD0h);
		ret;
	}
}
uint8_t LerpChannel(uint8_t start, uint8_t end, float t)
{
	return static_cast<uint8_t>(start + t * (end - start));
}
uint32_t GetLevelColour(int level, uint8_t alphaFade)
{
	// Clamp level between 0 and 100
	level = std::clamp(level, 0, 100);

	// Define our key colors (RGB)
	struct RGB { uint8_t r, g, b; };
	const RGB white{ 255, 255, 255 };
	const RGB blue{ 0,   0,   255 };
	const RGB green{ 0,   255, 0 };
	const RGB amber{ 255, 191, 0 };
	const RGB red{ 255, 0,   0 };

	RGB current{};

	if (level <= 25) {
		float t = level / 25.0f;
		current.r = LerpChannel(white.r, blue.r, t);
		current.g = LerpChannel(white.g, blue.g, t);
		current.b = LerpChannel(white.b, blue.b, t);
	}
	else if (level <= 50) {
		float t = (level - 25) / 25.0f;
		current.r = LerpChannel(blue.r, green.r, t);
		current.g = LerpChannel(blue.g, green.g, t);
		current.b = LerpChannel(blue.b, green.b, t);
	}
	else if (level <= 75) {
		float t = (level - 50) / 25.0f;
		current.r = LerpChannel(green.r, amber.r, t);
		current.g = LerpChannel(green.g, amber.g, t);
		current.b = LerpChannel(green.b, amber.b, t);
	}
	else { // 76 to 100
		float t = (level - 75) / 25.0f;
		current.r = LerpChannel(amber.r, red.r, t);
		current.g = LerpChannel(amber.g, red.g, t);
		current.b = LerpChannel(amber.b, red.b, t);
	}

	// Pack into 32-bit integer. 
	// Format assumes ARGB based on: (iStack_34 << 8) << 8 matching alpha.
	// Adjust order (current.r, current.g, current.b) if the engine uses RGBA.
	return (alphaFade << 24) | (current.r << 16) | (current.g << 8) | current.b;
}
uint32_t TranslateGameColour(uint32_t incomingColor)
{
	uint8_t alphaFade = (incomingColor >> 24) & 0xFF; // Usually iStack_34 distance fade
	uint8_t upperColor = (incomingColor >> 16) & 0xFF; // This holds the game's 'uVar12' calculation
	uint8_t lowerColor = incomingColor & 0xFF;         // This holds the game's 'uVar9' calculation
	int32_t deducedLevel = 0;
	if (lowerColor != 0)
		deducedLevel = 35 - ((lowerColor * 34) / 255);
	else {
		// Treat upperColor as a percentage factor
		float percentage = static_cast<float>(upperColor) / 255.0f;

		// The game's math squashes the level values. To counteract level 99 reporting as 83, 
		// we use a multiplier/tuning factor to stretch the output range back out to 100.
		int rawDeduced = 35 + static_cast<int>((1.0f - percentage) * (100 - 35));

		// Scale the squashed 35-83 perceived range back up out to 35-100
		if (rawDeduced > 35) {
			float scaleFactor = static_cast<float>(rawDeduced - 35) / (83 - 35);
			deducedLevel = 35 + static_cast<int>(scaleFactor * (100 - 35));
		}
		else {
			deducedLevel = 35;
		}
	}
	return GetLevelColour(deducedLevel, alphaFade);
}
char* __fastcall UpdateCarClassString(int param_1)
{
	switch (*(int*)0x006F64D0) {
	case 0:
		*(char*)0x006924A0 = *(char*)(*(int*)param_1 + 0xbc) + 'A';
		return (char*)0x006924A0;
	case 1:
		return (char*)0x006924AC;
	case 2:
		return (char*)0x006924BC;
	case 3:
		return (char*)0x006924CC;
	case 4:
		return (char*)0x006924DC;
	case 5:
		return (char*)0x006924EC;
	default:
		return (char*)0x006F2464;
	}
}

void adjustFloats(float* x, float* y)
{
	/*
	if (x) *x = (float)floor((*x / 640.0f) * resW);
	if (y) *y = (float)floor((*y / 480.0f) * resH);
	*/
	if (x) *x = (float)(((double)*x / 640.0) * resW);
	if (y) *y = (float)(((double)*y / 480.0) * resH);
}
void adjustInts(int* x, int* y)
{
	/*
	if (x) *x = (int)((*x / 640.0f) * resW);
	if (y) *y = (int)((*y / 480.0f) * resH);
	*/
	if (x) *x = (int)(((double)*x / 640.0) * resW);
	if (y) *y = (int)(((double)*y / 480.0) * resH);

}
void adjustXAxisValue(int* x)
{
	//if (*x < 100 && *x > -100 && *x != 0)
	//	*x = 0;
#ifdef _DEBUG
	int2 = *x;
#endif
	if ((*x > 0 && *x < 75) || (*x < 0 && *x > -75))
		*x = 0;
	else if ((*x > 0 && *x < 100) || (*x < 0 && *x > -100))
		*x = (int)((double)*x * 0.1);
	else if ((*x > 0 && *x < 300) || (*x < 0 && *x > -300))
		*x = (int)((double)*x * 0.3);
	else if ((*x > 0 && *x < 600) || (*x < 0 && *x > -600))
		*x = (int)((double)*x * 0.6);
	else if ((*x > 0 && *x < 800) || (*x < 0 && *x > -800))
		*x = (int)((double)*x * 0.8);
#ifdef _DEBUG
	snprintf(logItBuf, sizeof(logItBuf), "X Axis: %d, Adjusted: %d\n", int2, *x);
	OutputDebugStringA(logItBuf);
#endif
}
void NOPSpace(unsigned location, unsigned int count)
{
	__asm {
		mov edi, location;
		mov ecx, count;
		mov eax, 0x90;
		rep stosb;
	}
}
void insertFunction(int addrPtr, void* function, int nopCount, functionType ft)
{
	unsigned char FT = 0xE9;
	if (ft == FT_CALL) FT = 0xE8;
	NOPSpace(addrPtr, nopCount);
	*(int*)(addrPtr + 1) = ((int)function - addrPtr) - 5;
	*(unsigned char*)addrPtr = FT;
}
void setFunction(int addrPtr, void* function)
{
	*(int*)(addrPtr) = ((int)function);
}