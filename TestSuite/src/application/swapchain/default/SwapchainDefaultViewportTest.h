#pragma once

#include <string>
#include <d3d11.h>
#include <Windows.h>

#include "Swapchain.h"

class SwapchainDefaultViewportTest
{
public:
	SwapchainDefaultViewportTest(HINSTANCE, int);
	~SwapchainDefaultViewportTest();

	std::string test();

private:
	static LRESULT CALLBACK windowProcedure(HWND, UINT, WPARAM, LPARAM);
	void cleanup(IUnknown*);
	void initialiseWindowClass();
	HRESULT initialiseWindow();
	HRESULT initialiseD3D11();
	D3D11_VIEWPORT viewport();
	bool successful(D3D11_VIEWPORT);

private:
	HINSTANCE hInstance;
	int nCmdShow;
	std::wstring tag;
	HWND window;
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	HRESULT result;
};
