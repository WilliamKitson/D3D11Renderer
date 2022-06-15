#pragma once

#include <string>
#include <d3d11.h>
#include <Windows.h>

#include "Swapchain.h"

class SwapchainDefaultDepthTest
{
public:
	SwapchainDefaultDepthTest(HINSTANCE, int);
	~SwapchainDefaultDepthTest();

	std::string test();

private:
	static LRESULT CALLBACK windowProcedure(HWND, UINT, WPARAM, LPARAM);
	void initialiseWindowClass();
	void initialiseWindow();
	void initialiseD3D11();
	D3D11_TEXTURE2D_DESC texture();

private:
	HINSTANCE hInstance;
	int nCmdShow;
	std::wstring tag;
	HWND window;
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	HRESULT result;
};
