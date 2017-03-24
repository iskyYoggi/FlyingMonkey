/*
 * Screen.cpp
 *
 *  Created on: 23 mars 2017
 *      Author: A547010
 */

#include "Screen.h"
#include <iostream>

using namespace std;

namespace basic {

Screen::Screen() {
}

Screen::~Screen() {
}

bool Screen::init(){
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		cout << "Error: SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
		return false;
	}

//	//Set texture filtering to linear
//	if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
//	{
//		cout << "Warning: Linear texture filtering not enabled!" ;
//	}

	//Create window
	gWindow = SDL_CreateWindow( "Flying Monkey", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if( gWindow == NULL )
	{
		cout << "Error: Window could not be created! SDL Error: " << SDL_GetError() << endl;
		return false;
	}

	//Create renderer for window
	gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
	if( gRenderer == NULL )
	{
		cout << "Error: Renderer could not be created! SDL Error: "<< SDL_GetError() << endl;
		return false;
	}

	//Initialize renderer color
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
	{
		cout << "Error: SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
		return false;
	}

	return true;
}

void Screen::close(){
	//Free loaded image
	Monkey1.free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );

	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

bool Screen::loadMedia(){
	//Load texture
	if(Monkey1.loadFromFile( gRenderer, "resources/monkey1.png") == false)
	{
		cout << "Error: Failed to load texture image!" << endl;
		return false;
	}

	return true;
}

void Screen::clear(){
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear( gRenderer );
}

void Screen::update(){
	//Update screen
	SDL_RenderPresent( gRenderer );
}

void Screen::renderer(){
	//Top left corner viewport
	SDL_Rect topLeftViewport;
	topLeftViewport.x = 0;
	topLeftViewport.y = 0;
	topLeftViewport.w = Screen::SCREEN_WIDTH / 2;
	topLeftViewport.h = Screen::SCREEN_HEIGHT / 2;
	SDL_RenderSetViewport( gRenderer, &topLeftViewport );

	//Render texture to screen
	Monkey1.render( gRenderer, 0 ,0);
}
} /* namespace basic */
