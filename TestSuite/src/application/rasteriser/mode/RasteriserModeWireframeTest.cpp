#include "RasteriserModeWireframeTest.h"

RasteriserModeWireframeTest::RasteriserModeWireframeTest()
	: device{ nullptr }, context{ nullptr }, description()
{
}

RasteriserModeWireframeTest::~RasteriserModeWireframeTest()
{
}

std::string RasteriserModeWireframeTest::test()
{
	if (FAILED(initialise()))
	{
		return "rasteriser mode wireframe test failed to initialise\n";
	}

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

HRESULT RasteriserModeWireframeTest::initialise()
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
