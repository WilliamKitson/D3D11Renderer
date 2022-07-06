#include "PerSceneInvalidBindTest.h"

PerSceneInvalidBindTest::PerSceneInvalidBindTest()
	: device{ nullptr }, context{ nullptr }, sceneBuffer{ nullptr }, result()
{
}

PerSceneInvalidBindTest::~PerSceneInvalidBindTest()
{
	cleanup(sceneBuffer);
	cleanup(context);
	cleanup(device);
}

std::string PerSceneInvalidBindTest::test()
{
	initialiseD3D11();

	if (FAILED(result))
	{
		return "per scene invalid bind test failed to initialise D3D11\n";
	}

	D3D11Renderer::PerScene unit;

	unit.initialise(device);
	unit.bind(nullptr);

	context->VSGetConstantBuffers(
		0,
		1,
		&sceneBuffer
	);

	if (!sceneBuffer)
	{
		return std::string();
	}

	return "per scene invalid bind test failed\n";
}

void PerSceneInvalidBindTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void PerSceneInvalidBindTest::initialiseD3D11()
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
