#include "Game.h"
Game::Game(std::string& screen, std::string& _username) : currentScreen(screen), username(_username)
{
	
    backgroundImage = LoadImage("Resources/background.png");
    ImageResize(&backgroundImage, GetScreenWidth(), GetScreenHeight());
    backgroundTexture = LoadTextureFromImage(backgroundImage);
    spawnTimer = 0.0f;
    fireTimer = 0.0f;
    spawnInterval = 2.0f;
    fireInterval = 1.0f;
    Timer = 0.0f;
}

void Game::Update()
{
    DrawTexture(backgroundTexture, 0, 0, WHITE);
    DrawText(TextFormat("Score: %i", spaceship.GetScore()), 10, 10, 20, WHITE);
    DrawText(TextFormat("Timer: %i", (int)Timer), GetScreenWidth()-90, 10, 20, WHITE);

    float deltaTime = GetFrameTime();
    spawnTimer += deltaTime;
    fireTimer += deltaTime;

    spaceship.Update();
    //spaceship2.Update();
    if (spaceship.GetHealth() <= 0) {
        currentScreen = "GameOver";
		//apiConnection.InsertPlayer(username, spaceship.GetScore(), Timer);
        return;
    }

    if (Timer >= 30 && Timer < 60) {
        spawnInterval = 1.0f;
        fireInterval = 0.5f;
    }
    else if (Timer >= 60 && Timer < 90) {
        spawnInterval = 0.5f;
        fireInterval = 0.25f;
    }

    if ((int)Timer == 90 && !boss.isBossFight) {
        spawnInterval = 0.25f;
        fireInterval = 0.125f;
        enemies.clear();
        boss.isBossFight = true;
    }
    Timer += deltaTime;

    if (boss.isBossFight) {
        boss.Update();
        collisions.CollisionBulletVsBoss(spaceship.bullets, boss);
        collisions.CollisionSpaceshipVsBoss(spaceship, boss);
        collisions.CollisionBulletVsBossBullet(spaceship.bullets, boss.bullets);
        if (fireTimer >= fireInterval) {
            boss.SpawnBullets();
        }
    }
    else {
        SpawnEnemies();
        UpdateEnemies();
        collisions.CollisionBulletVsEnemyBullet(spaceship.bullets, enemies);
        collisions.CollisionBulletVsEnemy(spaceship.bullets, enemies, spaceship);
        collisions.CollisionSpaceshipVsEnemyBullet(spaceship, enemies);
        collisions.CollisionSpaceshipVsEnemy(spaceship, enemies);
    }

    if (fireTimer >= fireInterval) {
        fireTimer = 0.0f;
    }
}

void Game::UpdateEnemies() {
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
        [](const std::unique_ptr<Sprite>& enemy) {
            return enemy->ShouldBeRemoved || enemy->GetPosition().y > GetScreenHeight();
        }), enemies.end());
    for (auto& enemy : enemies) {
        enemy->Update();
        if (fireTimer >= fireInterval) {
            enemy->SpawnBullets();
        }
    }
}

void Game::SpawnEnemies()
{
    if (spawnTimer >= spawnInterval) {
        enemies.emplace_back(std::make_unique<Enemy>(GetRandomValue(0, GetScreenWidth() - 75), -100));
        spawnTimer = 0.0f;
    }
}

void Game::Reset()
{
    spaceship = Spaceship(KEY_W, KEY_S, KEY_A, KEY_D, KEY_SPACE);
    boss = Boss();
    enemies.clear();
    boss.isBossFight = false;
    Timer = 0.0f;
    spawnInterval = 2.0f;
    fireInterval = 1.0f;
    spawnTimer = 0.0f;
    fireTimer = 0.0f;
}

