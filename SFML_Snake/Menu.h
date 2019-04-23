// Daniel Harvey
// s6291311
#ifndef MENU_H
#define MENU_H
#include "Game.h"
#include <vector>
class Menu
{
public:
    Menu();
    virtual ~Menu();
    void runMenu(sf::RenderWindow& menuWindow);
    void settingsMenu(sf::RenderWindow& menuWindow, sf::Sprite playSprite, sf::Sprite exitSprite);

private:
    std::vector <sf::Sprite>  buttonSprites;
    int AA{0};
    bool Vsync{false};
    int resX{800};
    int resY{600};
    int numPlayers{1};
    sf::Vector2i mousePOS;
};

#endif // MENU_H
