#ifndef PLAYER_H
#define PLAYER_H
#include "Dir.h"
#include <SFML/Graphics.hpp>
class player
{
    public:

        player(int=150.f , int=300.f);  //determine the location of the player
        void move(char);  //move the player
        bool ishere(int , int);   //The presence or absence of a player
        int get_x();
        int get_y();


    protected:

    private:
        int x , y ;  //player location variables

};

#endif
