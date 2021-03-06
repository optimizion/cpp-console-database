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
	bool changePassword(string id);
	void printStudentInfo();
	void printSubjectInfo();
	void printCourseInfo();
	void printChangePassword();
};

// 싱글톤 구현
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

// 인트라넷 메소드 및 콘솔 메소드
bool Intranet::checkLogin(string id, string pw)
{
	LoginInfoManager loginInfoManager;
	bool isSuccessed = loginInfoManager.checkLogin(id, pw);

	if (isSuccessed)
	{
		return true;
	}
	return false;
}
bool Intranet::changePassword(string id)
{
	LoginInfoManager loginInfoManager;
	bool isSuccessed = loginInfoManager.updatePassword(id);
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
	cout << "|       |     Hello, " << setw(9) << userName << "      |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|              1. Student Info              |\n";
	cout << "|              2. Subject Info              |\n";
	cout << "|              3. Course  Info              |\n";
	cout << "|              4. Change  Password          |\n";
	cout << "|              5. Logout                    |\n";
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
void Intranet::printChangePassword()
{
	cout << ",-------------------------------------------.\n";
	cout << "|                                           |\n";
	cout << "|       ,---------------------------.       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |      Change Password      |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|                                           |\n";
	cout << "`-------------------------------------------'\n";
}

// 인트라넷 프로그램 시작
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
				// enter studentPw.
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
									cout << "--------------------------------------------------------------" << endl;
									cout << "| StudentId" << " | " << "Name" << " | " << "Sex" << " | " << "Grade" << " | " << "Age" << " | " << "Email" << " | " << "PhoneNumber |" << endl;
									cout << "--------------------------------------------------------------" << endl;
									cout << "| " << student.getStudentId() << " | " << student.getName() << " | " << student.getSex() << " | " << student.getGrade() << " | " << student.getAge() << " | " << student.getEmail() << " | " << student.getPhoneNum() << " |" << endl;
									system("pause");
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

								cout << "--------------------------------------------------------------------------------" << endl;
								cout << "| ClassCode" << " | " << "ClassName" << " | " << "Professor" << " | " << "Grade" << " | " << "TimePlan" << " | " << "Classified" << " | " << "EvalType |" << endl;
								cout << "--------------------------------------------------------------------------------" << endl;
								/*while (getline(subjects, str))
								{
									cout << str << endl;
								}*/
								subjectManager.querySubjectData();
								system("pause");
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
								cout << "-----------------------------------------------------------------------" << endl;
								cout << "| StudentId" << " | " << "ClassCode" << " | " << "ClassName" << " | " << "Professor" << " | " << "TimePlan" << " | " << "location |" << endl;
								cout << "-----------------------------------------------------------------------" << endl;

								/*while (getline(courses, str))
								{
									cout << str << endl;
								}*/
								courseManager.queryCourseData(studentId);

								system("pause");
								cout << endl << "Press Enter to Continue" << endl;
								cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
								continue;
							}
							// 비밀번호 변경
							else if (user_input == 4)
							{
								intranet->clearConsole();
								intranet->printChangePassword();

								if (intranet->changePassword(studentId))
								{
									system("pause");
									continue;
								}
								cout << "비밀번호 변경에 실패했습니다." << endl;
								continue;
							}
							// Logout
							else if (user_input == 5)
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