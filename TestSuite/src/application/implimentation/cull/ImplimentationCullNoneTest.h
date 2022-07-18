#pragma once

#include "Implimentation.h"
#include "Facade.h"

class ImplimentationCullNoneTest
{
public:
	ImplimentationCullNoneTest(HINSTANCE, int);
	~ImplimentationCullNoneTest();

	std::string test();

private:
	void cleanup(IUnknown*);
	CD3D11_RASTERIZER_DESC description();

private:
	HINSTANCE hInstance;
	int nCmdShow;
	D3D11Renderer::Facade* unit;
};
