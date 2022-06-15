#include "RasteriserModeSolidTest.h"

RasteriserModeSolidTest::RasteriserModeSolidTest()
	: device{ nullptr }, context{ nullptr }, result()
{
	initialise();
}

RasteriserModeSolidTest::~RasteriserModeSolidTest()
{
	cleanup(context);
	cleanup(device);
}

std::string RasteriserModeSolidTest::test()
{
	if (FAILED(result))
	{
		return "rasteriser mode solid test failed to initialise\n";
	}

	D3D11Renderer::Rasteriser unit;

	unit.setWireframe();
	unit.apply(device);

	unit.setSolid();
	unit.apply(device);
	unit.bind(context);

	if (description().FillMode == D3D11_FILL_SOLID)
	{
		return std::string();
	}

	return "rasteriser mode solid test failed\n";
}

void RasteriserModeSolidTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
		input = nullptr;
	}
}

void RasteriserModeSolidTest::initialise()
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

CD3D11_RASTERIZER_DESC RasteriserModeSolidTest::description()
{
	ID3D11RasterizerState* state;
	context->RSGetState(&state);

	if (!state)
	{
		return CD3D11_RASTERIZER_DESC();
	}

	CD3D11_RASTERIZER_DESC output;
	state->GetDesc(&output);
	cleanup(state);

	return output;
}
