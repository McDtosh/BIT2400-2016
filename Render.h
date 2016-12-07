/*
By: Duncan McIntosh
Whole description in Main.cpp

Render.cpp + Render.h
	The game is rendered through this function each frame.
	I didn't know how to render Score+Health images through the player function, so gave them their own render functions, because I wanted them displayed on screen.
*/
#pragma once
class Render
{
public:
	
	Render();
	~Render();

	void Draw(Players* p);	//draw player
	void Draw(Enemy* p);	//draw enemies
	void Draw(Score* p);	//draw score
	void Draw(Health* p);	//draw health 
	void Begin(ALLEGRO_BITMAP* bg);	//start a frame by drawing the background
	void End();	//Clear frame

};

