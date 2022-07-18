#pragma once

#include <string>
#include <Windows.h>
#include <d3d11.h>
#include <chrono>

#include "Facade.h"
#include "Implimentation.h"

class ImplimentationSyncHalfTest
{
public:
	ImplimentationSyncHalfTest(HINSTANCE, int);
	~ImplimentationSyncHalfTest();

	std::string test();

private:
	static LRESULT CALLBACK windowProcedure(HWND, UINT, WPARAM, LPARAM);
	void initialiseWindowClass();
	void initialiseWindow();
	int framerate();

private:
	HINSTANCE hInstance;
	int nCmdShow;
	std::wstring tag;
	HWND window;
	HRESULT result;
	D3D11Renderer::Facade* unit;
};
