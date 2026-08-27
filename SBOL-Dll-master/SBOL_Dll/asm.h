#pragma once
#ifndef ASM_HEADER
#define ASM_HEADER
#include "dx.h"
#include "globals.h"
#include "structures.h"
#include <algorithm>
#include <cstdint>
#include <functional>
#include <math.h>
#include <sstream>
#include <string.h>
#include <vector>
#include <Windows.h>

extern LPDIRECT3DDEVICE8 dx;

enum functionType {
	FT_CALL,
	FT_JUMP
};

#pragma region ASM Defines
#define call_imm(x) __asm \
{ \
__asm mov eax, x \
__asm call eax \
};
#define jmp_imm(x) __asm \
{ \
__asm mov eax, x \
__asm jmp eax \
};
#define SaveEAX __asm mov _EAX, eax;
#define RestoreEAX __asm mov eax, _EAX;
#define SaveECX __asm mov _ECX, ecx;
#define RestoreECX __asm mov ecx, _ECX;
#define SaveEDX __asm mov _EDX, edx;
#define RestoreEDX __asm mov edx, _EDX;
#define SaveEBX __asm mov _EBX, ebx;
#define RestoreEBX __asm mov ebx, _EBX;
#define SaveEDI __asm mov _EDI, edi;
#define RestoreEDI __asm mov edi, _EDI;
#define SaveESI __asm mov _ESI, esi;
#define RestoreESI __asm mov esi, _ESI;
#pragma endregion
void NOPSpace(unsigned location, unsigned int count);
void __fastcall createUIElementObject(void* _this, void* edx, int posx, int posy);
void __fastcall createUIElementObject_43(void* _this, void* edx, int posx, int posy);
void __fastcall createUIElementObject_AutoScale(void* _this, void* edx, int posx, int posy);
void __fastcall createUIElementObject_AutoScale_43(void* _this, void* edx, int posx, int posy);
void __fastcall createUIElementObject_Scale(void* _this, void* edx, int posx, int posy);
void __fastcall createUIElementObject_Scale_Reposition(void* _this, void* edx, int posx, int posy);
void __fastcall createUIElementObject_Scale_Reposition_BottomLeft(void* _this, void* edx, int posx, int posy);
void __fastcall createUIElementObject_Scale_Reposition_BottomRight(void* _this, void* edx, int posx, int posy);
void __fastcall createUIElement(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_43(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_Scale_Reposition(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_Scale_Reposition_TopLeft(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_Scale_Reposition_BottomLeft(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_Scale_Reposition_BottomRight(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_AutoScale(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_AutoScale_43(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_AutoScale_Handle(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_AutoScale_TeamName(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_Scale(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall positionUIElement(void* _this, void* edx, float posx, float posy, int type);
void __fastcall positionUIElement_Reposition(void* _this, void* edx, float posx, float posy, int type);
void __fastcall positionUIElement_Reposition_43(void* _this, void* edx, float posx, float posy, int type);
void __fastcall interactionUIElement(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall interactionUIElement_43(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall interactionUIElement_Scale(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall interactionUIElement_Scale_Reposition(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall interactionUIElement_Scale_Reposition_TopLeft(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall interactionUIElement_Scale_Reposition_BottomRight(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall moveUIElement(void* _this, void* edx, int posx, int posy);
void __fastcall moveUIElement_43(void* _this, void* edx, int posx, int posy);
void __fastcall moveUIElement_Position(void* _this, void* edx, int posx, int posy);
void __fastcall positionInteractionUI(void* _this, void* edx, int posx, int posy);
void __fastcall placeUIElement(void* _this, void* edx, char* uiElementLabel, float width, float height, int param_4);
void __fastcall uiInteractBoundary(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall uiSetInteractArea(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall uiSetInteractArea_43(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall createTextbox(void* _this, void* edx, float posx, float posy);
void __fastcall createTextbox_43(void* _this, void* edx, float posx, float posy);
void __fastcall createTextbox_Scale_Reposition_TopLeft(void* _this, void* edx, float posx, float posy);
void __fastcall createTextboxCarat(void* _this, void* edx, int caratpos);
void __fastcall colourUIElement(void* _this, void* edx, unsigned int newcolour, unsigned int colourmask);
void __fastcall SwfMatrixConstruct(SWFUI* _this, void* edx, D3D_MATRIX* d3dMatrix, float localX, float localY, float layerZ);
/* Scales SWF file to 4:3 */
void __fastcall SwfMatrixConstruct_Stretch(SWFUI* _this, void* edx, D3D_MATRIX* d3dMatrix, float width, float height, float scale);
/* Centers SWF in widescreen resolutions */
void __fastcall SwfMatrixConstruct_Centered(SWFUI* _this, void* edx, D3D_MATRIX* d3dMatrix, float localX, float localY, float layerZ);
/* Clips SWF anything outside 4:3 */
void __fastcall SwfDrawPrimitive(void* _this, void* edx, LPDIRECT3DDEVICE8 pDevice, D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount);
void __fastcall SwfDrawPrimitive_Stretch(void* _this, void* edx, LPDIRECT3DDEVICE8 pDevice, D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount);
/* Adjusts the mouse inputs for the SWF so that they work with the repositoned and sized SWF */
void __fastcall SwfGetMouseState(void* _this, void* edx, int* pOutX, int* pOutY, int* pOutClickState);
/* Original button interaction calculations */
unsigned int __fastcall ButtonInteract(void* _this, void* edx, int MouseX, int MouseY, int Width, int Height);
/* Button interactions scaled the the increased 4:3 resolution */
bool __fastcall ButtonInteract43(void* ButtonPtr, void* edx, int32_t MouseX, int32_t MouseY, int32_t Width, int32_t Height);
/* Button interactions scaled to the increased 4:3 resolution on object */
bool __fastcall ButtonInteract43_Object(void* ButtonPtr, void* edx, int16_t MouseX, int16_t MouseY);
void adjustfloats(float* x, float* y);
void adjustfloats43(float* x, float* y);
void adjustfloatsN(float* x, float* y);
void adjustfloatsNBR(float* x, float* y);
void adjustints(int* x, int* y);
void adjustints43(int* x, int* y);
void adjustints43Center(int* x, int* y);
void adjustintsN(int* x, int* y);
void adjustintsNTC(int* x, int* y);
void adjustbytesN(int* x, int* y);
void __fastcall addressbookArea(void* _this, void* edx, int posx, int posy);
void __fastcall addAddressbookEntry(void* object, void* edx);
void __cdecl SetViewport(D3DVIEWPORT8* pViewport);
void __cdecl SetViewport_Scale_Reposition_BottomLeft(D3DVIEWPORT8* pViewport);
void __cdecl SetViewport_Scale_Centered(D3DVIEWPORT8* pViewport);
void __cdecl SetViewport_Scale_Centered1(D3DVIEWPORT8* pViewport);
void __fastcall gameCreateRectRgn(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall setRect1(void* _this, void* edx, int param_1, int param_2, int param_3);
void __fastcall setRect2(void* _this, void* edx, int param_1, int param_2, int param_3);
void positionUIElement2();
void positionUIElement3();
void adjustUI();
void scaleUIElement();
void adjustXAxis();
typedef void(__fastcall *placeStringFunc)(void* obj, int unused, int x, int y);
typedef void(__fastcall* createUIElementObjectFunc)(void* _this, void* edx, int posx, int posy);
typedef void(__fastcall *createUIElementFunc)(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
typedef void(__fastcall* positionUIElementFunc)(void* _this, void* edx, float posx, float posy, int type);
typedef void(__fastcall* interactionUIElementFunc)(void* _this, void* edx, int posx, int posy, int width, int height);
typedef void(__fastcall* positionInteractionUIFunc)(void* _this, void* edx, int posx, int posy);
void exitFix();
void __cdecl windowMonitorThread(void* parg);
void getTireBrakePrice();
void getPFileTireBrakePriceMultipler();
void getPFileTireBrakePrice();
void adjustFloats(float* x, float* y);
void adjustInts(int* x, int* y);
void adjustXAxisValue(int* x);
void insertFunction(int addrPtr, void* function, int nopCount, functionType ft);
void setFunction(int addrPtr, void* function);
int notFullScreenMode();
int skipBootWarning();
void setTexturePositions();
void setItemUsePosition();
void drawString();
void directxScene();
void directxReturn();
uint8_t LerpChannel(uint8_t start, uint8_t end, float t);
uint32_t GetLevelColour(int level, uint8_t alphaFade);
uint32_t TranslateGameColour(uint32_t incomingColor);
char* __fastcall UpdateCarClassString(int param_1);
#endif