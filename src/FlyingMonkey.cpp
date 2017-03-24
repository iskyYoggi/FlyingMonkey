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

using namespace std;
using namespace basic;

Screen screen;
Texture monkey2;
Texture bird1;
Texture background;

bool loadMedia(void)
{
	if(monkey2.loadFromFile( screen.getRenderer(), "resources/monkey6.png") == false)
	{
		cout << "Error: Failed to load texture image!" << endl;
		return false;
	}

	if(bird1.loadFromFile( screen.getRenderer(), "resources/birds.png") == false)
	{
		cout << "Error: Failed to load texture image!" << endl;
		return false;
	}

	if(background.loadFromFile( screen.getRenderer(), "resources/sky.jpg") == false)
	{
		cout << "Error: Failed to load texture image!" << endl;
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
		}

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
		//monkey2.render( screen.getRenderer(), 0 ,0);

		//screen.renderer();

		screen.update();
	}

	//Free loaded image
	monkey2.free();
	bird1.free();
	background.free();

	screen.close();

	return 0;
}
