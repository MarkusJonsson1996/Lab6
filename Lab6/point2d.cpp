#include "point2d.h"


Point2d::Point2d() : x(0.0), y(0.0) {
}
Point2d::Point2d(float newX, float newY) : x(newX), y(newY) {
}
Point2d::Point2d(const Point2d& cpy) {
	x = cpy.x;
	y = cpy.y;
}

Point2d Point2d::operator+(const Point2d& otherPoint) {
	Point2d ret;

	ret.x = this->x + otherPoint.x;
	ret.y = this->y + otherPoint.y;

	return ret;
}
Point2d& Point2d::operator=(const Point2d& otherPoint) {
	x = otherPoint.x;
	y = otherPoint.y;

	return *this;
}
bool Point2d::operator==(const Point2d& otherPoint) {
	return x == otherPoint.x && y == otherPoint.y;
}
bool Point2d::operator!=(const Point2d& otherPoint) {
	return !(x == otherPoint.x && y == otherPoint.y);
}

float Point2d::get_x() {
	return x;
}
float Point2d::get_y() {
	return y;
}
float Point2d::set_x(float x) {
	this->x = x;
	return this->x;
}
float Point2d::set_y(float y) {
	this->y = y;
	return this->y;
}
double Point2d::len_to(const Point2d& otherPoint) {
	double lenX = (double)otherPoint.x - x;
	double lenY = (double)otherPoint.y - y;

	return sqrt(pow(lenX, 2.0) + pow(lenY, 2.0));
}
string Point2d::to_string() {
	string ret = "[,]";

	ret.insert(2, std::to_string(y));
	ret.insert(1, std::to_string(x));

	return ret;
}
