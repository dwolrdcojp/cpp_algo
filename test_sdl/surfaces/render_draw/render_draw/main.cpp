// Compile in the terminal for mac
// g++ -std=c++19 main.cpp ./glad/src/glad.c -I./glad/include -o prog -I/Users/max/Library/Frameworks/SDL2.framework/Versions/A/Headers -F/Users/max/Library/Frameworks -framework SDL2 -ldl
// install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 /Users/max/Library/Frameworks/SDL2.framework/Versions/A/SDL2 prog
// ./prog

// Example program
// Using SDL2 to create an application window

#include "SDL_events.h"
#include "SDL_render.h"
#include "SDL_stdinc.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include <SDL.h>
#include <stdio.h>
#include <iostream>

int main(int argc, char* argv[]) {

	SDL_Window *window=nullptr; // Declare a pointer

	SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2
	
	// Create an application window with the following settings:
	window = SDL_CreateWindow(
			"A SDL2 Window", // window title
			0, // initial x position
			0, // initial y position
			640, // width in pixels
			480, // height in pixels,
			SDL_WINDOW_SHOWN
	);

	SDL_Renderer* renderer=nullptr;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Check that window was successfully created
	if (window == NULL) {
		// In the case that window could not be made...
		std::cout << "Could not create the window" << std::endl;
		return 1;
	}

	SDL_Surface* surface = SDL_LoadBMP("./images/water.bmp");	

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	SDL_Rect rectangle;
	rectangle.x = 0;
	rectangle.y = 0;
	rectangle.w = 640;
	rectangle.h = 480;

	SDL_Rect rectangle2;
	rectangle2.x = -639;
	rectangle2.y = 0;
	rectangle2.w = 640;
	rectangle2.h = 480;

	SDL_Rect rectangle3;
	rectangle3.x = 0;
	rectangle3.y = 0;
	rectangle3.w = 640;
	rectangle3.h = 480;

	SDL_Rect rectangle4;
	rectangle4.x = 0;
	rectangle4.y = -480;
	rectangle4.w = 640;
	rectangle4.h = 480;

	// Infinite loop for our application 
	bool gameIsRunning = true;
	while(gameIsRunning){
		SDL_Event event;
		// Start our event loop
		while(SDL_PollEvent(&event)){
			// Handle each specific event
			if(event.type == SDL_QUIT){
				gameIsRunning = false;
			}
			if(event.type == SDL_MOUSEBUTTONDOWN){
				if(event.button.button == SDL_BUTTON_LEFT){
					SDL_SetTextureBlendMode(texture2, SDL_BLENDMODE_MOD);
				}
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		int w, h;
		SDL_QueryTexture(texture, NULL, NULL, &w, &h);
		// Little hack here, to slow down the simulation.
		SDL_Delay(20);
		
		// Handle textures scrolling left to right 
		rectangle.x++;
		if(rectangle.x > 639){
			rectangle.x = -639;
		}
		rectangle2.x++;
		if(rectangle2.x > 639){
			rectangle2.x = -639;
		}
		rectangle3.y++;
		if(rectangle3.y > 479){
			rectangle3.y = -480;
		}
		rectangle4.y++;
		if(rectangle4.y > 479){
			rectangle4.y = -480;
		}
		
		SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_NONE);
		SDL_RenderCopy(renderer, texture, NULL, &rectangle);
		SDL_RenderCopy(renderer, texture, NULL, &rectangle2);
		// SDL_RenderDrawRect(renderer, &rectangle);
		SDL_RenderCopy(renderer, texture2, NULL, &rectangle3);
		SDL_RenderCopy(renderer, texture2, NULL, &rectangle4);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);

	if(renderer) {
		SDL_DestroyRenderer(renderer);
	}
	// Close and destroy the window (becaue this is C and you have to create and delete memory allocations)
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}
