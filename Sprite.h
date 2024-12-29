#pragma once
#include "raylib.h"
#include <vector>
#include <memory>
class Sprite
{
public:
	virtual void Update();
	Vector2 GetPosition();
	Texture2D GetImage();
	virtual void CollisionEvent() = 0;
	bool operator ==(const Sprite& other);
	virtual ~Sprite() = default;
	bool ShouldBeRemoved = false;
	virtual void SpawnBullets();
protected:
	Vector2 position;
	Texture2D image;
	int speed;
	float deltaTime;
};
