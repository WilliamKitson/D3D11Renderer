#include "RasteriserDefaultModeTest.h"

RasteriserDefaultModeTest::RasteriserDefaultModeTest()
	: device{ nullptr }, context{ nullptr }, description()
{
}

RasteriserDefaultModeTest::~RasteriserDefaultModeTest()
{
	if (context)
	{
		context->Release();
		context = nullptr;
	}

	if (device)
	{
		device->Release();
		device = nullptr;
	}
}

std::string RasteriserDefaultModeTest::test()
{
	if (FAILED(initialise()))
	{
		return "rasteriser default mode test device failed to initialise\n";
	}

	D3D11Renderer::Rasteriser unit;

	unit.apply(device);
	unit.bind(context);

	if (FAILED(getDescription()))
	{
		return "rasteriser default mode test description failed to initialise\n";
	}

	if (description.FillMode == D3D11_FILL_SOLID)
	{
		return std::string();
	}

	return "rasteriser default mode test failed\n";
}

HRESULT RasteriserDefaultModeTest::initialise()
{
	D3D_FEATURE_LEVEL levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	D3D_FEATURE_LEVEL supported;

	HRESULT output = D3D11CreateDevice(
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

	return output;
}

HRESULT RasteriserDefaultModeTest::getDescription()
{
	ID3D11RasterizerState* state;
	context->RSGetState(&state);

	if (!state)
	{
		return E_FAIL;
	}

	state->GetDesc(&description);

	if (state)
	{
		state->Release();
		state = nullptr;
	}

	return S_OK;
}
