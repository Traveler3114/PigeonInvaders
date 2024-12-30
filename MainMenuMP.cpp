#include "MainMenuMP.h"
#include "raylib.h"

MainMenuMP::MainMenuMP(std::string& screen, std::string& _username) : currentScreen(screen), username(_username)
{
    buttonText = "Main Menu";
    buttonFontSize = 40;
    buttonWidth = 400;
    buttonHeight = 100;
    buttonX = (GetScreenWidth() / 2) - (buttonWidth / 2);
    buttonY = (GetScreenHeight() / 2) + 150;

    csButtonX = (GetScreenWidth() / 2) - buttonWidth - 20;
    csButtonY = (GetScreenHeight() / 2) + 0;
    fsButtonX = (GetScreenWidth() / 2) + 20;
    fsButtonY = (GetScreenHeight() / 2) + 0;
}

void MainMenuMP::Update()
{
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
            currentScreen = "CreateASession";
        }
        else if (CheckCollisionPointRec(mousePoint, { (float)fsButtonX, (float)fsButtonY, (float)buttonWidth, (float)buttonHeight })) {
            currentScreen = "FindASession";
        }
        else if (CheckCollisionPointRec(mousePoint, { (float)buttonX, (float)buttonY, (float)buttonWidth, (float)buttonHeight })) {
            currentScreen = "MainMenu";
        }
    }
}
