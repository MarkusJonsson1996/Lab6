#pragma once
#include <iostream>
#include "point2d.h"

using namespace std;

class Shape {
public:
	Shape(Point2d pos, unsigned int* colorAlpha);
	
	string get_pos();

	virtual void render();

private:
	Point2d pos;
	unsigned int colorAlpha[4];
};