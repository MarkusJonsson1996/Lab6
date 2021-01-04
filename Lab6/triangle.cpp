#include "triangle.h"

Triangle::Triangle(Point2d pos, unsigned int* colorAlpha, float base, float height) : Shape(pos, colorAlpha), base(base), height(height) {

}

void Triangle::render() {
	cout << "Rendering Triangle: " << endl;
	cout << "\tBase: " << this->base << endl;
	cout << "\tHeight: " << this->height << endl;
	cout << "\tPosition: " << this->get_pos() << endl;
}