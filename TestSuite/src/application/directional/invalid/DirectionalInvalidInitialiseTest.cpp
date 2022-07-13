#include "DirectionalInvalidInitialiseTest.h"

DirectionalInvalidInitialiseTest::DirectionalInvalidInitialiseTest()
	: device{ nullptr }, context{ nullptr }, objectBuffer{ nullptr }, result()
{
}

DirectionalInvalidInitialiseTest::~DirectionalInvalidInitialiseTest()
{
	cleanup(objectBuffer);
	cleanup(context);
	cleanup(device);
}

std::string DirectionalInvalidInitialiseTest::test()
{
	initialise();

	if (FAILED(result))
	{
		return "directional invalid initialise test failed to initialise\n";
	}

	D3D11Renderer::Directional unit;

	unit.initialise(nullptr);
	unit.bind(context);

	context->VSGetConstantBuffers(
		2,
		1,
		&objectBuffer
	);

	if (!objectBuffer)
	{
		return std::string();
	}

	return "directional invalid initialise test failed\n";
}

void DirectionalInvalidInitialiseTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void DirectionalInvalidInitialiseTest::initialise()
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
