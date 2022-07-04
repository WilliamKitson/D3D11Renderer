#pragma once

#include <string>

#include "CameraXrotTest.h"
#include "CameraYrotTest.h"
#include "CameraZrotTest.h"

class CameraRotTester
{
public:
	CameraRotTester();
	~CameraRotTester();

	std::string test();

private:
	std::string testX();
	std::string testY();
	std::string testZ();
};
