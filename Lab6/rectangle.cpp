#include "rectangle.h"

Rectangle::Rectangle(Point2d pos, unsigned int* colorAlpha, float height, float witdh): Shape (pos, colorAlpha), width(witdh), height(height) {
}

void Rectangle::render() {
	cout << "Rendering rectangle: " << endl;
	cout << "\tWidth: " << this->width << endl;
	cout << "\tHeight: " << this->height << endl;
	cout << "\tPosition " << this->get_pos() << endl;
}