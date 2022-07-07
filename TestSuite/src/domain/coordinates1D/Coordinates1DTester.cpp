#include "Coordinates1DTester.h"

Coordinates1DTester::Coordinates1DTester()
{
}

Coordinates1DTester::~Coordinates1DTester()
{
}

std::string Coordinates1DTester::test()
{
	std::string output{ "" };

	output += testCount();
	output += testIndex();

	return output;
}

std::string Coordinates1DTester::testCount()
{
	return Coordinates1DCountTester().test();
}

std::string Coordinates1DTester::testIndex()
{
	return Coordinates1DIndexTester().test();
}
