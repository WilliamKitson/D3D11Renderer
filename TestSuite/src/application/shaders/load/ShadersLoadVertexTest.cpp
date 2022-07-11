#include "ShadersLoadVertexTest.h"

ShadersLoadVertexTest::ShadersLoadVertexTest()
	: device{ nullptr }, context{ nullptr }, shader{ nullptr }, result()
{
}

ShadersLoadVertexTest::~ShadersLoadVertexTest()
{
	cleanup(shader);
	cleanup(context);
	cleanup(device);
}

std::string ShadersLoadVertexTest::test()
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

	if (FAILED(result))
	{
		return "shaders load vertex test failed to initialise\n";
	}

	D3D11Renderer::Shaders unit;

	unit.initialise(device);
	unit.bind(context);

	context->VSGetShader(
		&shader,
		nullptr,
		nullptr
	);

	if (shader)
	{
		return std::string();
	}

	return "shaders load vertex test failed\n";
}

void ShadersLoadVertexTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}
