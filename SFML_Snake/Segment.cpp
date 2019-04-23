// Daniel Harvey
// s6291311
#include "Segment.h"
Segment::Segment(int headSize, sf::Vector2f headPosition, sf::Color Colour)
{
    seg.setSize(sf::Vector2f(headSize,headSize));
    seg.setFillColor(sf::Color::White);
    seg.setPosition(sf::Vector2f(headPosition.x, headPosition.y));
    collides = false;
}
void Segment::Render(sf::RenderWindow& window)
{
    window.draw(seg);
}
Segment::~Segment()
{
    //dtor
}
