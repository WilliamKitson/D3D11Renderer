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
	initialiseSwapchain(input1);
	initialiseShaders(input2);
	initialiseRasteriser();
	initialiseSampler();
	initialiseScene();
	initialiseObject();
}

void D3D11Renderer::Implimentation::update()
{
	swapchain.update(context);
}

void D3D11Renderer::Implimentation::overlap()
{
	swapchain.overlap(context);
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

void D3D11Renderer::Implimentation::sceneCamera(Camera input)
{
	float camera[] = {
		input.xpos,
		input.ypos,
		input.zpos,
		input.xrot,
		input.yrot,
		input.zrot,
		input.frustum,
		input.aspectRatio
	};

	scene.setCamera(camera);
	scene.apply(context);
}

void D3D11Renderer::Implimentation::sceneAmbience(RGBA input)
{
	float ambience[] = {
		input.red,
		input.green,
		input.blue,
		input.alpha
	};

	scene.setAmbience(ambience);
	scene.apply(context);
}

void D3D11Renderer::Implimentation::objectTransform(Transform input)
{
	float transform[] = {
		input.xpos,
		input.ypos,
		input.zpos,
		input.xrot,
		input.yrot,
		input.zrot,
		input.xscale,
		input.yscale,
		input.zscale
	};

	object.setTransform(transform);
	object.apply(context);
}

void D3D11Renderer::Implimentation::objectColour(RGBA input)
{
	float colour[] = {
		input.red,
		input.green,
		input.blue,
		input.alpha
	};

	object.setColour(colour);
	object.apply(context);
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

void D3D11Renderer::Implimentation::initialiseSwapchain(HWND input)
{
	swapchain.initialise(device, input);
	swapchain.bind(context);
}

void D3D11Renderer::Implimentation::initialiseShaders(std::string input)
{
	shaders.setFilepath(input);
	shaders.initialise(device);
	shaders.bind(context);
}

void D3D11Renderer::Implimentation::initialiseRasteriser()
{
	rasteriser.initialise(device);
	rasteriser.bind(context);
}

void D3D11Renderer::Implimentation::initialiseSampler()
{
	sampler.initialise(device);
	sampler.bind(context);
}

void D3D11Renderer::Implimentation::initialiseScene()
{
	scene.initialise(device);
	scene.bind(context);
}

void D3D11Renderer::Implimentation::initialiseObject()
{
	object.initialise(device);
	object.bind(context);
}
