#include "snake.h"
#include "Board.h"
#include "Control.h"

snake::snake(int X , int Y)
{
    x = X;
    y = Y;

}
void snake::move(player & p)
{
    if(p.get_x()> x ){move(Dir::RIGHT);}
    if(p.get_x()< x){move(Dir::LEFT);}
    if(p.get_y()>y){move(Dir::DOWN);}
    if(p.get_y()< y){move(Dir::UP);}
}
void snake::move(Dir dir)
{
    if(dir == Dir::UP && (y-1)>-1 ){y-- ; return;}
    if(dir == Dir::DOWN && (y+1)< Board::get_maxy()-1 ){y++ ; return;}
    if(dir == Dir::LEFT && (x-1)>-1 ){x-- ; return;}
    if(dir == Dir::RIGHT && (x+1)< Board::get_maxx()-1 ){x++ ; return;}
}
int snake::get_x()
{
    return x;
}
int snake::get_y()
{
    return y;
}
bool snake::ishere(int j, int k)
{
    bool s;
    if(j == x && k == y)
        s = true;
    else
        s=false;
    return s;

}
