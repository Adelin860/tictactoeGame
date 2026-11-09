#include <iostream>
struct winner
{
    bool win = false;
    int player = 0;
};
struct Coordinates
{
    int col = 0;
    int row = 0;
};

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
            std::cout << " " << (arr[i][j] == '\0' ? display : arr[i][j]) << " " << (j < 2 ? "│" : "");
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

void input(char (*arr)[3], int player, Coordinates *(record), int &move)
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

        std::cout << "\nPosition: ("
                  << row << "," << col << ")\n";

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

void gameReplay(Coordinates *record, char (*arr)[3], int &move)
{
    std::cout << "\n";
    for (int k = 0; k < move; k++)
    {
        std::cout<<"\nMove "<<k<<std::endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {   bool flag =false;
                std::cout<<" ";
                for(int o=0;o<=k;o++){
                    if(record[o].col == j && record[o].row == i ){
                       std::cout<< arr[i][j] ;
                       flag=true;
                    }
                }
                if(!flag)
                   std::cout<<" ";
                std::cout<<" " << (j < 2 ? "│" : "");
            }
            std::cout << "\n";
            if (i < 2)
            {
                std::cout << "---|---|---\n";
            }
        }
        std::cout<<"\n-----------------------------";
    }
}

int main()
{
    char arr[3][3] = {};
    struct Coordinates replay[9] = {};
    int option = 0;

    int moves = 0;
    int player = 0;
    bool flag = true;

    struct winner win;
    do
    {
        do
        {
            drawBoard(arr);
            win = checkWinner(arr);
            if (win.win == true)
            {
                std::cout << "The winner is: " << (win.player == 1 ? "Player 1" : "Player 2") << std::endl;
                break;
            }
            if (win.win == false && moves == 9)
            {
                std::cout << "A draw \n";
                break;
            }
            player = moves % 2 == 0 ? 1 : 2;
            input(arr, player, replay, moves);

        } while (true);
        std::cout << "\n\n----| GAME OVER |----" << std::endl;

        std::cout << "-----| MENU |-----\n";
        std::cout << "1. Continue Playing\n";
        std::cout << "2. Watch game replay\n";
        std::cout << "3. Quit";

        do
        {
            std::cout << "\nEnter your choice: ";
            std::cin >> option;
            switch (option)
            {
            case 1:
                flag = true;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        arr[i][j] = '\0';
                    }
                }

                moves = 0;
                win.win = false;
                win.player = 0;

                flag = true;
                break;
             case 2:
                flag=false;
                std::cout<<"-------------| REPLAY |-------------"<<std::endl;
                gameReplay(replay,arr,moves);
                break;

            case 3:
                flag = false;
                std::cout << "Existing Game" << std::endl;
                break;
           
            default:
                std::cout << "Invalid Output \n";
                break;
            }
        } while (option < 1 || option > 3);
        ;

    } while (true && flag);
}