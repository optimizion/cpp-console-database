#pragma once
#include "../ManagaDatabase/ManageTable.cpp"
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
	void printSelectInfo(string userName);
	void printExit();
	bool checkLogin(string id, string pw);
	void printStudentInfo();
	void printSubjectInfo();
	void printCourseInfo();
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

	LoginInfoManager loginInfoManager;
	bool isSuccessed = loginInfoManager.checkLogin(id, pw);

	if (isSuccessed)
	{
		return true;
	}
	return false;
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
void Intranet::printSelectInfo(string userName)
{
	cout << ",-------------------------------------------.\n";
	cout << "|                                           |\n";
	cout << "|       ,---------------------------.       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |    Welcome to Intranet    |       |\n";
	cout << "|       |                           |       |\n";
	cout << left;
	cout << "|       |   Hello, " << setw(9) << userName << "        |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|              1. Student Info              |\n";
	cout << "|              2. Subject Info              |\n";
	cout << "|              3. Course  Info              |\n";
	cout << "|              4. Logout                    |\n";
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
void Intranet::printStudentInfo()
{
	cout << ",-------------------------------------------.\n";
	cout << "|                                           |\n";
	cout << "|       ,---------------------------.       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |        Student Info       |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|                                           |\n";
	cout << "`-------------------------------------------'\n";
}
void Intranet::printSubjectInfo()
{
	cout << ",-------------------------------------------.\n";
	cout << "|                                           |\n";
	cout << "|       ,---------------------------.       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |        Subject Info       |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|                                           |\n";
	cout << "`-------------------------------------------'\n";
}
void Intranet::printCourseInfo()
{
	cout << ",-------------------------------------------.\n";
	cout << "|                                           |\n";
	cout << "|       ,---------------------------.       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |        Course Info        |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|                                           |\n";
	cout << "`-------------------------------------------'\n";
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
					if (studentPw.empty())
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
						// 입력에 따라 정보 출력
						while (true)
						{
							// login successed.
							// SELECT INFO CONSOLE
							intranet->clearConsole();
							intranet->printSelectInfo(studentId);
							// user_input
							int user_input;
							cout << "Enter number : ";
							cin >> user_input;

							// 학생 정보 출력
							if (user_input == 1)
							{
								intranet->clearConsole();
								intranet->printStudentInfo();
								StudentManager studentManager;
								Student student = studentManager.queryStudentData(studentId);
								if (student.getStudentId() != "")
								{
									cout << "------------------------------------------------------------------------------------------------------" << endl;
									cout << "StudentId" << " | " << "Name" << " | " << "Sex" << " | " << "Grade" << " | " << "Age" << " | " << "Email" << " | " << "PhoneNumber" << " | " << endl;
									cout << "------------------------------------------------------------------------------------------------------" << endl;
									cout << student.getStudentId() << " | " << student.getName() << " | " << student.getSex() << " | " << student.getGrade() << " | " << student.getAge() << " | " << student.getEmail() << " | " << student.getPhoneNum() << endl;

									sleep_for(seconds(3));
									//cout << endl << "Press Enter to Continue" << endl;
									cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
									continue;
								}
								cout << "해당 학생 정보가 존재하지 않습니다." << endl;
								cout << endl << "Press Enter to Continue" << endl;
								cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
							}
							// 과목 정보 출력
							else if (user_input == 2)
							{
								intranet->clearConsole();
								intranet->printSubjectInfo();
								SubjectManager subjectManager;
								string str;
								stringstream subjects = subjectManager.querySubjectData();

								cout << "------------------------------------------------------------------------------------------------------" << endl;
								cout << "ClassCode" << " | " << "ClassName" << " | " << "Professor" << " | " << "Grade" << " | " << "TimePlan" << " | " << "Classified" << " | " << "EvalType" << " | " << endl;
								cout << "------------------------------------------------------------------------------------------------------" << endl;
								while (getline(subjects, str))
								{
									cout << str << endl;
								}
								sleep_for(seconds(3));
								//cout << "과목 정보가 존재하지 않습니다." << endl;
								cout << endl << "Press Enter to Continue" << endl;
								cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
								continue;
							}
							// 수강 정보 출력
							else if (user_input == 3)
							{
								intranet->clearConsole();
								intranet->printCourseInfo();
								CourseManager courseManager;
								string str;
								stringstream courses = courseManager.queryCourseData(studentId);
								cout << "------------------------------------------------------------------------------------------------------" << endl;
								cout << "StudentId" << " | " << "ClassCode" << " | " << "ClassName" << " | " << "Professor" << " | " << "TimePlan" << " | " << "location" << endl;
								cout << "------------------------------------------------------------------------------------------------------" << endl;

								while (getline(courses, str))
								{
									cout << str << endl;
								}
								sleep_for(seconds(3));

								cout << endl << "Press Enter to Continue" << endl;
								cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
								continue;
							}
							// Logout
							else if (user_input == 4)
							{
								break;
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
						// 로그인에 실패하였습니다. 다시 시도해주세요. -> 반복
						cout << "Login failed. Please try again.\n";
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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