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
	initialiseWindowClass();

	if (FAILED(result))
	{
		return "swapchain default depth test window class failed to initialise\n";
	}

	initialiseWindow();

	if (FAILED(result))
	{
		return "swapchain default depth test window failed to initialise\n";
	}

	initialiseD3D11();

	if (FAILED(result))
	{
		return "swapchain default depth test d3d11 failed to initialise\n";
	}

	D3D11Renderer::Swapchain unit;

	unit.initialise(device, window);
	unit.bind(context);

	if (success(texture()))
	{
		return std::string();
	}

	return "swapchain default depth test failed\n";
}

LRESULT CALLBACK SwapchainDefaultDepthTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void SwapchainDefaultDepthTest::initialiseWindowClass()
{
	WNDCLASS windowClass = WNDCLASS();
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.lpszClassName = tag.c_str();

	if (!RegisterClass(&windowClass))
	{
		result = E_FAIL;
	}

	result = S_OK;
}

void SwapchainDefaultDepthTest::initialiseWindow()
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
}

void SwapchainDefaultDepthTest::initialiseD3D11()
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

D3D11_TEXTURE2D_DESC SwapchainDefaultDepthTest::texture()
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
	depth->Release();
	depth = nullptr;

	D3D11_TEXTURE2D_DESC output;
	backBuffer->GetDesc(&output);
	backBuffer->Release();
	backBuffer = nullptr;

	return output;
}

bool SwapchainDefaultDepthTest::success(D3D11_TEXTURE2D_DESC input)
{
	if (input.Width != 960)
	{
		return false;
	}

	if (input.Height != 540)
	{
		return false;
	}

	if (input.MipLevels != 1)
	{
		return false;
	}

	if (input.ArraySize != 1)
	{
		return false;
	}

	if (input.Format != DXGI_FORMAT_D24_UNORM_S8_UINT)
	{
		return false;
	}

	if (input.SampleDesc.Count != 1)
	{
		return false;
	}

	if (input.SampleDesc.Quality != 0)
	{
		return false;
	}

	if (input.Usage != D3D11_USAGE_DEFAULT)
	{
		return false;
	}

	if (input.BindFlags != 64)
	{
		return false;
	}

	if (input.CPUAccessFlags != 0)
	{
		return false;
	}

	if (input.MiscFlags != 0)
	{
		return false;
	}

	return true;
}
