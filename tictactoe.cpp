#include <iostream>
using namespace std;

char board[3][3];

void resetBoard()
{
    char position = '1';

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = position++;
        }
    }
}

void displayBoard()
{
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "\n";
}

bool placeMark(int choice, char mark)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == choice + '0')
            {
                board[i][j] = mark;
                return true;
            }
        }
    }

    return false;
}

bool checkWinner()
{
    // Rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
        return true;

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
        return true;

    return false;
}

bool checkDraw()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] >= '1' && board[i][j] <= '9')
                return false;
        }
    }

    return true;
}

int main()
{
    char playAgain;

    do
    {
        resetBoard();

        char currentPlayer = 'X';

        while(true)
        {
            displayBoard();

            int choice;

            cout << "Player " << currentPlayer
                 << ", Enter Position (1-9): ";

            cin >> choice;

            if(choice < 1 || choice > 9)
            {
                cout << "\nInvalid Position!\n";
                continue;
            }

            if(!placeMark(choice, currentPlayer))
            {
                cout << "\nPosition Already Occupied!\n";
                continue;
            }

            if(checkWinner())
            {
                displayBoard();
                cout << "\nPlayer " << currentPlayer
                     << " Wins the Game!\n";
                break;
            }

            if(checkDraw())
            {
                displayBoard();
                cout << "\nGame Draw!\n";
                break;
            }

            if(currentPlayer == 'X')
                currentPlayer = 'O';
            else
                currentPlayer = 'X';
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while(playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank You For Playing!\n";

    return 0;
}