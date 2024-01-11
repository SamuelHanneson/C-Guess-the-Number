#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <thread>

int main() {

    srand(time(0)); // seed random number generator

    int secretNumber = rand() % 100 + 1; // random number between 1 and 100

    int tries = 0;
    int guess;
    int correct = false;
    int isFinished = false;
    std::cout << "Welcome to Guess the Number! \n\n";

    do {
        while (correct == false) {

            std::cout << "Enter a guess: ";
            std::cin >> guess;
            tries++;

            std::stringstream ss;
            ss << guess;
            int x;
            if (!(ss >> x)) {
                std::cout << "Please enter a number.\n\n";
            } else if (guess < 1 || guess > 100) {
                std::cout << "Please enter a number between 1 and 100.\n\n";
            } else if (guess > secretNumber) {
                std::cout << "Too high!\n\n";
            } else if (guess < secretNumber) {
                std::cout << "Too Low!\n\n";
            } else {
                std::cout << "\nThat's it! You got it in " << tries << " guesses!\n";
                correct = true;
            }
        }   

        std::cout << "Would you like to play again? (y/n): ";
        std::string userContinue; // Change the data type to std::string
        std::cin >> userContinue;
        if (userContinue == "y") {
            correct = false;
            tries = 0;
        } else if (userContinue == "n") {
            std::cout << "Thanks for playing!\n\n";
            std::this_thread::sleep_for(std::chrono::seconds(5));
            isFinished = true;
            //break;
        } else {
            std::cout << "Please enter y or n.\n\n";
            }
        }

        while (isFinished == false); 
           
        }

