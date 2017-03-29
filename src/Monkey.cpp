/*
 * Monkey.cpp
 *
 *  Created on: 29 mars 2017
 *      Author: A547010
 */
#include "Monkey.h"
#include "Screen.h"

extern Screen screen;

namespace objects {

Monkey::Monkey() {
    //Initialize the offsets
    mPosX = 200;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;

    mRenderer = screen.getRenderer();

	//Set sprite clips
	mSpriteClips[ 0 ].x = 0;
	mSpriteClips[ 0 ].y = 0;
	mSpriteClips[ 0 ].w = 150;
	mSpriteClips[ 0 ].h = 150;

	mSpriteClips[ 1 ].x = 150;
	mSpriteClips[ 1 ].y = 0;
	mSpriteClips[ 1 ].w = 150;
	mSpriteClips[ 1 ].h = 150;

	mSpriteClips[ 2 ].x = 450;
	mSpriteClips[ 2 ].y = 60;
	mSpriteClips[ 2 ].w = 150;
	mSpriteClips[ 2 ].h = 140;

	mSpriteClips[ 3 ].x = 340;
	mSpriteClips[ 3 ].y = 150;
	mSpriteClips[ 3 ].w = 150;
	mSpriteClips[ 3 ].h = 140;

}

Monkey::~Monkey() {
}

bool Monkey::init(){
	if(monkeyTexture.loadFromFile( screen.getRenderer(), "resources/monkey1.jpg") == false)
	{
		return false;
	}
	return true;
}

void Monkey::render(){
	SDL_Rect* currentClip = &mSpriteClips[(frame++) / MONKEY_ANIMATION_FRAMES];
	monkeyTexture.render( screen.getRenderer(), mPosX ,mPosY, currentClip);
	if( frame / MONKEY_ANIMATION_FRAMES >= MONKEY_ANIMATION_FRAMES )
	{
		frame = 0;
	}
}

void Monkey::free(){
	monkeyTexture.free();
}

void Monkey::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= MONKEY_VEL; break;
            case SDLK_DOWN: mVelY += MONKEY_VEL; break;
            case SDLK_LEFT: mVelX -= MONKEY_VEL; break;
            case SDLK_RIGHT: mVelX += MONKEY_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += MONKEY_VEL; break;
            case SDLK_DOWN: mVelY -= MONKEY_VEL; break;
            case SDLK_LEFT: mVelX += MONKEY_VEL; break;
            case SDLK_RIGHT: mVelX -= MONKEY_VEL; break;
        }
    }
}

void Monkey::move()
{
    //Move the dot left or right
    mPosX += mVelX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > screen.SCREEN_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }

    //Move the dot up or down
    mPosY += mVelY;

    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > screen.SCREEN_HEIGHT ) )
    {
        //Move back
        mPosY -= mVelY;
    }
}

} /* namespace Objects */
