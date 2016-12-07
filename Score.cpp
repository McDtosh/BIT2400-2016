/*
By: Duncan McIntosh
Whole description in Main.cpp

Score.h
	The score is private, so there's Get/Set functions for the score.
Score.cpp
	While originally meant to hold the score images (now in Game.cpp) it wasn't working, so it was relegated to help render the score by passing it to the render function.
	The score is private, hence why there's a SetS & GetS functions which pass it outside the class. Everytime SetS is called the score is increased.
*/
#include "Main.h"


Score::Score()
{
	scbmp = al_load_bitmap("score0.bmp");
	scoreCount = 0;
	x = 30;
	y = HEIGHT - 30;
}


Score::~Score()
{
	al_destroy_bitmap(scbmp);
}


void Score::SetS()
{
	scoreCount++;
}

int Score::GetS()
{
	return scoreCount;
}