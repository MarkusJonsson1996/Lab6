#include "rectangle.h"

Rectangle::Rectangle(Point2d pos, uint8_t* colorAlpha, float width, float height): Shape (pos, colorAlpha), width(width), height(height) {
	this->edges[0].set_x(this->get_pos()->get_x() - (width / 2));
	this->edges[0].set_y(this->get_pos()->get_y() - (height / 2));

	this->edges[1].set_x(this->get_pos()->get_x() + (width / 2));
	this->edges[1].set_y(this->get_pos()->get_y() - (height / 2));

	this->edges[2].set_x(this->get_pos()->get_x() + (width / 2));
	this->edges[2].set_y(this->get_pos()->get_y() + (height / 2));

	this->edges[3].set_x(this->get_pos()->get_x() - (width / 2));
	this->edges[3].set_y(this->get_pos()->get_y() + (height / 2));
}

void Rectangle::render(SDL_Renderer* renderer) {


	SDL_SetRenderDrawColor(renderer, 
		this->get_color_alpha(0), 
		this->get_color_alpha(1), 
		this->get_color_alpha(2),
		this->get_color_alpha(3)
	);

	//update_edge();

	for (int i = 0; i < 3; i++) {
		SDL_RenderDrawLine(renderer,
			(int)this->edges[i].get_x(),
			(int)this->edges[i].get_y(),
			(int)this->edges[i + 1].get_x(),
			(int)this->edges[i + 1].get_y()
		);


	}

	SDL_RenderDrawLine(renderer,
		(int)this->edges[3].get_x(),
		(int)this->edges[3].get_y(),
		(int)this->edges[0].get_x(),
		(int)this->edges[0].get_y()
	);

	SDL_SetRenderDrawColor(renderer,
		255,
		0,
		0,
		255
	);

	SDL_RenderDrawLine(renderer,
		(int)this->get_pos()->get_x(),
		(int)this->get_pos()->get_y(),
		(int)this->edges[1].get_x(),
		(int)this->edges[1].get_y()
	);

}

void Rectangle::set_angle(float angle) { 

	//angle = angle * (M_PI / 180);

	Shape::set_angle(angle);

	for (int i = 0; i < 4; i++) this->edges[i].rotate(this->get_pos(), this->get_angle());

	//this->edges[1].rotate(this->get_pos(), this->get_angle());

}
void Rectangle::offset(float x, float y) {

	this->get_pos()->set_x(this->get_pos()->get_x() + x);
	this->get_pos()->set_y(this->get_pos()->get_y() + y);

	for (int i = 0; i < 4; i++) {
		this->edges[i].set_x(this->edges[i].get_x() + x);
		this->edges[i].set_y(this->edges[i].get_y() + y);
	}
}