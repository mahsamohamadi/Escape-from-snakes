#include "player.h"
#include "Board.h"
#include <iostream>
player::player(int X , int Y )
{
    x = X;
    y = Y;
}

void player::move(char dir)
{
    //Player movement according to input keys
    switch(dir)
    {

        case 'W' : case 'w':         //moving up
            {
                if( (y-1)>-1 ){y-- ;  return;}
                break;
            }
        case 'S' : case 's':         //moving down
            {
                if( (y+1)< Board::get_maxy()-2 ){y++ ; return;}
                break;
            }

        case 'A' : case 'a':         //moving left
            {
                if( (x-1)>-1 ){x-- ; return;}
                break;
            }
        case 'D' : case 'd':         //moving right
            {
                if( (x+1)< Board::get_maxx()-2 ){x++ ; return;}
                break;
            }
    }
}
int player::get_x()
{
    return x;
}
int player::get_y()
{
    return y;
}
bool player::ishere(int j , int k)
{
    bool s;
    if(j == x && k == y)
        s = true;
    else
        s=false;
    return s;
}
