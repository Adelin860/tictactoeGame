#include <iostream>
#include "game.h"
#include "board.h"

void input(char (*arr)[3], int player, Coordinates *record, int &move)
{
    int position;
    int row, col;

    while (true)
    {
        std::cout << "Player " << player << ": ";

        if (!(std::cin >> position))
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');

            std::cout << "Invalid input. Enter a number.\n";
            continue;
        }

        if (position < 1 || position > 9)
        {
            std::cout << "Invalid position. Try again.\n";
            continue;
        }

        row = (position - 1) / 3;
        col = (position - 1) % 3;

        if (arr[row][col] != '\0')
        {
            std::cout << "This position is already occupied. Try another position.\n";
            continue;
        }

        arr[row][col] = (player == 1 ? 'X' : 'O');

        record[move].col = col;
        record[move].row = row;
        move++;

        break;
    }
}

// Plays one full game (this is your inner do-while loop, moved out of main).
// startPlayer is 1 or 2 and decides who plays the first move.
void playRound(char (*arr)[3], Coordinates *record, int &moves, int startPlayer)
{
    int player;
    winner win;

    while (true)
    {
        drawBoard(arr);
        win = checkWinner(arr);
        if (win.win == true)
        {
            std::cout << "The winner is: " << (win.player == 1 ? "Player 1" : "Player 2") << std::endl;
            break;
        }
        if (moves == 9)
        {
            std::cout << "A draw \n";
            break;
        }
        // first move belongs to startPlayer, then it alternates
        player = (moves % 2 == 0) ? startPlayer : 3 - startPlayer;
        input(arr, player, record, moves);
    }
    std::cout << "\n\n----| GAME OVER |----" << std::endl;
}

// Your replay code, unchanged.
void gameReplay(Coordinates *record, char (*arr)[3], int &move)
{
    std::cout << "\n";
    for (int k = 0; k < move; k++)
    {
        std::cout << "\nMove " << k << std::endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                bool flag = false;
                std::cout << " ";
                for (int o = 0; o <= k; o++)
                {
                    if (record[o].col == j && record[o].row == i)
                    {
                        std::cout << arr[i][j];
                        flag = true;
                    }
                }
                if (!flag)
                    std::cout << " ";
                std::cout << " " << (j < 2 ? "|" : "");
            }
            std::cout << "\n";
            if (i < 2)
            {
                std::cout << "---|---|---\n";
            }
        }
        std::cout << "\n-----------------------------";
    }
}

// Shows the menu and only returns once the user enters 1, 2 or 3.
int menu()
{
    int option;

    std::cout << "-----| MENU |-----\n";
    std::cout << "1. Continue Playing\n";
    std::cout << "2. Watch game replay\n";
    std::cout << "3. Quit";

    while (true)
    {
        std::cout << "\nEnter your choice: ";
        if (!(std::cin >> option))
        {
            if (std::cin.eof())
                return 3; // input closed, just quit
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Enter a number.";
            continue;
        }
        if (option >= 1 && option <= 3)
            return option;

        std::cout << "Invalid choice.";
    }
}