#include "RasteriserInvalidDeviceTest.h"

RasteriserInvalidDeviceTest::RasteriserInvalidDeviceTest()
	: device{ nullptr }, context{ nullptr }, state{ nullptr }, result()
{
}

RasteriserInvalidDeviceTest::~RasteriserInvalidDeviceTest()
{
	cleanup(state);
	cleanup(context);
	cleanup(device);
}

std::string RasteriserInvalidDeviceTest::test()
{
	initialise();

	if (FAILED(result))
	{
		return "rasteriser invalid device test failed to initialise\n";
	}

	D3D11Renderer::Rasteriser unit;

	unit.initialise(nullptr);
	unit.bind(context);

	context->RSGetState(&state);

	if (!state)
	{
		return std::string();
	}

	return "rasteriser invalid device test failed\n";
}

void RasteriserInvalidDeviceTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void RasteriserInvalidDeviceTest::initialise()
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
