#ifndef GRAPHICSDEVICE_H
#define GRAPHICSDEVICE_H

#include <d3d9.h>

class GraphicsDevice
{
public:
	GraphicsDevice();
	~GraphicsDevice();

	//Direct3D Function
	bool Initialize(HWND HWND, bool windowed);
	void Clear(D3DCOLOR color);
	void Begin();
	void End();
	void Present();

	//Shorthand for IDirect3DDevice *device;
	LPDIRECT3DDEVICE9 device;

private:
	LPDIRECT3D9 direct3d;
};

#endif /*GRAPHICSDEVICE_H*/