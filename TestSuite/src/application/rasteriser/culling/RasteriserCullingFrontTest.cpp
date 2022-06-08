#include "RasteriserCullingFrontTest.h"

RasteriserCullingFrontTest::RasteriserCullingFrontTest()
	: device{ nullptr }, context{ nullptr }, description()
{
}

RasteriserCullingFrontTest::~RasteriserCullingFrontTest()
{
}

std::string RasteriserCullingFrontTest::test()
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

	unit.setFront();
	unit.initialise(device);
	unit.bind(context);

	ID3D11RasterizerState* state;
	context->RSGetState(&state);

	if (!state)
	{
		return "rasteriser culling front test description failed to initialise\n";
	}

	state->GetDesc(&description);

	if (description.CullMode == D3D11_CULL_FRONT)
	{
		return std::string();
	}

	return "rasteriser culling front test failed\n";
}
