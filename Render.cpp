/*
By: Duncan McIntosh
Whole description in Main.cpp

Render.cpp + Render.h
	The game is rendered through this function each frame.
	I didn't know how to render Score+Health images through the player function, so gave them their own render functions, because I wanted them displayed on screen.
*/
#include "Main.h"



Render::Render()
{
}


Render::~Render()
{

}


void Render::Draw(Players* obj)	//draw an object 
{
	if (obj->bmp != NULL) //make sure we have a bitmap to draw
		al_draw_bitmap(obj->bmp, obj->GetX(), obj->GetY(), 0);
}

void Render::Draw(Enemy* obj)	//draw an object 
{
	if (obj->bmp != NULL) //make sure we have a bitmap to draw
		al_draw_bitmap(obj->bmp, obj->x, obj->y, 0);
}

void Render::Draw(Score* obj)	//draw an object 
{
	if (obj->scbmp != NULL) //make sure we have a bitmap to draw
		al_draw_bitmap(obj->scbmp, obj->x, obj->y, 0);
}

void Render::Draw(Health* obj)	//draw an object 
{
	if (obj->bmp != NULL) //make sure we have a bitmap to draw
		al_draw_bitmap(obj->bmp, obj->x, obj->y, 0);
}

void Render::Begin(ALLEGRO_BITMAP* bg)	//start a frame by drawing the background
{
	al_draw_bitmap(bg, 0, 0, 0);
}


void Render::End()
{
	al_flip_display();
}