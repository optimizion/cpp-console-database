#include "File_Manager_Student.h"

//생성자: 읽기, 쓰기로 파일열기 (없으면 새 파일로)
File_Manager_Student::File_Manager_Student()
{
	fout.open("파일_학생.txt", 1);
	if (!fout.is_open())
	{
		fout.open("파일_학생.txt");
		fout << "h[학번,이름,성별,학년,나이,이메일,연락처,주소]\n";
	}
	fin.open("파일_학생.txt", 1);

	MoveFirst();
}

//소멸자: 파일닫기
File_Manager_Student::~File_Manager_Student()
{
	fout.close();
	fin.close();
}

//첫번째 열로 이동
void File_Manager_Student::MoveFirst()
{
	fin.seekg(47, ios::beg);
	fout.seekp(47, ios::beg);
}

//다음 열로 이동, 마지막 열이라면 첫번째 열로
bool File_Manager_Student::MoveNext()
{
	int RollBackLoc = fin.tellg();

	fin.seekg(CurrentRow().length() + 2, fin.cur);
	fout.seekp(fin.tellg(), ios::beg);

	int CurrentLoc = fin.tellg();

	fin.seekg(0, ios::end);
	int end = fin.tellg();
	fin.seekg(CurrentLoc, ios::beg);

	if (CurrentLoc + 1 >= end)
	{
		fin.seekg(RollBackLoc, ios::beg);
		fout.seekp(RollBackLoc, ios::beg);
		return false;
	}
	return true;
}

//현재 열 읽고 문자열 반환 ([] 포함), 커서는 읽기 전 위치로
string File_Manager_Student::CurrentRow()
{
	string res("");
	string add;


	int CurrentLoc = fin.tellg();

	fin >> res;

	while (res.find(']') == -1)
	{
		fin >> add;
		res = res + " " + add;
	}

	fin.seekg(CurrentLoc, ios::beg);

	return res;
}

//학생 데이터화
student* File_Manager_Student::GetStudent()
{
	string RowStr = CurrentRow();
	string Value[8];

	int SubStart = 1;
	int Count = 0;
	int j = 0;

	for (int i = 1; i < RowStr.length() - 1; i++)
	{
		if (RowStr[i] == ',')
		{
			Value[j] = RowStr.substr(SubStart, Count);
			//cout << RowStr.substr(SubStart, Count) << endl;
			SubStart = i + 1;
			Count = 0;
			j++;
		}
		else
			Count++;
	}
	Value[j] = RowStr.substr(SubStart, Count);

	//for (int i=0; i< 9; i++)
	//	cout << Value[i] << endl;

	return new student(Value[0], Value[1], Value[2][0], atoi(Value[3].c_str()), atoi(Value[4].c_str()), Value[5], Value[6], Value[7]);
}

//파일 데이터 수 얻기
int File_Manager_Student::GetCount()
{
	int CurrentLoc = fin.tellg();
	fin.seekg(0, ios::end);
	if (fin.tellg() <= 48)
	{
		fin.seekg(CurrentLoc, ios::beg);
		return 0;
	}

	int Count = 1;
	MoveFirst();

	while (true)
	{
		if (MoveNext())
			Count++;
		else
		{
			fin.seekg(CurrentLoc, ios::beg);
			return Count;
		}
	}
}

bool File_Manager_Student::AddStudent(student a)
{
	/*
	fout.seekp(0, ios::end);
	if (GetCount() == 0)	//아무것도 없다면 처음부터 추가
	{
		cout << "처음";
		fout << "["
			<< a.GetId() << ","
			<< a.GetPassWord() << ","
			<< a.GetName() << ","
			<< a.GetSex() << ","
			<< a.GetGrade() << ","
			<< a.GetAge() << ","
			<< a.GetEmail() << ","
			<< a.GetPhoneNum() << ","
			<< a.GetAddress() << "]\n";
		MoveFirst();
		return true;
	}
	*/

	MoveFirst();
	string RowStr;

	for (int j = 0; j < GetCount(); j++)
	{
		RowStr = CurrentRow();
		int Count = 0;
		for (int i = 1; i < RowStr.length() - 1; i++)
		{
			if (RowStr[i] == ',')
			{
				if (RowStr.substr(1, Count) == a.GetId())
				{
					return false;
				}
				break;
			}
			else
				Count++;
		}
		MoveNext();
	}

	fout.seekp(0, ios::end);
	fout << "["
		<< a.GetId() << ","
		<< a.GetName() << ","
		<< a.GetSex() << ","
		<< a.GetGrade() << ","
		<< a.GetAge() << ","
		<< a.GetEmail() << ","
		<< a.GetPhoneNum() << ","
		<< a.GetAddress() << "]\n";
	MoveFirst();
	return true;
}

void File_Manager_Student::ShowTable()
{
	MoveFirst();

	bool IsEnd = false;
	student* Target;

	cout << "학번  이름  성별  학년  나이  이메일  전화번호  주소" << endl;
	cout << "======================================================" << endl;

	while (IsEnd == false)
	{
		Target = GetStudent();
		Target->ConsoleOut();
		delete Target;
		if (!MoveNext())
			IsEnd = true;
	}

	cout << "======================================================" << endl;

	MoveFirst();
}