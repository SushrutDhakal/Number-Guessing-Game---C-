
#include <iostream>
#include <cmath>
#include <cctype>
#include <stdlib.h>
#include <ctime>

using namespace std;

void PlayGame();
bool WantToPlayAgain();

bool IsGameOver(int secretNumber, int numberOfTries, int guess);
int GetGuess(int numberOfTries);

void DisplayResult(int secretNumber, int numberOfTries);


const int IGNORE_CHARS = 256;

int main()
{
	srand((unsigned int) time(NULL));

	do
	{
		PlayGame();

	}while(WantToPlayAgain());

	return 0;
}

void PlayGame()
{
	const int UPPER_BOUND = 100;
	int secretNumber = rand() % UPPER_BOUND;
	cout << secretNumber << endl;
	int numberOfTries = ceil( log2(UPPER_BOUND) );
	int guess = 0;

	cout << "The range from 0-100" << endl;

	do
	{
		guess = GetGuess(numberOfTries);
		if(guess != secretNumber)
		{
			numberOfTries--;

			if(guess > secretNumber)
			{
				cout << "Guess was too high" << endl;
			}
			else
			{
				cout << "Guess was too low!" << endl;
			}
		}

	}while(!IsGameOver(secretNumber, numberOfTries, guess));

	DisplayResult(secretNumber, numberOfTries);

}

bool WantToPlayAgain()
{
	char input;
	bool failure;

	do
	{
		failure = false;

		cout << "Play again? (y/n) ";
		cin >> input;

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << "Error! Try again." << endl;
			failure = true;
		}
		else
		{
			cin.ignore(IGNORE_CHARS, '\n');

			input = tolower(input);
		}

	}while(failure);

	return input == 'y';
}


bool IsGameOver(int secretNumber, int numberOfTries, int guess)
{
	return secretNumber == guess || numberOfTries <= 0;
}

int GetGuess(int numberOfTries)
{
	int guess;
	bool failure;

	do
	{
		failure = false;

		cout << "Enter Guess (Guesses left: " << numberOfTries << "): ";
		cin >> guess;

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << "Error! Try again." << endl;
			failure = true;
		}

	}while(failure);

	return guess;
}

void DisplayResult(int secretNumber, int numberOfTries)
{
	if(numberOfTries > 0)
	{
		cout << "Correct, YOU WIN! It was: " << secretNumber << endl;
	}
	else
	{
		cout << "Sorry, You Lose! The number was: " << secretNumber << endl;
	}
}
