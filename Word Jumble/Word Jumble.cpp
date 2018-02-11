// Word Jumble.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>
using namespace std;

void main()
{
	
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"brick","Dont you feel like throwing one of these?" },
		{"glasses", "These would help you see the answer clearly now wouldn't they"},
		{"work", "This sure is a lot of..."},
		{"persistent", "i guess you are just... to not guess this word"},
		{"change", "thats what you came to this game to figure everthing out right?"}
	};
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];// What to guess
	string TheHint = WORDS[choice][HINT]; // The hint for the word

	string change = theWord; // The Jumbled word
	int length = change.size();
	for (int i = 0; i < length; i++)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = change[index1];
		change[index1] = change[index2];
		change[index2] = temp; 
	}
	cout << "Welcome to the scramble training sim." << endl;
	cout << "find the pattern to make the words regular again" << endl;
	cout << "type 'hint' if it gets to tough for you" << endl;
	cout << "type 'quit' if you cant handle the stress and want to leave the game" << endl;
	cout << "The one to guess is: " << change << endl;
	string guess;
	cout << "Your guess is: ";
	cin >> guess;
	 int tries = 0;
	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << TheHint;
			tries += 2;
		}
		else
		{
			cout << "Sorry that is incorrect.";
			tries++;
		}
		cout << "Your guess is: ";
		cin >> guess;
	}
	if (guess == theWord)
	{
		cout << "That is the correct word" << endl;
		cout << "It took you " << tries << " tries to guess correctly" << endl;
		cout << "thanks for playing" << endl;
	}
	system("pause");
}

