#include "CameraPosTester.h"

CameraPosTester::CameraPosTester()
{
}

CameraPosTester::~CameraPosTester()
{
}

std::string CameraPosTester::test()
{
	std::string output{ "" };

	output += testXpos();
	output += testYpos();
	output += testZpos();

	return output;
}

std::string CameraPosTester::testXpos()
{
	return CameraXposTest().test();
}

std::string CameraPosTester::testYpos()
{
	return CameraYposTest().test();
}

std::string CameraPosTester::testZpos()
{
	return CameraZposTest().test();
}
