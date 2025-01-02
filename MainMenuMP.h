#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <mutex>
#include <thread>


class MainMenuMP
{
public:
	MainMenuMP(std::string& screen, std::string& _username);
	void Update();
private:
	std::string& currentScreen;
	std::string& username;
    std::mutex playersMutex;
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
    Client client;

	bool isServerRunning = false;

	std::vector<std::string> players;
};

