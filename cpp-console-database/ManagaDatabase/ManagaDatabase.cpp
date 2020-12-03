#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
	void createTable() {};
	//delete table
	void deleteTable()
	{
		// if(!테이블 존재 여부?) {"table doesn't exist"} else {해당 테이블 찾아서 파일 삭제, "table is successfully deleted"}
	};
	//테이블 존재 여부 확인
	bool hasTable(ManageDatabase::TABLE table) {};
	//테이블을 모아둘 폴더 생성
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
		EXIT
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
};

int main()
{
	//시작 화면 출력
	Console console;
	console.printConsole(Console::TYPE::MAIN);

	int user_input;
	cin >> user_input;
	//무한 루프를 돌면서 사용자한테 번호를 입력 받고, 콘솔을 출력한다.
	while (true)
	{
		//manage table
		if (user_input == 1)
		{
			// clear console, show manage table console
			console.clearConsole();
			console.printConsole(Console::TYPE::MANAGE_TABLE);
			while (true)
			{
				// create table
				if (true)
				{
				}
				// delete table
				else if (true)
				{
				}
				// go back
				else if (true)
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
			console.clearConsole();
			console.printConsole(Console::TYPE::MANAGE_TABLE_DATA);
			while (true)
			{
				// student table
				if (true)
				{
				}
				// subject table
				else if (true)
				{
				}
				// course table
				else if (true)
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
			console.clearConsole();
			console.printConsole(Console::TYPE::EXIT);
		}
		//wrong input
		else
		{
		}
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
		//fail()입력 에러가 발생했을 때  true 반환
		if (cin.fail())
		{
			cin.clear(); //에러버퍼 비우기.
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