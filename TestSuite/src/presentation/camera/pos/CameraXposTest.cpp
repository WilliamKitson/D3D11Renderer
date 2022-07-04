#include "CameraXposTest.h"

CameraXposTest::CameraXposTest()
{
}

CameraXposTest::~CameraXposTest()
{
}

std::string CameraXposTest::test()
{
	if (!D3D11Renderer::Camera().xpos)
	{
		return std::string();
	}

	return "camera xpos test failed\n";
}
