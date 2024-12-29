#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(float x, float y) {
	//Image fImage = LoadImage("Resources/poop.png");
	//ImageResize(&fImage, GetScreenWidth() * 0.025f, 38.0f * (GetScreenWidth() * 0.025f / 40.0f));
	//image = LoadTextureFromImage(fImage);
	image = LoadTexture("Resources/poop.png");
	speed = 400;
	position.x = x;
	position.y = y;
}

void EnemyBullet::Update()
{
	Sprite::Update();
	position.y += speed*deltaTime;
}

void EnemyBullet::CollisionEvent()
{
	ShouldBeRemoved = true;
}
