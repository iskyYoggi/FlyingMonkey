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
#include "Screen.h"
#include "Texture.h"
#include "Monkey.h"
#include "Bird.h"

using namespace std;
using namespace basic;
using namespace objects;

Screen screen;
Monkey monkey;
Bird bird1, bird2;
Texture background;

bool loadMedia(void)
{
	if(monkey.init() == false)
	{
		cout << "Error: Failed to load monkey image!" << endl;
		return false;
	}

	if(bird1.init(700,400) == false)
	{
		cout << "Error: Failed to load bird image!" << endl;
		return false;
	}

	if(bird2.init(100, 300) == false)
	{
		cout << "Error: Failed to load bird image!" << endl;
		return false;
	}

	if(background.loadFromFile( screen.getRenderer(), "resources/sky.jpg") == false)
	{
		cout << "Error: Failed to load sky image!" << endl;
		return false;
	}
	return true;
}

int main() {
	//Start up SDL and create window
	if( !screen.init() )
	{
		printf( "Failed to initialize!\n" );
		return -1;
	}
	//Load media
	if( !loadMedia() )
	{
		printf( "Failed to load media!\n" );
		return -1;
	}

	bool quit = false; //Main loop flag
	SDL_Event e; //Event handler
	int scrollingOffset = 0; //The background scrolling offset

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
			monkey.handleEvent(e);
		}
		monkey.move();

		//Scroll background
		--scrollingOffset;
		if( scrollingOffset < - background.getWidth() )
		{
			scrollingOffset = 0;
		}

		screen.clear();

		//Render background
		background.render( screen.getRenderer(), scrollingOffset, 0 );
		background.render( screen.getRenderer(), scrollingOffset + background.getWidth(), 0 );

		//Render Objects
		bird1.render();
		bird2.render();
		monkey.render();

		screen.update();
		SDL_Delay(10);
	}

	//Free loaded image
	monkey.free();
	bird1.free();
	bird2.free();
	background.free();

	screen.close();

	return 0;
}
