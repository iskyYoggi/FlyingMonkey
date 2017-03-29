/*
 * Screen.h
 *
 *  Created on: 23 mars 2017
 *      Author: A547010
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Texture.h"

namespace basic {

class Screen {
private:
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

public:
	//Screen dimension constants
	const static int SCREEN_WIDTH = 1024; //640;
	const static int SCREEN_HEIGHT = 600; //480;

	//The window renderer
	SDL_Renderer* gRenderer = NULL;

public:
	Screen();
	virtual ~Screen();

	bool init();
	void clear();
	void update();
	SDL_Renderer* getRenderer();
#if 0
	bool loadMedia();
	void renderer();
#endif
	void close();
};

} /* namespace basic */

#endif /* SCREEN_H_ */
