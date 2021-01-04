#include "shape.h"

Shape::Shape(Point2d pos, unsigned int* colorAlpha) : pos(pos) {
	for (int i = 0; i < 4; i++) {

		if (colorAlpha[i] < 0) colorAlpha[i] += 255;
		else if (colorAlpha[i] > 255) colorAlpha -= 255;

		this->colorAlpha[i] = colorAlpha[i];
	}
}

string Shape::get_pos() {
	return pos.to_string();
}
void Shape::render() {
	cout << "Rendering shape" << endl;
}