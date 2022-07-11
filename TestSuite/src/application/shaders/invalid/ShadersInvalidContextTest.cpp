#include "ShadersInvalidContextTest.h"

ShadersInvalidContextTest::ShadersInvalidContextTest()
	: device{ nullptr }, context{ nullptr }, vShader{ nullptr }, pShader{ nullptr }, result()
{
}

ShadersInvalidContextTest::~ShadersInvalidContextTest()
{
	cleanup(pShader);
	cleanup(vShader);
	cleanup(context);
	cleanup(device);
}

std::string ShadersInvalidContextTest::test()
{
	initialise();

	if (FAILED(result))
	{
		return "shaders invalid context test failed to initialise\n";
	}

	D3D11Renderer::Shaders unit;

	unit.setFilepath("assets/shaders/shaders.hlsl");
	unit.initialise(device);
	unit.bind(nullptr);

	if (success())
	{
		return std::string();
	}

	return "shaders invalid context test failed\n";
}

void ShadersInvalidContextTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void ShadersInvalidContextTest::initialise()
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

bool ShadersInvalidContextTest::success()
{
	context->VSGetShader(
		&vShader,
		nullptr,
		nullptr
	);

	if (vShader)
	{
		return false;
	}

	context->PSGetShader(
		&pShader,
		nullptr,
		nullptr
	);

	if (pShader)
	{
		return false;
	}

	return true;
}
