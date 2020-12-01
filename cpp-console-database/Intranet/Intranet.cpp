#include <iostream>
#include <string>
using namespace std;

class Intranet
{
private:
	static Intranet* instance;
	Intranet();
public:
	static Intranet* getInstance();
	enum CONSOLE
	{
		START,
		SIGNIN,
		SIGNUP,
		FINDID,
		EXIT
	};
	void clearConsole();
	void printConsole(CONSOLE console);
	void printStart();
	void printSignIn();
	void printSignUp();
	void printEnterId();
	void printEnterPw();
	void printFindId();
	void printExit();
};

Intranet* Intranet::instance = 0;
Intranet* Intranet::getInstance() {
	if (instance == 0) {
		instance = new Intranet();
	}

	return instance;
}

int main()
{
	Intranet* intranet = Intranet::getInstance();

	// Access Intranet
	intranet->printConsole(Intranet::CONSOLE::START);
	int user_input;

	// Infinity Loop
	while (true)
	{
		cout << "Number : ";
		cin >> user_input;
		switch (user_input)
		{
		case 1:
		{
			string studentId;
			string studentPw;
			while (true)
			{
				intranet->printConsole(Intranet::CONSOLE::SIGNIN);
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
		}

		case 2:
			intranet->printConsole(Intranet::CONSOLE::SIGNUP);
			continue;

		case 3:
			intranet->printConsole(Intranet::CONSOLE::FINDID);
			continue;
		case 5:
			intranet->printConsole(Intranet::CONSOLE::EXIT);
			break;
		default:
			continue;
		}

		cout << "로그아웃 되었습니다.";
		return 0;
	};
}

void Intranet::clearConsole()
{
	system("cls");
}

void Intranet::printConsole(CONSOLE console)
{
	switch (console)
	{
	case START:
		clearConsole();
		printStart();
		break;
	case SIGNIN:
		clearConsole();
		printSignIn();
		break;
	case SIGNUP:
		clearConsole();
		printSignUp();
		break;
	case FINDID:
		clearConsole();
		printFindId();
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
	cout << "|       |       Enter  number       |       |\n";
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
	cout << "|       |       Enter  number       |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|                                           |\n";
	cout << "|              1. Enter ID                  |\n";
	cout << "|              2. Enter PW                  |\n";
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
	cout << "|       |       Enter  number       |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|                                           |\n";
	cout << "|              1. Enter ID                  |\n";
	cout << "|              2. Enter PW                  |\n";
	cout << "|              3. Enter EMAIL               |\n";
	cout << "|              4. Enter USERNAME            |\n";
	cout << "`-------------------------------------------'\n";
}
void Intranet::printEnterId() {}
void Intranet::printEnterPw() {}
void Intranet::printFindId() {}
void Intranet::printExit() {}
