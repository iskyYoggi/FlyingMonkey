//============================================================================
// Name        : FlyingMonkey.cpp
// Author      : Yihui
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <Screen.h>

using namespace std;
using namespace basic;

int main() {

	Screen screen;
	//Start up SDL and create window
	if( !screen.init() )
	{
		printf( "Failed to initialize!\n" );
		return -1;
	}
	//Load media
	if( !screen.loadMedia() )
	{
		printf( "Failed to load media!\n" );
		return -1;
	}

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//While application is running
	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
		}

		screen.clear();

		screen.renderer();

		screen.update();
	}

	screen.close();

	return 0;
}
