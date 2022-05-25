#include "RasteriserDefaultModeTest.h"

RasteriserDefaultModeTest::RasteriserDefaultModeTest()
{
}

RasteriserDefaultModeTest::~RasteriserDefaultModeTest()
{
}

std::string RasteriserDefaultModeTest::test()
{
	ID3D11Device* device;
	ID3D11DeviceContext* context;

	D3D_FEATURE_LEVEL levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	D3D_FEATURE_LEVEL supported;

	HRESULT hResult = D3D11CreateDevice(
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

	if (FAILED(hResult))
	{
		return "rasteriser default mode test device failed to initialise\n";
	}

	D3D11Renderer::Rasteriser unit;

	unit.initialise(device);
	unit.bind(context);

	ID3D11RasterizerState* state;
	context->RSGetState(&state);

	if (!state)
	{
		return "rasteriser default mode test failed to retrieve state\n";
	}

	CD3D11_RASTERIZER_DESC description;
	state->GetDesc(&description);

	if (description.FillMode == D3D11_FILL_SOLID)
	{
		return std::string();
	}

	return "rasteriser default mode test failed\n";
}
