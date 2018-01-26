#include <iostream>
#include <SDL.h>
using namespace std;

int main(int argv, char** argc) {
	SDL_Window* window = SDL_CreateWindow("My title", 100, 100, 100, 100, SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_PRESENTVSYNC);
	SDL_Event* sdl_event = new SDL_Event;
	bool quit = false;

	SDL_ShowWindow(window);
	SDL_SetWindowMinimumSize(window, 300, 300);

	while (!quit) {

		while (SDL_PollEvent(sdl_event)) {
			if (sdl_event->type == SDL_QUIT)
				quit = true;
		}

		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	delete sdl_event; sdl_event = nullptr;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	cout << "Hello World!\n";
	system("pause");
	return 0;
}