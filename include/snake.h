#ifndef SNAKE_H
#define SNAKE_H
#include "Dir.h"
#include "player.h"

class snake
{

    public:
        snake(int , int);  //determine the location of the snake
        void move(player &);  //move the snake towards the player
        void move(Dir);    //move the snake
        bool ishere(int , int);  //The presence or absence of a snake
        int get_x();
        int get_y();

    private:
        int x , y ;  //Snake location variables
};

#endif
