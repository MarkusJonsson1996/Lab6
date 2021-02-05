#include "rectangle.h"	

Rectangle::Rectangle(Point2d pos, uint8_t* colorAlpha, float width, float height): Shape (pos, colorAlpha), width(width), height(height) {
	/*this->edges[0].set_x(this->get_pos()->get_x() - (width / 2));
	this->edges[0].set_y(this->get_pos()->get_y() - (height / 2));

	this->edges[1].set_x(this->get_pos()->get_x() + (width / 2));
	this->edges[1].set_y(this->get_pos()->get_y() - (height / 2));

	this->edges[2].set_x(this->get_pos()->get_x() + (width / 2));
	this->edges[2].set_y(this->get_pos()->get_y() + (height / 2));

	this->edges[3].set_x(this->get_pos()->get_x() - (width / 2));
	this->edges[3].set_y(this->get_pos()->get_y() + (height / 2));*/

	this->get_edges()->resize(4);

	this->get_edges()->at(0).set_x(this->get_pos()->get_x() - (width / 2));
	this->get_edges()->at(0).set_y(this->get_pos()->get_y() - (height / 2));

	this->get_edges()->at(1).set_x(this->get_pos()->get_x() + (width / 2));
	this->get_edges()->at(1).set_y(this->get_pos()->get_y() - (height / 2));

	this->get_edges()->at(2).set_x(this->get_pos()->get_x() + (width / 2));
	this->get_edges()->at(2).set_y(this->get_pos()->get_y() + (height / 2));

	this->get_edges()->at(3).set_x(this->get_pos()->get_x() - (width / 2));
	this->get_edges()->at(3).set_y(this->get_pos()->get_y() + (height / 2));

}

float Rectangle::set_height(float height) {
	this->height = height;

	return this->height;
}
float Rectangle::set_width(float width) {
	this->width = width;

	return this->width;
}
float Rectangle::get_height() {
	return this->height;
}
float Rectangle::get_width() {
	return this->width;
}