#include "Spaceship.h"

Spaceship::Spaceship(int _upKey, int _downKey, int _leftKey, int _rightKey, int _shootKey): upKey(_upKey), downKey(_downKey), leftKey(_leftKey), rightKey(_rightKey), shootKey(_shootKey)
{
    image = LoadTexture("Resources/spaceship.png");
    speed = 300;
    position.x = (GetScreenWidth() - image.width) / 2;
    position.y = (GetScreenHeight() - (image.height * 1.5));
    health = 3;
    score = 0;
    isOnGround = true;
    velocityY = 0;
    groundLevel = 300.0f;
    CanJump = true;
}

void Spaceship::Update()
{
    Sprite::Update();

    int healthBarWidth = (int)((float)health / 3 * image.width);
    DrawRectangle(position.x, position.y + image.height + 5, healthBarWidth, 10, BLUE);

    if (IsKeyDown(upKey)) position.y -= speed * deltaTime;
    if (IsKeyDown(leftKey)) position.x -= speed * deltaTime;
    if (IsKeyDown(downKey)) position.y += speed * deltaTime;
    if (IsKeyDown(rightKey)) position.x += speed * deltaTime;

    if (position.x > GetScreenWidth()) position.x = -100;
    else if (position.x < -100) position.x = GetScreenWidth();

    if (position.y < 0) position.y = 0;
    if (position.y > GetScreenHeight() - image.height - 20) position.y = GetScreenHeight() - image.height - 20;

    SpawnBullets();
    Jump();

    bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
        [](const std::unique_ptr<Sprite>& bullet) {
            return bullet->GetPosition().y <=0 || bullet->ShouldBeRemoved;
        }), bullets.end());
	for (auto& bullet : bullets) {
		bullet->Update();
	}
}

void Spaceship::SpawnBullets()
{
    if (IsKeyPressed(shootKey) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        bullets.emplace_back(std::make_unique<Bullet>(position.x + image.width / 2, position.y - image.height / 2));
    }
}

void Spaceship::Jump() {
    float gravity = 0.5f;
    float jumpForce = -10.0f;
    if ((IsKeyPressed(shootKey) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON))&&CanJump) {
        CanJump = false;
        velocityY = jumpForce;
        isOnGround = false;
    }
    velocityY += gravity;
    position.y += velocityY;

    if (position.y >= groundLevel) {
        position.y = groundLevel;
        velocityY = 0;
        isOnGround = true;
        CanJump = true;
    }
}

void Spaceship::IncreaseScore()
{
	score++;
}

int Spaceship::GetScore()
{
    return score;
}

int Spaceship::GetHealth()
{
    return health;
}

void Spaceship::CollisionEvent() {
        //score++;
        health--;
}

