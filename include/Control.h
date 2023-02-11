#ifndef CONTROL_H
#define CONTROL_H
#include <vector>
#include <string>
#include "snake.h"
#include "Dir.h"
#include "player.h"
class Control
{
    public:
        Control();   //Control constructor
        ~Control();   //Control destructor
        void updatekay();  //Update the location of the player according to the input key
        void updetesnake();    //Move the snakes to the player's new location
        bool finished();       //Check the completion of the game
        void render(sf::RenderTarget* target);

    private:
        std::vector <snake *> s;   //snake vector
        player p;    //player object
        sf::RectangleShape shape;   //shape of player

        sf::CircleShape snake1;  //shape of snakes
        sf::CircleShape snake2;
        sf::CircleShape snake3;

};
#endif
