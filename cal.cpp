#include <iostream>
#include <windows.h>  
using namespace std;

int main()
{
    int a, b, choice;

    cout << "Which arithmetic operation do you want to perform" << endl;
    cout << "1<--Addition\n2<--Subtraction\n3<--Multiplication\n4<--Division\n5<--Exit" << endl;
    cin >> choice;

    while (choice != 5)
    {
        cout << "Enter a number: ";
        cin >> a;
        cout << "Enter another number: ";
        cin >> b;

        switch (choice)
        {
            case 1:
                cout << "The sum is " << a + b << endl;
                break;
            case 2:
                cout << "The difference is " << a - b << endl;
                break;
            case 3:
                cout << "The Multiplication is " << a * b << endl;  
                break;
            case 4:
                cout << "The division is " << a / b << endl;  
                break;
            case 5:
                Sleep(200);
                cout << "Exiting..." << endl;
                Sleep(200);
                break;
            default:
                cout << "Enter only from above given option" << endl;
        }
        Sleep(3000);
        cout << "Which arithmetic operation do you want to perform" << endl;
        Sleep(2000);
    cout << "\n\n1<--Addition\n2<--Subtraction\n3<--Multiplication\n4<--Division\n5<--Exit\n\n" << endl;
    cin >> choice;



    }

    return 0;
}
