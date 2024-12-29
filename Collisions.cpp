#include "Collisions.h"

void Collisions::CollisionBulletVsEnemyBullet(std::vector<std::unique_ptr<Sprite>>& Bullets, std::vector<std::unique_ptr<Sprite>>& Enemies)
{

    for (auto& bullet : Bullets) {
        for (auto& enemy : Enemies) {
            auto& enemyRef = dynamic_cast<Enemy&>(*enemy);
            for (auto& enemyBullet : enemyRef.bullets) {
                if (*bullet == *enemyBullet) {
                    bullet->CollisionEvent();
                    enemyBullet->CollisionEvent();
                }
            }
        }
    }
}

void Collisions::CollisionBulletVsEnemy(std::vector<std::unique_ptr<Sprite>>& Bullets, std::vector<std::unique_ptr<Sprite>>& Enemies, Spaceship& spaceship)
{
    for (auto& bullet : Bullets) {
        for (auto& enemy : Enemies) {
            if (*bullet == *enemy) {
                bullet->CollisionEvent();
                enemy->CollisionEvent();
                spaceship.IncreaseScore();
            }
        }
    }
}

void Collisions::CollisionBulletVsBoss(std::vector<std::unique_ptr<Sprite>>& Bullets, Boss& boss)
{
    for (auto& bullet : Bullets) {
        if (*bullet == boss) {
            bullet->CollisionEvent();
            boss.CollisionEvent();
        }
    }
}

void Collisions::CollisionBulletVsBossBullet(std::vector<std::unique_ptr<Sprite>>& Bullets, std::vector<std::unique_ptr<Sprite>>& BossBullets)
{
	for (auto& bullet : Bullets) {
		for (auto& bossBullet : BossBullets) {
			if (*bullet == *bossBullet) {
				bullet->CollisionEvent();
				bossBullet->CollisionEvent();
			}
		}
	}
}

void Collisions::CollisionSpaceshipVsEnemyBullet(Spaceship& spaceship, std::vector<std::unique_ptr<Sprite>>& Enemies)
{
    for (auto& enemy : Enemies) {
        auto& enemyRef = dynamic_cast<Enemy&>(*enemy);
        for (auto& enemyBullet : enemyRef.bullets) {
            if (spaceship == *enemyBullet) {
                spaceship.CollisionEvent();
                enemyBullet->CollisionEvent();
            }
        }
    }
}

void Collisions::CollisionSpaceshipVsEnemy(Spaceship& spaceship, std::vector<std::unique_ptr<Sprite>>& Enemies)
{
    for (auto& enemy : Enemies) {
        if (spaceship == *enemy) {
            spaceship.CollisionEvent();
            enemy->CollisionEvent();
        }
    }
}

void Collisions::CollisionSpaceshipVsBoss(Spaceship& spaceship, Boss& boss)
{
    if (spaceship == boss)
    {
        spaceship.CollisionEvent();
        boss.CollisionEvent();
    }
}

void Collisions::CollisionSpaceshipVsBossBullet(Spaceship& spaceship, std::vector<std::unique_ptr<Sprite>>& BossBullets)
{
    for (auto& bullet : BossBullets) {
        if (spaceship == *bullet) {
            spaceship.CollisionEvent();
            bullet->CollisionEvent();
        }
    }
}
