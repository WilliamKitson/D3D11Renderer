#include "CameraYrotTest.h"

CameraYrotTest::CameraYrotTest()
{
}

CameraYrotTest::~CameraYrotTest()
{
}

std::string CameraYrotTest::test()
{
	if (!D3D11Renderer::Camera().yrot)
	{
		return std::string();
	}

	return "camera yrot test failed\n";
}
