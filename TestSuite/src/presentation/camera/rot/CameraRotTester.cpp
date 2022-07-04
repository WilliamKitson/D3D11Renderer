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
	output += testY();
	output += testZ();

	return output;
}

std::string CameraRotTester::testX()
{
	return CameraXrotTest().test();
}

std::string CameraRotTester::testY()
{
	return CameraYrotTest().test();
}

std::string CameraRotTester::testZ()
{
	return CameraZrotTest().test();
}
