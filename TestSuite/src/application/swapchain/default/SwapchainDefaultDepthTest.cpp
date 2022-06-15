#include "SwapchainDefaultDepthTest.h"

SwapchainDefaultDepthTest::SwapchainDefaultDepthTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"swapchain default depth test" }, window(), device{ nullptr }, context{ nullptr }, result()
{
}

SwapchainDefaultDepthTest::~SwapchainDefaultDepthTest()
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

	DestroyWindow(window);
}

std::string SwapchainDefaultDepthTest::test()
{
	initialiseWindow();

	if (FAILED(result))
	{
		return "swapchain default depth test window failed to initialise\n";
	}

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

	D3D11Renderer::Swapchain unit;

	unit.initialise(device, window);
	unit.bind(context);

	ID3D11DepthStencilView* depth = nullptr;

	context->OMGetRenderTargets(
		1,
		nullptr,
		&depth
	);

	if (!depth)
	{
		return "swapchain default depth test depth failed to initialise\n";
	}

	ID3D11Texture2D* backBuffer = nullptr;
	depth->GetResource(reinterpret_cast<ID3D11Resource**>(&backBuffer));
	depth->Release();
	depth = nullptr;

	D3D11_TEXTURE2D_DESC texture;
	backBuffer->GetDesc(&texture);
	backBuffer->Release();
	backBuffer = nullptr;

	bool success = true;

	if (texture.Width != 960)
	{
		success = false;
	}

	if (texture.Height != 540)
	{
		success = false;
	}

	if (texture.MipLevels != 1)
	{
		success = false;
	}

	if (texture.ArraySize != 1)
	{
		success = false;
	}

	if (texture.Format != DXGI_FORMAT_D24_UNORM_S8_UINT)
	{
		success = false;
	}

	if (texture.SampleDesc.Count != 1)
	{
		success = false;
	}

	if (texture.SampleDesc.Quality != 0)
	{
		success = false;
	}

	if (texture.Usage != D3D11_USAGE_DEFAULT)
	{
		success = false;
	}

	if (texture.BindFlags != 64)
	{
		success = false;
	}

	if (texture.CPUAccessFlags != 0)
	{
		success = false;
	}

	if (texture.MiscFlags != 0)
	{
		success = false;
	}

	if (success)
	{
		return std::string();
	}

	return "swapchain default depth test failed\n";
}

LRESULT CALLBACK SwapchainDefaultDepthTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void SwapchainDefaultDepthTest::initialiseWindow()
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
}
