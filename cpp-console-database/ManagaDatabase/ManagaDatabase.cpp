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
	//테이블 존재 여부 확인
	bool hasTable(ManageDatabase::TABLE table);
	//테이블을 모아둘 폴더 생성
	void makeDirectory();
};

int main()
{
	//시작 화면 출력
	printConsole(CONSOLE::MAIN);

	int user_input;
	cin >> user_input;
	//무한 루프를 돌면서 사용자한테 번호를 입력 받고, 콘솔을 출력한다.
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
	// if(!테이블 존재 여부?) {"table doesn't exist"} else {해당 테이블 찾아서 파일 삭제, "table is successfully deleted"}
}
bool ManageDatabase::hasTable(TABLE table)
{
	// 테이블이 있는지 확인하는 코드
}

// 다른 파일로 뺄 부분
void userInsert()
{
	clearConsole();
	ifstream input;
	input.open("database.txt");//열람할 파일 이름 적는 공간
	ofstream writefile;
	writefile.open("database.txt"); //쓰기위한 파일 오픈
	int i = 0;
	if (input.fail())
	{
		cout << "**파일이 존재하지 않습니다.**" << endl;
		cout << "**파일을 생성합니다.**" << endl;
		ofstream writefile; //파일 위치는 소스코드 파일
		writefile.open("database.txt");
	}

	string write_line;
	cout << endl << endl;
	cout << "데이터를 5번 입력하면 종료안내가 나옵니다." << endl << endl;
	cout << ",-----------------------------------------------------------------------------------------." << endl;
	cout << "|순번| 과목코드 | 과목명 | 이수구분 | 교수명 | 학점 | 시간표 | 상대평가 유형 | 수업계획서 |" << endl;
	cout << "'-----------------------------------------------------------------------------------------'" << endl;
	char key;
	while (i < User_MAX)
	{
		cin >> write_line; //write_line 문자 입력받기
		i++;
		writefile << write_line << endl; //입력받은 문자를 파일에 넣기
		if (i % 5 == 0)
		{
			char ch;
			cout << "입력을 종료하시겠습니까?(Y/N):";
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				cout << "입력을 종료합니다" << endl << endl;
				cout << "1. RE Insert 2. Show Data 3. Delete Data 4. Back " << endl;
				break;
			}
			else if (ch == 'N' || ch == 'n')
			{

			}
		}

		/*key = _getch();
		if (key == ESC) {
		cout << "입력을 종료합니다" << endl << endl;
		cout << "1. RE Insert 2. Show Data 3. Delete Data 4. Back " << endl;
		break;
		}*/

	}

	input.close();

}
void showUser()
{
	cout << ",=========================================================================================.\n";
	cout << "|순번| 과목코드 | 과목명 | 이수구분 | 교수명 | 학점 | 시간표 | 상대평가 유형 | 수업계획서  |\n";
	cout << "`========================================================================================='\n";
}
void userDel() {}

// 파일로 저장하는 부분
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