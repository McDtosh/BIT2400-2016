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

#include "Main.h"



Enemy::Enemy()
{
	x = rand() % (WIDTH - 20);
	y = rand() % (HEIGHT - 20);
}


Enemy::~Enemy()
{
	al_destroy_bitmap(bmp);
}

void Enemy::Move(int px, int py)
{
	//Types dictate how they move, randomly or following
	if (type == true && sx != 0 && sy != 0)
	{
		if (x > px)
		{
			x--;
		}
		if (y > py)
		{
			y--;
		}

		if (x < px)
		{
			x++;
		}
		if (y < py)
		{
			y++;
		}
	}

	if (type == false && sx != 0 && sy != 0)
	{
		x += sx;
		y += sy;

		if (x >= (WIDTH - 30))
		{
			sx = -2;
		}
		if (y >= (HEIGHT - 30))
		{
			sy = -2;
		}

		if (x < 30)
		{
			sx = 2;
		}
		if (y < 30)
		{
			sy = 2;
		}
	}


}
