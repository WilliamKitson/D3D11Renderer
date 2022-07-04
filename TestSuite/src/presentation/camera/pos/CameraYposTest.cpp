#include "CameraYposTest.h"

CameraYposTest::CameraYposTest()
{
}

CameraYposTest::~CameraYposTest()
{
}

std::string CameraYposTest::test()
{
	if (!D3D11Renderer::Camera().ypos)
	{
		return std::string();
	}

	return "camera ypos test failed\n";
}
