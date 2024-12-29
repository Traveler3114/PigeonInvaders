#pragma once
#include "Sprite.h"
#include "Bullet.h"
#include <memory>
#include "raylib.h"
class Spaceship : public Sprite
{
public:
	Spaceship(int _upKey, int _downKey, int _leftKey, int _rightKey, int _shootKey);
	void Update() override;
	int GetScore();
	int GetHealth();
	void CollisionEvent() override;
	void SpawnBullets() override;
	void IncreaseScore();
	std::vector<std::unique_ptr<Sprite>> bullets;
private:
	int health;
	int score;
	int upKey;
	int downKey;
	int leftKey;
	int rightKey;
	int shootKey;
};



