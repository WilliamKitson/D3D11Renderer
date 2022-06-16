#pragma once

#include <string>
#include <d3d11.h>
#include <Windows.h>
#include <chrono>

#include "Swapchain.h"

class SwapchainIntervalHalfTest
{
public:
	SwapchainIntervalHalfTest(HINSTANCE, int);
	~SwapchainIntervalHalfTest();

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
