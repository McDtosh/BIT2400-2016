/*
By: Duncan McIntosh
Whole description in Main.cpp

Health.cpp + Health.h
The only purpose of this class is to pass the health images to the render function, I couldn't do it through the Player class.
*/
#pragma once
class Health
{
public:

	ALLEGRO_BITMAP* bmp;
	int x;
	int y;
	Health();
	~Health();
};

