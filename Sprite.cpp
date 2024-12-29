#include "Sprite.h"
#include <algorithm> 

void Sprite::Update()
{
	DrawTexture(image, position.x, position.y, WHITE);
    deltaTime = GetFrameTime();
}



Vector2 Sprite::GetPosition() {
	return position;
}

Texture2D Sprite::GetImage()
{
	return image;
}



bool Sprite::operator==(const Sprite& other)
{
	if (this == &other) {
		return false;
	}

    float leftA = position.x;
    float rightA = position.x + image.width;
    float topA = position.y;
    float bottomA = position.y + image.height;

    float leftB = other.position.x;
    float rightB = other.position.x + other.image.width;
    float topB = other.position.y;
    float bottomB = other.position.y + other.image.height;

    return !(rightA <= leftB || leftA >= rightB || bottomA <= topB || topA >= bottomB);
}

void Sprite::SpawnBullets()
{
}




