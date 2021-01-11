#include "triangle.h"

Triangle::Triangle(Point2d pos, uint8_t* colorAlpha, float base, float height) : Shape(pos, colorAlpha), base(base), height(height) {

}

void Triangle::render(SDL_Renderer* renderer) {

	SDL_SetRenderDrawColor(renderer,
		this->get_color_alpha(0),
		this->get_color_alpha(1),
		this->get_color_alpha(2),
		this->get_color_alpha(3)
	);

	SDL_RenderDrawLine(renderer,
		(int)this->get_pos().get_x(),
		(int)this->get_pos().get_y(),
		(int)(this->get_pos().get_x() + this->base),
		(int)this->get_pos().get_y()
	);

	SDL_RenderDrawLine(renderer,
		(int)this->get_pos().get_x() + (int)this->base,
		(int)this->get_pos().get_y(),
		(int)(this->get_pos().get_x() + (this->base / 2)),
		(int)(this->get_pos().get_y() - this->height)
	);

	SDL_RenderDrawLine(renderer,
		(int)(this->get_pos().get_x() + (this->base / 2)),
		(int)(this->get_pos().get_y() - this->height),
		(int)this->get_pos().get_x(),
		(int)this->get_pos().get_y()
	);

}