#include "ImplimentationDeviceTest.h"

ImplimentationDeviceTest::ImplimentationDeviceTest()
	: unit{ new D3D11Renderer::Implimentation }
{
}

ImplimentationDeviceTest::~ImplimentationDeviceTest()
{
	cleanup();
}

std::string ImplimentationDeviceTest::test()
{
	unit->initialise(HWND(), "");

	if (unit->getDevice())
	{
		return std::string();
	}

	return "implimentation device test failed\n";
}

void ImplimentationDeviceTest::cleanup()
{
	delete unit;
	unit = nullptr;
}
