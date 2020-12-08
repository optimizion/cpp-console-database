#pragma once
#include <stdlib.h>
#include <fstream>
using namespace std;
#include "student.h"

class File_Manager_Student
{
private:
	ifstream fin;
	ofstream fout;

public:
	File_Manager_Student();
	~File_Manager_Student();

	//커서의 이동
	void MoveFirst();
	bool MoveNext();

	string CurrentRow();
	student* GetStudent();
	bool AddStudent(student a);
	int GetCount();

	void ShowTable();
};

