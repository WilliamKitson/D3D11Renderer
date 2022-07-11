#include "ShadersLoadInputTest.h"

ShadersLoadInputTest::ShadersLoadInputTest()
	: device{ nullptr }, context{ nullptr }, input{ nullptr }, result()
{
}

ShadersLoadInputTest::~ShadersLoadInputTest()
{
	cleanup(input);
	cleanup(context);
	cleanup(device);
}

std::string ShadersLoadInputTest::test()
{
	initialise();

	if (FAILED(result))
	{
		return "shaders load input test failed to initialise\n";
	}

	D3D11Renderer::Shaders unit;

	unit.setFilepath("assets/shaders/shaders.hlsl");
	unit.initialise(device);
	unit.bind(context);

	unit.initialise(device);
	unit.bind(context);

	context->IAGetInputLayout(&input);

	if (input)
	{
		return std::string();
	}

	return "shaders load input test failed\n";
}

void ShadersLoadInputTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void ShadersLoadInputTest::initialise()
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
