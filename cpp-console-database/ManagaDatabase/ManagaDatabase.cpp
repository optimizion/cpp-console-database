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
	input.open("database.txt");//������ ���� �̸� ���� ����
	ofstream writefile;
	writefile.open("database.txt"); //�������� ���� ����
	int i = 0;
	if (input.fail()) {
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
	while (i < User_MAX) {
		cin >> write_line; //write_line ���� �Է¹ޱ�
		i++;
		writefile << write_line << endl; //�Է¹��� ���ڸ� ���Ͽ� �ֱ�
		if (i % 5 == 0) {
			char ch;
			cout << "�Է��� �����Ͻðڽ��ϱ�?(Y/N):";
			cin >> ch;
			if (ch == 'Y') {
				cout << "�Է��� �����մϴ�" << endl << endl;
				cout << "1. RE Insert 2. Show Data 3. Delete Data 4. Back " << endl;
				break;
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
void ShowUser() {
	cout << ",=========================================================================================.\n";
	cout << "|����| �����ڵ� | ����� | �̼����� | ������ | ���� | �ð�ǥ | ����� ���� | ������ȹ��  |\n";
	cout << "`========================================================================================='\n";

}
void UserDel() {}

int main() {
	Printmain();
	int u_input;
	while (true) {
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
