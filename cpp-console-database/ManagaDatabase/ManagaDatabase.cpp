#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include "ManageTable.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

class ManageDatabase
{
private:

public:
	//���̺��� ��Ƶ� ���� ����
	void makeDirectory();
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
		cout << "|              4. Go Back                   |\n";
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
		cout << "ex)�й�, �̸�, ����, �г�, ����, �̸���, ��ȭ��ȣ('-'����), �ּ�\n";
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
			cout << "ex)�����ڵ�, �����, ������, ����, �ð�ǥ(ȭ(7,8,9)), \n�̼�����(���� or ����), ������(����� or ������)\n";
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
			cout << "ex)�й�, �����ڵ�, �����, ������, �ð�ǥ(ȭ(7,8,9)), ���ǽ�\n";
		}
	}
};

int main()
{
	// print start console
	Console console;
	console.printConsole(Console::TYPE::MAIN);

	// user_input
	int user_input;
	cin >> user_input;

	// infinity loop, user_input, print console
	while (true)
	{
		//manage table
		if (user_input == 1)
		{
			// clear console, show manage table console
			console.clearConsole();
			console.printConsole(Console::TYPE::MANAGE_TABLE);
			// user_input
			cin >> user_input;
			while (true)
			{
				TableManager tableManager;
				// create table
				if (user_input == 1)
				{
					// clear console, show select table console
					console.clearConsole();
					console.printConsole(Console::TYPE::SELECT_TABLE);

					// ��ȣ�� �Է¹ް�, �ش��ϴ� ���̺��� �����
					TableManager::TABLE table;
					if (user_input == 1)
					{
						table = TableManager::TABLE::STUDENT;
					}
					else if (user_input == 2)
					{
						table = TableManager::TABLE::SUBJECT;
					}
					else if (user_input == 3)
					{
						table = TableManager::TABLE::COURSE;
					}
					else if (user_input == 4)
					{
						table = TableManager::TABLE::LOGIN_INFO;
					}

					tableManager.createTable(table);
				}
				// delete table
				else if (user_input == 2)
				{
					// clear console, show select table console
					console.clearConsole();
					console.printConsole(Console::TYPE::SELECT_TABLE);

					// ��ȣ�� �Է¹ް�, �ش��ϴ� ���̺��� �����Ѵ�
					TableManager::TABLE table;
					if (user_input == 1)
					{
						table = TableManager::TABLE::STUDENT;
					}
					else if (user_input == 2)
					{
						table = TableManager::TABLE::SUBJECT;
					}
					else if (user_input == 3)
					{
						table = TableManager::TABLE::COURSE;
					}
					else if (user_input == 4)
					{
						table = TableManager::TABLE::LOGIN_INFO;
					}

					tableManager.deleteTable(table);
				}
				// go back
				else if (user_input == 3)
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
		}
		//manage table data
		else if (user_input == 2)
		{
			// clear console, show manage select table console
			console.clearConsole();
			console.printConsole(Console::TYPE::SELECT_TABLE);

			while (true)
			{
				// user_input
				cin >> user_input;
				// clear console, show manage table data console
				console.clearConsole();
				console.printConsole(Console::TYPE::MANAGE_TABLE_DATA);
				// student table
				if (user_input == 1)
				{
					StudentManager studentManager;
					// user_input
					cin >> user_input;
					// insert data
					if (user_input == 1)
					{
						StudentManager.insertData();
					}
					// update data
					else if (user_input == 2)
					{
					}
					// delete data
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
				// subject table
				else if (user_input == 2)
				{
				}
				// course table
				else if (user_input == 3)
				{
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
		}
		//wrong input
		else
		{
		}

		console.clearConsole();
		console.printConsole(Console::TYPE::MAIN);
		int user_input;
		cin >> user_input;
	}
}




// Manage Table


/*

	Printmain();
	int u_input;
	while (true)
	{
		cout << "Choose number: ";
		cin >> u_input;
		//fail()�Է� ������ �߻����� ��  true ��ȯ
		if (cin.fail())
		{
			cin.clear(); //�������� ����.
			cin.ignore(1024, '\n');
			continue;
		}
		switch (u_input)
		{
		case 1:
			UserInsert();
			break;
		case 2:
			ShowUser();
			break;
		case 3:
			UserDel();
			break;
		default:
			break;
		}
	}
*/