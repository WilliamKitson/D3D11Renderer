#include "SamplerInvalidDeviceTest.h"

SamplerInvalidDeviceTest::SamplerInvalidDeviceTest()
	: device{ nullptr }, context{ nullptr }, state{ nullptr }, result()
{
}

SamplerInvalidDeviceTest::~SamplerInvalidDeviceTest()
{
	cleanup(state);
	cleanup(context);
	cleanup(device);
}

std::string SamplerInvalidDeviceTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "sampler default test failed to initialise D3D11\n";
	}

	D3D11Renderer::Sampler unit;

	unit.initialise(nullptr);
	unit.bind(context);

	context->PSGetSamplers(
		0,
		1,
		&state
	);

	if (!state)
	{
		return std::string();
	}

	return "sampler default test failed\n";
}

void SamplerInvalidDeviceTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void SamplerInvalidDeviceTest::initialiseD3D11()
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