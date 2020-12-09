#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include "ManageTable.h"
#include <direct.h>
#include <io.h>
#include <vector>
#include <sstream>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

// �����ͺ��̽� ���� Ŭ����
class ManageDatabase
{
private:
	StudentManager studentManager;
	SubjectManager subjectManager;
	CourseManager courseManager;
	LoginInfoManager loginInfoManager;
public:
	ManageDatabase() {}
	//���̺��� ��Ƶ� ���� ����
	bool hasDirectory()
	{
		if (_waccess(L"./table", 0) != 0)
		{
			return false;
		}
		return true;
	}
	bool makeDirectory()
	{
		if (_mkdir("./table") != 0)
		{
			return false;
		}
		return true;
	}
	bool inputStudentData()
	{
		ifstream fin;
		fin.open("./table/student.txt");
		if (!fin)
		{
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}

		// ����ó�� �ʿ�
		Student student = Student();
		string studentId, name, email, phoneNum, sex;
		short grade, age;

		cout << "ex)�й�,�̸�,����,�г�,����,�̸���,�޴�����ȣ('-'����)\n";
		cout << "Enter data : ";
		vector<string> results;
		string str;
		cin >> str;
		stringstream ss(str);

		while (getline(ss, str, ','))
		{
			results.push_back(str);
		}
		student.setStudentId(results[0]);
		student.setName(results[1]);
		student.setSex(results[2]);
		student.setGrade(stoi(results[3]));
		student.setAge(stoi(results[4]));
		student.setEmail(results[5]);
		student.setPhoneNum(results[6]);

		studentManager.insertData(student);
		return true;
	}
	bool inputSubjectData()
	{
		ifstream fin;
		fin.open("./table/subject.txt");
		if (!fin)
		{
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}

		// ����ó�� �ʿ�
		Subject subject = Subject();
		string classCode, className, professor, timePlan, classified, evalType;
		int grade;

		cout << "ex)�����ڵ�,�����,������,����,�ð�ǥ(ȭ(789)),�̼�����(���� or ����),������(����� or ������)\n";
		cout << "Enter data : ";
		vector<string> results;
		string str;
		cin >> str;
		stringstream ss(str);

		while (getline(ss, str, ','))
		{
			results.push_back(str);
		}
		subject.setClassCode(results[0]);
		subject.setClassName(results[1]);
		subject.setProfessor(results[2]);
		subject.setGrade(stoi(results[3]));
		subject.setTimePlan(results[4]);
		subject.setClassified(results[5]);
		subject.setEvalType(results[6]);

		subjectManager.insertData(subject);
		return true;
	}
	bool inputCourseData()
	{
		ifstream fin;
		fin.open("./table/course.txt");
		if (!fin)
		{
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}

		// ����ó�� �ʿ�
		Course course = Course();
		string studentId, classCode, className, professor, timePlan, location;

		cout << "ex)�й�,�����ڵ�,�����,������,�ð�ǥ(ȭ(789)),���ǽ�(��(605))\n";
		cout << "Enter data : ";
		vector<string> results;
		string str;
		cin >> str;
		stringstream ss(str);

		while (getline(ss, str, ','))
		{
			results.push_back(str);
		}

		course.setStudentId(results[0]);
		course.setClassCode(results[1]);
		course.setClassName(results[2]);
		course.setProfessor(results[3]);
		course.setTimePlan(results[4]);
		course.setLocation(results[5]);
		courseManager.insertData(course);
		return true;
	}
	bool inputLoginInfoData()
	{
		ifstream fin;
		fin.open("./table/loginInfo.txt");
		if (!fin)
		{
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}

		// ����ó�� �ʿ�
		LoginInfo loginInfo = LoginInfo();
		string studentId, password;
		//string user_input;
		cout << "ex)�й�,��й�ȣ\n";
		cout << "Enter data : ";
		vector<string> results;
		string str;
		cin >> str;
		stringstream ss(str);

		while (getline(ss, str, ','))
		{
			results.push_back(str);
		}


		loginInfo.setStudentId(results[0]);
		loginInfo.setPassword(results[1]);
		loginInfoManager.insertData(loginInfo);
		return true;
	}
	bool updateStudentData()
	{
		ifstream fin;
		fin.open("./table/student.txt");
		if (!fin)
		{
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}

		string studentId;
		cout << "�й� �Է� : ";
		cin >> studentId;

		bool isSuccessed = studentManager.updateData(studentId);
		if (isSuccessed)
		{
			return true;
		}
		return false;
	}
	bool updateSubjectData()
	{
		ifstream fin;
		fin.open("./table/subject.txt");
		if (!fin)
		{
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}

		string classCode;
		cout << "�����ȣ �Է� : ";
		cin >> classCode;

		bool isSuccessed = subjectManager.updateData(classCode);
		if (isSuccessed)
		{
			return true;
		}
		return false;
	}
	bool updateCourseData()
	{
		ifstream fin;
		fin.open("./table/course.txt");
		if (!fin)
		{
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}

		string studentId, classCode;
		cout << "�й� �Է� : ";
		cin >> studentId;
		cout << "�����ڵ� �Է� : ";
		cin >> classCode;

		bool isSuccessed = courseManager.updateData(studentId, classCode);
		if (isSuccessed)
		{
			return true;
		}
		return false;
	}
	bool updateLoginInfoData()
	{
		ifstream fin;
		fin.open("./table/loginInfo.txt");
		if (!fin)
		{
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}
		string studentId;
		cout << "�й� �Է� : ";
		cin >> studentId;

		bool isSuccessed = loginInfoManager.updatePassword(studentId);
		if (isSuccessed)
		{
			return true;
		}
		return false;
	}
	bool deleteStudentData()
	{
		ifstream fin;
		fin.open("./table/student.txt");
		if (!fin)
		{
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}
		fin.close();
		string studentId;
		cout << "�й� �Է� : ";
		cin >> studentId;

		bool isSuccessed = studentManager.deleteData(studentId);
		if (isSuccessed)
		{
			return true;
		}
		return false;
	}
	bool deleteSubjectData()
	{
		ifstream fin;
		fin.open("./table/subject.txt");
		if (!fin)
		{
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}
		fin.close();
		string classCode;
		cout << "�����ڵ� �Է� : ";
		cin >> classCode;

		bool isSuccessed = subjectManager.deleteData(classCode);
		if (isSuccessed)
		{
			return true;
		}
		return false;
	}
	bool deleteCourseData()
	{
		ifstream fin;
		fin.open("./table/course.txt");
		if (!fin)
		{
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}
		fin.close();
		string studentId, classCode;
		cout << "�й� �Է� : ";
		cin >> studentId;
		cout << "�����ڵ� �Է� : ";
		cin >> classCode;

		bool isSuccessed = courseManager.deleteData(studentId, classCode);
		if (isSuccessed)
		{
			return true;
		}
		return false;
	}
	bool deleteLoginInfoData()
	{
		ifstream fin;
		fin.open("./table/loginInfo.txt");
		if (!fin)
		{
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}
		fin.close();
		string studentId;
		cout << "�й� �Է� : ";
		cin >> studentId;

		bool isSuccessed = loginInfoManager.deleteData(studentId);
		if (isSuccessed)
		{
			return true;
		}
		return false;
	}
};

// �ܼ� ó�� Ŭ����
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
		}
	}
	void printInsertLoginInfoData()
	{
		cout << ",-------------------------------------------.\n";
		cout << "|                                           |\n";
		cout << "|       ,---------------------------.       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       |   Insert LoginInfo Data   |       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       `---------------------------'       |\n";
		cout << "|                                           |\n";
		cout << "`-------------------------------------------'\n";
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
	void printUpdateLoginInfoData()
	{
		cout << ",-------------------------------------------.\n";
		cout << "|                                           |\n";
		cout << "|       ,---------------------------.       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       |   Update LoginInfo Data   |       |\n";
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
	void printDeleteLoginInfoData()
	{
		cout << ",-------------------------------------------.\n";
		cout << "|                                           |\n";
		cout << "|       ,---------------------------.       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       |   Delete LoginInfo Data   |       |\n";
		cout << "|       |                           |       |\n";
		cout << "|       `---------------------------'       |\n";
		cout << "|                                           |\n";
		cout << "`-------------------------------------------'\n";
	}
};

// �����ͺ��̽� ���� ���α׷� ����
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
		int user_input = 0;
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
				int user_input = 0;
				cout << "Enter number : ";
				cin >> user_input;

				TableManager tableManager;
				// create table
				if (user_input == 1)
				{
					// clear console, show select table console
					console.clearConsole();
					console.printConsole(Console::TYPE::SELECT_TABLE);

					// ��ȣ�� �Է¹ް�, �ش��ϴ� ���̺��� �����
					int user_input = 0;
					cout << "Enter number : ";
					cin >> user_input;
					TableManager::TABLE table;
					// create student table
					if (user_input == 1)
					{
						if (!manageDatabase.hasDirectory())
						{
							if (manageDatabase.makeDirectory())
							{
								sleep_for(seconds(1));
							}
						}
						table = TableManager::TABLE::STUDENT;
						tableManager.createTable(table);
						break;
					}
					// create subject table
					else if (user_input == 2)
					{
						if (!manageDatabase.hasDirectory())
						{
							if (manageDatabase.makeDirectory())
							{
								cout << "������ �����Ǿ����ϴ�.\n";
								sleep_for(seconds(1));
							}
						}
						table = TableManager::TABLE::SUBJECT;
						tableManager.createTable(table);
						break;
					}
					// create course table
					else if (user_input == 3)
					{
						if (!manageDatabase.hasDirectory())
						{
							if (manageDatabase.makeDirectory())
							{
								cout << "������ �����Ǿ����ϴ�.\n";
								sleep_for(seconds(1));
							}
						}
						table = TableManager::TABLE::COURSE;
						tableManager.createTable(table);
						break;
					}
					// create loginInfo table
					else if (user_input == 4)
					{
						if (!manageDatabase.hasDirectory())
						{
							if (manageDatabase.makeDirectory())
							{
								cout << "������ �����Ǿ����ϴ�.\n";
								sleep_for(seconds(1));
							}
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

					// ��ȣ�� �Է¹ް�, �ش��ϴ� ���̺��� �����Ѵ�
					int user_input = 0;
					cout << "Enter number : ";
					cin >> user_input;

					TableManager::TABLE table;
					//student table ����
					if (user_input == 1)
					{
						bool isDeleted;
						table = TableManager::TABLE::STUDENT;
						//isDeleted = tableManager.deleteTable(table);
						tableManager.deleteTable(table);
						break;
					}
					//subject table ����
					else if (user_input == 2)
					{
						table = TableManager::TABLE::SUBJECT;
						tableManager.deleteTable(table);
						break;
					}
					//course table ����
					else if (user_input == 3)
					{
						table = TableManager::TABLE::COURSE;
						tableManager.deleteTable(table);
						break;
					}
					//loginInfo table ����
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
				int user_input = 0;
				cout << "Enter number : ";
				cin >> user_input;
				// clear console, show manage table data console
				console.clearConsole();
				console.printConsole(Console::TYPE::MANAGE_TABLE_DATA);
				// student table
				if (user_input == 1)
				{
					// user_input
					int user_input = 0;
					cout << "Enter number : ";
					cin >> user_input;
					// insert data
					if (user_input == 1)
					{
						console.clearConsole();
						console.printInsertStudentData();
						// ������ ���Կ� �����ϸ� true, �����ϸ� false ��ȯ
						bool isSuccessed = manageDatabase.inputStudentData();

						if (isSuccessed)
						{
							cout << "������ ���Կ� �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
							break;
						}
						else
						{
							cout << "������ ���Կ� �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
							break;
						}

					}
					// update data
					else if (user_input == 2)
					{
						console.clearConsole();
						console.printUpdateStudentData();
						// ������ ������ �����ϸ� true, �����ϸ� false ��ȯ
						bool isSuccessed = manageDatabase.updateStudentData();
						if (isSuccessed)
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
						else
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
					}
					// delete data
					else if (user_input == 3)
					{
						console.clearConsole();
						console.printDeleteStudentData();
						// ������ ������ �����ϸ� true, �����ϸ� false ��ȯ
						bool isSuccessed = manageDatabase.deleteStudentData();
						if (isSuccessed)
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
						else
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
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
					// user_input
					int user_input = 0;
					cout << "Enter number : ";
					cin >> user_input;
					// insert data
					if (user_input == 1)
					{
						console.clearConsole();
						console.printInsertSubjectData();
						// ������ ���Կ� �����ϸ� true, �����ϸ� false ��ȯ
						bool isSuccessed = manageDatabase.inputSubjectData();
						if (isSuccessed)
						{
							cout << "������ ���Կ� �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
						else
						{
							cout << "������ ���Կ� �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}

					}
					// update data
					else if (user_input == 2)
					{
						console.clearConsole();
						console.printUpdateSubjectData();
						// ������ ������ �����ϸ� true, �����ϸ� false ��ȯ
						bool isSuccessed = manageDatabase.updateSubjectData();
						if (isSuccessed)
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
						else
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
					}
					// delete data
					else if (user_input == 3)
					{
						console.clearConsole();
						console.printDeleteSubjectData();
						// ������ ������ �����ϸ� true, �����ϸ� false ��ȯ
						bool isSuccessed = manageDatabase.deleteSubjectData();
						if (isSuccessed)
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
						else
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
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
					int user_input = 0;
					cout << "Enter number : ";
					cin >> user_input;
					// insert data
					if (user_input == 1)
					{
						console.clearConsole();
						console.printInsertCourseData();
						// ������ ���Կ� �����ϸ� true, �����ϸ� false ��ȯ
						bool isSuccessed = manageDatabase.inputCourseData();
						if (isSuccessed)
						{
							cout << "������ ���Կ� �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
						else
						{
							cout << "������ ���Կ� �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
					}
					// update data
					else if (user_input == 2)
					{
						console.clearConsole();
						console.printUpdateCourseData();
						// ������ ������ �����ϸ� true, �����ϸ� false ��ȯ
						bool isSuccessed = manageDatabase.updateCourseData();
						if (isSuccessed)
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
						else
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
					}
					// delete data
					else if (user_input == 3)
					{
						console.clearConsole();
						console.printDeleteCourseData();
						// ������ ������ �����ϸ� true, �����ϸ� false ��ȯ
						bool isSuccessed = manageDatabase.deleteCourseData();
						if (isSuccessed)
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
						else
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
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
					int user_input = 0;
					cout << "Enter number : ";
					cin >> user_input;
					// insert data
					if (user_input == 1)
					{
						console.clearConsole();
						console.printInsertLoginInfoData();
						// ������ ���Կ� �����ϸ� true, �����ϸ� false ��ȯ
						bool isSuccessed = manageDatabase.inputLoginInfoData();
						if (isSuccessed)
						{
							cout << "������ ���Կ� �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
							break;
						}
						else
						{
							cout << "������ ���Կ� �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
							break;
						}
					}
					// update data
					else if (user_input == 2)
					{
						console.clearConsole();
						console.printUpdateLoginInfoData();
						// ������ ������ �����ϸ� true, �����ϸ� false ��ȯ
						bool isSuccessed = manageDatabase.updateLoginInfoData();
						if (isSuccessed)
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
						else
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
					}
					// delete data
					else if (user_input == 3)
					{
						console.clearConsole();
						console.printDeleteLoginInfoData();
						// ������ ������ �����ϸ� true, �����ϸ� false ��ȯ
						bool isSuccessed = manageDatabase.deleteLoginInfoData();
						if (isSuccessed)
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
						else
						{
							cout << "������ ������ �����Ͽ����ϴ�.\n";
							sleep_for(seconds(1));
						}
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
				// go back
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