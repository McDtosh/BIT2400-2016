/*
By: Duncan McIntosh
Whole description in Main.cpp

Enemy.h
	Initialize variables
Enemy.cpp
	Constructor
		Give a random position by defeault - which is reset at another random location by the game
	Move
		Type is assigned in Game.cpp
		Enemy if type 1 - Moves randomly and bounces off walls
		Enemy if type 2 - Moves towards the player at a reduced speed (so that the player can escape)
*/
#pragma once

class Enemy
{

public:
	int r;
	int x;
	int y;
	ALLEGRO_BITMAP* bmp;
	int sx;
	int sy;

	bool type;	//False - enemy2		True - enemy

	Enemy();
	~Enemy();

	void Move(int px, int py);
};

