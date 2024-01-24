// Create a c++ program that generates a random number and asks the
// user to guess it. Provide feedback on whether the guess is too
// high or too low until the user guesses the correct number.
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    int randomNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess;
    int attempts = 0;

    std::cout << "Guess the number between 1 and 100: ";

    do {
        std::cin >> guess;
        attempts++;

        if (guess < randomNumber) {
            std::cout << "Too low! Try again: ";
        } else if (guess > randomNumber) {
            std::cout << "Too high! Try again: ";
        } else {
            std::cout << "Congratulations! You guessed the number " << randomNumber << " in " << attempts << " attempts!" << std::endl;
        }
    } while (guess != randomNumber);

    return 0;
}
