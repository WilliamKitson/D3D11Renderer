#include "Resolution.h"

windowsPlatform::Resolution::Resolution()
	: resolution()
{
	setResolution(0, 0);
}

windowsPlatform::Resolution::~Resolution()
{
}

int windowsPlatform::Resolution::getWidth()
{
	return resolution[0];
}

int windowsPlatform::Resolution::getHeight()
{
	return resolution[1];
}

void windowsPlatform::Resolution::setResolution(int width, int height)
{
	resolution[0] = validateMinimum(960, width);
	resolution[1] = validateMinimum(540, height);
}

int windowsPlatform::Resolution::validateMinimum(int minimum, int value)
{
	if (value < minimum)
	{
		return minimum;
	}

	return value;
}
