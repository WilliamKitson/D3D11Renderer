#include "SwapchainDefaultViewTest.h"

SwapchainDefaultViewTest::SwapchainDefaultViewTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"swapchain default view test" }, window(), device{ nullptr }, context{ nullptr }, result()
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

SwapchainDefaultViewTest::~SwapchainDefaultViewTest()
{
	cleanup(context);
	cleanup(device);
	DestroyWindow(window);
}

std::string SwapchainDefaultViewTest::test()
{
	if (FAILED(result))
	{
		return "swapchain default view test failed to initialise\n";
	}

	D3D11Renderer::Swapchain unit;

	unit.initialise(device, window);
	unit.bind(context);

	if (successful(texture()))
	{
		return std::string();
	}

	return "swapchain default view test failed\n";
}

LRESULT SwapchainDefaultViewTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void SwapchainDefaultViewTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
		input = nullptr;
	}
}

void SwapchainDefaultViewTest::initialiseWindowClass()
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

void SwapchainDefaultViewTest::initialiseWindow()
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

void SwapchainDefaultViewTest::initialiseD3D11()
{
	D3D_FEATURE_LEVEL levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	D3D_FEATURE_LEVEL supported;

	HRESULT success = D3D11CreateDevice(
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

	result = success;
}

D3D11_TEXTURE2D_DESC SwapchainDefaultViewTest::texture()
{
	ID3D11RenderTargetView* view = nullptr;

	context->OMGetRenderTargets(
		1,
		&view,
		nullptr
	);

	if (!view)
	{
		return D3D11_TEXTURE2D_DESC();
	}

	ID3D11Texture2D* backBuffer = nullptr;
	view->GetResource(reinterpret_cast<ID3D11Resource**>(&backBuffer));
	cleanup(view);

	D3D11_TEXTURE2D_DESC output;
	backBuffer->GetDesc(&output);
	cleanup(backBuffer);

	return output;
}

bool SwapchainDefaultViewTest::successful(D3D11_TEXTURE2D_DESC input)
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

	if (input.Format != DXGI_FORMAT_R8G8B8A8_UNORM)
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

	if (input.BindFlags != 32)
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
