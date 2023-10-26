#include <iostream>
using namespace std;

// 3x3 grid
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;

// players name and tokens
string n1 = "Player X", n2 = "Player 0";
char token = 'X'; // starting with player X
bool tie = false; // check for a tie

void functionone() // display the current state of board
{

    cout << "   |   |   " << endl;
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << " \n";
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << " \n";
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << " \n";
    cout << "   |   |   " << endl;
}

void function2() // Function to handle player input and update the board
{
    int digit;
    if (token == 'X')
    {
        cout << n1 << " please enter ";
        cin >> digit;
    }

    if (token == '0')
    {
        cout << n2 << " please enter ";
        cin >> digit;
    }

    if (digit == 1)
    {
        row = 0;
        column = 0;
    }

    if (digit == 2)
    {
        row = 0;
        column = 1;
    }
    if (digit == 3)
    {
        row = 0;
        column = 2;
    }
    if (digit == 4)
    {
        row = 1;
        column = 0;
    }
    if (digit == 5)
    {
        row = 1;
        column = 1;
    }
    if (digit == 6)
    {
        row = 1;
        column = 2;
    }
    if (digit == 7)
    {
        row = 2;
        column = 0;
    }
    if (digit == 8)
    {
        row = 2;
        column = 1;
    }
    if (digit == 9)
    {
        row = 2;
        column = 2;
    }
    else if (digit < 1 || digit > 9)
    {
        cout << "Invalid digit" << endl;
    }

    if (token == 'X' && space[row][column] != 'X' && space[row][column] != '0')
    {
        space[row][column] = 'X';
        token = '0';
    }
    else if (token == '0' && space[row][column] != 'X' && space[row][column] != '0')
    {
        space[row][column] = '0';
        token = 'X';
    }
    else
    {
        cout << "There s no empty space" << endl;
        function2();
    }
}

bool function3() // function to check for win
{
    for (int i = 0; i < 3; i++)
    {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
        {
            return true;
        }
    }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0])
    {
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'X' && space[i][j] != '0')
            {
                return false;
            }
        }
    }
    tie = true;
    return false;
}

bool playAgain() // play again handling code
{
    char choice;
    cout << "Do you want to play again? (Y/N): ";
    cin >> choice;
    choice = toupper(choice);

    if (choice == 'Y')
    {
        // Reset the game state
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                space[i][j] = '1' + i * 3 + j;
            }
        }
        token = 'X';
        tie = false;
        return true;
    }
    else if (choice == 'N')
    {
        return false;
    }
    else
    {
        cout << "Invalid input. Please enter Y or N." << endl;
        return playAgain(); // Re-prompt if the input is invalid
    }
}

bool isBoardFull() // board full check code
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'X' && space[i][j] != '0')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{

    do
    {

        while (!function3() && !isBoardFull())
        {
            functionone();
            function2();
            function3();
        }

        if (isBoardFull() && !function3())
        {
            cout << "It's a draw!" << endl;
        }
        else if (token == 'X')
        {
            cout << n2 << " wins!!" << endl;
        }
        else if (token == '0')
        {
            cout << n1 << " wins!!" << endl;
        }
    } while (playAgain());

    cout<<"Thank you for playing Tic-Tac-Toe! "<<endl;
}
