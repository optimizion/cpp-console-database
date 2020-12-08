#define _CRT_SECURE_NO_WARNINGS
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
	void printSelectInfo();
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
				int user_input;
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
					sleep_for(seconds(2));
					if (isSuccess)
					{
						// login successed.
						// SELECT INFO CONSOLE
						intranet->clearConsole();
						intranet->printSelectInfo();

						// user_input
						int user_input;
						cout << "Enter number : ";
						cin >> user_input;

						// 입력에 따라 정보 출력
						while (true)
						{
							// 학생 정보 출력
							if (user_input == 1)
							{
							}
							// 과목 정보 출력
							else if (user_input == 2)
							{
							}
							// 수강 정보 출력
							else if (user_input == 3)
							{
							}
							// go back
							else if (user_input == 4)
							{
							}
							// wrong input
							else
							{
							}
						}

					}
					else
					{
						// login failed.
						sleep_for(seconds(2));
						// 로그인에 실패하였습니다. 다시 시도해주세요. -> 반복
						cout << "Login failed. Please try again.\n";
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						sleep_for(seconds(1));

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
					cout << "wrong input. Please try again.\n";
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
	/*char ID[10], PW[10], line[100];
	int i, j;
	cout << "아이디(학번)을 입력하세요";
	cin >> ID;
	cout << "비밀번호를 입력하세요(무조건 8자리)";
	cin >> PW;

	FILE* fp;
	fp = fopen("student.txt", "r");
	for (i = 0; i < 4; i++)
		fclose(fp);*/

		// loginInfo.txt의 내용을 한 줄씩 읽어서
		// 값을 파싱한 다음에
		// 각각의 값을 id, pw와 비교하여 같은 값이 있으면 true
		// 없으면 false를 반환한다

	return true;
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

void Intranet::printSelectInfo()
{
	cout << ",-------------------------------------------.\n";
	cout << "|                                           |\n";
	cout << "|       ,---------------------------.       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |    Welcome to Intranet    |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       | What do you want to know? |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|              1. Student Info              |\n";
	cout << "|              2. Subject Info              |\n";
	cout << "|              3. Course  Info              |\n";
	cout << "|              4. Logout                   |\n";
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

/*#include <stdio.h> - 변경된 비밀번호 정보 changestuent 파일에다 새로 작성했습니다. 근데 이거를 로그인정보와 어떻게 엮을지... 난관입니다.
#include <string.h>
#include <iostream>
using namespace std;

void main()
{
	cout << "비밀번호 변경을 위해 학번과 비밀번호를 작성해주세요." << endl;
	char ID[10], PW[10], changePW[10], line[100];
	int i, j;
	cout << "아이디입력";
	cin >> ID;
	cout << "비밀번호 입력(무조건 8자리)";
	cin >> PW;

	FILE* fp;
	FILE* fp1;
	fp = fopen("student.txt", "r");//파일 이름 변경 필요
	for (i = 0; i < 4; i++)
	{
		fgets(line, 20, fp);

		line[9] = '\0';
		line[18] = '\0';

		if (strcmp(ID, &line[0]) == 0 && strcmp(PW, &line[10]) == 0)
		{
			cout << "확인된 정보입니다. 비밀번호 변경 부탁드립니다." << endl;
			cout << "새로 변경할 비밀번호 입력:";
			cin >> changePW;
			cout << endl;
			cout << "입력이 완료되었습니다.";
			fp1 = fopen("changestudent.txt", "w");
			fprintf(fp1, ID);
			fprintf(fp1, " ");
			fprintf(fp1, changePW);
			break;

		}


		else
		{
			cout << "비확인된 정보입니다" << endl;
			break;
		}

	}

	fclose(fp);

}*/