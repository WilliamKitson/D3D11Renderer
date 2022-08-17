#include "ImplimentationResolutionReloadTest.h"

ImplimentationResolutionReloadTest::ImplimentationResolutionReloadTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"implimentation resolution reload test" }, window(), result(), unit{ new D3D11Renderer::Implimentation }
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

ImplimentationResolutionReloadTest::~ImplimentationResolutionReloadTest()
{
	cleanup();
	DestroyWindow(window);
}

std::string ImplimentationResolutionReloadTest::test()
{
	if (FAILED(result))
	{
		return "implimentation resolution reload test failed to initialise\n";
	}

	D3D11Renderer::Output output{
		1000,
		2000
	};

	unit->initialise(window, "assets/shaders/shaders.hlsl");
	unit->outputResolution(output, window);

	if (successful(texture(), output))
	{
		return std::string();
	}

	return "implimentation resolution reload test failed\n";
}

LRESULT ImplimentationResolutionReloadTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void ImplimentationResolutionReloadTest::cleanup()
{
	delete unit;
	unit = nullptr;
}

void ImplimentationResolutionReloadTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void ImplimentationResolutionReloadTest::initialiseWindowClass()
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

void ImplimentationResolutionReloadTest::initialiseWindow()
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

D3D11_TEXTURE2D_DESC ImplimentationResolutionReloadTest::texture()
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

bool ImplimentationResolutionReloadTest::successful(D3D11_TEXTURE2D_DESC view, D3D11Renderer::Output output)
{
	if (view.Width != output.width)
	{
		return false;
	}

	if (view.Height != output.height)
	{
		return false;
	}

	return true;
}
