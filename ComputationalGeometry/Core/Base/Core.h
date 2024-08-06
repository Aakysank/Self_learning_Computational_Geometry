#pragma once
#include <math.h>
#define TOL 0.000001

enum class RELATIVE_POSITION
{
	LEFT,
	RIGHT,
	BEHIND,
	BEYOND,
	BETWEEN,
	ORIGIN,
	DESTINATION
};

bool isEqualD(double _x, double _y)
{
	if (fabs(_x - _y) <= TOL)
		return true;

	return false;
}