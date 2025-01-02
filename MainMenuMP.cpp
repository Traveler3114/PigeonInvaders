#include "raylib.h"
#include "MainMenuMP.h"
#include <iostream>

MainMenuMP::MainMenuMP(std::string& screen, std::string& _username) : currentScreen(screen), username(_username)
{

    buttonText = "Main Menu";
    buttonFontSize = 40;
    buttonWidth = 400;
    buttonHeight = 100;
    buttonX = (GetScreenWidth() / 2) - (buttonWidth / 2);
    buttonY = (GetScreenHeight() / 2) + 150;

    // Initialize Singleplayer and Multiplayer button positions
    csButtonX = (GetScreenWidth() / 2) - buttonWidth - 20;
    csButtonY = (GetScreenHeight() / 2) + 0;
    fsButtonX = (GetScreenWidth() / 2) + 20;
    fsButtonY = (GetScreenHeight() / 2) + 0;

}

void MainMenuMP::Update()
{   
	if (!isServerRunning) {
        ClearBackground(BLUE);

        DrawText(username.c_str(), (GetScreenWidth() - MeasureText(username.c_str(), 50)) / 2, 100, 50, BLACK);
        // Draw the "CreateSession" button
        DrawRectangle(csButtonX, csButtonY, buttonWidth, buttonHeight, LIGHTGRAY);
        int csTextWidth = MeasureText("Create a session", buttonFontSize);
        DrawText("Create a session", csButtonX + (buttonWidth - csTextWidth) / 2, csButtonY + (buttonHeight - buttonFontSize) / 2, buttonFontSize, BLACK);

        // Draw the "FindSession" button
        DrawRectangle(fsButtonX, fsButtonY, buttonWidth, buttonHeight, LIGHTGRAY);
        int fsTextWidth = MeasureText("Find a session", buttonFontSize);
        DrawText("Find a session", fsButtonX + (buttonWidth - fsTextWidth) / 2, fsButtonY + (buttonHeight - buttonFontSize) / 2, buttonFontSize, BLACK);

        // Draw the "Back" button
        DrawRectangle(buttonX, buttonY, buttonWidth, buttonHeight, LIGHTGRAY);
        int backTextWidth = MeasureText(buttonText.c_str(), buttonFontSize);
        DrawText(buttonText.c_str(), buttonX + (buttonWidth - backTextWidth) / 2, buttonY + (buttonHeight - buttonFontSize) / 2, buttonFontSize, BLACK);

        // Check for button click
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePoint = GetMousePosition();

            if (CheckCollisionPointRec(mousePoint, { (float)csButtonX, (float)csButtonY, (float)buttonWidth, (float)buttonHeight }) && !username.empty()) {

            }
            else if (CheckCollisionPointRec(mousePoint, { (float)fsButtonX, (float)fsButtonY, (float)buttonWidth, (float)buttonHeight })) {
            }
            else if (CheckCollisionPointRec(mousePoint, { (float)buttonX, (float)buttonY, (float)buttonWidth, (float)buttonHeight })) {
                currentScreen = "MainMenu";
            }
        }
	}
    else {
		ClearBackground(BLUE);
		DrawText("Server is running...", 10, 10, 20, WHITE);
        DrawText("Player", 100, 50, 20, WHITE);
        DrawText("Username", 300, 50, 20, WHITE);

        // Example player data
        std::vector<std::string> players = { "Player1", "Player2", "Player3" };
        std::vector<std::string> usernames = { "User1", "User2", "User3" };

        // Get the player list from the client
		players=client.GetPlayerList();

        // Draw table rows
        for (size_t i = 0; i < players.size(); ++i) {
            DrawText(players[i].c_str(), 100, 100 + i * 30, 20, WHITE);
            DrawText(usernames[i].c_str(), 300, 100 + i * 30, 20, WHITE);
        }
    }
}
