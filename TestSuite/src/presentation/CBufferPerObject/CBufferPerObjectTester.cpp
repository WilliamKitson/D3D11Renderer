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

	return output;
}

std::string CBufferPerObjectTester::testTransfrom()
{
	return CBufferPerObjectTransformTest().test();
}
