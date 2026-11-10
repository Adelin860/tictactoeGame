#ifndef BOARD_H
#define BOARD_H

struct winner
{
    bool win ;
    int player;
};

void drawBoard(char (*arr)[3]);
void clearBoard(char (*arr)[3]);
struct winner checkWinner(char (*arr)[3]);

#endif