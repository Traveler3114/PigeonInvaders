#include "Enemy.h"

Enemy::Enemy(float x, float y)
{
    if (x < GetScreenWidth() / 2) image = LoadTexture("Resources/pigeonleft.png");
    else image = LoadTexture("Resources/pigeonright.png");
    position.x = x;
    position.y = y;
    speed = 180;
}

void Enemy::Update()
{
    Sprite::Update();
    position.y += speed * deltaTime;

    bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
        [](const std::unique_ptr<Sprite>& bullet) {
            return bullet->GetPosition().y > GetScreenHeight() || bullet->ShouldBeRemoved;
        }), bullets.end());
	for (auto& bullet : bullets) {
		bullet->Update();
	}
    //for (int i = bullets.size() - 1; i >= 0; i--) {
    //    bullets[i]->Update();
    //}
}

void Enemy::SpawnBullets()
{
    bullets.emplace_back(std::make_unique<EnemyBullet>(position.x, position.y + image.height / 2));
}

void Enemy::CollisionEvent() {
    ShouldBeRemoved = true;
}
