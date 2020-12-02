// ManagaDatabase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define User_MAX 100
#define ESC 27
void Ctrl_clear() {
	system("cls");
}

void Printmain() {
	cout << ",-------------------------------------------.\n";
	cout << "|                                           |\n";
	cout << "|       ,---------------------------.       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       |        Class Info         |       |\n";
	cout << "|       |             -             |       |\n";
	cout << "|       |    What will you choose   |       |\n";
	cout << "|       |             ?             |       |\n";
	cout << "|       |                           |       |\n";
	cout << "|       `---------------------------'       |\n";
	cout << "|                                           |\n";
	cout << "|              1. Data Insert               |\n";
	cout << "|              2. Show Data                 |\n";
	cout << "|              3. Delete Data               |\n";
	cout << "|              4. Back                      |\n";
	cout << "|                                           |\n";
	cout << "`-------------------------------------------'\n";
}
void UserInsert() {
	Ctrl_clear();
	ifstream input; 
	input.open("database.txt");//열람할 파일 이름 적는 공간
	ofstream writefile;
	writefile.open("database.txt"); //쓰기위한 파일 오픈
	int i = 0;
	if (input.fail()) {
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
	while (i < User_MAX) {
		cin >> write_line; //write_line 문자 입력받기
		i++;
		writefile << write_line << endl; //입력받은 문자를 파일에 넣기
		if (i % 5 == 0) {
			char ch;
			cout << "입력을 종료하시겠습니까?(Y/N):";
			cin >> ch;
			if (ch == 'Y') {
				cout << "입력을 종료합니다" << endl << endl;
				cout << "1. RE Insert 2. Show Data 3. Delete Data 4. Back " << endl;
				break;
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
void ShowUser() {
	cout << ",=========================================================================================.\n";
	cout << "|순번| 과목코드 | 과목명 | 이수구분 | 교수명 | 학점 | 시간표 | 상대평가 유형 | 수업계획서  |\n";
	cout << "`========================================================================================='\n";

}
void UserDel() {}

int main() {
	Printmain();
	int u_input;
	while (true) {
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
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
