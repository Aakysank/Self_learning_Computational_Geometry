#include "GeoUtils.h"

double jmk::areaTriangle2D(const Point2d& a, const Point2d& b, const Point2d& c)
{
	Point2d AB = b - a;
	Point2d AC = c - a;

	return 0.5 * crossProduct2D(AB, AC);
}

RELATIVE_POSITION jmk::orientation2d(const Point2d& a, const Point2d& b, const Point2d& c)
{
	auto area = areaTriangle2D(a, b, c);
	if (area > 0.0 && area < TOL)
		area = 0.0;

	if (area < 0.0 && area > TOL)
		area = 0.0;

	if (area > 0.0)
		return RELATIVE_POSITION::LEFT;

	if (area < 0.0)
		return RELATIVE_POSITION::RIGHT;

	auto AB = b - a;
	auto AC = c - a;

	if ((AB[X] * AC[X]) < 0.0 || (AB[Y] * AC[Y]) < 0.0)
		return RELATIVE_POSITION::BEHIND;

	if (a == c)
		return RELATIVE_POSITION::ORIGIN;

	if (a == b)
		return RELATIVE_POSITION::DESTINATION;

	return RELATIVE_POSITION::BETWEEN;
}