#pragma once
#include "Sprite.h"
#include "Spaceship.h"
#include "Enemy.h"
#include "Boss.h"
#include "EnemyBullet.h"
#include "Bullet.h"
class Collisions
{
public:
	void CollisionBulletVsEnemyBullet(std::vector<std::unique_ptr<Sprite>>& Bullets , std::vector<std::unique_ptr<Sprite>>& Enemies);
	void CollisionBulletVsEnemy(std::vector<std::unique_ptr<Sprite>>& Bullets, std::vector<std::unique_ptr<Sprite>>& Enemies, Spaceship& spaceship);
	void CollisionBulletVsBoss(std::vector<std::unique_ptr<Sprite>>& Bullets, Boss& boss);
	void CollisionBulletVsBossBullet(std::vector<std::unique_ptr<Sprite>>& Bullets, std::vector<std::unique_ptr<Sprite>>& BossBullets);
	void CollisionSpaceshipVsEnemyBullet(Spaceship& spaceship, std::vector<std::unique_ptr<Sprite>>& Enemies);
	void CollisionSpaceshipVsEnemy(Spaceship& spaceship, std::vector<std::unique_ptr<Sprite>>& Enemies);
	void CollisionSpaceshipVsBoss(Spaceship& spaceship, Boss& boss);
	void CollisionSpaceshipVsBossBullet(Spaceship& spaceship, std::vector<std::unique_ptr<Sprite>>& BossBullets);
};

