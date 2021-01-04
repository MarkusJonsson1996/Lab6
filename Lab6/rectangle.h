#pragma once
#include "shape.h"

class Rectangle : public Shape {
public:
	Rectangle(Point2d pos, unsigned int* colorAlpha, float height, float width);

	void render();
private:
	float width, height;
};

