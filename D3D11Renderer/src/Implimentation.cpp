#include "Implimentation.h"

D3D11Renderer::Implimentation::Implimentation()
	: Facade(), device{ nullptr }, context{ nullptr }, swapchain(), shaders(), rasteriser(), sampler(), scene(), object()
{
}

D3D11Renderer::Implimentation::~Implimentation()
{
	cleanup(context);
	cleanup(device);
}

void D3D11Renderer::Implimentation::initialise(HWND input1, std::string input2)
{
	initialiseDevice();

	swapchain.initialise(device, input1);
	swapchain.bind(context);

	shaders.setFilepath(input2);
	shaders.initialise(device);
	shaders.bind(context);

	rasteriser.initialise(device);
	rasteriser.bind(context);

	sampler.initialise(device);
	sampler.bind(context);

	scene.initialise(device);
	scene.bind(context);

	object.initialise(device);
	object.bind(context);
}

void D3D11Renderer::Implimentation::update()
{
	swapchain.update(context);
}

void D3D11Renderer::Implimentation::outputResolution(Output input1, HWND input2)
{
	int resolution[] = {
		input1.width,
		input1.height
	};

	swapchain.setResolution(resolution);
	swapchain.initialise(device, input2);
	swapchain.bind(context);
}

void D3D11Renderer::Implimentation::syncFull()
{
	swapchain.setFull();
}

void D3D11Renderer::Implimentation::syncHalf()
{
	swapchain.setHalf();
}

void D3D11Renderer::Implimentation::syncQuater()
{
	swapchain.setQuater();
}

void D3D11Renderer::Implimentation::syncNone()
{
	swapchain.setNone();
}

void D3D11Renderer::Implimentation::drawWireframe()
{
	rasteriser.setWireframe();
	rasteriser.initialise(device);
	rasteriser.bind(context);
}

void D3D11Renderer::Implimentation::drawSolid()
{
	rasteriser.setSolid();
	rasteriser.initialise(device);
	rasteriser.bind(context);
}

void D3D11Renderer::Implimentation::cullNone()
{
	rasteriser.setNone();
	rasteriser.initialise(device);
	rasteriser.bind(context);
}

void D3D11Renderer::Implimentation::cullFront()
{
	rasteriser.setFront();
	rasteriser.initialise(device);
	rasteriser.bind(context);
}

void D3D11Renderer::Implimentation::cullBack()
{
	rasteriser.setBack();
	rasteriser.initialise(device);
	rasteriser.bind(context);
}

ID3D11Device* D3D11Renderer::Implimentation::getDevice()
{
	return device;
}

ID3D11DeviceContext* D3D11Renderer::Implimentation::getContext()
{
	return context;
}

void D3D11Renderer::Implimentation::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void D3D11Renderer::Implimentation::initialiseDevice()
{
	D3D_FEATURE_LEVEL levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	D3D_FEATURE_LEVEL supported;

	D3D11CreateDevice(
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
