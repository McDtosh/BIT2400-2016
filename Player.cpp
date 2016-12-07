#include "Main.h"

//Global functions used by Collision

//simple structure with info for a rectangle
struct Rect
{
	int x;
	int y;
	int w;
	int h;
};

//check if a point is inside a rectangle
bool InRect(int x, int y, Rect r)
{
	if (x >= r.x && x < r.x + r.w && y >= r.y && y < r.y + r.h)
		return true;
	else
		return false;
}

Player::Player()
{
	collisionMethod = CollisionMethod::TopLeft;
}


Player::~Player()
{
}

bool Player::Collision(GameObject* o1, GameObject* o2)
{
	//method 3 (check if one is inside the other)
	int w1 = al_get_bitmap_width(o1->bmp);
	int h1 = al_get_bitmap_height(o1->bmp);
	int w2 = al_get_bitmap_width(o2->bmp);
	int h2 = al_get_bitmap_height(o2->bmp);
	Rect r;
	r.x = o2->x;
	r.y = o2->y;
	r.w = w2;
	r.h = h2;
	bool in_TopLeft = InRect(o1->x, o1->y, r);
	bool in_TopRight = InRect(o1->x + w1 - 1, o1->y, r);
	bool in_BottomLeft = InRect(o1->x, o1->y + h1 - 1, r);
	bool in_BottomRight = InRect(o1->x + w1 - 1, o1->y + h1 - 1, r);
	if (in_TopLeft || in_TopRight || in_BottomLeft || in_BottomRight)
		return true;
	else
		return false;
}

void Player::Move(GameObject* obj)
{
	obj->x += obj->sx;
	obj->y += obj->sy;
}