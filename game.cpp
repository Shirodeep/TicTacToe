#include <iostream>
#include <ctype.h>
using namespace std;

char field[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int i, j, playerInputValue;

void displayGame()
{
    // Displaying the output of game
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << field[i][j] << ' ';
        }
        cout << endl;
    }
}

void gameBody(int gameTurn)
{
    char playerDisplayValue = 'O';

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {

            if (isalpha(field[i][j]))
            {
                cout << "Enter the field that is not selected by player  ";
                gameTurn--;
            }
            else
            {
                cout << "Enter the field you want to mark:";
                cin >> playerInputValue;
                goto aa;
            }
        }
    }
aa:
    // Switching players
    if (gameTurn % 2 == 0)
    {
        playerDisplayValue = 'X';
    }

    else
    {
        playerDisplayValue = 'O';
    }
    ////placing 'X' and 'O' for game
    switch (playerInputValue)
    {
    case 1:
        field[0][0] = playerDisplayValue;
        break;
    case 2:
        field[0][1] = playerDisplayValue;
        break;
    case 3:
        field[0][2] = playerDisplayValue;
        break;
    case 4:
        field[1][0] = playerDisplayValue;
        break;
    case 5:
        field[1][1] = playerDisplayValue;
        break;
    case 6:
        field[1][2] = playerDisplayValue;
        break;
    case 7:
        field[2][0] = playerDisplayValue;
        break;
    case 8:
        field[2][1] = playerDisplayValue;
        break;
    case 9:
        field[2][2] = playerDisplayValue;
        break;
    };
}
char checkGame()
{
    // Checking who won either 'O' or 'X'
    // if 'X' won
    ////Checking diagonals
    if (field[0][0] == 'X' && field[1][1] == 'X' && field[2][2] == 'X')
        return 'X';
    if (field[0][2] == 'X' && field[1][1] == 'X' && field[2][0] == 'X')
        return 'X';
    //// Chcking columns
    if (field[0][0] == 'X' && field[1][0] == 'X' && field[2][0] == 'X')
        return 'X';
    if (field[0][1] == 'X' && field[1][1] == 'X' && field[2][1] == 'X')
        return 'X';
    if (field[0][2] == 'X' && field[1][2] == 'X' && field[2][2] == 'X')
        return 'X';
    //// Checking rows
    if (field[0][0] == 'X' && field[0][1] == 'X' && field[0][2] == 'X')
        return 'X';
    if (field[1][0] == 'X' && field[1][1] == 'X' && field[1][2] == 'X')
        return 'X';
    if (field[2][0] == 'X' && field[2][1] == 'X' && field[2][2] == 'X')
        return 'X';

    // If 'O' won
    //// Checing Diagonals
    if (field[0][0] == 'O' && field[1][1] == 'O' && field[2][2] == 'O')
        return 'O';
    if (field[0][2] == 'O' && field[1][1] == 'O' && field[2][0] == 'O')
        return 'O';
    //// Checking Columns
    if (field[0][0] == 'O' && field[1][0] == 'O' && field[2][0] == 'O')
        return 'O';
    if (field[0][1] == 'O' && field[1][1] == 'O' && field[2][1] == 'O')
        return 'O';
    if (field[0][2] == 'O' && field[1][2] == 'O' && field[2][2] == 'O')
        return 'O';
    //// Checking Rows
    if (field[0][0] == 'O' && field[0][1] == 'O' && field[0][2] == 'O')
        return 'O';
    if (field[1][0] == 'O' && field[1][1] == 'O' && field[1][2] == 'O')
        return 'O';
    if (field[2][0] == 'O' && field[2][1] == 'O' && field[2][2] == 'O')
        return 'O';

    return 'E';
}

int main()
{
    // initializing counter for toggling player
    int gameTurn = 0;

    cout << endl
         << "\t\tWelcome to TICTACTOE -v 1.0" << endl;
    displayGame();
    // Infinite loop for game
    while (1)
    {
        gameBody(gameTurn);
        displayGame();
        if (gameTurn == (gameTurn - 1))
        {
            cout << "DRAW!!!";
            break;
        }
        else if ('O' == checkGame())
        {
            cout << "PLAYER 'O' WON!!!";
            break;
        }
        else if ('X' == checkGame())
        {
            cout << "PLAYER 'X' WON!!!";
            break;
        }

        gameTurn++;
    }
    return 0;
}

// This code is done by Shirodeep Dahal if you want to suggest easier code than you can Email me -shirodeepdahal0987@gmail.com