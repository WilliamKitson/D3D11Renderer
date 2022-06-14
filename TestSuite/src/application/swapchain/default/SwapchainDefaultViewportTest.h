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

private:
	HINSTANCE hInstance;
	int nCmdShow;
	HWND window;
	ID3D11Device* device;
	ID3D11DeviceContext* context;
};
