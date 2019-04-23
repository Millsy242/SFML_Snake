// Daniel Harvey
// s6291311
#include "Menu.h"

Menu::Menu()
{
    sf::ContextSettings menusettings;
    menusettings.antialiasingLevel = AA;
    sf::RenderWindow menuWindow(sf::VideoMode(800,800), "C++ Snake ICA : s6291311", sf::Style::Default, menusettings);
    runMenu(menuWindow);
}
void Menu::runMenu(sf::RenderWindow& menuWindow)
{
    menuWindow.setActive(true);

    sf::Texture titleTexture;
    if (!titleTexture.loadFromFile("textures/title.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite titleSprite;
    titleSprite.setTexture(titleTexture);
    titleSprite.setOrigin(300,0);

    sf::Texture playTexture;
    if (!playTexture.loadFromFile("textures/Play.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite playSprite;
    playSprite.setTexture(playTexture);
    playSprite.setOrigin(100,50);

    sf::Texture exitTexture;
    if (!exitTexture.loadFromFile("textures/Exit.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite exitSprite;
    exitSprite.setTexture(exitTexture);
    exitSprite.setOrigin(100,50);

    sf::Texture settingsTexture;
    if (!settingsTexture.loadFromFile("textures/Settings.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite settingsSprite;
    settingsSprite.setTexture(settingsTexture);
    settingsSprite.setOrigin(40,40);

    sf::Texture HighscoreTexture;
    if (!HighscoreTexture.loadFromFile("textures/HighScore.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite HighscoreSprite;
    HighscoreSprite.setTexture(HighscoreTexture);
    HighscoreSprite.setOrigin(40,40);

    sf::Texture numPlayersTexture;
    if (!numPlayersTexture.loadFromFile("textures/numPlayers.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite numPlayersSprite;
    numPlayersSprite.setTexture(numPlayersTexture);
    numPlayersSprite.setOrigin(100,50);

    sf::Texture numPlayers1Texture;
    if (!numPlayers1Texture.loadFromFile("textures/numPlayers1.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite numPlayers1Sprite;
    numPlayers1Sprite.setTexture(numPlayers1Texture);
    numPlayers1Sprite.setOrigin(40,40);

    sf::Texture numPlayers2Texture;
    if (!numPlayers2Texture.loadFromFile("textures/numPlayers2.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite numPlayers2Sprite;
    numPlayers2Sprite.setTexture(numPlayers2Texture);
    numPlayers2Sprite.setOrigin(40,40);
    menuWindow.close();
    Game(AA, Vsync, resX, resY, numPlayers);
/*
    while(menuWindow.isOpen())
    {
        mousePOS = sf::Mouse::getPosition(menuWindow);

        if((mousePOS.x < (playSprite.getPosition().x + 100) && mousePOS.x > (playSprite.getPosition().x -100) ) && (mousePOS.y < (playSprite.getPosition().y+50) && mousePOS.y > (playSprite.getPosition().y -50) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                menuWindow.close();
                Game(AA, Vsync, resX, resY, numPlayers);
            }
        }
        if((mousePOS.x < settingsSprite.getPosition().x +40 && mousePOS.x > (settingsSprite.getPosition().x -40) ) && (mousePOS.y < settingsSprite.getPosition().y +40 && mousePOS.y > (settingsSprite.getPosition().y -40) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                settingsMenu(menuWindow, playSprite, exitSprite);
            }
        }
        if((mousePOS.x < HighscoreSprite.getPosition().x +40  && mousePOS.x > (HighscoreSprite.getPosition().x -40) ) && (mousePOS.y < HighscoreSprite.getPosition().y +40  && mousePOS.y > (HighscoreSprite.getPosition().y -40) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                std::cout << "ERROR: HighScore button has not been implemented yet" << std::endl;
        }
        if((mousePOS.x < exitSprite.getPosition().x +100 && mousePOS.x > (exitSprite.getPosition().x -100) ) && (mousePOS.y < exitSprite.getPosition().y +100 && mousePOS.y > (exitSprite.getPosition().y -50) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                menuWindow.close();
        }
        if((mousePOS.x < numPlayers1Sprite.getPosition().x +40  && mousePOS.x > (numPlayers1Sprite.getPosition().x -40) ) && (mousePOS.y < numPlayers1Sprite.getPosition().y +40  && mousePOS.y > (numPlayers1Sprite.getPosition().y -40) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                numPlayers1Sprite.setColor(sf::Color::Red);
                if(numPlayers != 1)
                    numPlayers = 1;
                if(numPlayers2Sprite.getColor() == sf::Color::Red)
                    numPlayers2Sprite.setColor(sf::Color::White);
            }
        }
        if((mousePOS.x < numPlayers2Sprite.getPosition().x +40  && mousePOS.x > (numPlayers2Sprite.getPosition().x -40) ) && (mousePOS.y < numPlayers2Sprite.getPosition().y +40  && mousePOS.y > (numPlayers2Sprite.getPosition().y -40) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                numPlayers2Sprite.setColor(sf::Color::Red);
                if(numPlayers != 2)
                    numPlayers = 2;
                if(numPlayers1Sprite.getColor() == sf::Color::Red)
                    numPlayers1Sprite.setColor(sf::Color::White);
            }
        }

        menuWindow.clear(sf::Color(0,165,137));

        titleSprite.setPosition(sf::Vector2f(400,0));
        playSprite.setPosition(sf::Vector2f(400,300));
        settingsSprite.setPosition(sf::Vector2f(80,700));
        HighscoreSprite.setPosition(sf::Vector2f(720,700));
        exitSprite.setPosition(sf::Vector2f(400, 700));
        numPlayersSprite.setPosition(sf::Vector2f(200, 500));
        numPlayers1Sprite.setPosition(sf::Vector2f(400, 500));
        numPlayers2Sprite.setPosition(sf::Vector2f(600, 500));

        menuWindow.draw(playSprite);
        menuWindow.draw(settingsSprite);
        menuWindow.draw(HighscoreSprite);
        menuWindow.draw(titleSprite);
        menuWindow.draw(exitSprite);
        menuWindow.draw(numPlayersSprite);
        menuWindow.draw(numPlayers1Sprite);
        menuWindow.draw(numPlayers2Sprite);

        menuWindow.display();
    }
  */
}
void Menu::settingsMenu(sf::RenderWindow& menuWindow, sf::Sprite playSprite, sf::Sprite exitSprite)
{
    sf::Texture settings_AATexture;
    if (!settings_AATexture.loadFromFile("textures/Settings_AA.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite settings_AASprite;
    settings_AASprite.setTexture(settings_AATexture);
    settings_AASprite.setOrigin(100,25);

    sf::Texture settings_Reset_High_ScoreTexture;
    if (!settings_Reset_High_ScoreTexture.loadFromFile("textures/Settings_Reset_High_Score.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite settings_Reset_High_ScoreSprite;
    settings_Reset_High_ScoreSprite.setTexture(settings_Reset_High_ScoreTexture);
    settings_Reset_High_ScoreSprite.setOrigin(100,25);

    sf::Texture settings_ResolutionTexture;
    if (!settings_ResolutionTexture.loadFromFile("textures/Settings_Resolution.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite settings_ResolutionSprite;
    settings_ResolutionSprite.setTexture(settings_ResolutionTexture);
    settings_ResolutionSprite.setOrigin(100,25);

    sf::Texture settings_VsyncTexture;
    if (!settings_VsyncTexture.loadFromFile("textures/Settings_Vsync.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite settings_VsyncSprite;
    settings_VsyncSprite.setTexture(settings_VsyncTexture);
    settings_VsyncSprite.setOrigin(100,25);

    sf::Texture settings_AA_2Texture;
    if (!settings_AA_2Texture.loadFromFile("textures/Settings_AA_2.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite settings_AA_2Sprite;
    settings_AA_2Sprite.setTexture(settings_AA_2Texture);
    settings_AA_2Sprite.setOrigin(50,25);

    sf::Texture settings_AA_4Texture;
    if (!settings_AA_4Texture.loadFromFile("textures/Settings_AA_4.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite settings_AA_4Sprite;
    settings_AA_4Sprite.setTexture(settings_AA_4Texture);
    settings_AA_4Sprite.setOrigin(50,25);

    sf::Texture settings_AA_8Texture;
    if (!settings_AA_8Texture.loadFromFile("textures/Settings_AA_8.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite settings_AA_8Sprite;
    settings_AA_8Sprite.setTexture(settings_AA_8Texture);
    settings_AA_8Sprite.setOrigin(50,25);

    sf::Texture settings_AA_16Texture;
    if (!settings_AA_16Texture.loadFromFile("textures/Settings_AA_16.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite settings_AA_16Sprite;
    settings_AA_16Sprite.setTexture(settings_AA_16Texture);
    settings_AA_16Sprite.setOrigin(50,25);

    sf::Texture settings_AA_noneTexture;
    if (!settings_AA_noneTexture.loadFromFile("textures/Settings_AA_none.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite settings_AA_noneSprite;
    settings_AA_noneSprite.setTexture(settings_AA_noneTexture);
    settings_AA_noneSprite.setOrigin(50,25);

    sf::Texture Settings_High_Score_yesTexture;
    if (!Settings_High_Score_yesTexture.loadFromFile("textures/Settings_High_Score_yes.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite Settings_High_Score_yesSprite;
    Settings_High_Score_yesSprite.setTexture(Settings_High_Score_yesTexture);
    Settings_High_Score_yesSprite.setOrigin(50,25);

    sf::Texture Settings_Resolution_800x600Texture;
    if (!Settings_Resolution_800x600Texture.loadFromFile("textures/Settings_Resolution_800x600.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite Settings_Resolution_800x600Sprite;
    Settings_Resolution_800x600Sprite.setTexture(Settings_Resolution_800x600Texture);
    Settings_Resolution_800x600Sprite.setOrigin(50,25);

    sf::Texture Settings_Resolution_1024x768Texture;
    if (!Settings_Resolution_1024x768Texture.loadFromFile("textures/Settings_Resolution_1024x768.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite Settings_Resolution_1024x768Sprite;
    Settings_Resolution_1024x768Sprite.setTexture(Settings_Resolution_1024x768Texture);
    Settings_Resolution_1024x768Sprite.setOrigin(50,25);

    sf::Texture settings_Vsync_YESTexture;
    if (!settings_Vsync_YESTexture.loadFromFile("textures/Settings_Vsync_YES.png"))
        std::cerr << "no Texture" << std::endl;

    sf::Sprite settings_Vsync_YESSprite;
    settings_Vsync_YESSprite.setTexture(settings_Vsync_YESTexture);
    settings_Vsync_YESSprite.setOrigin(50,25);

    settings_AASprite.setPosition(sf::Vector2f(150,50));
    settings_Reset_High_ScoreSprite.setPosition(sf::Vector2f(150,100));
    settings_ResolutionSprite.setPosition(sf::Vector2f(150,150));
    settings_VsyncSprite.setPosition(sf::Vector2f(150,200));

    settings_AA_noneSprite.setPosition(sf::Vector2f(300,50));
    settings_AA_2Sprite.setPosition(sf::Vector2f(350,50));
    settings_AA_4Sprite.setPosition(sf::Vector2f(400,50));
    settings_AA_8Sprite.setPosition(sf::Vector2f(450,50));
    settings_AA_16Sprite.setPosition(sf::Vector2f(500,50));

    Settings_High_Score_yesSprite.setPosition(sf::Vector2f(300,100));

    Settings_Resolution_800x600Sprite.setPosition(sf::Vector2f(300,150));
    Settings_Resolution_1024x768Sprite.setPosition(sf::Vector2f(450,150));

    settings_Vsync_YESSprite.setPosition(sf::Vector2f(300,200));

    playSprite.setPosition(sf::Vector2f(400,600));
    exitSprite.setPosition(sf::Vector2f(400, 700));

    buttonSprites.push_back(settings_AASprite);
    buttonSprites.push_back(settings_Reset_High_ScoreSprite);
    buttonSprites.push_back(settings_ResolutionSprite);
    buttonSprites.push_back(settings_VsyncSprite);
    buttonSprites.push_back(settings_AA_2Sprite);
    buttonSprites.push_back(settings_AA_4Sprite);
    buttonSprites.push_back(settings_AA_8Sprite);
    buttonSprites.push_back(settings_AA_16Sprite);
    buttonSprites.push_back(settings_AA_noneSprite);
    buttonSprites.push_back(Settings_High_Score_yesSprite);
    buttonSprites.push_back(Settings_Resolution_800x600Sprite);
    buttonSprites.push_back(Settings_Resolution_1024x768Sprite);
    buttonSprites.push_back(settings_Vsync_YESSprite);
    buttonSprites.push_back(playSprite);
    buttonSprites.push_back(exitSprite);

    while(menuWindow.isOpen())
    {
        //mouse - button collisions
        mousePOS = sf::Mouse::getPosition(menuWindow);

        if((mousePOS.x < settings_AA_2Sprite.getPosition().x+50 && mousePOS.x > (settings_AA_2Sprite.getPosition().x -50) ) && (mousePOS.y < settings_AA_2Sprite.getPosition().y+25 && mousePOS.y > (settings_AA_2Sprite.getPosition().y -25) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                AA = 2;
        }
        if((mousePOS.x < settings_AA_4Sprite.getPosition().x+50  && mousePOS.x > (settings_AA_4Sprite.getPosition().x -50) ) && (mousePOS.y < settings_AA_4Sprite.getPosition().y+25 && mousePOS.y > (settings_AA_4Sprite.getPosition().y -25) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                AA = 4;
        }
        if((mousePOS.x < settings_AA_8Sprite.getPosition().x+50  && mousePOS.x > (settings_AA_8Sprite.getPosition().x -50) ) && (mousePOS.y < settings_AA_8Sprite.getPosition().y+25 && mousePOS.y > (settings_AA_8Sprite.getPosition().y -25) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                AA = 8;
        }
        if((mousePOS.x < settings_AA_16Sprite.getPosition().x+50  && mousePOS.x > (settings_AA_16Sprite.getPosition().x -50) ) && (mousePOS.y < settings_AA_16Sprite.getPosition().y+25 && mousePOS.y > (settings_AA_16Sprite.getPosition().y -25) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                AA = 16;
        }
        if((mousePOS.x < settings_AA_noneSprite.getPosition().x+50  && mousePOS.x > (settings_AA_noneSprite.getPosition().x -50) ) && (mousePOS.y < settings_AA_noneSprite.getPosition().y+25  && mousePOS.y > (settings_AA_noneSprite.getPosition().y -25) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                AA = 0;
        }
        if((mousePOS.x < Settings_High_Score_yesSprite.getPosition().x+50  && mousePOS.x > (Settings_High_Score_yesSprite.getPosition().x -50) ) && (mousePOS.y < Settings_High_Score_yesSprite.getPosition().y+25  && mousePOS.y > (Settings_High_Score_yesSprite.getPosition().y -25) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                std::cout << "yet to implement high score table" << std::endl;
        }
        if((mousePOS.x < Settings_Resolution_800x600Sprite.getPosition().x+50  && mousePOS.x > (Settings_Resolution_800x600Sprite.getPosition().x -50) ) && (mousePOS.y < Settings_Resolution_800x600Sprite.getPosition().y+25  && mousePOS.y > (Settings_Resolution_800x600Sprite.getPosition().y -25) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                Settings_Resolution_800x600Sprite.setColor(sf::Color::Red);
                resX = 800;
                resY = 600;
            }
        }
        if((mousePOS.x < Settings_Resolution_1024x768Sprite.getPosition().x+50  && mousePOS.x > (Settings_Resolution_1024x768Sprite.getPosition().x -50) ) && (mousePOS.y < Settings_Resolution_1024x768Sprite.getPosition().y+25 && mousePOS.y > (Settings_Resolution_1024x768Sprite.getPosition().y -25) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                Settings_Resolution_1024x768Sprite.setColor(sf::Color::Red);
                resX = 1024;
                resY = 768;
            }
        }
        if((mousePOS.x < settings_Vsync_YESSprite.getPosition().x+50  && mousePOS.x > (settings_Vsync_YESSprite.getPosition().x -50) ) && (mousePOS.y < settings_Vsync_YESSprite.getPosition().y+25  && mousePOS.y > (settings_Vsync_YESSprite.getPosition().y -25) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                Vsync = true;
        }
        if((mousePOS.x < playSprite.getPosition().x+100 && mousePOS.x > (playSprite.getPosition().x -100) ) && (mousePOS.y < playSprite.getPosition().y+50  && mousePOS.y > (playSprite.getPosition().y -50) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                playSprite.setColor(sf::Color::Red);
                menuWindow.close();
                Game(AA, Vsync, resX, resY, numPlayers);
            }
        }
        if((mousePOS.x < exitSprite.getPosition().x+100 && mousePOS.x > (exitSprite.getPosition().x -100) ) && (mousePOS.y < exitSprite.getPosition().y+50  && mousePOS.y > (exitSprite.getPosition().y -50) ) )
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                exitSprite.setColor(sf::Color::Red);
                menuWindow.close();
            }
        }
        menuWindow.clear(sf::Color(0,165,137));

        for (unsigned int a{0}; a<buttonSprites.size() ; a++)
            menuWindow.draw(buttonSprites[a]);

        menuWindow.display();
    }
}
Menu::~Menu()
{
    //dtor
}
