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

namespace basic {

class Screen {
private:
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The window renderer
	SDL_Renderer* gRenderer = NULL;

public:
	//Screen dimension constants
	const static int SCREEN_WIDTH = 640;
	const static int SCREEN_HEIGHT = 480;

	//Current displayed texture
	SDL_Texture* gTexture = NULL;
	SDL_Texture* gTexture1 = NULL;
	SDL_Texture* gTexture2 = NULL;

private:
	SDL_Texture* loadTexture( std::string path );

public:
	Screen();
	virtual ~Screen();

	bool init();
	bool loadMedia();
	void clear();
	void update();
//	void renderViewPoint(SDL_Texture* myTexture, SDL_Rect* myViewport);
	void renderer();
	void close();
};

} /* namespace basic */

#endif /* SCREEN_H_ */
