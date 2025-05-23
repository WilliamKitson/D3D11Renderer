#pragma once

#include <string>
#include <d3d11.h>

#include "Swapchain.h"

class SwapchainInvalidOverlapTest
{
public:
	SwapchainInvalidOverlapTest(HINSTANCE, int);
	~SwapchainInvalidOverlapTest();

	std::string test();

private:
	static LRESULT CALLBACK windowProcedure(HWND, UINT, WPARAM, LPARAM);
	void cleanup(IUnknown*);
	void initialiseWindowClass();
	void initialiseWindow();
	void initialiseD3D11();

private:
	HINSTANCE hInstance;
	int nCmdShow;
	std::wstring tag;
	HWND window;
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	HRESULT result;
	ID3D11DepthStencilView* depth;
};
