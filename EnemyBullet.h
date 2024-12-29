#pragma once
#include "Sprite.h"
class EnemyBullet : public Sprite
{
public:
	EnemyBullet(float x, float y);
	void Update() override;
	void CollisionEvent() override; 
};

