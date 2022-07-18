#include "ImplimentationCullDefaultTest.h"

ImplimentationCullDefaultTest::ImplimentationCullDefaultTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, unit{ new D3D11Renderer::Implimentation }
{
}

ImplimentationCullDefaultTest::~ImplimentationCullDefaultTest()
{
	if (unit)
	{
		delete unit;
	}
}

std::string ImplimentationCullDefaultTest::test()
{
	unit->initialise(HWND(), "");

	if (description().CullMode == D3D11_CULL_BACK)
	{
		return std::string();
	}

	return "implimentation cull default test failed\n";
}

void ImplimentationCullDefaultTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

CD3D11_RASTERIZER_DESC ImplimentationCullDefaultTest::description()
{
	ID3D11RasterizerState* state;
	unit->getContext()->RSGetState(&state);

	if (!state)
	{
		return CD3D11_RASTERIZER_DESC();
	}

	CD3D11_RASTERIZER_DESC output;
	state->GetDesc(&output);
	cleanup(state);

	return output;
}
