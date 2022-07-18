#include "ImplimentationSyncNoneTest.h"

ImplimentationSyncNoneTest::ImplimentationSyncNoneTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"implimentation sync none test" }, window(), result(), unit{ new D3D11Renderer::Implimentation }
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

ImplimentationSyncNoneTest::~ImplimentationSyncNoneTest()
{
	if (unit)
	{
		delete unit;
	}

	DestroyWindow(window);
}

std::string ImplimentationSyncNoneTest::test()
{
	if (FAILED(result))
	{
		return "implimentation sync none test failed to initialise\n";
	}

	unit->initialise(window, "assets/shaders/shaders.hlsl");
	unit->syncFull();
	unit->syncNone();

	if (framerate() > 144)
	{
		return std::string();
	}

	return "implimentation sync none test failed\n";
}

LRESULT CALLBACK ImplimentationSyncNoneTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void ImplimentationSyncNoneTest::initialiseWindowClass()
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

void ImplimentationSyncNoneTest::initialiseWindow()
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

int ImplimentationSyncNoneTest::framerate()
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
