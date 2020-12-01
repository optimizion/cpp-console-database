// cpp-console-database.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
using namespace std;

class Intranet
{
public:
	enum CONSOLE
	{
		START,
		SIGNIN,
		SIGNUP,
		FINDID,
		FINDPW,
		EXIT
	};
	void clearConsole();
	void printConsole(CONSOLE console);
	void printStart();
	void printSignIn();
	void printSignUp();
	void printFindId();
	void printFindPw();
	void printExit();
};

int main()
{
	Intranet intranet = Intranet();
	//std::cout << "Hello World!\n";

	intranet.printConsole(Intranet::CONSOLE::START);

	int user_input;



	while (true)
	{
		cout << "input? : ";
		cin >> user_input;
		switch (user_input)
		{
		case 1:
			string studentId;
			string studentPw;
			while (true)
			{
				intranet.printConsole(Intranet::CONSOLE::SIGNIN);
				cin >> user_input;
				switch (user_input)
				{
				case 1:
					cin >> studentId;
				case 2:
					cin >> studentPw;
				case 3:
					cout << "?";
				default:
					break;
				}
			}
			if (true)
			{
			}
			else
			{
			}

		case 2:
			intranet.printConsole(Intranet::CONSOLE::SIGNUP);
			continue;

		case 3:
			intranet.printConsole(Intranet::CONSOLE::FINDID);
			continue;

		case 4:
			intranet.printConsole(Intranet::CONSOLE::FINDPW);
			continue;

		case 5:
			intranet.printConsole(Intranet::CONSOLE::EXIT);
			break;
		default:
			continue;
		}
	}

	return 0;
};

void Intranet::printConsole(CONSOLE console)
{
	switch (console)
	{
	case START:
		printStart();
		break;
	case SIGNIN:
		printSignIn();
		break;
	case SIGNUP:
		printSignUp();
		break;
	case FINDID:
		printFindId();
		break;
	case FINDPW:
		printFindPw();
		break;
	}
}
void Intranet::printStart()
{
	cout << ",-------------------------------------------.\n";
	cout << "|                                           |\n";
	cout << "|       ,---------------------------.       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |    Welcome to Intranet    |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |       Input  number       |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|                                           |\n";
	cout << "|              1. Sign In                   |\n";
	cout << "|              2. Sign Up                   |\n";
	cout << "|              3. Find ID                   |\n";
	cout << "|              4. Change PW                 |\n";
	cout << "|              5. Exit                      |\n";
	cout << "`-------------------------------------------'\n";
}
void Intranet::printSignIn()
{
	cout << ",-------------------------------------------.\n";
	cout << "|                                           |\n";
	cout << "|       ,---------------------------.       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |          Sign In          |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |       Input  number       |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|                                           |\n";
	cout << "|              1. Input ID                  |\n";
	cout << "|              2. Input PW                  |\n";
	cout << "`-------------------------------------------'\n";
}
void Intranet::printSignUp()
{
	cout << ",-------------------------------------------.\n";
	cout << "|                                           |\n";
	cout << "|       ,---------------------------.       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |          Sign Up          |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |       Input  number       |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|                                           |\n";
	cout << "|              1. Input ID                  |\n";
	cout << "|              2. Input PW                  |\n";
	cout << "|              3. Input EMAIL               |\n";
	cout << "|              4. Input USERNAME            |\n";
	cout << "`-------------------------------------------'\n";
}
void Intranet::printFindId() {}
void Intranet::printFindPw() {}
void Intranet::printExit() {}
