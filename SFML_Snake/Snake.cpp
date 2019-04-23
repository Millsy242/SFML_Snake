// Daniel Harvey
// s6291311
#include "Snake.h"

Snake::Snake(unsigned int screenwidth, unsigned int screenheight, sf::Color Colour, int StartX)
{
    //initialise snake
    snakeColour = Colour;
    snakeHead.setSize(sf::Vector2f(headSize,headSize));
    snakeHead.setFillColor(snakeColour);
    sf::Vector2f snakeHeadPOS(StartX,screenwidth/2);
    position = snakeHeadPOS;
}
Snake::~Snake()
{
}
void Snake::Update(std::vector <Collectables> &collectable,std::vector <Snake> &Snakes, int screenwidth,  int screenheight, int border_size, sf::RenderWindow& window, sf::RectangleShape Glue, int Glue_Size)
{
    //Prevent snake moving out of window
    if (position.x > screenwidth-snakeHead.getSize().x-border_size)
    {
        position.x = screenwidth-snakeHead.getSize().x-border_size;
        isAlive = false;
    }
    if (position.y > screenheight-snakeHead.getSize().y-border_size)
    {
        position.y = screenheight-snakeHead.getSize().y-border_size;
        isAlive = false;
    }
    if (position.x < border_size)
    {
        position.x = border_size;
        isAlive = false;
    }
    if (position.y < border_size)
    {
        position.y = border_size;
        isAlive = false;
    }
    //collectable snake collisions
    for (unsigned int b{0}; b < collectable.size(); b++)
    {
        if ((((position.x + headSize) > collectable[b].getPosition().x) && (position.x < (collectable[b].getPosition().x + collectable[b].collectSize)))&&
                (((position.y + headSize) > collectable[b].getPosition().y) && (position.y < (collectable[b].getPosition().y + collectable[b].collectSize))))
        {
            collectable[b].Spawn(screenwidth, screenheight, border_size);
            Score += collectable[b].getaddScore();
            collectable[b].setisActive(false);
            int x{0};
            while(x <= collectable[b].getgrowAmount())
            {
                Segment s(headSize,snakeHead.getPosition(), snakeColour);
                segment.push_front(s);
                x++;
            }
            segment.front().setCollides(false);
        };
    }

    snakeHead.setPosition(position);

    if(currentDirection != eStop)
    {
        segment.push_front(Segment(headSize,position, snakeColour));
        segment.pop_back();
    }

    segment.front().setCollides(false);

    //Check for Snake-tail Collisions
    for(auto &iter : segment)
    {
        if ((((position.x + headSize) > iter.getseg().getPosition().x) && (position.x < (iter.getseg().getPosition().x + headSize)))&&
                (((position.y + headSize) >iter.getseg().getPosition().y) && (position.y < (iter.getseg().getPosition().y + headSize))) && iter.getCollides())
            isAlive = false;
        iter.setCollides(true);
    }
    if(!isAlive) //prevent invisible dead snake killing player
    {
        for(auto &iter : segment)
            iter.setCollides(false);
    }

    for(auto &iter : segment)
    {
        iter.Render(window);
    }
    //Add Glue if snake moves into Glue area
    if ((((position.x + headSize) > Glue.getPosition().x) && (position.x < (Glue.getPosition().x + Glue_Size)))&&
            (((position.y + headSize) > Glue.getPosition().y) && (position.y < (Glue.getPosition().y + Glue_Size))))
        hasGlue = true;

    // Check for head-head collisions
    if ((((Snakes[0].position.x + headSize) > Snakes[1].position.x) && (Snakes[0].position.x < (Snakes[1].position.x + headSize)))&&
            (((Snakes[0].position.y + headSize) > Snakes[1].position.y) && (Snakes[0].position.y < (Snakes[1].position.y + headSize))))
        isAlive = false;

    //SnakeA_Head - SnakeB_Tail
    if(Snakes.size() > 1)
    {
        for (auto &iter0 : Snakes[0].segment)
        {
            //Player 2 collides with Player 1's tail
            if ((((Snakes[1].position.x + headSize) > iter0.getseg().getPosition().x) && (Snakes[1].position.x < (iter0.getseg().getPosition().x + headSize)))&&
                    (((Snakes[1].position.y + headSize) >iter0.getseg().getPosition().y) && (Snakes[1].position.y < (iter0.getseg().getPosition().y + headSize))))
                    Snakes[1].setisAlive(false);
        }
        for (auto &iter1 : Snakes[1].segment)
        {
            //Player 1 collides with Player 2's tail
            if ((((Snakes[0].position.x + headSize) > iter1.getseg().getPosition().x) && (Snakes[0].position.x < (iter1.getseg().getPosition().x + headSize)))&&
                    (((Snakes[0].position.y + headSize) >iter1.getseg().getPosition().y) && (Snakes[0].position.y < (iter1.getseg().getPosition().y + headSize))))
                Snakes[0].setisAlive(false);
        }
    }
}
void Snake::Render(sf::RenderWindow& window)
{
    for(auto &iter : segment)
        window.draw(iter.getseg());
    window.draw(snakeHead);
}
void Snake::ChangeDirection( sf::RenderWindow& window, int border_size, int screenheight, int screenwidth)
{
    switch (currentDirection)
    {
    case eDirection::eEast:
        position.x += movement;
        break;
    case eDirection::eNorth:
        position.y -= movement;
        break;
    case eDirection::eSouth:
        position.y += movement;
        break;
    case eDirection::eWest:
        position.x -= movement;
        break;
    case eDirection::eStop:
        //Do nothing
        break;
    default:
        break;
    }
}
