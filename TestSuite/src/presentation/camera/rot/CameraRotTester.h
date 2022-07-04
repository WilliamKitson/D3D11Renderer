#pragma once

#include <string>

#include "CameraXrotTest.h"
#include "CameraYrotTest.h"

class CameraRotTester
{
public:
	CameraRotTester();
	~CameraRotTester();

	std::string test();

private:
	std::string testX();
	std::string testY();
};
