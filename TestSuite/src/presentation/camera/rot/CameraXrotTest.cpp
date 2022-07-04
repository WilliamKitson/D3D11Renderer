#include "CameraXrotTest.h"

CameraXrotTest::CameraXrotTest()
{
}

CameraXrotTest::~CameraXrotTest()
{
}

std::string CameraXrotTest::test()
{
	if (!D3D11Renderer::Camera().xrot)
	{
		return std::string();
	}

	return "camera xrot test failed\n";
}
