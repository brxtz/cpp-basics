#include <iostream> //input-output library 
#include <cstdlib>
#include <ctime>
using namespace std;

int main ()
{
    cout << "********************************" << endl; //cout will print & endl will jump to the next line
    cout << "* Welcome to the Guessing Game *" << endl;
    cout << "********************************" << endl;

    cout << "Choose the dificulty level: " << endl;
    cout << "Easy (E), Normal (N), or Hard (H)" << endl;

    char dificulty;
    cin >> dificulty;

    int number_of_attempts;
    if(dificulty == 'E'){
        number_of_attempts = 15;
    }
    else if(dificulty == 'N'){
        number_of_attempts = 10;
    }
    else{
        number_of_attempts = 5;
    }

    srand(time(0)); //random seed 
    const int SECRET_NUMBER = rand() % 100; //random number between 0-99

    bool incorrect_guess = true;
    int attempts = 1;

    double points = 1000.0;

    for(attempts; attempts <= number_of_attempts; attempts++){
        int guess;
        cout << "Attempts: " << attempts << endl;
        cout << "What is your guess?" << endl;
        cin >> guess; //guess input

        double lost_points = abs(guess - SECRET_NUMBER) / 2.0;
        points -= lost_points;

        cout << "You guessed: " << guess << endl;

        bool guessed = guess == SECRET_NUMBER;
        bool bigger = guess > SECRET_NUMBER;

        if(guessed){
            cout << "Congratulations! You've guessed the secret number!" << endl;
            break;
        }
        else if(bigger){
            cout << "The number you guessed was bigger than the secret number!" << endl;
        }
        else{
            cout << "The number you guessed was smaller than the secret number!" << endl;
        }
    }

    cout << "Game Over!" << endl;
    if(incorrect_guess){
        cout << "You Lost! Try Again!" << endl;
    }
    else{
        cout << "You guessed after " << attempts << " attempts!" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Score: " << points << endl;
    }
}