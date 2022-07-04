#pragma once

#include <string>

#include "pos/CameraPosTester.h"
#include "CameraFrustumTest.h"
#include "CameraClippingTest.h"

class CameraTester
{
public:
	CameraTester();
	~CameraTester();

	std::string test();

private:
	std::string testPos();
	std::string testFrustum();
	std::string testClipping();
};
