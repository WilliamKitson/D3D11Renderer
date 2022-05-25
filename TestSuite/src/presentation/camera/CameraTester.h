#pragma once

#include <string>
#include "CameraXposTest.h"

class CameraTester
{
public:
	CameraTester();
	~CameraTester();

	std::string test();

private:
	std::string testXpos();
};
