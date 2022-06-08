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
	if (FAILED(initialise()))
	{
		return "rasteriser default depth test failed to initialise\n";
	}

	D3D11Renderer::Rasteriser unit;

	unit.apply(device);
	unit.bind(context);

	if (FAILED(getDescription()))
	{
		return "rasteriser default depth test description failed to initialise\n";
	}

	if (description.DepthClipEnable)
	{
		return std::string();
	}

	return "rasteriser default depth test failed\n";
}

HRESULT RasteriserDefaultDepthTest::initialise()
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

	return output;
}

HRESULT RasteriserDefaultDepthTest::getDescription()
{
	ID3D11RasterizerState* state;
	context->RSGetState(&state);

	if (!state)
	{
		return E_FAIL;
	}

	state->GetDesc(&description);
	return S_OK;
}
