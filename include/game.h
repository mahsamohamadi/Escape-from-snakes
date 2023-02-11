#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Control.h"
#include "player.h"
#include "snake.h"
#include <vector>
#include <sstream>
#include <ctime>

class game
{
    public:
        game();
        ~game();
        void update();   //function update game
        void render();  // render game
        const bool running() const;  //function running
        void pollEvents();

    private:
        sf::VideoMode videomode;
        sf::RenderWindow* window;
        bool endgame;
        sf::Event ev;
        Control c;  //control object
        int points;
        sf::Clock startTime;  //game start time
        sf::Font font;  // text font
        sf::Text text; //points text
        sf::Text endgametext;  // End game text
        void inittext();   //Initialization text
        void initfont();   //Initialization font
        void updatepoints();  // update points game
        void renderp(sf::RenderTarget* );   //render in window
        void initVariables();  //Initialization variables
        void initwindow();  //Initialization window game
};

#endif
