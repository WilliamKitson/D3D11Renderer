#include "ImplimentationCullBackTest.h"

ImplimentationCullBackTest::ImplimentationCullBackTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, unit{ new D3D11Renderer::Implimentation }
{
}

ImplimentationCullBackTest::~ImplimentationCullBackTest()
{
	delete unit;
	unit = nullptr;
}

std::string ImplimentationCullBackTest::test()
{
	unit->initialise(HWND(), "");
	unit->cullFront();
	unit->cullBack();

	if (description().CullMode == D3D11_CULL_BACK)
	{
		return std::string();
	}

	return "implimentation cull back test failed\n";
}

void ImplimentationCullBackTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

CD3D11_RASTERIZER_DESC ImplimentationCullBackTest::description()
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
