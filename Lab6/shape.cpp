#include "shape.h"

Shape::Shape() : angle(0) {
	/*for (int i = 0; i < 3; i++) colorAlpha[i] = 0;
	colorAlpha[3] = 255;*/
}
Shape::Shape(Point2d pos, uint8_t* colorAlpha) : pos(pos), angle(0) {
	for (int i = 0; i < 4; i++) {

		if (colorAlpha[i] < 0) colorAlpha[i] += 255;
		else if (colorAlpha[i] > 255) colorAlpha -= 255;

		this->colorAlpha[i] = colorAlpha[i];
	}
	
	this->get_vel()->set_x(0);
	this->get_vel()->set_y(0);
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
vector<Point2d>* Shape::get_edges() {
	return &this->edges;
}
Point2d* Shape::get_vel() {
	return &this->vel;
}

Point2d Shape::set_pos(float x, float y) {
	this->get_pos()->set_x(x);
	this->get_pos()->set_y(y);

	return pos;
}
float Shape::set_angle(float newAngle) {

	float ass = newAngle - this->get_angle();

	for (int i = 0; i < edges.size(); i++) {
		this->edges[i].rotate_around(this->get_pos(), ass);
	}
	this->angle = newAngle;

	return angle;
}
Point2d Shape::set_vel(float x, float y) {
	this->vel.set_x(x);
	this->vel.set_y(y);

	return this->vel;
}
uint8_t Shape::get_color_alpha(uint8_t i){	
	Uint8 ret = -1;

	if (i < 5 || i > -1) ret = this->colorAlpha[i];

	return ret;
}

void Shape::offset(float x, float y) {
	this->pos.set_x(this->pos.get_x() + x);
	this->pos.set_y(this->pos.get_y() + y);

	for (int i = 0; i < edges.size(); i++) {
		edges[i].set_x(this->edges[i].get_x() + x);
		edges[i].set_y(this->edges[i].get_y() + y);
	}
}
void Shape::render(SDL_Renderer* renderer) {

	SDL_SetRenderDrawColor(renderer,
		this->colorAlpha[0],
		this->colorAlpha[1],
		this->colorAlpha[2],
		this->colorAlpha[3]
	);

	for (int i = 0; i < edges.size()-1; i++) {
		SDL_RenderDrawLine(renderer,
			(int)edges[i].get_x(),
			(int)edges[i].get_y(),
			(int)edges[i+1].get_x(),
			(int)edges[i+1].get_y()
		);
	}

	SDL_RenderDrawLine(renderer,
		(int)this->edges.back().get_x(),
		(int)this->edges.back().get_y(),
		(int)this->edges.front().get_x(),
		(int)this->edges.front().get_y()
	);

}