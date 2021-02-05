#include "SDL.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"

#define SCREENWIDTH 1360
#define SCREENHIGHT 720

using namespace std;

void car_in(SDL_Event* ev, map<string, Shape*>* worldsObjects);
Uint32 update_world_objects(Uint32 interval, void* param);

bool gameRunning = true;
bool bulletFired = false;

int main(int argc, char* argv[]){
	uint8_t platCol[4] = { 0, 255, 0, 255 };
	uint8_t bulCol[4] = { 255, 125, 125, 255 };

	Rectangle platform(Point2d(SCREENWIDTH / 2, SCREENHIGHT - 25), platCol, 200, 50);
	Circle bullet(Point2d(SCREENWIDTH / 2, SCREENHIGHT / 2), bulCol, 25);
	
	map<string, Shape*> worldObjects;

	worldObjects["platform"] = &platform;
	worldObjects["bullet"] = &bullet;


	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Event inputEvent;
	SDL_Window* gameWindow = SDL_CreateWindow("gamename", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENWIDTH, SCREENHIGHT, SDL_WINDOW_SHOWN);
	SDL_TimerID myTimer =  SDL_AddTimer(16, update_world_objects, &worldObjects);
	SDL_Renderer* renderer = SDL_CreateRenderer(gameWindow, -1, 0);

	while (gameRunning) {
		 
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		
		car_in(&inputEvent, &worldObjects);

		platform.render(renderer);
		bullet.render(renderer);


		SDL_RenderPresent(renderer);
	}


	return 0;
}

void car_in(SDL_Event* ev, map<string, Shape*>* worldObjects) {
	const Uint8* keyState;

	while (SDL_PollEvent(ev)) {
		if (ev->type == SDL_KEYDOWN && ev->key.keysym.sym == SDLK_ESCAPE)  gameRunning = false;

		if (ev->type == SDL_KEYDOWN && ev->key.keysym.sym == SDLK_SPACE) {
			worldObjects->at("bullet")->set_vel(worldObjects->at("platform")->get_vel()->get_x(), -2.0);
			bulletFired = true;
		}
	}
	
	keyState = SDL_GetKeyboardState(NULL);

	if (keyState[SDL_SCANCODE_LEFT] && worldObjects->at("platform")->get_pos()->get_x() > 100) {
		worldObjects->at("platform")->set_vel(-5, 0.00);
	}
	else if (keyState[SDL_SCANCODE_RIGHT] && worldObjects->at("platform")->get_pos()->get_x() < SCREENWIDTH - 100) {
		worldObjects->at("platform")->set_vel(5, 0.00);
	}
	else worldObjects->at("platform")->set_vel(0, 0.00);

}

Uint32 update_world_objects(Uint32 interval, void* param) {
	map<string, Shape*>* worldObjects = static_cast<map<string, Shape*>*>(param);
	Rectangle* platform = dynamic_cast<Rectangle*>(worldObjects->at("platform"));
	Circle* bullet = dynamic_cast<Circle*>(worldObjects->at("bullet"));

	float bulletRad = bullet->get_rad();

	platform->offset(platform->get_vel()->get_x(), platform->get_vel()->get_y());
	
	if(!bulletFired) bullet->set_pos(platform->get_pos()->get_x(), platform->get_pos()->get_y() - (bullet->get_rad() * 2));
	else {
		bullet->offset(bullet->get_vel()->get_x(), bullet->get_vel()->get_y());

		if (bullet->get_pos()->get_x() < bulletRad) bullet->set_vel(bullet->get_vel()->get_x() * -1, bullet->get_vel()->get_y());
		else if(bullet->get_pos()->get_x() > SCREENWIDTH - bulletRad) bullet->set_vel(bullet->get_vel()->get_x() * -1, bullet->get_vel()->get_y());

		if(bullet->get_pos()->get_y() < bulletRad) bullet->set_vel(bullet->get_vel()->get_x(), bullet->get_vel()->get_y() * -1);
		else if(bullet->get_pos()->get_y() > SCREENHIGHT - (platform->get_height() / 2 ) - (bulletRad * 2)) bullet->set_vel(bullet->get_vel()->get_x(), bullet->get_vel()->get_y() * -1);

	}

	return (interval);
}