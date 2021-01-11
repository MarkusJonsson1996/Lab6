#pragma once
#include <iostream>
#include "point2d.h"
#include "SDL.h"

using namespace std;

class Shape {
public:
	Shape();
	Shape(Point2d pos, uint8_t* colorAlpha);
	
	string get_string_pos();
	Point2d* get_pos();
	float get_angle();
	float set_angle(float newAngle);
	uint8_t get_color_alpha(uint8_t i);


	virtual void render(SDL_Renderer* renderer);

private:
	Point2d pos;
	uint8_t colorAlpha[4];
	float angle;
};