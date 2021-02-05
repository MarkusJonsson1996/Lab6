#include "triangle.h"

Triangle::Triangle(Point2d pos, uint8_t* colorAlpha, float base, float height) : Shape(pos, colorAlpha), base(base), height(height) {
	this->get_edges()->resize(3);

	this->get_edges()->at(0).set_x(this->get_pos()->get_x() - (base / 2));
	this->get_edges()->at(0).set_y(this->get_pos()->get_y() + (height / 2));

	this->get_edges()->at(1).set_x(this->get_pos()->get_x());
	this->get_edges()->at(1).set_y(this->get_pos()->get_y() - (height / 2));

	this->get_edges()->at(2).set_x(this->get_pos()->get_x() + (base / 2));
	this->get_edges()->at(2).set_y(this->get_pos()->get_y() + (height / 2));
}

