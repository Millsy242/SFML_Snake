// Daniel Harvey
// s6291311
#ifndef SNAKE_H
#define SNAKE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include "Collectables.h"
#include "Game.h"
#include "Segment.h"

enum eDirection {eStop, eSouth, eNorth, eEast, eWest};

class Snake
{
public:
    Snake(unsigned int screenWidth, unsigned int screenHeight, sf::Color Colour, int startX);
    virtual ~Snake();
    void Update(std::vector <Collectables> &collectable, std::vector <Snake> &Snakes,  int screenWidth,  int screenHeight, int border_size, sf::RenderWindow& window, sf::RectangleShape Glue, int Glue_Size);
    void Render(sf::RenderWindow& window);
    void ChangeDirection(sf::RenderWindow& window, int border_size, int screenHeight, int screenWidth);
    int Score{0};
    eDirection currentDirection {eStop};
    eDirection lastDirection;
    bool gethasGlue()
    {
        return hasGlue;
    };
    void addGlue(bool glue)
    {
        hasGlue = glue;
    };
    sf::Color getsnakeColour()
    {
        return snakeColour;
    };
    bool getisAlive()
    {
        return isAlive;
    };
    void setisAlive(bool Alive)
    {
        isAlive = Alive;
    };

private:
    int movement{11};
    sf::RectangleShape snakeHead;
    sf::Vector2f position;
    int headSize {10};
    std::list <Segment> segment;
    sf::Color snakeColour;
    bool hasGlue{false};
    bool isAlive{true};
};

#endif // SNAKE_H
