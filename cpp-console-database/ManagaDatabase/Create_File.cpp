#include <iostream>
#include <fstream>
using namespace std;
#include "File_Manager_Student.h"


int main()
{
	File_Manager_Student Manager;
	student a("s001", "��", 'm', 1, 20, "sdfs", "asdfhgaedfh", "asggdsg");
	//student a(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);



	cout << "���� ������ ��(��):" << Manager.GetCount() << endl;
	Manager.AddStudent(a);
	cout << "���� ������ ��(��):" << Manager.GetCount() << endl;


}