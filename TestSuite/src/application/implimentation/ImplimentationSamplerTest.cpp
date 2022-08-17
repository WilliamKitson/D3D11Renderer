#include "ImplimentationSamplerTest.h"

ImplimentationSamplerTest::ImplimentationSamplerTest()
	: unit{ new D3D11Renderer::Implimentation }, state{ nullptr }
{
}

ImplimentationSamplerTest::~ImplimentationSamplerTest()
{
	cleanup();
	cleanup(state);
}

std::string ImplimentationSamplerTest::test()
{
	unit->initialise(HWND(), "");

	unit->getContext()->PSGetSamplers(
		0,
		1,
		&state
	);

	if (!state)
	{
		return "implimentation sampler test failed to initialise state\n";
	}

	if (success())
	{
		return std::string();
	}

	return "implimentation sampler test failed\n";
}

void ImplimentationSamplerTest::cleanup()
{
	delete unit;
	unit = nullptr;
}

void ImplimentationSamplerTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

bool ImplimentationSamplerTest::success()
{
	D3D11_SAMPLER_DESC description = D3D11_SAMPLER_DESC();
	state->GetDesc(&description);

	if (description.Filter != D3D11_FILTER_MIN_MAG_MIP_LINEAR)
	{
		return false;
	}

	if (description.AddressU != D3D11_TEXTURE_ADDRESS_WRAP)
	{
		return false;
	}

	if (description.AddressV != D3D11_TEXTURE_ADDRESS_WRAP)
	{
		return false;
	}

	if (description.AddressW != D3D11_TEXTURE_ADDRESS_WRAP)
	{
		return false;
	}

	if (description.MipLODBias != 0.0f)
	{
		return false;
	}

	if (description.MaxAnisotropy != 0)
	{
		return false;
	}

	if (description.ComparisonFunc != 1)
	{
		return false;
	}

	if (description.BorderColor[0] != 0.0f)
	{
		return false;
	}

	if (description.BorderColor[1] != 0.0f)
	{
		return false;
	}

	if (description.BorderColor[2] != 0.0f)
	{
		return false;
	}

	if (description.BorderColor[3] != 0.0f)
	{
		return false;
	}

	if (description.MinLOD != 0.0f)
	{
		return false;
	}

	if (description.MaxLOD != D3D11_FLOAT32_MAX)
	{
		return false;
	}

	return true;
}
