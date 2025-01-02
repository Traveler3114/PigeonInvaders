#include "APIConnection.h"
#include <iostream>
#include <sstream>
#include <iomanip> // For std::setw and std::setfill
#include "httplib.h"
#include <nlohmann/json.hpp>

// Declare the client instance here
httplib::Client client("http://localhost:5181");

void APIConnection::InsertPlayer(std::string username, int score, int timer)
{
    // Convert timer to "HH:MM:SS" format
    int hours = timer / 3600;
    int minutes = (timer % 3600) / 60;
    int seconds = timer % 60;

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << hours << ":"
        << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << seconds;

    std::string formattedTime = oss.str();

    // Construct JSON data
    nlohmann::json player_data = {
        {"Username", username},
        {"Score", score},
        {"Timer", formattedTime}
    };

    // Send a POST request to add player data
    auto res = client.Post("/api/Values/AddPlayer", player_data.dump(), "application/json");

    // Check if the request was successful
    if (res && res->status == 200) {
        std::cout << "Player added successfully: " << res->body << std::endl;
    }
    else {
        std::cerr << "Error: Unable to connect to the API or post data!" << std::endl;
        if (res) {
            std::cerr << "HTTP Status: " << res->status << "\nResponse Body: " << res->body << std::endl;
        }
    }
}

std::vector<std::map<std::string, std::string>> APIConnection::GetPlayers()
{
    std::vector<std::map<std::string, std::string>> players;
    auto res = client.Get("/api/Values/GetPlayers");

    // Check if the request was successful
    if (res && res->status == 200) {
        std::cout << "Players fetched successfully:\n" << res->body << std::endl;

        try {
            // Parse JSON response
            auto jsonResponse = nlohmann::json::parse(res->body);

            // Ensure it's an array of players
            if (!jsonResponse.is_array()) {
                std::cerr << "Error: JSON response is not an array!" << std::endl;
                return players;
            }

            for (const auto& player : jsonResponse) {
                std::map<std::string, std::string> playerData;

                // Access lowercase keys
                if (player.contains("username")) {
                    playerData["Username"] = player["username"].get<std::string>();
                }
                else {
                    playerData["Username"] = "Unknown";
                }

                if (player.contains("score")) {
                    playerData["Score"] = std::to_string(player["score"].get<int>());
                }
                else {
                    playerData["Score"] = "0";
                }

                if (player.contains("timer")) {
                    playerData["Timer"] = player["timer"].get<std::string>();
                }
                else {
                    playerData["Timer"] = "00:00:00";
                }

                players.push_back(playerData);
            }
        }
        catch (const std::exception& ex) {
            std::cerr << "Error parsing JSON response: " << ex.what() << std::endl;
        }
    }
    else {
        std::cerr << "Error: Unable to connect to the API or fetch data!" << std::endl;
        if (res) {
            std::cerr << "HTTP Status: " << res->status << "\nResponse Body: " << res->body << std::endl;
        }
    }

    return players;
}