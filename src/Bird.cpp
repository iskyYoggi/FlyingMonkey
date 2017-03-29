/*
 * Bird.cpp
 *
 *  Created on: 29 mars 2017
 *      Author: A547010
 */

#include "Bird.h"
#include "Screen.h"

extern Screen screen;

namespace objects {

Bird::Bird() {
    //Initialize the offsets
    bPosX = 0;
    bPosY = 0;

    //Initialize the velocity
    bVelX = 0;
    bVelY = 0;

    bRenderer = screen.getRenderer();

	//Set sprite clips
	bSpriteClips[ 0 ].x = 0;
	bSpriteClips[ 0 ].y = 5;
	bSpriteClips[ 0 ].w = 50;
	bSpriteClips[ 0 ].h = 50;

	bSpriteClips[ 1 ].x = 60;
	bSpriteClips[ 1 ].y = 5;
	bSpriteClips[ 1 ].w = 50;
	bSpriteClips[ 1 ].h = 50;

	bSpriteClips[ 2 ].x = 120;
	bSpriteClips[ 2 ].y = 5;
	bSpriteClips[ 2 ].w = 50;
	bSpriteClips[ 2 ].h = 50;

	bSpriteClips[ 3 ].x = 180;
	bSpriteClips[ 3 ].y = 5;
	bSpriteClips[ 3 ].w = 50;
	bSpriteClips[ 3 ].h = 50;
}

Bird::~Bird() {
}

bool Bird::init(int x, int y){
	if(birdTexture.loadFromFile( screen.getRenderer(), "resources/birds.jpg") == false)
	{
		return false;
	}

    bPosX = x;
    bPosY = y;
	return true;
}

void Bird::render(){
	SDL_Rect* currentClip = &bSpriteClips[(this->frame++) / BIRD_ANIMATION_FRAMES];
	birdTexture.render( screen.getRenderer(), bPosX ,bPosY, currentClip);
	if( this->frame / BIRD_ANIMATION_FRAMES >= BIRD_ANIMATION_FRAMES )
	{
		frame = 0;
	}
}

void Bird::free(){
	birdTexture.free();
}

void Bird::move()
{
    //Move the dot left or right
    bPosX += bVelX;

    //If the dot went too far to the left or right
    if( ( bPosX < 0 ) || ( bPosX + DOT_WIDTH > screen.SCREEN_WIDTH ) )
    {
        //Move back
        bPosX -= bVelX;
    }

    //Move the dot up or down
    bPosY += bVelY;

    //If the dot went too far up or down
    if( ( bPosY < 0 ) || ( bPosY + DOT_HEIGHT > screen.SCREEN_HEIGHT ) )
    {
        //Move back
        bPosY -= bVelY;
    }
}

} /* namespace Objects */
