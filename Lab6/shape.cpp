#include "shape.h"

Shape::Shape() { 

}
Shape::Shape(Point2d pos, uint8_t* colorAlpha) : pos(pos),  angle(0) {
	for (int i = 0; i < 4; i++) {

		if (colorAlpha[i] < 0) colorAlpha[i] += 255;
		else if (colorAlpha[i] > 255) colorAlpha -= 255;

		this->colorAlpha[i] = colorAlpha[i];
	}
}

string Shape::get_string_pos() {
	return pos.to_string();
}
Point2d* Shape::get_pos() {
	return &pos;
}
float Shape::get_angle() {
	return angle;
}
float Shape::set_angle(float newAngle) {
	
	/*if (newAngle >= 2*M_PI) this->angle = newAngle - 2*M_PI;
	else if (newAngle < 0) this->angle = newAngle + 2*M_PI;
	else this->angle = newAngle;*/

	this->angle = newAngle;

	return angle;
}
uint8_t Shape::get_color_alpha(uint8_t i){	
	Uint8 ret = -1;

	if (i < 5 || i > -1) ret = this->colorAlpha[i];

	return ret;
}

void Shape::render(SDL_Renderer* renderer) {
	cout << "Rendering shape" << endl;
}