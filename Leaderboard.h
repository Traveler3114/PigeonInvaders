#pragma once
#include "raylib.h"
#include <map>
#include <string>
#include <vector>
#include "APIConnection.h"
class Leaderboard{
private:
	std::string& currentScreen; 
	std::vector<std::map<std::string, std::string>> Users;
	APIConnection apiConnection;
	int tableX;              // Top-left corner of the table
	int tableY = 100;
	int cellWidth;
	int cellHeight = 40;     // Height of each cell
	int columnCount = 3;

	// Button properties
	int buttonX;
	int buttonY;
	int buttonWidth = 100;
	int buttonHeight = 40;
public:
	Leaderboard(std::string& screen);
	void Update();
	void DrawTable(int x, int y, int cellWidth, int cellHeight, const std::vector<std::map<std::string, std::string>>& data);
};

