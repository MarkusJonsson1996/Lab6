#include "point2d.h"
#include <math.h>

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

void Point2d::rotate_around(Point2d* rotPoint, float angle) {
	//if (angle < 0)  angle += 2 * M_PI;
	
	double xTemp, yTemp, angleTemp;

	angleTemp = angle + this->angle_from(*rotPoint);


	xTemp = rotPoint->get_x() + this->len_to(*rotPoint) * cos(angleTemp);
	yTemp = rotPoint->get_y() +  -1 * this->len_to(*rotPoint) * sin(angleTemp);

	this->set_x(xTemp);
	this->set_y(yTemp);
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
double Point2d::len_to(const Point2d& otherPoint, int axis) {
	double ret;
	double lenX = (double)otherPoint.x - x;
	double lenY = (double)otherPoint.y - y;

	if (axis == 1) ret = lenX;
	else if(axis == 2) ret = lenY;
	else ret = sqrt(pow(lenX, 2.0) + pow(lenY, 2.0));

	return ret;
}
double Point2d::angle_from(const Point2d& otherPoint) {

	float mot = otherPoint.y - this->y;
	float nar = this->x - otherPoint.x;

	double angle1 = asin(mot / this->len_to(otherPoint));

	if (mot >= 0 && nar < 0) angle1 = M_PI - angle1;
	else if (mot < 0 && nar < 0) angle1 = (-1 * angle1) + M_PI;
	else if (mot < 0 && nar >= 0) angle1 = (2 * M_PI) + angle1;


	return angle1;
}
string Point2d::to_string() {
	string ret = "[,]";

	ret.insert(2, std::to_string(y));
	ret.insert(1, std::to_string(x));

	return ret;
}
