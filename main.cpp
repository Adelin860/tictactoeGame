#include <iostream>
#include "board.h"
#include "game.h"

int main()
{
    char arr[3][3] = {};
    Coordinates replay[9] = {};

    int moves ;
    int startPlayer;
    bool running = true;

    while (running)
    {
        clearBoard(arr);
        moves = 0;
        playRound(arr, replay, moves, startPlayer);

        bool inMenu = true;
        while (inMenu)
        {
            switch (menu())
            {
            case 1:
                startPlayer = 3 - startPlayer; // other player starts next round
                inMenu = false;
                break;
            case 2:
                std::cout << "-------------| REPLAY |-------------" << std::endl;
                gameReplay(replay, arr, moves);
                std::cout << "\n";
                break; // stay in the menu after the replay
            case 3:
                std::cout << "Exiting Game" << std::endl;
                running = false;
                inMenu = false;
                break;
            }
        }
    }
    return 0;
}