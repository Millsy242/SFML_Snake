// Daniel Harvey
// s6291311
#include "Game.h"
#include "Snake.h"
#include "Menu.h"

Game::Game(int AA, bool Vsync,  int ResX, int ResY, int numplayers)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = AA;
    sf::RenderWindow window(sf::VideoMode(ResX,ResY), "C++ Snake ICA : s6291311", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(Vsync);
    srand((unsigned int)time(0));
    numberofPlayers = numplayers;
    run(window);
}
void Game::run(sf::RenderWindow& window)
{
    window.setActive(true);
    sf::Clock gameClock; //start gameClock
    sf::Clock delay; //clock for delay

    unsigned int screenwidth = window.getSize().x;
    unsigned int screenheight = window.getSize().y;

    //Glue
    glueSize = screenheight/8;
    sf::RectangleShape Glue(sf::Vector2f(glueSize, glueSize));
    Glue.setFillColor(sf::Color::Cyan);
    Glue.setOutlineThickness(5);
    Glue.setOutlineColor(sf::Color::Black);
    sf::Vector2f gluePosition(500,200);
    Glue.setPosition(gluePosition);

    if(numberofPlayers == 1)
        Snakes.push_back(Snake(screenheight, screenwidth, sf::Color(124,252,0), screenwidth/2));
    else
    {
        Snakes.push_back(Snake(screenheight, screenwidth, sf::Color(124,252,0), screenwidth*0.75)); //player_1
        Snakes.push_back(Snake(screenheight, screenwidth, sf::Color(135,206,235),screenwidth/4 ));//player_2
    }

    //create 5 collectables
    for(int i{0}; i<=5; i++)
        collectable.push_back(Collectables(screenheight, screenwidth, borderSize));

    sf::Font font;
    font.loadFromFile("fonts/Strange_Path.ttf");
    if(!font.loadFromFile("fonts/Strange_Path.ttf"))
        std::cout<<"ERROR: Cant find font"<<std::endl;

    sf::Text timeText;
    timeText.setFont(font);
    timeText.setCharacterSize(24);
    timeText.setFillColor(sf::Color::White);

    sf::Text ScoreTextP1;
    ScoreTextP1.setFont(font);
    ScoreTextP1.setCharacterSize(24);
    ScoreTextP1.setFillColor(Snakes[0].getsnakeColour());

    sf::Text ScoreTextP2;
    ScoreTextP2.setFont(font);
    ScoreTextP2.setCharacterSize(24);
    ScoreTextP2.setFillColor(Snakes[1].getsnakeColour());

    //Borders
    sf::RectangleShape top_border(sf::Vector2f(screenwidth, borderSize));
    sf::Vector2f top_borderPosition(0,0);
    sf::RectangleShape bottom_border(sf::Vector2f(screenwidth, borderSize));
    sf::Vector2f bottom_borderPosition(0,(screenheight-borderSize));
    sf::RectangleShape left_border(sf::Vector2f(screenheight, borderSize));
    left_border.rotate(90);
    sf::Vector2f right_borderPosition(borderSize,0);
    sf::RectangleShape right_border(sf::Vector2f(screenheight, borderSize));
    right_border.rotate(90);
    sf::Vector2f left_borderPosition(screenwidth,0);

    //Spawn 5 Collectables
    for(unsigned int s{0}; s<collectable.size(); s++)
        collectable[s].Spawn(screenwidth, screenheight, borderSize);

    //Glue indicator overlay's
    sf::Texture P1_Gluetexture;
    if (!P1_Gluetexture.loadFromFile("textures/P1_Glue.png"))
        std::cerr << "no texture" << std::endl;
    sf::Sprite P1_GlueSprite;
    P1_GlueSprite.setTexture(P1_Gluetexture);
    P1_GlueSprite.setOrigin(25,25);
    P1_GlueSprite.setPosition(screenwidth-borderSize-75, screenheight-borderSize-25);

    sf::Texture P2_Gluetexture;
    if (!P2_Gluetexture.loadFromFile("textures/P2_Glue.png"))
        std::cerr << "no texture" << std::endl;
    sf::Sprite P2_GlueSprite;
    P2_GlueSprite.setTexture(P2_Gluetexture);
    P2_GlueSprite.setOrigin(25,25);
    P2_GlueSprite.setPosition(screenwidth-borderSize-25, screenheight-borderSize-25);

    //While Loop
    while (window.isOpen())
    {
        top_border.setFillColor(borderColour);
        left_border.setFillColor(borderColour);
        right_border.setFillColor(borderColour);
        bottom_border.setFillColor(borderColour);

        numberofSnakes = 0; //reset number of alive snakes to ensure no snakes died last frame
        for(unsigned int i{0}; i<Snakes.size(); i++)
        {
            if(Snakes[i].getisAlive())
                numberofSnakes++;
        }
        for(unsigned int n{0}; n<Snakes.size(); n++)
        {
            if(Snakes[n].getisAlive())
            {
                Snakes[n].Update(collectable, Snakes, screenwidth, screenheight, borderSize, window, Glue, glueSize);
                Snakes[n].ChangeDirection(window, borderSize, screenheight, screenwidth);
            }
        };
        //Controls
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                case sf::Keyboard::Escape: //For debugging Only
                    window.close();
                    Menu();
                    break;
                case sf::Keyboard::Left:
                    Snakes[0].lastDirection = Snakes[0].currentDirection;
                    if(Snakes[0].currentDirection != eEast)
                        Snakes[0].currentDirection = eDirection::eWest;
                    break;
                case sf::Keyboard::Right:
                    Snakes[0].lastDirection = Snakes[0].currentDirection;
                    if(Snakes[0].currentDirection != eWest)
                        Snakes[0].currentDirection = eDirection::eEast;
                    break;
                case sf::Keyboard::Up:
                    Snakes[0].lastDirection = Snakes[0].currentDirection;
                    if(Snakes[0].currentDirection != eSouth)
                        Snakes[0].currentDirection = eDirection::eNorth;
                    break;
                case sf::Keyboard::Down:
                    Snakes[0].lastDirection = Snakes[0].currentDirection;
                    if(Snakes[0].currentDirection != eNorth and Snakes[0].lastDirection != eNorth)
                        Snakes[0].currentDirection = eDirection::eSouth;
                    break;
                case sf::Keyboard::Space:
                    if(Snakes[0].gethasGlue())
                    {
                        Snakes[0].lastDirection = Snakes[0].currentDirection;
                        Snakes[0].currentDirection = eDirection::eStop;
                        Snakes[0].addGlue(false);
                    }
                    break;
                    if(Snakes.size() > 1)
                    {
                    case sf::Keyboard::A:
                        Snakes[1].lastDirection = Snakes[1].currentDirection;
                        if(Snakes[1].currentDirection != eEast)
                            Snakes[1].currentDirection = eDirection::eWest;
                        break;
                    case sf::Keyboard::D:
                        Snakes[1].lastDirection = Snakes[1].currentDirection;
                        if(Snakes[1].currentDirection != eWest)
                            Snakes[1].currentDirection = eDirection::eEast;
                        break;
                    case sf::Keyboard::W:
                        Snakes[1].lastDirection = Snakes[1].currentDirection;
                        if(Snakes[1].currentDirection != eSouth)
                            Snakes[1].currentDirection = eDirection::eNorth;
                        break;
                    case sf::Keyboard::S:
                        Snakes[1].lastDirection = Snakes[1].currentDirection;
                        if(Snakes[1].currentDirection != eNorth and Snakes[1].lastDirection != eNorth)
                            Snakes[1].currentDirection = eDirection::eSouth;
                        break;
                    case sf::Keyboard::Z:
                        if(Snakes[1].gethasGlue())
                        {
                            Snakes[1].lastDirection = Snakes[1].currentDirection;
                            Snakes[1].currentDirection = eDirection::eStop;
                            Snakes[1].addGlue(false);
                        }
                        break;
                    }
                default:
                    break;
                }
            default:
                break;
            }
        }
        //Change Glue Overlay if snake has glue
        if(!Snakes[0].gethasGlue() )
            P1_GlueSprite.setColor(sf::Color::Red);
        else
            P1_GlueSprite.setColor(sf::Color::Green);
        if(Snakes.size() > 1)
        {
            if(!Snakes[1].gethasGlue())
                P2_GlueSprite.setColor(sf::Color::Red);
            else
                P2_GlueSprite.setColor(sf::Color::Green);
        }

        int R = rand()%200; // make collectables spawn randomly
        if ( R <5 )
            collectable[0].setisActive(true);
        if (R>5 and R<30)
            collectable[1].setisActive(true);
        if(R>30 and R<45)
            collectable[2].setisActive(true);
        if(R>45 and R<60)
            collectable[3].setisActive(true);
        if(R>60 and R<75)
            collectable[4].setisActive(true);

        //output time
        sf::Time gameTime = gameClock.getElapsedTime();
        std::ostringstream stringTime;
        float Gtime =(std::ceil((gameTime.asSeconds()/60)*100))/100; //convert to minutes and round to 2dp
        stringTime << Gtime;
        timeText.setString("TIME : " + stringTime.str());

        //Output Scores
        std::ostringstream stringScoreP1;
        stringScoreP1 << Snakes[0].Score;
       if(Snakes[0].getisAlive() == true)
            ScoreTextP1.setString("PLAYER1 : " + stringScoreP1.str());
        else
            ScoreTextP1.setString("PLAYER1 : " + stringScoreP1.str() + " DEAD");
        std::ostringstream stringScoreP2;
        stringScoreP2 << Snakes[1].Score;
        if(Snakes[1].getisAlive() == true)
            ScoreTextP2.setString("PLAYER2 : " + stringScoreP2.str());
        else
            ScoreTextP2.setString("PLAYER2 : " + stringScoreP2.str() + " DEAD");

        //Change Colour of the borders after 1 minute
        if(Gtime >= 1)
            borderColour = sf::Color::Yellow;
        //End game after 90 seconds or when all snakes are dead
        if(Gtime > 1.5 or numberofSnakes == 0)
            End(window);

        //Set position of borders/text
        top_border.setPosition(top_borderPosition);
        bottom_border.setPosition(bottom_borderPosition);
        right_border.setPosition(right_borderPosition);
        left_border.setPosition(left_borderPosition);
        ScoreTextP1.setPosition(sf::Vector2f(10,10));
        ScoreTextP2.setPosition(sf::Vector2f(10,40));
        timeText.setPosition(screenwidth/2,10);

        while(delay.getElapsedTime().asMilliseconds()<200); // Set delay so Snake moves at even steps
        delay.restart(); //restart delay clock

        // We must clear the window each time round the loop also set background colour
        window.clear(sf::Color(128,128,128));

        // draw shapes to the window
        window.draw(top_border);
        window.draw(left_border);
        window.draw(bottom_border);
        window.draw(right_border);
        window.draw(Glue);
        window.draw(timeText);

        for(unsigned int i{0}; i < Snakes.size(); i++)
        {
            if(Snakes[i].getisAlive())
                Snakes[i].Render(window);
        }
        for (unsigned int i = 0; i < collectable.size(); i++)
            collectable[i].Render(window);

        window.draw(P1_GlueSprite);
        window.draw(ScoreTextP1);
        if(Snakes.size() > 1)
        {
            window.draw(ScoreTextP2);
            window.draw(P2_GlueSprite);
        }
        // Get the window to display its contents
        window.display();
    }
}
void Game::End(sf::RenderWindow& window)
{
    sf::Vector2i MousePOS;

    sf::Font font;
    font.loadFromFile("fonts/Strange_Path.ttf");
    if(!font.loadFromFile("fonts/Strange_Path.ttf"))
        std::cout<<"ERROR: Cant find font"<<std::endl;

    sf::Text ScoreTextP1;
    ScoreTextP1.setFont(font);
    ScoreTextP1.setCharacterSize(60);
    ScoreTextP1.setColor(Snakes[0].getsnakeColour());

    sf::Text ScoreTextP2;
    ScoreTextP2.setFont(font);
    ScoreTextP2.setCharacterSize(60);
    ScoreTextP2.setColor(Snakes[1].getsnakeColour());

    std::ostringstream stringScoreP1;
    stringScoreP1 << Snakes[0].Score;
    if(Snakes[0].getisAlive() == true)
        ScoreTextP1.setString("PLAYER1 : " + stringScoreP1.str() + " ALIVE");
    else
        ScoreTextP1.setString("PLAYER1 : " + stringScoreP1.str() + " DIED");
    ScoreTextP1.setPosition(sf::Vector2f((window.getSize().x/2)-400,window.getSize().y/4));

    std::ostringstream stringScoreP2;
    stringScoreP2 << Snakes[1].Score;
    if(Snakes[1].getisAlive() == true)
        ScoreTextP2.setString("PLAYER2 : " + stringScoreP2.str() + " ALIVE");
    else
        ScoreTextP2.setString("PLAYER2 : " + stringScoreP2.str() + " DIED");
    ScoreTextP2.setPosition(sf::Vector2f((window.getSize().x/2)-400,window.getSize().y/1.5));

    sf::Texture exittexture;
    if (!exittexture.loadFromFile("textures/Exit.png"))
        std::cerr << "no texture" << std::endl;
    sf::Sprite exitSprite;
    exitSprite.setTexture(exittexture);
    exitSprite.setOrigin(100,50);
    exitSprite.setPosition(sf::Vector2f(window.getSize().x/2, 300));

    while(window.isOpen())
    {
        MousePOS = sf::Mouse::getPosition(window);
        if((MousePOS.x < exitSprite.getPosition().x+100 && MousePOS.x > (exitSprite.getPosition().x -100) ) && (MousePOS.y < exitSprite.getPosition().y+50  && MousePOS.y > (exitSprite.getPosition().y -50) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                window.close();
                Menu(window);
            }
        }
        window.clear(sf::Color(100,100,100));

        window.draw(exitSprite);
        window.draw(ScoreTextP1);
        if(Snakes.size() > 1)
            window.draw(ScoreTextP2);

        window.display();
    }
}
Game::~Game()
{
}
