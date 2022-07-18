#pragma once

#include <string>
#include <Windows.h>
#include <d3d11.h>

#include "Facade.h"
#include "Implimentation.h"

class ImplimentationResolutionReloadTest
{
public:
	ImplimentationResolutionReloadTest(HINSTANCE, int);
	~ImplimentationResolutionReloadTest();

	std::string test();

private:
	static LRESULT CALLBACK windowProcedure(HWND, UINT, WPARAM, LPARAM);
	void cleanup(IUnknown*);
	void initialiseWindowClass();
	void initialiseWindow();
	D3D11_TEXTURE2D_DESC texture();
	bool successful(D3D11_TEXTURE2D_DESC, D3D11Renderer::Output);

private:
	HINSTANCE hInstance;
	int nCmdShow;
	std::wstring tag;
	HWND window;
	HRESULT result;
	D3D11Renderer::Facade* unit;
};
