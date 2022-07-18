#include "ImplimentationCullNoneTest.h"

ImplimentationCullNoneTest::ImplimentationCullNoneTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, unit{ new D3D11Renderer::Implimentation }
{
}

ImplimentationCullNoneTest::~ImplimentationCullNoneTest()
{
	if (unit)
	{
		delete unit;
	}
}

std::string ImplimentationCullNoneTest::test()
{
	unit->initialise(HWND(), "");
	unit->cullNone();

	if (description().CullMode == D3D11_CULL_NONE)
	{
		return std::string();
	}

	return "implimentation cull none test failed\n";
}

void ImplimentationCullNoneTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

CD3D11_RASTERIZER_DESC ImplimentationCullNoneTest::description()
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
