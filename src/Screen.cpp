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
	SDL_DestroyTexture( gTexture );
	SDL_DestroyTexture( gTexture1 );
	SDL_DestroyTexture( gTexture2 );

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );

	gWindow = NULL;
	gRenderer = NULL;
	gTexture = NULL;
	gTexture1 = NULL;
	gTexture2 = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

//Loads individual image as texture
SDL_Texture* Screen::loadTexture( std::string path ){
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		cout << "Unable to load image from: " << path.c_str() << "! SDL_image Error: " << IMG_GetError() << endl;
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			cout << "Unable to create texture from: " << path.c_str() << "! SDL Error: " << SDL_GetError() << endl;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

bool Screen::loadMedia(){
	//Load texture
	gTexture = loadTexture( "resources/monkey3.png" );
	if( gTexture == NULL )
	{
		cout << "Error: Failed to load texture image!" << endl;
		return false;
	}
	gTexture1 = loadTexture( "resources/monkey4.png" );
	if( gTexture1 == NULL )
	{
		cout << "Error: Failed to load texture image!" << endl;
		return false;
	}
	gTexture2 = loadTexture( "resources/monkey6.png" );
	if( gTexture2 == NULL )
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

//void Screen::renderViewPoint(SDL_Texture* myTexture, SDL_Rect* myViewport){
//	SDL_RenderSetViewport( gRenderer, myViewport );
//	//Render texture to screen
//	SDL_RenderCopy( gRenderer, myTexture, NULL, NULL );
//}

void Screen::renderer(){
	//Top left corner viewport
	SDL_Rect topLeftViewport;
	topLeftViewport.x = 0;
	topLeftViewport.y = 0;
	topLeftViewport.w = Screen::SCREEN_WIDTH / 2;
	topLeftViewport.h = Screen::SCREEN_HEIGHT / 2;
	SDL_RenderSetViewport( gRenderer, &topLeftViewport );

	//Render texture to screen
	SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );


	//Top right viewport
	SDL_Rect topRightViewport;
	topRightViewport.x = Screen::SCREEN_WIDTH / 2;
	topRightViewport.y = 0;
	topRightViewport.w = Screen::SCREEN_WIDTH / 2;
	topRightViewport.h = Screen::SCREEN_HEIGHT / 2;
	SDL_RenderSetViewport( gRenderer, &topRightViewport );

	//Render texture to screen
	SDL_RenderCopy( gRenderer, gTexture1, NULL, NULL );


	//Bottom viewport
	SDL_Rect bottomViewport;
	bottomViewport.x = 0;
	bottomViewport.y = Screen::SCREEN_HEIGHT / 2;
	bottomViewport.w = Screen::SCREEN_WIDTH;
	bottomViewport.h = Screen::SCREEN_HEIGHT / 2;
	SDL_RenderSetViewport( gRenderer, &bottomViewport );

	//Render texture to screen
	SDL_RenderCopy( gRenderer, gTexture2, NULL, NULL );
}
} /* namespace basic */
