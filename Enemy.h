#pragma once
#include "Sprite.h"
#include "EnemyBullet.h"
class Enemy : public Sprite
{
public:
	Enemy(float x, float y);
	void Update() override;
	void CollisionEvent() override;
	void SpawnBullets() override;
	std::vector<std::unique_ptr<Sprite>> bullets;
private:
	
	
};

