#include "ImplimentationShadersTest.h"

ImplimentationShadersTest::ImplimentationShadersTest()
	: unit{ new D3D11Renderer::Implimentation }, shader{ nullptr }, result()
{
}

ImplimentationShadersTest::~ImplimentationShadersTest()
{
	cleanup();
	cleanup(shader);
}

std::string ImplimentationShadersTest::test()
{
	unit->initialise(HWND(), "assets/shaders/shaders.hlsl");

	unit->getContext()->VSGetShader(
		&shader,
		nullptr,
		nullptr
	);

	if (shader)
	{
		return std::string();
	}

	return "shaders load vertex test failed\n";
}

void ImplimentationShadersTest::cleanup()
{
	delete unit;
	unit = nullptr;
}

void ImplimentationShadersTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}
