#include <iostream>
#include "board.h"

void drawBoard(char (*arr)[3])
{
    std::cout << "\n";
    int pos = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char display =
                (arr[i][j] == '\0')
                    ? ('0' + pos)
                    : arr[i][j];
            std::cout << " " << display << " " << (j < 2 ? "|" : "");
            pos++;
        }
        std::cout << "\n";
        if (i < 2)
        {
            std::cout << "---|---|---\n";
        }
    }
    std::cout << "\n";
}

void clearBoard(char (*arr)[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = '\0';
        }
    }
}

struct winner checkWinner(char (*arr)[3])
{
    winner win;
    for (int i = 0; i < 3; i++)
    {
        // Check rows
        if (arr[i][0] != '\0' &&
            arr[i][0] == arr[i][1] &&
            arr[i][1] == arr[i][2])
        {
            win.win = true;
            win.player = arr[i][0] == 'X' ? 1 : 2;
            return win;
        }

        // Check columns
        if (arr[0][i] != '\0' &&
            arr[0][i] == arr[1][i] &&
            arr[1][i] == arr[2][i])
        {
            win.win = true;
            win.player = arr[0][i] == 'X' ? 1 : 2;
            return win;
        }
    }
    // Main diagonal
    if (arr[0][0] != '\0' &&
        arr[0][0] == arr[1][1] &&
        arr[1][1] == arr[2][2])
    {
        win.win = true;
        win.player = arr[0][0] == 'X' ? 1 : 2;
        return win;
    }

    // Anti-diagonal
    if (arr[0][2] != '\0' &&
        arr[0][2] == arr[1][1] &&
        arr[1][1] == arr[2][0])
    {
        win.win = true;
        win.player = arr[0][2] == 'X' ? 1 : 2;
        return win;
    }
    return win;
}