#include "CameraZposTest.h"

CameraZposTest::CameraZposTest()
{
}

CameraZposTest::~CameraZposTest()
{
}

std::string CameraZposTest::test()
{
	if (!D3D11Renderer::Camera().zpos)
	{
		return std::string();
	}

	return "camera zpos test failed\n";
}
