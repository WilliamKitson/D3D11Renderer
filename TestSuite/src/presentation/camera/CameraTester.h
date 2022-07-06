#pragma once

#include <string>

#include "pos/CameraPosTester.h"
#include "rot/CameraRotTester.h"
#include "CameraFrustumTest.h"
#include "CameraAspectRatioTest.h"

class CameraTester
{
public:
	CameraTester();
	~CameraTester();

	std::string test();

private:
	std::string testPos();
	std::string testRot();
	std::string testFrustum();
	std::string testAspectRatio();
};
