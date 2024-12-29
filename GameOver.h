#pragma once
#include "raylib.h"
#include <string>
class GameOver
{
public:
	GameOver(std::string& screen,std::string& _username);
	void Update();
private:
	std::string& currentScreen;
	std::string& username;
	const char* gameOverText;
	const char* instructionText;
	const char* instructionText2;
	int titleFontSize;
	int instructionFontSize;

	// Button properties
	int buttonX;
	int buttonY;
	int buttonWidth = 300;
	int buttonHeight = 75;
};

