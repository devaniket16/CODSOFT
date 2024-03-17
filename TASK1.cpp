#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() {
    // Initialize random seed
    srand(time(nullptr));

    // Generate random number between 1 and 100
    int randomNumber = rand() % 100 + 1;

    // Initialize user's guess and attempts counter
    int guess;
    int attempts = 0;

    // Game loop
    while (true) {
        cout << "Guess the number (between 1 and 100): ";
        cin >> guess;

        // Increment attempts counter
        attempts++;

        // Check if guess is correct
        if (guess == randomNumber) {
            cout << "Congratulations! You guessed the number " << randomNumber << " correctly in " << attempts << " attempts." << endl;
            break; // Exit the loop
        } else if (guess < randomNumber) {
            cout << "Too low. Try again." << endl;
        } else {
            cout << "Too high. Try again." << endl;
        }
    }

    return 0;
}
