#include "RasteriserModeWireframeTest.h"

RasteriserModeWireframeTest::RasteriserModeWireframeTest()
{
}

RasteriserModeWireframeTest::~RasteriserModeWireframeTest()
{
}

std::string RasteriserModeWireframeTest::test()
{
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	CD3D11_RASTERIZER_DESC description;

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
	unit.initialise(device);
	unit.bind(context);

	ID3D11RasterizerState* state;
	context->RSGetState(&state);

	if (!state)
	{
		return "rasteriser mode wireframe test desciption failed to initialise\n";
	}

	state->GetDesc(&description);

	if (description.FillMode == D3D11_FILL_WIREFRAME)
	{
		return std::string();
	}

	return "rasteriser mode wireframe test failed\n";
}
