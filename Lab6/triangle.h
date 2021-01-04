#pragma once
#include "point2d.h"
#include "shape.h"

class Triangle : public Shape {
public:

	Triangle(Point2d pos, unsigned int* colorAlpha, float base, float height);

	void render();
private:
	float base, height;
};

