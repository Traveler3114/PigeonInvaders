#include <string>

class MainMenu {
public:
    MainMenu(std::string& screen);
    void Update();

    void Reset();

    std::string GetUsername();

private:
    std::string& currentScreen;
    std::string username;
    bool textboxActive;
    int titleFontSize;
    std::string titleText;

    // Button properties
    std::string buttonText;
    int buttonFontSize;
    int buttonWidth;
    int buttonHeight;
    int buttonX;
    int buttonY;

    // Additional buttons
    std::string spButtonText = "Singleplayer";
    std::string mpButtonText = "Multiplayer";
    int spButtonX;
    int spButtonY;
    int mpButtonX;
    int mpButtonY;

    int textboxX;
    int textboxY;
    int textboxWidth;
    int textboxHeight;
};



