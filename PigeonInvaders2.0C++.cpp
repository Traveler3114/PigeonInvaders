#include "raylib.h"
#include "MainMenu.h"
#include "MainMenuMP.h"
#include "Game.h"
#include "GameOver.h"
#include "Leaderboard.h"

std::string currentScreen = "MainMenu";
bool gameReset = false;

int main() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    //const int screenWidth = 1280;
    //const int screenHeight = 720;

    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(screenWidth, screenHeight, "Pigeon Invaders");
    SetTargetFPS(60);
    MainMenu mainMenu(currentScreen);
	std::string currentUsername;
    MainMenuMP mainMenuMP(currentScreen, currentUsername);
    Game game(currentScreen, currentUsername);
    GameOver gameOver(currentScreen, currentUsername);
    Leaderboard leaderboard(currentScreen);

    while (!WindowShouldClose()) {
		//currentScreen = "GameOver";
        BeginDrawing();
        ClearBackground(RAYWHITE);

		if (currentScreen == "MainMenu") {
			mainMenu.Update();
            currentUsername = mainMenu.GetUsername();
		}
		else if (currentScreen == "MainMenuMP") {
			mainMenuMP.Update();
		}
        else if (currentScreen == "Game") {
            game.Update();
            if (gameReset) gameReset = false;
        }
        else if (currentScreen == "GameOver") {
            gameOver.Update();
            if (!gameReset) {
                mainMenu.Reset();
                game.Reset();
                gameReset = true;
            }
        }
        else if (currentScreen == "Leaderboard") {
            leaderboard.Update();
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
