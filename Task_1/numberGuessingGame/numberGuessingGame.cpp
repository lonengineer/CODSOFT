// numberGuessingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using std::cout;
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand() % 100 + 1;
    cout << randomNumber << std::endl;
    int guessed = 0, attempts = 0;
    cout << "::::::::::::::: Welcome, player! Time to embark on a journey of guesses and wins! :::::::::::::::";
    do {
        cout << "\n\nInsert your guess:\t";
        std::cin >> guessed;
        if ((randomNumber - guessed) > 0) {
            cout << "Think Big! ";
            if ((randomNumber - guessed) > 15)
                cout << "You are thinking too low.";
        }
        else if ((randomNumber - guessed) < 0) {
            cout << "Think of a smaller number! ";
            if ((randomNumber - guessed) < -15)
                cout << "You are thinking too high.";
        }
        attempts++;
    } while (!(randomNumber == guessed));
    cout << "\n----------||||||||||||||| Congratulations!!! You guessed in " << attempts << " attempt/s |||||||||||||||----------\n";
}


