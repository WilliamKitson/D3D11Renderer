#include "ImplimentationResolutionDefaultTest.h"

ImplimentationResolutionDefaultTest::ImplimentationResolutionDefaultTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"implimentation resolution default test" }, window(), result(), unit{ new D3D11Renderer::Implimentation }
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
}

ImplimentationResolutionDefaultTest::~ImplimentationResolutionDefaultTest()
{
	cleanup();
	DestroyWindow(window);
}

std::string ImplimentationResolutionDefaultTest::test()
{
	if (FAILED(result))
	{
		return "implimentation resolution default test failed to initialise\n";
	}

	unit->initialise(window, "assets/shaders/shaders.hlsl");

	if (successful(texture()))
	{
		return std::string();
	}

	return "implimentation resolution default test failed\n";
}

LRESULT ImplimentationResolutionDefaultTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void ImplimentationResolutionDefaultTest::cleanup()
{
	delete unit;
	unit = nullptr;
}

void ImplimentationResolutionDefaultTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void ImplimentationResolutionDefaultTest::initialiseWindowClass()
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

void ImplimentationResolutionDefaultTest::initialiseWindow()
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

D3D11_TEXTURE2D_DESC ImplimentationResolutionDefaultTest::texture()
{
	ID3D11RenderTargetView* view = nullptr;

	unit->getContext()->OMGetRenderTargets(
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

bool ImplimentationResolutionDefaultTest::successful(D3D11_TEXTURE2D_DESC view)
{
	if (view.Width != 960)
	{
		return false;
	}

	if (view.Height != 540)
	{
		return false;
	}

	return true;
}
