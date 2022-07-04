#include "CameraRotTester.h"

CameraRotTester::CameraRotTester()
{
}

CameraRotTester::~CameraRotTester()
{
}

std::string CameraRotTester::test()
{
	std::string output{ "" };

	output += testX();

	return output;
}

std::string CameraRotTester::testX()
{
	return CameraXrotTest().test();
}
