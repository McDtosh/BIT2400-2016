/*
By: Duncan McIntosh
Whole description in Main.cpp

Player.h
	Initialize the Get/Set functions for location, speed, health (because all their variables are private) and the collision functions
Player.cpp
	Constructor
		Initialize the location, bmp and health
	SetX/GetX/SetY/GetY
		They're private, so they must have functions to retrieve and return them.
	InRect/Collision
		Enables collision between the player and the enemy entities
	Move
		Moves the position according to the speed (which is set in Game.cpp\Update)
	GetH/SetH
		Health is not being added, so when SetH is called, it decreases the players health (newH = -1)
*/
#pragma once

class Players
{
	int x;
	int y;

	struct Rect
	{
		int x;
		int y;
		int w;
		int h;
	};

	int health;

public:
	ALLEGRO_BITMAP* bmp; //a pointer to bitmap
						 //speed
	int sx;
	int sy;
	

	//Score Data
	int hitCount;

	Players();
	~Players();

	void SetH(int newh);
	int GetH();

	void SetX(int newx);
	int GetX();

	void SetY(int newy);
	int GetY();

	bool Collision0(Enemy* o2);
	bool InRect(int x, int y, Rect r);
	void Move();
};

