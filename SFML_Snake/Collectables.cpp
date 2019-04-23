// Daniel Harvey
// s6291311
 #include "Collectables.h"

Collectables::Collectables(int screenWidth, int screenHeight, int border_size)
{
    collectMe.setSize(sf::Vector2f(collectSize,collectSize));
}
void Collectables::Spawn(int screenWidth, int screenHeight, int border_size)
{
    int boundary = border_size + collectSize + 10;

    int innerBoundX = screenWidth - boundary;
    int innerBoundY = screenHeight - boundary;

    collectX = rand() % innerBoundX + 10;
    collectY = rand() % innerBoundY + 10;

    sf::Vector2f collectMePosition(collectX, collectY);
    collectPOS = collectMePosition;
    collectMe.setPosition(collectPOS);

    int A = rand() % 5 + 1;
    growAmount = A;
    addScore = 100 * growAmount;
    if (A == 1)
        collectColour = sf::Color::Green;
    if (A == 2)
        collectColour = sf::Color::Yellow;
    if (A == 3)
        collectColour = sf::Color::Blue;
    if (A == 4)
        collectColour = sf::Color::Black;
    if (A == 5)
        collectColour = sf::Color::Cyan;

    collectMe.setFillColor(collectColour);
}
void Collectables::Render(sf::RenderWindow &window) const
{
    if(isActive)
        window.draw(collectMe);

}
Collectables::~Collectables()
{
}

