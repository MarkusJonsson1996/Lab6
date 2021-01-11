#include "circle.h"

Circle::Circle(Point2d pos, uint8_t* colorAlpha, float rad) : Shape(pos, colorAlpha), rad(rad) {

}


void Circle::render(SDL_Renderer* renderer) {
	double x1, x2, y1, y2;

	SDL_SetRenderDrawColor(renderer,
		this->get_color_alpha(0),
		this->get_color_alpha(1),
		this->get_color_alpha(2),
		this->get_color_alpha(3)
	);

	for (int deg = 0; deg < 359; deg++) {
		x1 = this->get_pos()->get_x() + this->rad * cos(deg * (M_PI/180));
		y1 = this->get_pos()->get_y() + this->rad * sin(deg * (M_PI / 180));
		x2 = this->get_pos()->get_x() + this->rad * cos((deg+1) * (M_PI / 180));
		y2 = this->get_pos()->get_y() + this->rad * sin((deg+1) * (M_PI / 180));

		SDL_RenderDrawLine(renderer,
			(int)x1,
			(int)y1,
			(int)x2,
			(int)y2
		);

	}

}