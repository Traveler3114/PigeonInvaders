#pragma once
#include "Sprite.h"
#include "EnemyBullet.h"
class Boss : public Sprite
{
public:
	Boss();
	void Update() override;
	int GetHealth();
	bool isBossFight;
	void CollisionEvent() override;
	void SpawnBullets() override;
	std::vector<std::unique_ptr<Sprite>> bullets;
private:
	int health;
	
};

