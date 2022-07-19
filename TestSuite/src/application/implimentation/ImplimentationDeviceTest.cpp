#include "ImplimentationDeviceTest.h"

ImplimentationDeviceTest::ImplimentationDeviceTest()
	: unit{ new D3D11Renderer::Implimentation }
{
}

ImplimentationDeviceTest::~ImplimentationDeviceTest()
{
	if (unit)
	{
		delete unit;
	}
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
