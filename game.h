#ifndef GAME_H
#define GAME_H

struct Coordinates
{
    int col;
    int row;
};

void input(char (*arr)[3], int player, Coordinates *record, int &move);
void playRound(char (*arr)[3], Coordinates *record, int &moves, int startPlayer);
void gameReplay(Coordinates *record, char (*arr)[3], int &move);
int menu();

#endif