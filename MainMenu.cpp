#include "MainMenu.h"
#include "raylib.h"

MainMenu::MainMenu(std::string& screen) : currentScreen(screen), textboxActive(false)
{
    titleFontSize = 100;
    titleText = "Pigeon Invaders";

    buttonText = "Leaderboard";
    buttonFontSize = 40;
    buttonWidth = 400;
    buttonHeight = 100;
    buttonX = (GetScreenWidth() / 2) - (buttonWidth / 2);
    buttonY = (GetScreenHeight() / 2) + 150;

    // Initialize Singleplayer and Multiplayer button positions
    spButtonX = (GetScreenWidth() / 2) - buttonWidth - 20;
    spButtonY = (GetScreenHeight() / 2) + 0;
    mpButtonX = (GetScreenWidth() / 2) + 20;
    mpButtonY = (GetScreenHeight() / 2) + 0;

    username = "";
    textboxX = (GetScreenWidth() / 2) - 250;
    textboxY = (GetScreenHeight() / 2) - 100;
    textboxWidth = 500;
    textboxHeight = 75;
}

void MainMenu::Update()
{
    ClearBackground(BLUE);
    DrawText(titleText.c_str(), (GetScreenWidth() / 2) - (MeasureText(titleText.c_str(), titleFontSize) / 2), (GetScreenHeight() / 2) - (titleFontSize / 2) - 300, titleFontSize, WHITE);

    // Draw the "Singleplayer" button
    DrawRectangle(spButtonX, spButtonY, buttonWidth, buttonHeight, LIGHTGRAY);
    int spTextWidth = MeasureText(spButtonText.c_str(), buttonFontSize);
    DrawText(spButtonText.c_str(), spButtonX + (buttonWidth - spTextWidth) / 2, spButtonY + (buttonHeight - buttonFontSize) / 2, buttonFontSize, BLACK);

    // Draw the "Multiplayer" button
    DrawRectangle(mpButtonX, mpButtonY, buttonWidth, buttonHeight, LIGHTGRAY);
    int mpTextWidth = MeasureText(mpButtonText.c_str(), buttonFontSize);
    DrawText(mpButtonText.c_str(), mpButtonX + (buttonWidth - mpTextWidth) / 2, mpButtonY + (buttonHeight - buttonFontSize) / 2, buttonFontSize, BLACK);

    // Draw the "Leaderboard" button
    DrawRectangle(buttonX, buttonY, buttonWidth, buttonHeight, LIGHTGRAY);
    int lbTextWidth = MeasureText(buttonText.c_str(), buttonFontSize);
    DrawText(buttonText.c_str(), buttonX + (buttonWidth - lbTextWidth) / 2, buttonY + (buttonHeight - buttonFontSize) / 2, buttonFontSize, BLACK);

    // Check for button clicks
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePoint = GetMousePosition();

        if (CheckCollisionPointRec(mousePoint, { (float)spButtonX, (float)spButtonY, (float)buttonWidth, (float)buttonHeight })&&!username.empty()) {
            currentScreen = "Game";
        }
        else if (CheckCollisionPointRec(mousePoint, { (float)mpButtonX, (float)mpButtonY, (float)buttonWidth, (float)buttonHeight })) {
            currentScreen = "MainMenuMP";
        }
        else if (CheckCollisionPointRec(mousePoint, { (float)buttonX, (float)buttonY, (float)buttonWidth, (float)buttonHeight })) {
            currentScreen = "Leaderboard";
        }
    }

	//Draw textbox
    DrawRectangle(textboxX, textboxY, textboxWidth, textboxHeight, LIGHTGRAY);
    int usernameTextWidth = MeasureText(username.c_str(), 50);
    DrawText(username.c_str(), textboxX + (textboxWidth - usernameTextWidth) / 2, textboxY + (textboxHeight - 50) / 2, 50, BLACK);

    // Check for textbox click
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, { (float)textboxX, (float)textboxY, (float)textboxWidth, (float)textboxHeight })) {
            textboxActive = true;
        }
        else {
            textboxActive = false;
        }
    }

    // Handle text input
    if (textboxActive) {
        int key = GetKeyPressed();
        while (key > 0) {
            if ((key >= 32) && (key <= 125) && (username.length() < 15)) {
                if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) {
                    username += (char)key;
                }
                else {
                    username += (char)tolower(key);
                }
            }
            if (key == KEY_BACKSPACE && !username.empty()) {
                username.pop_back();
            }
            key = GetKeyPressed();
        }
    }
}

void MainMenu::Reset()
{
    username = "";
}

std::string MainMenu::GetUsername() {
    return username;
}

