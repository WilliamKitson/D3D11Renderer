#include "ShadersInvalidFilepathTest.h"

ShadersInvalidFilepathTest::ShadersInvalidFilepathTest()
	: device{ nullptr }, context{ nullptr }, vShader{ nullptr }, layout{ nullptr }, pShader{ nullptr }, result()
{
}

ShadersInvalidFilepathTest::~ShadersInvalidFilepathTest()
{
	cleanup(pShader);
	cleanup(layout);
	cleanup(vShader);
	cleanup(context);
	cleanup(device);
}

std::string ShadersInvalidFilepathTest::test()
{
	initialise();

	if (FAILED(result))
	{
		return "shaders invalid filepath test failed to initialise\n";
	}

	D3D11Renderer::Shaders unit;

	unit.initialise(device);
	unit.bind(context);

	if (success())
	{
		return std::string();
	}

	return "shaders invalid filepath test failed\n";
}

void ShadersInvalidFilepathTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void ShadersInvalidFilepathTest::initialise()
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

bool ShadersInvalidFilepathTest::success()
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

	context->IAGetInputLayout(&layout);

	if (layout)
	{
		return false;
	}

	return true;
}
