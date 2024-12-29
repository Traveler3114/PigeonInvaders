#include "raylib.h"
#include "APIConnection.h"
#include <vector>
#include <memory>
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Spaceship.h"
#include "Boss.h"
#include "Collisions.h"
#include <string>


class Game
{
public:
	Game(std::string& screen,std::string& _username);
    void Update();
    void UpdateEnemies();
    void SpawnEnemies();
	void Reset();
private:
	std::string& currentScreen;
    std::string& username;
    Spaceship spaceship = Spaceship(KEY_W, KEY_S, KEY_A, KEY_D, KEY_SPACE);
    Image backgroundImage;
    Texture2D backgroundTexture;
    Boss boss;
    Collisions collisions;
	APIConnection apiConnection;
    float spawnTimer;
    float spawnInterval;
    float fireTimer ;
    float fireInterval;
    float Timer;
    std::vector<std::unique_ptr<Sprite>> enemies;
};