
#include "SDL.h"
#include "rectangle.h"

using namespace std;
bool gameRunning = true;

void car_in(SDL_Event* ev, Rectangle* car);

int main(int argc, char* argv[]){

	int screenWidth = 1360;
	int screenHeight = 720;
	Point2d screenSpaceCenter = Point2d((float)screenWidth / 2, (float)screenHeight / 2);

	uint8_t carCol[4] = { 0, 255, 0, 255 };
	Rectangle car(screenSpaceCenter, carCol, 200, 50);
	const Uint8* keystate;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* gameWindow = SDL_CreateWindow("gamename", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(gameWindow, -1, 0);
	SDL_Event keyboardEvent;

	while (gameRunning) {

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		while (SDL_PollEvent(&keyboardEvent)) {
			if (keyboardEvent.type == SDL_KEYDOWN) {
				car_in(&keyboardEvent, &car);

			}
		}

		//cout << car.get_angle() << endl;

		car.render(renderer);
		SDL_RenderPresent(renderer);
	}


	return 0;
}

void car_in(SDL_Event* ev, Rectangle* car) {

	switch (ev->key.keysym.sym) {

		case SDLK_UP:
			car->offset(0, -0.5);
			break;

		case SDLK_DOWN:
			car->offset(0, 0.5);
			break;
		case SDLK_LEFT:
			car->set_angle(0.02);
			break;
		case SDLK_RIGHT:
			car->set_angle(-0.02);
			break;
	}
	//cout << car->get_string_pos() << endl;
}