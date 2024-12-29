#include "Leaderboard.h"
#include <iostream>

Leaderboard::Leaderboard(std::string& screen) : currentScreen(screen)
{
    cellWidth = GetScreenWidth() / columnCount - 30;
    int tableWidth = cellWidth * columnCount;
    tableX = (GetScreenWidth() - tableWidth) / 2;

    // Initialize button position
    buttonX= (GetScreenWidth() - tableWidth) / 2;
    buttonY = 20;
}

void Leaderboard::Update()
{
    ClearBackground(RAYWHITE);
    DrawText("Leaderboard", GetScreenWidth() / 2 - (MeasureText("Leaderboard", 40) / 2), 20, 40, LIGHTGRAY);
    Users = apiConnection.GetPlayers();

    DrawTable(tableX, tableY, cellWidth, cellHeight, Users);

    // Draw the "Back" button
    DrawRectangle(buttonX, buttonY, buttonWidth, buttonHeight, LIGHTGRAY);
    DrawText("Back", buttonX + (buttonWidth-MeasureText("Back",20))/2, buttonY + 10, 20, BLACK);

    // Check for button click
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, { (float)buttonX, (float)buttonY, (float)buttonWidth, (float)buttonHeight })) {
            currentScreen = "MainMenu";
        }
    }
}

void Leaderboard::DrawTable(int x, int y, int cellWidth, int cellHeight, const std::vector<std::map<std::string, std::string>>& data) {
    int rowCount = data.size();
    int tableWidth = cellWidth * columnCount;  // 3 columns: Username, Score, Timer

    // Draw table header
    DrawRectangle(x, y, tableWidth, cellHeight, GRAY);
    DrawText("Username", x + 10, y + 10, 20, BLACK);
    DrawText("Score", x + cellWidth + 10, y + 10, 20, BLACK);
    DrawText("Timer", x + 2 * cellWidth + 10, y + 10, 20, BLACK);

    // Draw rows
    for (int i = 0; i < rowCount; i++) {
        int rowY = y + (i + 1) * cellHeight;

        // Alternate row colors for better readability
        Color rowColor = (i % 2 == 0) ? LIGHTGRAY : RAYWHITE;
        DrawRectangle(x, rowY, tableWidth, cellHeight, rowColor);

        // Draw data
        DrawText(data[i].at("Username").c_str(), x + 10, rowY + 10, 20, BLACK);
        DrawText(data[i].at("Score").c_str(), x + cellWidth + 10, rowY + 10, 20, BLACK);
        DrawText(data[i].at("Timer").c_str(), x + 2 * cellWidth + 10, rowY + 10, 20, BLACK);
    }

    // Draw grid lines
    for (int i = 0; i <= rowCount + 1; i++) {
        int lineY = y + i * cellHeight;
        DrawLine(x, lineY, x + tableWidth, lineY, BLACK);
    }
    for (int i = 0; i <= columnCount; i++) {  // 3 columns
        int lineX = x + i * cellWidth;
        DrawLine(lineX, y, lineX, y + (rowCount + 1) * cellHeight, BLACK);
    }
}

