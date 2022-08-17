#include "ImplimentationDrawWireframeTest.h"

ImplimentationDrawWireframeTest::ImplimentationDrawWireframeTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, unit{ new D3D11Renderer::Implimentation }
{
}

ImplimentationDrawWireframeTest::~ImplimentationDrawWireframeTest()
{
	delete unit;
	unit = nullptr;
}

std::string ImplimentationDrawWireframeTest::test()
{
	unit->initialise(HWND(), "");
	unit->drawWireframe();

	if (description().FillMode == D3D11_FILL_WIREFRAME)
	{
		return std::string();
	}

	return "implimentation draw wireframe test failed\n";
}

void ImplimentationDrawWireframeTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

CD3D11_RASTERIZER_DESC ImplimentationDrawWireframeTest::description()
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
