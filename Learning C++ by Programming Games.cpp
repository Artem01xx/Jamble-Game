
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>  
#include <Windows.h>
using namespace std;



// Jumble Game

int main()
{
	srand(time(NULL));
	enum field {Word , Hint , NUM_FIELDS};
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"Wall" , "Hit it "},
		{"ShotGun" , "Shoot it"},
		{"Roof" , "Look up" },
		{"Persisten" , "Be pationt"},
		{" Cow " , " MUUUUU " }
	};
	int choice = rand() % NUM_WORDS;
	string theWord = WORDS[choice][Word];
	string theHint = WORDS[choice][Hint];

	string jumble = theWord;
	int length = jumble.size();

	for (int i = 0;i < length;i++)
	{
		int index1 = rand() % length;
		int index2 = rand() % length;
		char temp = jumble[index2];
		jumble[index2] = jumble[index1];
		jumble[index1] = temp;
	}

		cout << " Welcome to Word Jumble Game " << endl;
		cout<< " Enter 'Hint' for a hint " <<endl;
		cout << " Enter 'quit' to quit " << endl;
		cout << " The Jumble is " << jumble << endl;
		string guess;
		cout << " Your guess is ";
		cin >> guess;

		while (guess != theWord && guess != "quit")
		{
			if (guess == "Hint")
			{
				cout << theHint << endl;
			}

			else
			{
				cout << " Sorry thats not That " << endl;
			}

			cout << " Your guess " << endl;
			cin >> guess;
		}

		if (guess == theWord)
		{
			cout << " Thats it you guess it " << endl;
		}

		cout << " Goodbuy " << endl;
		return 0;
}