#pragma once

#include <string>
#include <d3d11.h>
#include <Windows.h>

#include "Swapchain.h"

class SwapchainResolutionViewTest
{
public:
	SwapchainResolutionViewTest(HINSTANCE, int);
	~SwapchainResolutionViewTest();

	std::string test();

private:
	static LRESULT CALLBACK windowProcedure(HWND, UINT, WPARAM, LPARAM);
	void cleanup(IUnknown*);
	void initialiseWindowClass();
	void initialiseWindow();
	void initialiseD3D11();
	D3D11_TEXTURE2D_DESC texture();
	bool successful(D3D11_TEXTURE2D_DESC, int[2]);

private:
	HINSTANCE hInstance;
	int nCmdShow;
	std::wstring tag;
	HWND window;
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	HRESULT result;
};
