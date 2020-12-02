#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define User_MAX 100
#define ESC 27

class Ctrl_class {
public:
	enum menu {
		Insert,
		Show,
		Del
	};
	void Printmain();
	void UserInsert();
	void ShowUser();
	void UserDel();
	void CealrCtrl() {system("cls");};
};
void Ctrl_class::Printmain() {
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
void Ctrl_class::UserInsert() {
	Ctrl_class clear = Ctrl_class();
	clear.CealrCtrl();
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
void Ctrl_class::ShowUser() {
	cout << ",=========================================================================================.\n";
	cout << "|����| �����ڵ� | ����� | �̼����� | ������ | ���� | �ð�ǥ | ����� ���� | ������ȹ��  |\n";
	cout << "`========================================================================================='\n";

}
void Ctrl_class::UserDel() {}

int main() {
	Ctrl_class control = Ctrl_class();
	control.Printmain();
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
			control.UserInsert();
			break;
		case 2:
			control.ShowUser();
			break;
		case 3:
			control.UserDel();
			break;
		default:
			break;
		}
	}
}

