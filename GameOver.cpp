#include "GameOver.h"

GameOver::GameOver(std::string& screen, std::string& _username) : currentScreen(screen), username(_username)
{
    titleFontSize = 100;
    instructionFontSize = 50;
    gameOverText = "Game Over";
    instructionText = "Press Enter to play again";
    instructionText2 = "Press Esc to exit";

    // Initialize button position
    buttonX = GetScreenWidth() / 2 - buttonWidth / 2;
    buttonY = GetScreenHeight() - buttonHeight - 20;
}

void GameOver::Update()
{
    ClearBackground(RED);
    DrawText(gameOverText, (GetScreenWidth() / 2) - (MeasureText(gameOverText, titleFontSize) / 2), (GetScreenHeight() / 2) - (titleFontSize / 2) - 50, titleFontSize, WHITE);
    DrawText(instructionText, (GetScreenWidth() / 2) - (MeasureText(instructionText, instructionFontSize) / 2), (GetScreenHeight() / 2) - (instructionFontSize / 2) + 20, instructionFontSize, WHITE);
    DrawText(instructionText2, (GetScreenWidth() / 2) - (MeasureText(instructionText2, instructionFontSize) / 2), (GetScreenHeight() / 2) - (instructionFontSize / 2) + 80, instructionFontSize, WHITE);

    // Draw the "Back to Main Menu" button
    DrawRectangle(buttonX, buttonY, buttonWidth, buttonHeight, LIGHTGRAY);
    DrawText("Back to Main Menu", buttonX + (buttonWidth - MeasureText("Back to Main Menu",30)) / 2, buttonY + (buttonHeight - 30) / 2, 30, BLACK);

    // Check for button click
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, { (float)buttonX, (float)buttonY, (float)buttonWidth, (float)buttonHeight })) {
            currentScreen = "MainMenu";
        }
    }

    // Check for Enter key press
    if (IsKeyDown(KEY_ENTER)) {
        currentScreen = "Game";
    }
}

