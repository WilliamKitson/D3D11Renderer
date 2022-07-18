#pragma once

#include "Implimentation.h"
#include "Facade.h"

class ImplimentationCullDefaultTest
{
public:
	ImplimentationCullDefaultTest(HINSTANCE, int);
	~ImplimentationCullDefaultTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	CD3D11_RASTERIZER_DESC description();

private:
	HINSTANCE hInstance;
	int nCmdShow;
	D3D11Renderer::Facade* unit;
};
