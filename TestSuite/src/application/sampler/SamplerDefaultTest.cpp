#include "SamplerDefaultTest.h"

SamplerDefaultTest::SamplerDefaultTest()
	: device{ nullptr }, context{ nullptr }, state{ nullptr }, result()
{
}

SamplerDefaultTest::~SamplerDefaultTest()
{
	cleanup(state);
	cleanup(context);
	cleanup(device);
}

std::string SamplerDefaultTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "sampler default test failed to initialise D3D11\n";
	}

	D3D11Renderer::Sampler unit;

	unit.initialise(device);
	unit.bind(context);

	context->PSGetSamplers(
		0,
		1,
		&state
	);

	if (!state)
	{
		return "sampler default test failed to initialise state\n";
	}

	D3D11_SAMPLER_DESC description = D3D11_SAMPLER_DESC();
	state->GetDesc(&description);

	bool success = true;

	if (description.Filter != D3D11_FILTER_MIN_MAG_MIP_LINEAR)
	{
		success = false;
	}

	if(description.AddressU != D3D11_TEXTURE_ADDRESS_WRAP)
	{
		success = false;
	}

	if(description.AddressV != D3D11_TEXTURE_ADDRESS_WRAP)
	{
		success = false;
	}

	if(description.AddressW != D3D11_TEXTURE_ADDRESS_WRAP)
	{
		success = false;
	}

	if(description.MipLODBias != 0.0f)
	{
		success = false;
	}

	if(description.MaxAnisotropy != 0)
	{
		success = false;
	}

	if(description.ComparisonFunc != 1)
	{
		success = false;
	}

	if(description.BorderColor[0] != 0.0f)
	{
		success = false;
	}

	if(description.BorderColor[1] != 0.0f)
	{
		success = false;
	}

	if(description.BorderColor[2] != 0.0f)
	{
		success = false;
	}

	if(description.BorderColor[3] != 0.0f)
	{
		success = false;
	}

	if(description.MinLOD != 0.0f)
	{
		success = false;
	}

	if(description.MaxLOD != D3D11_FLOAT32_MAX)
	{
		success = false;
	}

	if (success)
	{
		return std::string();
	}

	return "sampler default test failed\n";
}

void SamplerDefaultTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void SamplerDefaultTest::initialiseD3D11()
{
	D3D_FEATURE_LEVEL levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	D3D_FEATURE_LEVEL supported;

	result = D3D11CreateDevice(
		0,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		D3D11_CREATE_DEVICE_DEBUG,
		levels,
		1,
		D3D11_SDK_VERSION,
		&device,
		&supported,
		&context
	);
}
