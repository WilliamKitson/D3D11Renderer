#include "ImplimentationSyncFullTest.h"

ImplimentationSyncFullTest::ImplimentationSyncFullTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"implimentation sync full test" }, window(), result(), unit{ new D3D11Renderer::Implimentation }
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

ImplimentationSyncFullTest::~ImplimentationSyncFullTest()
{
	if (unit)
	{
		delete unit;
	}

	DestroyWindow(window);
}

std::string ImplimentationSyncFullTest::test()
{
	if (FAILED(result))
	{
		return "implimentation sync full test failed to initialise\n";
	}

	unit->initialise(window, "assets/shaders/shaders.hlsl");
	unit->syncFull();

	if (framerate() < 150)
	{
		return std::string();
	}

	return "implimentation sync full test failed\n";
}

LRESULT CALLBACK ImplimentationSyncFullTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void ImplimentationSyncFullTest::initialiseWindowClass()
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

void ImplimentationSyncFullTest::initialiseWindow()
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

int ImplimentationSyncFullTest::framerate()
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
