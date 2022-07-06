#include "CameraAspectRatioTest.h"

CameraAspectRatioTest::CameraAspectRatioTest()
{
}

CameraAspectRatioTest::~CameraAspectRatioTest()
{
}

std::string CameraAspectRatioTest::test()
{
	if (!D3D11Renderer::Camera().aspectRatio)
	{
		return std::string();
	}

	return "camera aspect ratio test failed\n";
}
