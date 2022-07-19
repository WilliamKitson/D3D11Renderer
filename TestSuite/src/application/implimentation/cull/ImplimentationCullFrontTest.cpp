#include "ImplimentationCullFrontTest.h"

ImplimentationCullFrontTest::ImplimentationCullFrontTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, unit{ new D3D11Renderer::Implimentation }
{
}

ImplimentationCullFrontTest::~ImplimentationCullFrontTest()
{
	if (unit)
	{
		delete unit;
	}
}

std::string ImplimentationCullFrontTest::test()
{
	unit->initialise(HWND(), "");
	unit->cullFront();

	if (description().CullMode == D3D11_CULL_FRONT)
	{
		return std::string();
	}

	return "implimentation cull front test failed\n";
}

void ImplimentationCullFrontTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

CD3D11_RASTERIZER_DESC ImplimentationCullFrontTest::description()
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
