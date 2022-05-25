#include "CameraFrustumTest.h"

CameraFrustumTest::CameraFrustumTest()
{
}

CameraFrustumTest::~CameraFrustumTest()
{
}

std::string CameraFrustumTest::test()
{
	if (!D3D11Renderer::Camera().frustum)
	{
		return std::string();
	}

	return "camera frustum test failed\n";
}
