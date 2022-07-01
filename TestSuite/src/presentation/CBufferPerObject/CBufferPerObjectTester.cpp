#include "CBufferPerObjectTester.h"

CBufferPerObjectTester::CBufferPerObjectTester()
{
}

CBufferPerObjectTester::~CBufferPerObjectTester()
{
}

std::string CBufferPerObjectTester::test()
{
	std::string output{ "" };

	output += testTransfrom();
	output += testColour();

	return output;
}

std::string CBufferPerObjectTester::testTransfrom()
{
	return CBufferPerObjectTransformTest().test();
}

std::string CBufferPerObjectTester::testColour()
{
	return CBufferPerObjectColourTest().test();
}
