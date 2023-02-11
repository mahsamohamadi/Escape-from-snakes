#include "Board.h"
int Board::maxx=770;
int Board::maxy=570;
Board::Board(int a , int b)
{
    maxy = b;
    maxx =a;
}

int Board::get_maxy()
{
    return maxy;
}
int Board::get_maxx()
{
    return maxx;
}
