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
	void printSignIn(string id);
	void printExit();
	bool checkLogin(string id, string pw);
};

Intranet::Intranet()
{
}
Intranet* Intranet::instance = 0;
Intranet* Intranet::getInstance()
{
	if (instance == 0)
	{
		instance = new Intranet();
	}
	return instance;
}

int main()
{
	// get Intranet instance
	Intranet* intranet = Intranet::getInstance();

	// Infinity Loop
	while (true)
	{
		// Access Intranet
		intranet->clearConsole();
		intranet->printStart();
		int user_input = 0;
		cout << "Enter number : ";
		cin >> user_input;

		// sign in
		if (user_input == 1)
		{
			string studentId = "";
			string studentPw = "";
			while (true)
			{
				intranet->clearConsole();
				intranet->printSignIn(studentId);
				user_input = 0;
				cout << "Enter number : ";
				cin >> user_input;

				// enter studentId
				if (user_input == 1)
				{
					while (true)
					{
						cout << "Enter your Student ID : ";
						//getline(cin, studentId);
						cin >> studentId;

						if (studentId.length() > 9 || studentId.empty() || studentId.find(' ') != std::string::npos)
						{
							cout << "wrong id. Please retry.\n";
							studentId = "";
							sleep_for(seconds(1));
							intranet->clearConsole();
							intranet->printSignIn(studentId);
							continue;
						}
						break;
					}
				}
				// enter studentPw. I cannot afford to make it securely. Just show..
				else if (user_input == 2)
				{
					cout << "Enter your Password : ";
					cin >> studentPw;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (studentPw.empty() || studentPw.find(' ') != string::npos)
					{
						cout << "wrong password. Please retry.\n";
						studentPw = "";
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						sleep_for(seconds(1));
						intranet->clearConsole();
						intranet->printSignIn(studentId);
						continue;
					}
				}
				// login
				else if (user_input == 3)
				{
					// try login
					cout << "trying login...\n";
					sleep_for(seconds(1));

					// check login
					bool isSuccess = intranet->checkLogin(studentId, studentPw);
					if (isSuccess)
					{
						// login successed.
						sleep_for(seconds(2));
					}
					else
					{
						// login failed.
						sleep_for(seconds(2));
					}
				}
				// go back
				else if (user_input == 4)
				{
					break;
				}
				// wrong input
				else
				{
					// wrong input
					cout << "wrong input. Please retry.\n";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					sleep_for(seconds(1));
				}
			}
		}
		// exit
		else if (user_input == 2)
		{
			// Exit
			intranet->clearConsole();
			intranet->printExit();
			break;
		}
		// wrong input
		else
		{
			// get rid of failure state
			cin.clear();
			// discard 'bad' character(s)
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "wrong input. Please retry.\n";
			sleep_for(seconds(1));
			continue;
		}
	};

	return 0;
}

bool Intranet::checkLogin(string id, string pw)
{
	// ���� �����Ͻø� �ſ�.
	char ID[10], PW[10], line[100];
	int i, j;
	cout << "���̵�(�й�)�� �Է��ϼ���";
	cin >> ID;
	cout << "��й�ȣ�� �Է��ϼ���(������ 8�ڸ�)";
	cin >> PW;

	FILE* fp;
	fp = fopen("student.txt", "r");
	for (i = 0; i < 4; i++)
	{
		fgets(line, 20, fp);

		line[9] = '\0';
		line[18] = '\0';

		if (strcmp(ID, &line[0]) == 0 && strcmp(PW, &line[10]) == 0)
		{
			printf("�α��� ���");
			break;
		}
	}

	fclose(fp);
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
	cout << "|       `---------------------------'       |\n";
	cout << "|                                           |\n";
	cout << "|              1. Sign In                   |\n";
	cout << "|              2. Exit                      |\n";
	cout << "|                                           |\n";
	cout << "`-------------------------------------------'\n";
}

void Intranet::printSignIn(string id)
{
	cout << ",-------------------------------------------.\n";
	cout << "|                                           |\n";
	cout << "|       ,---------------------------.       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |          Sign In          |       |\n";
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
	cout << "|              3. Login                     |\n";
	cout << "|              4. Go Back                   |\n";
	cout << "|                                           |\n";
	cout << "`-------------------------------------------'\n";
}

void Intranet::printExit()
{
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

/*#include <stdio.h> - ����� ��й�ȣ ���� changestuent ���Ͽ��� ���� �ۼ��߽��ϴ�. �ٵ� �̰Ÿ� �α��������� ��� ������... �����Դϴ�.
#include <string.h>
#include <iostream>
using namespace std;

void main()
{
	cout << "��й�ȣ ������ ���� �й��� ��й�ȣ�� �ۼ����ּ���." << endl;
	char ID[10], PW[10], changePW[10], line[100];
	int i, j;
	cout << "���̵��Է�";
	cin >> ID;
	cout << "��й�ȣ �Է�(������ 8�ڸ�)";
	cin >> PW;

	FILE* fp;
	FILE* fp1;
	fp = fopen("student.txt", "r");//���� �̸� ���� �ʿ�
	for (i = 0; i < 4; i++)
	{
		fgets(line, 20, fp);

		line[9] = '\0';
		line[18] = '\0';

		if (strcmp(ID, &line[0]) == 0 && strcmp(PW, &line[10]) == 0)
		{
			cout << "Ȯ�ε� �����Դϴ�. ��й�ȣ ���� ��Ź�帳�ϴ�." << endl;
			cout << "���� ������ ��й�ȣ �Է�:";
			cin >> changePW;
			cout << endl;
			cout << "�Է��� �Ϸ�Ǿ����ϴ�.";
			fp1 = fopen("changestudent.txt", "w");
			fprintf(fp1, ID);
			fprintf(fp1, " ");
			fprintf(fp1, changePW);
			break;

		}


		else
		{
			cout << "��Ȯ�ε� �����Դϴ�" << endl;
			break;
		}

	}

	fclose(fp);

}*/