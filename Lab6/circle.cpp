#include "circle.h"

Circle::Circle(Point2d pos, uint8_t* colorAlpha, float rad) : Shape(pos, colorAlpha), rad(rad) {
	this->get_edges()->resize(360);


	for (int deg = 0; deg < 360; deg++) {
		this->get_edges()->at(deg).set_x(this->get_pos()->get_x() + this->rad * cos(deg * (M_PI / 180)));
		this->get_edges()->at(deg).set_y(this->get_pos()->get_y() + this->rad * sin(deg * (M_PI / 180)));
	}

}

float Circle::get_rad() {
	return this->rad;
}

Point2d Circle::set_pos(float x, float y) {
	this->get_pos()->set_x(x);
	this->get_pos()->set_y(y);

	for (int deg = 0; deg < 360; deg++) {
		this->get_edges()->at(deg).set_x(this->get_pos()->get_x() + this->rad * cos(deg * (M_PI / 180)));
		this->get_edges()->at(deg).set_y(this->get_pos()->get_y() + this->rad * sin(deg * (M_PI / 180)));
	}

	return *this->get_pos();
}