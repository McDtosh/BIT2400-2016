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
#include "Main.h"



Players::Players()
{
	//scbmp = al_load_bitmap("score0.bmp");
	//scx = 10;
	//scy = HEIGHT - 20;
	bmp = al_load_bitmap("player.bmp");
	x = y = 0;
	health = (HEALTH-1);
	hitCount = 0;
}


Players::~Players()
{
	al_destroy_bitmap(bmp);
}

void Players::SetX(int newx)
{
	x = newx;
}

int Players::GetX()
{
	return x;
}

void Players::SetY(int newy)
{
	y = newy;
}

int Players::GetY()
{
	return y;
}

bool Players::InRect(int x, int y, Rect r)
{
	if (x >= r.x && x < r.x + r.w && y >= r.y && y < r.y + r.h)
		return true;
	else
		return false;
}

bool Players::Collision0(Enemy* o2)
{
	//method 3 (check if one is inside the other)
	int w1 = al_get_bitmap_width(bmp);
	int h1 = al_get_bitmap_height(bmp);
	int w2 = al_get_bitmap_width(o2->bmp);
	int h2 = al_get_bitmap_height(o2->bmp);
	Rect r;
	r.x = o2->x;
	r.y = o2->y;
	r.w = w2;
	r.h = h2;
	bool in_TopLeft = InRect(x, y, r);
	bool in_TopRight = InRect(x + w1 - 1, y, r);
	bool in_BottomLeft = InRect(x, y + h1 - 1, r);
	bool in_BottomRight = InRect(x + w1 - 1, y + h1 - 1, r);
	if (in_TopLeft || in_TopRight || in_BottomLeft || in_BottomRight)
		return true;
	else
		return false;
}

void Players::Move()
{
	x += sx;
	y += sy;
}

void Players::SetH(int newh)
{
	health += newh;
}

int Players::GetH()
{
	return health;
}