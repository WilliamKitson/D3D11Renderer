#include "SwapchainResolutionViewTest.h"

SwapchainResolutionViewTest::SwapchainResolutionViewTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"swapchain resolution view test" }, window(), device{ nullptr }, context{ nullptr }, result()
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

SwapchainResolutionViewTest::~SwapchainResolutionViewTest()
{
	cleanup(context);
	cleanup(device);
	DestroyWindow(window);
}

std::string SwapchainResolutionViewTest::test()
{
	if (FAILED(result))
	{
		return "swapchain resolution view test failed to initialise\n";
	}

	D3D11Renderer::Swapchain unit;
	unit.initialise(device, window);
	unit.bind(context);

	int resolution[2]{
		1000,
		2000
	};

	unit.setResolution(resolution);
	unit.initialise(device, window);
	unit.bind(context);

	if (successful(texture(), resolution))
	{
		return std::string();
	}

	return "swapchain resolution view test failed\n";
}

LRESULT SwapchainResolutionViewTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void SwapchainResolutionViewTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void SwapchainResolutionViewTest::initialiseWindowClass()
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

void SwapchainResolutionViewTest::initialiseWindow()
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

		ShowWindow(
			window,
			nCmdShow
		);

		result = S_OK;
	}
}

void SwapchainResolutionViewTest::initialiseD3D11()
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

D3D11_TEXTURE2D_DESC SwapchainResolutionViewTest::texture()
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

bool SwapchainResolutionViewTest::successful(D3D11_TEXTURE2D_DESC view, int resolution[2])
{
	if (view.Width != resolution[0])
	{
		return false;
	}

	if (view.Height != resolution[1])
	{
		return false;
	}

	return true;
}
