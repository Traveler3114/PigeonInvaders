#include "Bullet.h"


Bullet::Bullet(float x, float y) {
	//Image fImage = LoadImage("Resources/laser.png");
	//ImageResize(&fImage, GetScreenWidth() * 0.005f, 54.0f * (GetScreenWidth() * 0.005f / 8.0f));
	//image = LoadTextureFromImage(fImage);
	image = LoadTexture("Resources/laser.png");
	speed = 300;
	position.x = x;
	position.y = y;
}

void Bullet::Update()
{
	Sprite::Update();
	position.y -= speed*deltaTime;
}

void Bullet::CollisionEvent()
{
	ShouldBeRemoved = true;
}
