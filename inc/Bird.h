/*
 * Bird.h
 *
 *  Created on: 29 mars 2017
 *      Author: A547010
 */

#ifndef BIRD_H_
#define BIRD_H_

#include "Texture.h"

using namespace std;
using namespace basic;

namespace objects {

class Bird {

private:
	const static int BIRD_VEL = 1;
	const static int DOT_WIDTH = 100;
	const static int DOT_HEIGHT = 80;
	Texture birdTexture;
	SDL_Renderer* bRenderer = NULL;
	const static int BIRD_ANIMATION_FRAMES = 4;
	SDL_Rect bSpriteClips[ BIRD_ANIMATION_FRAMES ];
	int frame = 0;

public:
    //Initialize the offsets
    int bPosX;
    int bPosY;

    //Initialize the velocity
    int bVelX;
    int bVelY;

public:
	Bird();
	virtual ~Bird();
	bool init(int x, int y);
	void render();
	void move();
	void free();
};

} /* namespace objects */

#endif /* BIRD_H_ */
