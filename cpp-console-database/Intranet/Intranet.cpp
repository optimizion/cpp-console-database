#include <iostream>
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
class Intranet
{
private:
	static Intranet* instance;
	Intranet();
public:
	static Intranet* getInstance();
	void clearConsole();
	void printStart();
	void printSignIn(string id, string pw);
	void printEnterId();
	void printEnterPw();
	void printExit();
	bool checkLogin(string id, string pw);
};
Intranet::Intranet() {}
Intranet* Intranet::instance = 0;
Intranet* Intranet::getInstance() {
	if (instance == 0) {
		instance = new Intranet();
	}

	return instance;
}

int main()
{
	// get Intranet instance
	Intranet* intranet = Intranet::getInstance();

	// Access Intranet
	intranet->printStart();
	// Infinity Loop
	while (true)
	{
		int user_input;
		cout << "Number : ";
		cin >> user_input;
		switch (user_input)
		{
		case 1:
			// Sign In
		{
			string studentId = "";
			string studentPw = "";
			while (true)
			{
				intranet->clearConsole();
				intranet->printSignIn(studentId, studentPw);
				cout << "Number : ";
				cin >> user_input;
				switch (user_input)
				{
				case 1:
					// enter studentId
					while (true) {
						cout << "Enter your Student ID : ";
						cin >> studentId;

						if (studentId.length() > 9) {
							cout << "wrong id. Please retry.\n";
							studentId = "";
							sleep_for(seconds(1));
							continue;
						}
						break;
					}
					break;
				case 2:
					// enter studentPw. I cannot afford to make it securely. Just show..
					cout << "Enter your Password : ";
					cin >> studentPw;
					break;
				case 3:
					// try login
					cout << "?";
					break;
				case 4:
					// go back
					break;
				default:
					// wrong input
					break;
				}
			}
			// check login
			bool isSuccess = intranet->checkLogin(studentId, studentPw);
			if (isSuccess) {
				// login successed.
				sleep_for(seconds(1));
			}
			else {
				// login failed.
				sleep_for(seconds(1));
			}
		}
		case 2:
			// Exit
			intranet->clearConsole();
			intranet->printExit();
			break;
		default:
			// wrong input
			// get rid of failure state
			cin.clear();
			// discard 'bad' character(s)
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "wrong input. Please retry.\n";
			continue;
		}
		return 0;
	};
}
bool Intranet::checkLogin(string id, string pw) {
	if (id == "")
	{
		// no id input
		cout << "no id input. Please retry.\n";
	}
	else if (pw == "")
	{
		// no pw input
		cout << "no password input. Please retry.\n";
	}
	else {
		// check student database file for login
		if (true) {
			// login success
			return true;
		}
		else {
			// login failed
			return false;
		}
	}
}

void Intranet::clearConsole()
{
	system("cls");
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
	cout << "|              2. Exit                      |\n";
	cout << "|                                           |\n";
	cout << "`-------------------------------------------'\n";
}

void Intranet::printSignIn(string id, string pw)
{
	cout << ",-------------------------------------------.\n";
	cout << "|                                           |\n";
	cout << "|       ,---------------------------.       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |          Sign In          |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |       Enter  number       |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |---------------------------|       |\n";
	cout << "|       |                           |       |\n";
	cout << left;
	cout << "|       |       ID : " << setw(9) << id << "      |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|                                           |\n";
	cout << "|              1. Enter ID                  |\n";
	cout << "|              2. Enter PW                  |\n";
	cout << "|              4. Login                     |\n";
	cout << "|              3. Go Back                   |\n";
	cout << "|                                           |\n";
	cout << "`-------------------------------------------'\n";
}

void Intranet::printEnterId() {
	cout << ",-------------------------------------------.\n";
	cout << "|                                           |\n";
	cout << "|       ,---------------------------.       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |         Enter ID          |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |   Enter your student ID   |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|                                           |\n";
	cout << "`-------------------------------------------'\n";
}

void Intranet::printEnterPw() {
	cout << ",-------------------------------------------.\n";
	cout << "|                                           |\n";
	cout << "|       ,---------------------------.       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |         Enter PW          |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |       Enter your PW       |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|                                           |\n";
	cout << "`-------------------------------------------'\n";
}

void Intranet::printExit() {
	cout << ",-------------------------------------------.\n";
	cout << "|                                           |\n";
	cout << "|       ,---------------------------.       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |            Exit           |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |          Good Bye         |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|                                           |\n";
	cout << "`-------------------------------------------'\n";
}
