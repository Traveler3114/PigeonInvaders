#include "Boss.h"

Boss::Boss() {
    Image fImage = LoadImage("Resources/boss.png");
    ImageResize(&fImage, GetScreenWidth() * 0.3f, 532.0f * ((float)GetScreenWidth() * 0.3f / 590.f));
    image = LoadTextureFromImage(fImage);
    health = 100;
    position.x = 0;
    position.y = 25;
    speed = 180;
    isBossFight = false;
}


void Boss::Update()
{
    if (health <= 0) {
        return;
    }

    Sprite::Update();
    int healthBarWidth = (int)((float)health / 100 * image.width);
    DrawRectangle(position.x, position.y - 20, healthBarWidth, 10, RED);

    if (position.x > GetScreenWidth() - image.width) {
        speed = -180;
    }
    else if (position.x < 0) {
        speed = 180;
    }
    position.x += speed * deltaTime;

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

int Boss::GetHealth()
{
    return health;
}

void Boss::CollisionEvent()
{
    health--;
    if (health <= 0) {
		isBossFight = false;
		UnloadTexture(image);
		bullets.clear();
    }
}

void Boss::SpawnBullets()
{
    if (health <= 0) {
        return;
    }

    bullets.emplace_back(std::make_unique<EnemyBullet>(position.x, position.y + image.height));
    bullets.emplace_back(std::make_unique<EnemyBullet>(position.x + image.width * 0.2, position.y + image.height));
    bullets.emplace_back(std::make_unique<EnemyBullet>(position.x + image.width * 0.4, position.y + image.height));
    bullets.emplace_back(std::make_unique<EnemyBullet>(position.x + image.width * 0.6, position.y + image.height));
    bullets.emplace_back(std::make_unique<EnemyBullet>(position.x + image.width * 0.8, position.y + image.height));
}
