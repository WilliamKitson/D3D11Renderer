#include "RasteriserModeSolidTest.h"

RasteriserModeSolidTest::RasteriserModeSolidTest()
	: device{ nullptr }, context{ nullptr }, description()
{
}

RasteriserModeSolidTest::~RasteriserModeSolidTest()
{
}

std::string RasteriserModeSolidTest::test()
{
	D3D_FEATURE_LEVEL levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	D3D_FEATURE_LEVEL supported;

	D3D11CreateDevice(
		0,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		0,
		levels,
		1,
		D3D11_SDK_VERSION,
		&device,
		&supported,
		&context
	);

	D3D11Renderer::Rasteriser unit;

	unit.setWireframe();
	unit.setSolid();
	unit.initialise(device);
	unit.bind(context);

	ID3D11RasterizerState* state;
	context->RSGetState(&state);

	if (!state)
	{
		return "rasteriser mode solid test description failed to initialise\n";
	}

	state->GetDesc(&description);

	if (description.FillMode == D3D11_FILL_SOLID)
	{
		return std::string();
	}

	return "rasteriser mode solid test failed\n";
}
