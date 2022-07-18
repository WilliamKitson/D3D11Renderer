#include "ImplimentationDrawDefaultTest.h"

ImplimentationDrawDefaultTest::ImplimentationDrawDefaultTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, unit{ new D3D11Renderer::Implimentation }
{
}

ImplimentationDrawDefaultTest::~ImplimentationDrawDefaultTest()
{
	if (unit)
	{
		delete unit;
	}
}

std::string ImplimentationDrawDefaultTest::test()
{
	unit->initialise(HWND(), "");

	if (description().FillMode == D3D11_FILL_SOLID)
	{
		return std::string();
	}

	return "implimentation draw default test failed\n";
}

void ImplimentationDrawDefaultTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

CD3D11_RASTERIZER_DESC ImplimentationDrawDefaultTest::description()
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
