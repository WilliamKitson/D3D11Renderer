#include "SwapchainResolutionDepthTest.h"

SwapchainResolutionDepthTest::SwapchainResolutionDepthTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"swapchain resolution depth test" }, window(), device{ nullptr }, context{ nullptr }, result()
{
	initialiseWindowClass();

	if (FAILED(result))
	{
		return;
	}

	initialiseWindow();

	if (FAILED(result))
	{
		return;
	}

	initialiseD3D11();
}

SwapchainResolutionDepthTest::~SwapchainResolutionDepthTest()
{
	cleanup(context);
	cleanup(device);
	DestroyWindow(window);
}

std::string SwapchainResolutionDepthTest::test()
{
	if (FAILED(result))
	{
		return "swapchain resolution view test failed to initialise\n";
	}

	D3D11Renderer::Swapchain unit;
	unit.initialise(device, window);
	unit.bind(context);

	int resolution[2]{
		2000,
		1000
	};

	unit.setResolution(resolution);
	unit.initialise(device, window);
	unit.bind(context);

	D3D11_TEXTURE2D_DESC output = texture();

	bool success = true;

	if (output.Width != resolution[0])
	{
		success = false;
	}

	if (output.Height != resolution[1])
	{
		success = false;
	}

	if (success)
	{
		return std::string();
	}

	return "swapchain resolution depth test failed\n";
}

LRESULT CALLBACK SwapchainResolutionDepthTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void SwapchainResolutionDepthTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void SwapchainResolutionDepthTest::initialiseWindowClass()
{
	WNDCLASS windowClass = WNDCLASS();
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.lpszClassName = tag.c_str();

	if (!RegisterClass(&windowClass))
	{
		result = E_FAIL;
		return;
	}

	result = S_OK;
}

void SwapchainResolutionDepthTest::initialiseWindow()
{
	window = CreateWindow(
		tag.c_str(),
		tag.c_str(),
		WS_OVERLAPPEDWINDOW,
		100,
		100,
		960,
		540,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!window)
	{
		result = E_FAIL;
		return;
	}

	ShowWindow(
		window,
		nCmdShow
	);

	result = S_OK;
}

void SwapchainResolutionDepthTest::initialiseD3D11()
{
	D3D_FEATURE_LEVEL levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	D3D_FEATURE_LEVEL supported;

	result = D3D11CreateDevice(
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

D3D11_TEXTURE2D_DESC SwapchainResolutionDepthTest::texture()
{
	ID3D11DepthStencilView* depth = nullptr;

	context->OMGetRenderTargets(
		1,
		nullptr,
		&depth
	);

	if (!depth)
	{
		return D3D11_TEXTURE2D_DESC();
	}

	ID3D11Texture2D* backBuffer = nullptr;
	depth->GetResource(reinterpret_cast<ID3D11Resource**>(&backBuffer));
	cleanup(depth);

	D3D11_TEXTURE2D_DESC output;
	backBuffer->GetDesc(&output);
	cleanup(backBuffer);

	return output;
}
