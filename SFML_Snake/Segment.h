// Daniel Harvey
// s6291311
#ifndef SEGMENT_H
#define SEGMENT_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Segment
{
public:
    Segment(int headSize, sf::Vector2f headPosition, sf::Color Colour);
    virtual ~Segment();
    void Render(sf::RenderWindow& window);
    sf::Vector2f segPosition;
    sf::RectangleShape getseg()
    {
        return seg;
    }
    bool getCollides()
    {
        return collides;
    }
    void setCollides(bool a)
    {
        collides = a;
    }

private:
    sf::RectangleShape seg;
    bool collides;
};

#endif // SEGMENT_H
