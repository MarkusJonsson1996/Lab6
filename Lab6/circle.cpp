#include "circle.h"

Circle::Circle(Point2d pos, unsigned int* colorAlpha, float rad) : Shape(pos, colorAlpha), rad(rad) {

}

void Circle::render() {
	cout << "Rendering Circle:" << endl;
	cout << "\tRadius: " << this->rad << endl;
	cout << "\tPosition: " << this->get_pos() << endl;
}