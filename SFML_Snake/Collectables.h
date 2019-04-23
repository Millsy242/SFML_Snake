// Daniel Harvey
// s6291311
#ifndef COLLECTABLES_H
#define COLLECTABLES_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Collectables
{
public:
    Collectables(int screenWidth, int screenHeight,int borderSize);
    virtual ~Collectables();
    void Spawn(int screenWidth, int screenHeight, int borderSize);
    sf::Vector2f getPosition() const
    {
        return collectPOS;
    }
    void Render (sf::RenderWindow &window) const;

    void setisActive(bool activate )
    {
        isActive = activate;
    };
    bool getisActive()
    {
        return isActive;
    };
    int collectSize {5};
    int getgrowAmount()
    {
        return growAmount;
    }
    int getaddScore()
    {
        return addScore;
    }

private:
    sf::Vector2f collectPOS; //collectable position
    bool isActive{false}; // default false
    sf::RectangleShape collectMe;
    int collectX;
    int collectY;
    int growAmount{0};
    int addScore{10};
    sf::Color collectColour;
};

#endif // COLLECTABLES_H
