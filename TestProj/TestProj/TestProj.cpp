#include "stdafx.h"  //idk
#include <iostream>  //cin && cout
#include <string>    //string datatype
#include <conio.h>   //_getch basically a better cin

using namespace std; //can use standard library w/o std:: prefix

void copycat();
void calculator();
void likeCheck();

int main()
{
	bool quit = false;
	char input;

	cout << "Hey, look; a test project!" << endl << "> what does it doooo?" << endl << "well for one, it copies you!" << endl << endl;
	copycat();
	cout << endl << "> Hey, that was sort of cool... what else does it do?" << endl << "it can do math!" << endl << endl;
	calculator();
	cout << "> Huh, neat. But how is that useful?" << endl << "It's NOT! do you like it?" << endl;
	likeCheck();

	while (!quit)
	{
		cout << endl << endl << "> What if I want to do that again?" << endl << "Type [r] for copycat, [c] for calculator, [l] for likequery, or [q] to quit. Have fun!" << endl;
		
		cin >> input;
		cin.ignore();
		cout << endl;

		switch (input)
		{
		case ('r'):
			copycat();
			break;
		case ('c'):
			calculator();
			break;
		case ('l'):
			likeCheck();
			break;
		default:
			quit = true;
			cout << "Cya!";
			break;
		}
	}
    return 0;
}

void copycat() {
	string response1;

	cout << "> ";
	getline(cin, response1);
	cout << "You said: " << response1 << endl;
}
void calculator() {
	char op;
	float var1, var2, result;
	
	cout << "enter [*,/,-,+]: ";
	cin >> op;
	cout << "Enter the first number: ";
	cin >> var1;
	cout << "Enter the second number: ";
	cin >> var2;
	cin.ignore();

	switch (op)
	{
	case ('+'):
		result = var1 + var2;
		break;
	case ('-'):
		result = var1 - var2;
		break;
	case ('*'):
		result = var1 * var2;
		break;
	case ('/'):
		result = var1 / var2;
		break;
	default:
		result = 0;
		break;
	}

	cout << "The answer to your question is " << result << "." << endl << endl;
}
void likeCheck() {
	string response2;

	cout << "> ";
	getline(cin, response2);

	if (response2 == "yes" || response2 == "ya" || response2 == "yep" || response2 == "uh huh")
	{
		cout << "That's great!" << endl;
	}
	else if (response2 == "no" || response2 == "nah" || response2 == "nop" || response2 == "uh uh")
	{
		cout << "Tough shit!" << endl;
	}
	else
	{
		cout << "Uhhh.... Ok." << endl;
	}
}