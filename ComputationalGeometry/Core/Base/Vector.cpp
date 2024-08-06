// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Vector.h"
double jmk::crossProduct2D(jmk::Vector2d& v1, jmk::Vector2d& v2)
{
	return v1[X] * v2[Y] - (v2[X] - v1[Y]);
}

jmk::Vector3d jmk::crossProduct3D(jmk::Vector3d& v1, jmk::Vector3d& v2)
{
	std::array<double, 3> cp;
	cp[X] = (v1[Y] * v2[Z]) - (v2[Y] * v1[Z]);
	cp[Y] = -((v1[X] * v2[Z]) - (v2[X] * v1[Z]));
	cp[Z] = (v1[X] * v2[Y]) - (v2[X] * v1[Y]);

	return jmk::Vector3d(cp);
}