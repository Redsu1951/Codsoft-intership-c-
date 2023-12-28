#include <iostream>
#include <cstdlib>
#include <ctime>   
#include <unistd.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int random_number = (rand() % 100) + 1;
    int guessed_number = 0, counter = 0;

    cout << "Generating a number to guess" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << ". ";
        sleep(1);  
    }
    cout << endl;

    sleep(3);
    cout << "Now..";
    sleep(2);
    cout << "Let's start the game!" << endl;
    sleep(2);

    do {
        cout << "Enter your guess" << endl;
        cin >> guessed_number;

        if (guessed_number > random_number) {
            cout<<"You guessed higher"<<endl;
            
        } else if (guessed_number < random_number) {
            cout<<"You guessed lower"<<endl;
        } else {
            cout << "You finally did it!" << endl;
        }

        counter++;
    } while (guessed_number != random_number);

    sleep(2);
    cout << "You guessed after trying for " << counter << " times!" << endl;

    return 0;
}
