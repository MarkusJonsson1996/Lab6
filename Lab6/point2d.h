#pragma once

#include <math.h>
#include <string>
#include "SDL.h"

using namespace std;

#define AXIS_X  1
#define AXIS_Y  2

class Point2d {
public:
	Point2d();
	Point2d(float newX, float newY);
	Point2d(const Point2d &cpy);

	Point2d operator+(const Point2d& otherPoint);
	Point2d& operator=(const Point2d& otherPoint);
	bool operator==(const Point2d& otherPoint);
	bool operator!=(const Point2d& otherPoint);

	float get_x();
	float get_y();
	float set_x(float x);
	float set_y(float y);

	void rotate(Point2d* rotPoint, float angle);
	double len_to(const Point2d& thisPoint, int axis = 0);
	double angle(const Point2d& thisPoint);
	string to_string();

private:
	float x, y;
};