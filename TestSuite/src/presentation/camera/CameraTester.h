#pragma once

#include <string>

#include "CameraXposTest.h"
#include "CameraYposTest.h"
#include "CameraZposTest.h"
#include "CameraFrustumTest.h"

class CameraTester
{
public:
	CameraTester();
	~CameraTester();

	std::string test();

private:
	std::string testXpos();
	std::string testYpos();
	std::string testZpos();
	std::string testFrustum();
};
