#pragma once
#include "Sprite.h"
class Bullet : public Sprite
{
public:
	Bullet(float x, float y);
	void Update() override;
	void CollisionEvent() override;
};

