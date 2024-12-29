#pragma once
#include <string>
#include <vector>
#include <map>
class APIConnection
{
public:
	void InsertPlayer(std::string username, int score, int timer);
	std::vector<std::map<std::string, std::string>> GetPlayers();
private:
	std::vector<std::map<std::string, std::string>> players;
};

