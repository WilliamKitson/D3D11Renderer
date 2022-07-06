#include "PerObjectInvalidDeviceTest.h"

PerObjectInvalidDeviceTest::PerObjectInvalidDeviceTest()
	: device{ nullptr }, context{ nullptr }, objectBuffer{ nullptr }, result()
{
}

PerObjectInvalidDeviceTest::~PerObjectInvalidDeviceTest()
{
	cleanup(objectBuffer);
	cleanup(context);
	cleanup(device);
}

std::string PerObjectInvalidDeviceTest::test()
{
	initialise();

	if (FAILED(result))
	{
		return "per object invalid device test failed to initialise\n";
	}

	D3D11Renderer::PerObject unit;

	unit.initialise(nullptr);
	unit.bind(context);

	context->VSGetConstantBuffers(
		1,
		1,
		&objectBuffer
	);

	if (!objectBuffer)
	{
		return std::string();
	}

	return "per object invalid device test failed\n";
}

void PerObjectInvalidDeviceTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void PerObjectInvalidDeviceTest::initialise()
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
