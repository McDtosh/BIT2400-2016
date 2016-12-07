/*
By: Duncan McIntosh
Whole description in Main.cpp

Health.cpp + Health.h
	The only purpose of this class is to pass the health images to the render function, I couldn't do it through the Player class.
*/
#include "Main.h"



Health::Health()
{
	bmp = al_load_bitmap("player.bmp");
	x = 10;
	y = 10;
}


Health::~Health()
{
	al_destroy_bitmap(bmp);
}