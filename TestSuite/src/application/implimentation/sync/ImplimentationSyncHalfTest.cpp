#include "ImplimentationSyncHalfTest.h"

ImplimentationSyncHalfTest::ImplimentationSyncHalfTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"implimentation sync half test" }, window(), result(), unit{ new D3D11Renderer::Implimentation }
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

ImplimentationSyncHalfTest::~ImplimentationSyncHalfTest()
{
	cleanup();
	DestroyWindow(window);
}

std::string ImplimentationSyncHalfTest::test()
{
	if (FAILED(result))
	{
		return "implimentation sync half test failed to initialise\n";
	}

	unit->initialise(window, "assets/shaders/shaders.hlsl");
	unit->syncHalf();

	if (framerate() < 80)
	{
		return std::string();
	}

	return "implimentation sync half test failed\n";
}

void ImplimentationSyncHalfTest::cleanup()
{
	delete unit;
	unit = nullptr;
}

LRESULT CALLBACK ImplimentationSyncHalfTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void ImplimentationSyncHalfTest::initialiseWindowClass()
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

void ImplimentationSyncHalfTest::initialiseWindow()
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

int ImplimentationSyncHalfTest::framerate()
{
	int output = 0;
	double elapced = 0.0f;
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	while (elapced < 1.0f)
	{
		unit->update();

		elapced += (float)std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		output++;
	}

	return output - 1;
}
