#pragma once
#include "shape.h"
#include "SDL.h"

class Rectangle : public Shape {
public:
	Rectangle(Point2d pos, uint8_t* colorAlpha, float width, float height);

	float set_height(float height);
	float set_width(float width);

	float get_height();
	float get_width();
private:
	float width, height;

};

