#pragma once
#include <string>
class MainMenuMP
{
public:
	MainMenuMP(std::string& screen, std::string& _username);
	void Update();
private:
	std::string& currentScreen;
	std::string& username;
    // Button properties
    std::string buttonText;
    int buttonFontSize;
    int buttonWidth;
    int buttonHeight;
    int buttonX;
    int buttonY;

    int csButtonX;
    int csButtonY;
    int fsButtonX;
    int fsButtonY;
};

