/*
 * Texture.h
 *
 *  Created on: 24 mars 2017
 *      Author: A547010
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <stdio.h>
#include <SDL.h>

namespace basic {

class Texture {
public:
	Texture();
	virtual ~Texture();

	//Loads image at specified path
	bool loadFromFile( SDL_Renderer* gRenderer, std::string path );

	#ifdef _SDL_TTF_H
	//Creates image from font string
	bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
	#endif

	//Renders texture at given point
	void render( SDL_Renderer* mRenderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Deallocates texture
	void free();

	//Set color modulation
	void setColor( Uint8 red, Uint8 green, Uint8 blue );

	//Set blending
	void setBlendMode( SDL_BlendMode blending );

	//Set alpha modulation
	void setAlpha( Uint8 alpha );

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};

} /* namespace basic */

#endif /* TEXTURE_H_ */
