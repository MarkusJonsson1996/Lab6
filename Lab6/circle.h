#pragma once
#include "shape.h"
class Circle : public Shape {
public:

	Circle(Point2d, uint8_t*, float rad);

	float get_rad();
	
	Point2d set_pos(float x, float y);

private:
	float rad;
};

