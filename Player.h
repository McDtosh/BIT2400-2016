#pragma once

enum CollisionMethod
{
	TopLeft,
	Centre,
	InsideRect
};

class Player
{
public:
	CollisionMethod collisionMethod;

	Player();
	~Player();

	bool Collision(GameObject* o1, GameObject* o2);

	void Move(GameObject* obj);
};

