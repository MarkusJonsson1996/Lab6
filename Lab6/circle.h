#pragma once
#include "shape.h"
class Circle : public Shape {
public:

	Circle(Point2d, uint8_t*, float rad);

	void render(SDL_Renderer* renderer);
private:
	float rad;
};

