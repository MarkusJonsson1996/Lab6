#pragma once
#include "point2d.h"
#include "shape.h"

class Triangle : public Shape {
public:

	Triangle(Point2d pos, uint8_t* colorAlpha, float base, float height);

	//void render(SDL_Renderer* renderer);
private:
	float base, height;
};

