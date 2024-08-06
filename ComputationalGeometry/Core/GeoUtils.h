#pragma once
#include "./Primitives/Point.h"

namespace jmk
{
	double areaTriangle2D(const Point2d& a, const Point2d& b, const Point2d& c);
	RELATIVE_POSITION orientation2d(const Point2d& a, const Point2d& b, const Point2d& c);
};

