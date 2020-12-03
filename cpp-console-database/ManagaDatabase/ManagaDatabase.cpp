#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum CONSOLE
{
	MAIN,
	MANAGE_TABLE,
	SELECT_TABLE,
	MANAGE_TABLE_DATA,
	EXIT
};

class ManageDatabase
{
private:

public:
	//table info
	enum TABLE
	{
		STUDENT,
		SUBJECT,
		COURSE
	};
	//create table
	void createTable();
	//delete table
	void deleteTable();
	//���̺� ���� ���� Ȯ��
	bool hasTable(ManageDatabase::TABLE table);
	//���̺��� ��Ƶ� ���� ����
	void makeDirectory();
};

int main()
{
	//���� ȭ�� ���
	printConsole(CONSOLE::MAIN);

	int user_input;
	cin >> user_input;
	//���� ������ ���鼭 ��������� ��ȣ�� �Է� �ް�, �ܼ��� ����Ѵ�.
	while (true)
	{
		//manage table
		if (user_input == 1)
		{
			// clear console, show manage table console
			while (true)
			{
				// create table
				if ()
				{
				}
				// delete table
				else if ()
				{
				}
				// go back
				else if ()
				{
				}
				// wrong input
				else
				{
				}
			}
		}
		//manage table data
		else if (user_input == 2)
		{
			// clear console, show manage select table console
			while (true)
			{
				// student table
				if ()
				{
				}
				// subject table
				else if ()
				{
				}
				// course table
				else if ()
				{
				}
				// wrong input
				else
				{
				}
			}
		}
		//exit
		else if (user_input == 3)
		{
			// clear console, show exit console
		}
		//wrong input
		else
		{
		}
	}
}

// Console Method
void printConsole(CONSOLE console)
{
	switch (console)
	{
	case MAIN:
		printMain();
		break;
	case MANAGE_TABLE:
		printManageTable();
		break;
	case SELECT_TABLE:
		printSelectTable();
	case MANAGE_TABLE_DATA:
		printManageTableData();
		break;
	case EXIT:
		printExit();
	default:
		break;
	}
};
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

// Manage Table
void ManageDatabase::createTable()
{
}
void ManageDatabase::deleteTable()
{
	// if(!���̺� ���� ����?) {"table doesn't exist"} else {�ش� ���̺� ã�Ƽ� ���� ����, "table is successfully deleted"}
}
bool ManageDatabase::hasTable(TABLE table)
{
	// ���̺��� �ִ��� Ȯ���ϴ� �ڵ�
}

// �ٸ� ���Ϸ� �� �κ�
void userInsert()
{
	clearConsole();
	ifstream input;
	input.open("database.txt");//������ ���� �̸� ���� ����
	ofstream writefile;
	writefile.open("database.txt"); //�������� ���� ����
	int i = 0;
	if (input.fail())
	{
		cout << "**������ �������� �ʽ��ϴ�.**" << endl;
		cout << "**������ �����մϴ�.**" << endl;
		ofstream writefile; //���� ��ġ�� �ҽ��ڵ� ����
		writefile.open("database.txt");
	}

	string write_line;
	cout << endl << endl;
	cout << "�����͸� 5�� �Է��ϸ� ����ȳ��� ���ɴϴ�." << endl << endl;
	cout << ",-----------------------------------------------------------------------------------------." << endl;
	cout << "|����| �����ڵ� | ����� | �̼����� | ������ | ���� | �ð�ǥ | ����� ���� | ������ȹ�� |" << endl;
	cout << "'-----------------------------------------------------------------------------------------'" << endl;
	char key;
	while (i < User_MAX)
	{
		cin >> write_line; //write_line ���� �Է¹ޱ�
		i++;
		writefile << write_line << endl; //�Է¹��� ���ڸ� ���Ͽ� �ֱ�
		if (i % 5 == 0)
		{
			char ch;
			cout << "�Է��� �����Ͻðڽ��ϱ�?(Y/N):";
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				cout << "�Է��� �����մϴ�" << endl << endl;
				cout << "1. RE Insert 2. Show Data 3. Delete Data 4. Back " << endl;
				break;
			}
			else if (ch == 'N' || ch == 'n')
			{

			}
		}

		/*key = _getch();
		if (key == ESC) {
		cout << "�Է��� �����մϴ�" << endl << endl;
		cout << "1. RE Insert 2. Show Data 3. Delete Data 4. Back " << endl;
		break;
		}*/

	}

	input.close();

}
void showUser()
{
	cout << ",=========================================================================================.\n";
	cout << "|����| �����ڵ� | ����� | �̼����� | ������ | ���� | �ð�ǥ | ����� ���� | ������ȹ��  |\n";
	cout << "`========================================================================================='\n";
}
void userDel() {}

// ���Ϸ� �����ϴ� �κ�
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