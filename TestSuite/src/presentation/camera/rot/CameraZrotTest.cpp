#include "CameraZrotTest.h"

CameraZrotTest::CameraZrotTest()
{
}

CameraZrotTest::~CameraZrotTest()
{
}

std::string CameraZrotTest::test()
{
	if (!D3D11Renderer::Camera().zrot)
	{
		return std::string();
	}

	return "camera zrot test failed\n";
}
