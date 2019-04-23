// Daniel Harvey
// s6291311
#ifndef GAME_H
#define GAME_H
#include <cmath>
#include "Collectables.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <sstream>

class Snake;
class Menu;

class Game
{
public:
    Game(int AA, bool Vsync,  int ResX, int ResY, int numplayers);

    virtual ~Game();
    void run(sf::RenderWindow& window);
    void End(sf::RenderWindow& window);

private:
    int numberofPlayers{1};
    int borderSize{5};
    std::vector <Collectables> collectable;
    std::vector <Snake> Snakes;
    sf::Color borderColour{sf::Color::Blue};
    sf::RectangleShape Glue;
    sf::Vector2f gluePosition;
    int glueSize{0};
    unsigned int numberofSnakes{0};
};

#endif // GAME_H
