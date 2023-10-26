#include <iostream>
using namespace std;

int main()
{
    char op;                       
    int num1, num2;
    cout << "Enter 1st number: ";
    cin >> num1;
    cout << "Enter 2nd number: ";
    cin >> num2;
    cout << "Enter Operator (+, -, *, /): ";
    cin >> op;
    switch (op)
    {
    case '+':
        cout << "Addition of " << num1 << " + " << num2 << " = " << (num1 + num2);
        break;
    case '-':
        cout << "Subtraction of " << num1 << " - " << num2 << " = " << (num1 - num2);
        break;
    case '*':
        cout << "Multiplication of " << num1 << " * " << num2 << " = " << (num1 * num2);
        break;
    case '/':
        if (num2 != 0)
            cout << "Division of " << num1 << " / " << num2 << " = " << (num1 / num2);
        else
            cout << "\n Error! Division by zero is not allowed.";
        break;
    default:
        cout << "\nInvalid Operator.";
    }
    return 0;
}
