#include "OutputWidthTest.h"

OutputWidthTest::OutputWidthTest()
{
}

OutputWidthTest::~OutputWidthTest()
{
}

std::string OutputWidthTest::test()
{
	if (!D3D11Renderer::Output().width)
	{
		return std::string();
	}

	return "output width test failed\n";
}
