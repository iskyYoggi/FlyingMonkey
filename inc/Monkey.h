/*
 * Monkey.h
 *
 *  Created on: 29 mars 2017
 *      Author: A547010
 */

#ifndef MONKEY_H_
#define MONKEY_H_

#include "Texture.h"

using namespace std;
using namespace basic;

namespace objects {

class Monkey {
private:
	const static int MONKEY_VEL = 1;
	const static int DOT_WIDTH = 100;
	const static int DOT_HEIGHT = 80;
	Texture monkeyTexture;
	SDL_Renderer* mRenderer = NULL;
	const static int MONKEY_ANIMATION_FRAMES = 4;
	SDL_Rect mSpriteClips[ MONKEY_ANIMATION_FRAMES ];
	int frame = 0;

public:
    //Initialize the offsets
    int mPosX;
    int mPosY;

    //Initialize the velocity
    int mVelX;
    int mVelY;

public:
	Monkey();
	virtual ~Monkey();
	bool init();
	void render();
	void handleEvent( SDL_Event& e );
	void move();
	void free();
};

} /* namespace Objects */

#endif /* MONKEY_H_ */
