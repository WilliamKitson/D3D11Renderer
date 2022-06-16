#pragma once

#include <string>
#include <d3d11.h>
#include <Windows.h>
#include <chrono>

#include "Swapchain.h"

class SwapchainIntervalFullTest
{
public:
	SwapchainIntervalFullTest(HINSTANCE, int);
	~SwapchainIntervalFullTest();

	std::string test();

private:
	static LRESULT CALLBACK windowProcedure(HWND, UINT, WPARAM, LPARAM);

private:
	HINSTANCE hInstance;
	int nCmdShow;
	std::wstring tag;
	HWND window;
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	HRESULT result;
	D3D11Renderer::Swapchain unit;
};
