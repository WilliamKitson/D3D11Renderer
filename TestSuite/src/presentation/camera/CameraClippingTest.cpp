#include "CameraClippingTest.h"

CameraClippingTest::CameraClippingTest()
{
}

CameraClippingTest::~CameraClippingTest()
{
}

std::string CameraClippingTest::test()
{
	if (!D3D11Renderer::Camera().clipping)
	{
		return std::string();
	}

	return "camera clipping test failed\n";
}
