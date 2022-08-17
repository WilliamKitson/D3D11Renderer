#include "ImplimentationDrawSolidTest.h"

ImplimentationDrawSolidTest::ImplimentationDrawSolidTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, unit{ new D3D11Renderer::Implimentation }
{
}

ImplimentationDrawSolidTest::~ImplimentationDrawSolidTest()
{
	delete unit;
	unit = nullptr;
}

std::string ImplimentationDrawSolidTest::test()
{
	unit->initialise(HWND(), "");
	unit->drawWireframe();
	unit->drawSolid();

	if (description().FillMode == D3D11_FILL_SOLID)
	{
		return std::string();
	}

	return "implimentation draw solid test failed\n";
}

void ImplimentationDrawSolidTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

CD3D11_RASTERIZER_DESC ImplimentationDrawSolidTest::description()
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
