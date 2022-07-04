#include "PerObjectInvalidBindTest.h"

PerObjectInvalidBindTest::PerObjectInvalidBindTest()
	: device{ nullptr }, context{ nullptr }, objectBuffer{ nullptr }, result()
{
}

PerObjectInvalidBindTest::~PerObjectInvalidBindTest()
{
	cleanup(objectBuffer);
	cleanup(context);
	cleanup(device);
}

std::string PerObjectInvalidBindTest::test()
{
	initialise();

	if (FAILED(result))
	{
		return "per object invalid bind test failed to initialise\n";
	}

	D3D11Renderer::PerObject unit;

	unit.initialise(device);
	unit.bind(nullptr);

	context->VSGetConstantBuffers(
		0,
		1,
		&objectBuffer
	);

	if (!objectBuffer)
	{
		return std::string();
	}

	return "per object invalid bind test failed\n";
}

void PerObjectInvalidBindTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void PerObjectInvalidBindTest::initialise()
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
