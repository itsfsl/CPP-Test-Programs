#include <iostream>
#include <ctime>

void printBoard(char *board)
{
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << "\n";
    std::cout << "------------" << "\n";
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << "\n";
    std::cout << "------------" << "\n";
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << "\n";
}
void delay(int sec)
{
    int ms = 1000 * sec;
    clock_t startTime = clock();
    while(clock() < startTime + ms);
}
void playerMove(char *board, char player)
{
    int input;

    do
    {
        std::cout << "Enter a number(1-9): ";
        std::cin >>input;
        input--;

        if (board[input] == ' ')
        {
            board[input] = player;
            break;
        }
        else
        {
            std::cout << "Invalid input\n";
        }
    } while (board[input] != ' ');
}
void computerMove(char *board, char computer)
{
    srand(time(0));
    int num;

    do
    {
        num = (rand() % 8);
        if (board[num] == ' ')
        {
            board[num] = computer;
            break;
        }
    } while (board[num] != ' ');
}
bool checkWinner(char *board, char player, char computer)
{
    bool winner = false;
    if (board[0] != ' ' && board[0] == board[1] && board[1] == board[2])
    {
        if (board[0] == player)
        {
            std::cout << "You win!";
            winner = true;
        }
        else if (board[0] == computer)
        {
            std::cout << "You lose!";
            winner = true;
        }
    }
    if (board[3] != ' ' && board[3] == board[4] && board[4] == board[5])
    {
        if (board[3] == player)
        {
            std::cout << "You win!";
            winner = true;
        }
        else if (board[3] == computer)
        {
            std::cout << "You lose!";
            winner = true;
        }
    }
    if (board[6] != ' ' && board[6] == board[7] && board[7] == board[8])
    {
        if (board[6] == player)
        {
            std::cout << "You win!";
            winner = true;
        }
        else if (board[6] == computer)
        {
            std::cout << "You lose!";
            winner = true;
        }
    }
    if (board[0] != ' ' && board[0] == board[3] && board[3] == board[6])
    {
        if (board[0] == player)
        {
            std::cout << "You win!";
            winner = true;
        }
        else if (board[0] == computer)
        {
            std::cout << "You lose!";
            winner = true;
        }
    }
    if (board[1] != ' ' && board[1] == board[4] && board[4] == board[7])
    {
        if (board[1] == player)
        {
            std::cout << "You win!";
            winner = true;
        }
        else if (board[1] == computer)
        {
            std::cout << "You lose!";
            winner = true;
        }
    }
    if (board[2] != ' ' && board[2] == board[5] && board[5] == board[8])
    {
        if (board[2] == player)
        {
            std::cout << "You win!";
            winner = true;
        }
        else if (board[2] == computer)
        {
            std::cout << "You lose!";
            winner = true;
        }
    }
    if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8])
    {
        if (board[0] == player)
        {
            std::cout << "You win!";
            winner = true;
        }
        else if (board[0] == computer)
        {
            std::cout << "You lose!";
            winner = true;
        }
    }
    if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6])
    {
        if (board[2] == player)
        {
            std::cout << "You win!";
            winner = true;
        }
        else if (board[2] == computer)
        {
            std::cout << "You lose!";
            winner = true;
        }
    }
    return winner;
}
bool checkTie(char *board)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
        {
            return false;
        }
    }
    std::cout << "It's a tie!";
    return true;
}

int main()
{
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    
    char const PLAYER = 'X';
    char const COMPUTER = 'O';
    bool running = true;

    system("cls");

    printBoard(board);

    while (running)
    {
        playerMove(board, PLAYER);
        if(checkWinner(board, PLAYER, COMPUTER))
        {
            running = false;
            break;
        }
        if(checkTie(board))
        {
            running = false;
            break;
        }
        computerMove(board, COMPUTER);
        if(checkWinner(board, PLAYER, COMPUTER))
        {
            running = false;
            break;
        }
        if(checkTie(board))
        {
            running = false;
            break;
        }
        system("cls");
        printBoard(board);
    }
    std::cout << "\n";
    printBoard(board);
    delay(3);
    return 0;
}