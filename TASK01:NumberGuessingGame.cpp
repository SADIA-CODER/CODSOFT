#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int num = rand() % 100 + 1;
    int guess = 0;
    cout << "     WELCOME TO THE GUESSING GAME! \n\n";
    cout << "Guess a number between 1-100: ";
    cin >> guess;
    while (guess != num)
    {
        if (guess < num)
        {
            cout << "Too Low! Try Again. " << endl;
        }
        else
        {
            cout << "Too High! Try Again. " << endl;
        }
        cout << "Guess another number: ";
        cin >> guess;
    }
    cout << "Congratulations you guesses correctly!" << endl;
    return 0;
}
