#include <iostream>

using namespace std;

int main()
{
    char op;
    double num1, num2;
    bool exitProgram = false;

    while (!exitProgram)
    {
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "Enter operation (+, -, *, /) or 'q' to quit: ";
        cin >> op;

        switch (op)
        {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Error! Division by zero!" << endl;
            break;
        case 'q':
            exitProgram = true;
            break;
        default:
            cout << "Invalid operation!" << endl;
        }
    }

    cout << "Exiting program. Goodbye!" << endl;

    return 0;
}
