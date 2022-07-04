#pragma once

#include <string>
#include "CameraXrotTest.h"

class CameraRotTester
{
public:
	CameraRotTester();
	~CameraRotTester();

	std::string test();

private:
	std::string testX();
};
