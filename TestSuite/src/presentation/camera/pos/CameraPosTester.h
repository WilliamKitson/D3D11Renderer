#pragma once

#include <string>

#include "CameraXposTest.h"
#include "CameraYposTest.h"
#include "CameraZposTest.h"

class CameraPosTester
{
public:
	CameraPosTester();
	~CameraPosTester();

	std::string test();

private:
	std::string testXpos();
	std::string testYpos();
	std::string testZpos();
};
