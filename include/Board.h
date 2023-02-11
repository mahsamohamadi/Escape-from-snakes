#ifndef BOARD_H
#define BOARD_H


class Board
{
    public:
        Board(int , int);  //Determination of length and width
        static int get_maxy();
        static int get_maxx();


    private:
        static int maxy , maxx;  //Length and width variables board

};

#endif
