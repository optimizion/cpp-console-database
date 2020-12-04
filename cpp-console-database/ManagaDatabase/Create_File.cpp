#include <iostream>
#include <fstream>
using namespace std;
#include "File_Manager_Student.h"


int main()
{
	File_Manager_Student Manager;
	student a("s001", "뚝", 'm', 1, 20, "sdfs", "asdfhgaedfh", "asggdsg");
	//student a(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);



	cout << "파일 데이터 수(전):" << Manager.GetCount() << endl;
	Manager.AddStudent(a);
	cout << "파일 데이터 수(후):" << Manager.GetCount() << endl;


}