#include "GraphicsDevice.h"

GraphicsDevice::GraphicsDevice(){
	//Constructor logic
}

GraphicsDevice::~GraphicsDevice(){
	if(device){
		device->Release();
		device = NULL;
	}

	if (direct3d){
		direct3d->Release();
		direct3d = NULL;
	}
}

bool GraphicsDevice::Initialize(HWND hWnd, bool windowed){
	//Create the Direct 3D Pointer
	direct3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS presentationParams;
	ZeroMemory(&presentationParams, sizeof(presentationParams));
	presentationParams.Windowed = windowed;
	presentationParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
	presentationParams.hDeviceWindow = hWnd;

	//Create the device
	//D3DAPAPTER_DEFAULT = Primary display adapter (default graphics card)
	//D3DDEVTYPE_HAL = Hardware rasterization
	//D3DCREATE_MIXED_VERTEXPROCESSING = Uses both hardware and software for 3D calculations
	if(!SUCCEEDED(direct3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING, &presentationParams, &device))) 
	{
		MessageBox(NULL, "Error in creating a D3DX9 Device! Verify if your computer supports or has DirectX9", "Error in creating a D3DX9 Device!", MB_ICONERROR | MB_OK);
		return false; 
	}

	return true;
}

void GraphicsDevice::Clear(D3DCOLOR color){
	//2nd param is set no 'NULL' so that it clears the entire back buffer
	device->Clear(0, NULL, D3DCLEAR_TARGET, color, 1.0f, 0);
}

void GraphicsDevice::Begin(){
	device->BeginScene();
}

void GraphicsDevice::End(){
	device->EndScene();
}

void GraphicsDevice::Present(){
	//Present our scene to the window
	device->Present(NULL, NULL, NULL, NULL);
}