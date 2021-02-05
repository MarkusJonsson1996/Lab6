#pragma once
//Standerd includes
#include <iostream>
#include <vector>
#include <map>
//Custom includes
#include "point2d.h"
#include "SDL.h"

using namespace std;

class Shape {
public:
	Shape();
	Shape(Point2d pos, uint8_t* colorAlpha);
	
	string get_string_pos();
	Point2d* get_pos();
	vector<Point2d>* get_edges();
	float get_angle();
	Point2d* get_vel();
	uint8_t get_color_alpha(uint8_t i);

	virtual Point2d set_pos(float x, float y);
	float set_angle(float newAngle);
	Point2d set_vel(float x, float y);

	void offset(float x, float y);

	virtual void render(SDL_Renderer* renderer);

private:
	Point2d pos;
	Point2d vel;
	vector<Point2d> edges;
	uint8_t colorAlpha[4];
	float angle;
};