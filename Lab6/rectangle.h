#pragma once
#include "shape.h"
#include "SDL.h"

class Rectangle : public Shape {
public:
	Rectangle(Point2d pos, uint8_t* colorAlpha, float width, float height);

	void set_angle(float angle);
	void offset(float x, float y);
	void render(SDL_Renderer* renderer);
private:
	float width, height;
	Point2d edges[4];

};

