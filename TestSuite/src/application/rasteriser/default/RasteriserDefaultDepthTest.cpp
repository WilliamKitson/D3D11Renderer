#include "RasteriserDefaultDepthTest.h"

RasteriserDefaultDepthTest::RasteriserDefaultDepthTest()
	: device{ nullptr }, context{ nullptr }, description()
{
}

RasteriserDefaultDepthTest::~RasteriserDefaultDepthTest()
{
}

std::string RasteriserDefaultDepthTest::test()
{
	D3D_FEATURE_LEVEL levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	D3D_FEATURE_LEVEL supported;

	HRESULT output = D3D11CreateDevice(
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

	unit.apply(device);
	unit.bind(context);

	ID3D11RasterizerState* state;
	context->RSGetState(&state);

	if (!state)
	{
		return "rasteriser default depth test description failed to initialise\n";
	}

	state->GetDesc(&description);

	if (description.DepthClipEnable)
	{
		return std::string();
	}

	return "rasteriser default depth test failed\n";
}
