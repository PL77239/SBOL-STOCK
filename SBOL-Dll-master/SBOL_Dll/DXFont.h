#pragma once
#include <d3dx8.h>

#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }

// Font creation flags
#define D3DFONT_BOLD        0x0001
#define D3DFONT_ITALIC      0x0002
#define D3DFONT_ZENABLE     0x0004

// Font rendering flags
#define D3DFONT_CENTERED    0x0001
#define D3DFONT_TWOSIDED    0x0002
#define D3DFONT_FILTERED    0x0004

class DXFont
{
private:
	DWORD   m_dwFontHeight;
	DWORD   m_dwFontFlags;
	HFONT	m_hFont;

	LPDIRECT3DDEVICE8       m_pd3dDevice; // A D3DDevice used for rendering
	LPDIRECT3DTEXTURE8      m_pTexture;   // The d3d texture for this font
	LPDIRECT3DVERTEXBUFFER8 m_pVB;        // VertexBuffer for rendering text
	DWORD   m_dwTexWidth;                 // Texture dimensions
	DWORD   m_dwTexHeight;
	FLOAT   m_fTextScale;
	FLOAT   m_fTexCoords[128 - 32][4];

	// Stateblocks for setting and restoring render states
	DWORD   m_dwSavedStateBlock;
	DWORD   m_dwDrawTextStateBlock;

	void InitializeValues();
public:
	DXFont(HFONT hFont = nullptr, LPDIRECT3DDEVICE8 pd3dDevice = nullptr);
	~DXFont();

	HRESULT CheckDevice();
	HRESULT SetFont(HFONT hFont);
	HRESULT DrawText(FLOAT x, FLOAT y, DWORD dwColor, char* strText, DWORD dwFlags = 0L);
	HRESULT DrawTextScaled(FLOAT x, FLOAT y, FLOAT z, FLOAT fXScale, FLOAT fYScale, DWORD dwColor, const char* strText, DWORD dwFlags = 0L);
	HRESULT GetTextExtent(char* strText, SIZE* pSize);
	HRESULT InitDeviceObjects(LPDIRECT3DDEVICE8 pd3dDevice);
	HRESULT RestoreDeviceObjects();
	HRESULT InvalidateDeviceObjects();
	HRESULT DeleteDeviceObjects();
	void SetFontFlags(DWORD flags) { m_dwFontFlags |= flags; }
};

