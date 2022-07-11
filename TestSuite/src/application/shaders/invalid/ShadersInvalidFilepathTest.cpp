#include "ShadersInvalidFilepathTest.h"

ShadersInvalidFilepathTest::ShadersInvalidFilepathTest()
	: device{ nullptr }, context{ nullptr }, shader{ nullptr }, result()
{
}

ShadersInvalidFilepathTest::~ShadersInvalidFilepathTest()
{
	cleanup(shader);
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

	context->VSGetShader(
		&shader,
		nullptr,
		nullptr
	);

	if (!shader)
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
