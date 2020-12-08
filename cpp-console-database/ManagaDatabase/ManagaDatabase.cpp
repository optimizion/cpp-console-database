#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include "ManageTable.h"
#include <direct.h>
#include <io.h>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

class ManageDatabase
{
private:

public:
	//테이블을 모아둘 폴더 생성
	bool hasDirectory();
	bool makeDirectory();
	Student inputStudentData();
	Subject inputSubjectData();
	Course inputCourseData();
};
bool ManageDatabase::hasDirectory()
{
	if (_waccess(L"./table", 0) != 0)
	{
		return false;
	}
	return true;
}

bool ManageDatabase::makeDirectory()
{
	if (_mkdir("./table") != 0)
	{
		return false;
	}
	return true;
}
Student ManageDatabase::inputStudentData()
{
	Student student = Student();
	string studentId, name, email = NULL, phoneNum = NULL, address = NULL;
	char sex;
	short grade, age;

	return student;
};
Subject ManageDatabase::inputSubjectData()
{
	Subject subject = Subject();
	string classCode, className, professor, timePlan, classified, evalType;
	int grade;

	return subject;
};
Course ManageDatabase::inputCourseData()
{
	Course course = Course();
	string studentId, classCode, className, professor, timePlan, location;

	return course;
};

class Console
{
public:
	enum TYPE
	{
		MAIN,
		MANAGE_TABLE,
		SELECT_TABLE,
		MANAGE_TABLE_DATA,
		EXIT,
		INSERT_STUDENT_DATA,
		INSERT_SUBJECT_DATA,
		INSERT_COURSE_DATA
	};

	void printConsole(TYPE console)
	{
		switch (console)
		{
		case Console::MAIN:
			Console::printMain();
			break;
		case Console::MANAGE_TABLE:
			Console::printManageTable();
			break;
		case Console::SELECT_TABLE:
			Console::printSelectTable();
			break;
		case Console::MANAGE_TABLE_DATA:
			Console::printManageTableData();
			break;
		case TYPE::EXIT:
			Console::printExit();
		default:
			break;
		}
	}
	void clearConsole()
	{
		system("cls");
	}
	void printMain()
	{
		cout << ",-------------------------------------------.\n";
		cout << "|                                           |\n";
		cout << "|       ,---------------------------.       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       |      Manage Database      |       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       `---------------------------'       |\n";
		cout << "|                                           |\n";
		cout << "|              1. Manage Table              |\n";
		cout << "|              2. Manage Table Data         |\n";
		cout << "|              3. Exit                      |\n";
		cout << "|                                           |\n";
		cout << "`-------------------------------------------'\n";
	}
	void printManageTable()
	{
		cout << ",-------------------------------------------.\n";
		cout << "|                                           |\n";
		cout << "|       ,---------------------------.       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       |        Manage Table       |       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       `---------------------------'       |\n";
		cout << "|                                           |\n";
		cout << "|              1. Create Table              |\n";
		cout << "|              2. Delete Table              |\n";
		cout << "|              3. Go Back                   |\n";
		cout << "|                                           |\n";
		cout << "`-------------------------------------------'\n";
	}
	void printManageTableData()
	{
		cout << ",-------------------------------------------.\n";
		cout << "|                                           |\n";
		cout << "|       ,---------------------------.       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       |     Manage Table Data     |       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       `---------------------------'       |\n";
		cout << "|                                           |\n";
		cout << "|              1. Insert Data               |\n";
		cout << "|              2. Update Data               |\n";
		cout << "|              3. Delete Data               |\n";
		cout << "|              4. Go Back                   |\n";
		cout << "|                                           |\n";
		cout << "`-------------------------------------------'\n";
	}
	void printSelectTable()
	{
		cout << ",-------------------------------------------.\n";
		cout << "|                                           |\n";
		cout << "|       ,---------------------------.       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       |        Select Table       |       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       `---------------------------'       |\n";
		cout << "|                                           |\n";
		cout << "|              1. Student                   |\n";
		cout << "|              2. Subject                   |\n";
		cout << "|              3. Course                    |\n";
		cout << "|              4. Login Info                |\n";
		cout << "|              5. Go Back                   |\n";
		cout << "|                                           |\n";
		cout << "`-------------------------------------------'\n";
	}
	void printExit()
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
	void printInsertStudentData()
	{
		cout << ",-------------------------------------------.\n";
		cout << "|                                           |\n";
		cout << "|       ,---------------------------.       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       |    Insert Student Data    |       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       `---------------------------'       |\n";
		cout << "|                                           |\n";
		cout << "`-------------------------------------------'\n";
		cout << "ex)학번, 이름, 성별, 학년, 나이, 이메일, 휴대폰번호('-'제외), 주소\n";
	}
	void printInsertSubjectData()
	{
		{
			cout << ",-------------------------------------------.\n";
			cout << "|                                           |\n";
			cout << "|       ,---------------------------.       |\n";
			cout << "|       |                           |       |\n";
			cout << "|       |    Insert Subject Data    |       |\n";
			cout << "|       |                           |       |\n";
			cout << "|       `---------------------------'       |\n";
			cout << "|                                           |\n";
			cout << "`-------------------------------------------'\n";
			cout << "ex)과목코드, 과목명, 교수명, 학점, 시간표(화(7,8,9)), \n이수구분(전공 or 교양), 평가유형(상대평가 or 절대평가)\n";
		}
	}
	void printInsertCourseData()
	{
		{
			cout << ",-------------------------------------------.\n";
			cout << "|                                           |\n";
			cout << "|       ,---------------------------.       |\n";
			cout << "|       |                           |       |\n";
			cout << "|       |    Insert Course Data     |       |\n";
			cout << "|       |                           |       |\n";
			cout << "|       `---------------------------'       |\n";
			cout << "|                                           |\n";
			cout << "`-------------------------------------------'\n";
			cout << "ex)학번, 과목코드, 과목명, 교수명, 시간표(화(7,8,9)), 강의실\n";
		}
	}
	void printUpdateStudentData()
	{
		cout << ",-------------------------------------------.\n";
		cout << "|                                           |\n";
		cout << "|       ,---------------------------.       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       |    Update Student Data    |       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       `---------------------------'       |\n";
		cout << "|                                           |\n";
		cout << "`-------------------------------------------'\n";
	}
	void printUpdateSubjectData()
	{
		cout << ",-------------------------------------------.\n";
		cout << "|                                           |\n";
		cout << "|       ,---------------------------.       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       |    Update Subject Data    |       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       `---------------------------'       |\n";
		cout << "|                                           |\n";
		cout << "`-------------------------------------------'\n";
	}
	void printUpdateCourseData()
	{
		cout << ",-------------------------------------------.\n";
		cout << "|                                           |\n";
		cout << "|       ,---------------------------.       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       |    Update Course Data     |       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       `---------------------------'       |\n";
		cout << "|                                           |\n";
		cout << "`-------------------------------------------'\n";
	}
	void printDeleteStudentData()
	{
		cout << ",-------------------------------------------.\n";
		cout << "|                                           |\n";
		cout << "|       ,---------------------------.       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       |    Delete Student Data    |       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       `---------------------------'       |\n";
		cout << "|                                           |\n";
		cout << "`-------------------------------------------'\n";
	}
	void printDeleteSubjectData()
	{
		cout << ",-------------------------------------------.\n";
		cout << "|                                           |\n";
		cout << "|       ,---------------------------.       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       |    Delete Subject Data    |       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       `---------------------------'       |\n";
		cout << "|                                           |\n";
		cout << "`-------------------------------------------'\n";
	}
	void printDeleteCourseData()
	{
		cout << ",-------------------------------------------.\n";
		cout << "|                                           |\n";
		cout << "|       ,---------------------------.       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       |    Delete Course Data     |       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       `---------------------------'       |\n";
		cout << "|                                           |\n";
		cout << "`-------------------------------------------'\n";
	}
};

int main()
{
	ManageDatabase manageDatabase;
	Console console;

	// infinity loop, user_input, print console
	while (true)
	{
		//clear console
		console.clearConsole();
		console.printConsole(Console::TYPE::MAIN);

		// user_input
		int user_input;
		cout << "Enter number : ";
		cin >> user_input;

		//manage table
		if (user_input == 1)
		{
			while (true)
			{
				// clear console, show manage table console
				console.clearConsole();
				console.printConsole(Console::TYPE::MANAGE_TABLE);

				// user_input
				int user_input;
				cout << "Enter number : ";
				cin >> user_input;

				TableManager tableManager;
				// create table
				if (user_input == 1)
				{
					// clear console, show select table console
					console.clearConsole();
					console.printConsole(Console::TYPE::SELECT_TABLE);

					// 번호를 입력받고, 해당하는 테이블을 만든다
					int user_input;
					cout << "Enter number : ";
					cin >> user_input;
					TableManager::TABLE table;
					// create student table
					if (user_input == 1)
					{
						if (manageDatabase.hasDirectory())
						{
							manageDatabase.makeDirectory();
						}
						table = TableManager::TABLE::STUDENT;
						tableManager.createTable(table);
						break;
					}
					// create subject table
					else if (user_input == 2)
					{
						if (manageDatabase.hasDirectory())
						{
							manageDatabase.makeDirectory();
						}
						table = TableManager::TABLE::SUBJECT;
						tableManager.createTable(table);
						break;
					}
					// create course table
					else if (user_input == 3)
					{
						if (manageDatabase.hasDirectory())
						{
							manageDatabase.makeDirectory();
						}
						table = TableManager::TABLE::COURSE;
						tableManager.createTable(table);
						break;
					}
					// create loginInfo table
					else if (user_input == 4)
					{
						if (manageDatabase.hasDirectory())
						{
							manageDatabase.makeDirectory();
						}
						table = TableManager::TABLE::LOGIN_INFO;
						tableManager.createTable(table);
						break;
					}
					// go back
					else if (user_input == 5)
					{
						break;
					}
					// wrong input
					else
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "wrong input. Please retry.\n";
						sleep_for(seconds(1));
						continue;
					}

				}
				// delete table
				else if (user_input == 2)
				{
					// clear console, show select table console
					console.clearConsole();
					console.printConsole(Console::TYPE::SELECT_TABLE);

					// 번호를 입력받고, 해당하는 테이블을 삭제한다
					int user_input;
					cout << "Enter number : ";
					cin >> user_input;

					TableManager::TABLE table;
					//student table 삭제
					if (user_input == 1)
					{
						bool isDeleted;
						table = TableManager::TABLE::STUDENT;
						//isDeleted = tableManager.deleteTable(table);
						tableManager.deleteTable(table);
						break;
					}
					//subject table 삭제
					else if (user_input == 2)
					{
						table = TableManager::TABLE::SUBJECT;
						tableManager.deleteTable(table);
						break;
					}
					//course table 삭제
					else if (user_input == 3)
					{
						table = TableManager::TABLE::COURSE;
						tableManager.deleteTable(table);
						break;
					}
					//loginInfo table 삭제
					else if (user_input == 4)
					{
						table = TableManager::TABLE::LOGIN_INFO;
						tableManager.deleteTable(table);
						break;
					}
					//go back
					else if (user_input == 5)
					{
						break;
					}
					//wrong input
					else
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "wrong input. Please retry.\n";
						sleep_for(seconds(1));
						continue;
					}
				}
				// go back
				else if (user_input == 3)
				{
					console.clearConsole();
					break;
				}
				// wrong input
				else
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "wrong input. Please retry.\n";
					sleep_for(seconds(1));
					continue;
				}
			}
		}
		//manage table data
		else if (user_input == 2)
		{
			while (true)
			{
				// clear console, show manage select table console
				console.clearConsole();
				console.printConsole(Console::TYPE::SELECT_TABLE);
				// user_input
				int user_input;
				cout << "Enter number : ";
				cin >> user_input;
				// clear console, show manage table data console
				console.clearConsole();
				console.printConsole(Console::TYPE::MANAGE_TABLE_DATA);
				// student table
				if (user_input == 1)
				{
					StudentManager studentManager;
					// user_input
					int user_input;
					cout << "Enter number : ";
					cin >> user_input;
					// insert data
					if (user_input == 1)
					{
						//Student student = manageDatabase.inputStudentData();
						//StudentManager.insertData(student);
					}
					// update data
					else if (user_input == 2)
					{
						//Subject subject = manageDatabase.inputSubjectData();
					}
					// delete data
					else if (user_input == 3)
					{
					}
					// go back
					else if (user_input == 4)
					{
						continue;
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
				// subject table
				else if (user_input == 2)
				{
					SubjectManager subjectManager;
					// user_input
					int user_input;
					cout << "Enter number : ";
					cin >> user_input;
					// insert data
					if (user_input == 1)
					{
						//SubjectManager.insertData();
					}
					// update data
					else if (user_input == 2)
					{
						//SubjectManager.updateData();
					}
					// delete data
					else if (user_input == 3)
					{
						//SubjectManager.deleteData();
					}
					// go back
					else if (user_input == 4)
					{
						continue;
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
				// course table
				else if (user_input == 3)
				{
					CourseManager courseManager;
					// user_input
					int user_input;
					cout << "Enter number : ";
					cin >> user_input;
					// insert data
					if (user_input == 1)
					{
						//CourseManager.insertData();
					}
					// update data
					else if (user_input == 2)
					{
						//CourseManager.updateData();
					}
					// delete data
					else if (user_input == 3)
					{
						//CourseManager.deleteData();
					}
					// go back
					else if (user_input == 4)
					{
						continue;
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
				// loginInfo table
				else if (user_input == 4)
				{
					LoginInfoManager loginInfoManager;
					// user_input
					int user_input;
					cout << "Enter number : ";
					cin >> user_input;
					// insert data
					if (user_input == 1)
					{
						//LoginInfoManager.insertData();
					}
					// update data
					else if (user_input == 2)
					{
						//LoginInfoManager.updateData();
					}
					// delete data
					else if (user_input == 3)
					{
						//LoginInfoManager.deleteData();
					}
					// go back
					else if (user_input == 4)
					{
						continue;
					}
					// wrong input
					else
					{
						cout << "wrong input. Please try again.\n";
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						sleep_for(seconds(1));
					}

				}
				else if (user_input == 5)
				{
					console.clearConsole();
					break;
				}
				// wrong input
				else
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "wrong input. Please retry.\n";
					sleep_for(seconds(1));
					continue;
				}
			}
		}
		//exit
		else if (user_input == 3)
		{
			// clear console, show exit console
			console.clearConsole();
			console.printConsole(Console::TYPE::EXIT);
			sleep_for(seconds(1));
			break;
		}
		//wrong input
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