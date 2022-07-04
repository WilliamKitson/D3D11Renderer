#include "RasteriserInvalidContextTest.h"

RasteriserInvalidContextTest::RasteriserInvalidContextTest()
	: device{ nullptr }, context{ nullptr }, state{ nullptr }, result()
{
}

RasteriserInvalidContextTest::~RasteriserInvalidContextTest()
{
	cleanup(state);
	cleanup(context);
	cleanup(device);
}

std::string RasteriserInvalidContextTest::test()
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

	D3D11Renderer::Rasteriser unit;

	unit.initialise(device);
	unit.bind(nullptr);

	context->RSGetState(&state);

	if (!state)
	{
		return std::string();
	}

	return "rasteriser invalid context test failed\n";
}

void RasteriserInvalidContextTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}
