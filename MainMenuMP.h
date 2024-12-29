#pragma once
#include <string>
class MainMenuMP
{
public:
	MainMenuMP(std::string& screen);
	void Update();
private:
	std::string& currentScreen;
};

