#include "OutputHeightTest.h"

OutputHeightTest::OutputHeightTest()
{
}

OutputHeightTest::~OutputHeightTest()
{
}

std::string OutputHeightTest::test()
{
	if (!D3D11Renderer::Output().height)
	{
		return std::string();
	}

	return "output height test failed\n";
}
