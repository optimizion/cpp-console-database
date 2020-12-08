#include "File_Manager_Student.h"

//������: �б�, ����� ���Ͽ��� (������ �� ���Ϸ�)
File_Manager_Student::File_Manager_Student()
{
	fout.open("����_�л�.txt", 1);
	if (!fout.is_open())
	{
		fout.open("����_�л�.txt");
		fout << "h[�й�,�̸�,����,�г�,����,�̸���,����ó,�ּ�]\n";
	}
	fin.open("����_�л�.txt", 1);

	MoveFirst();
}

//�Ҹ���: ���ϴݱ�
File_Manager_Student::~File_Manager_Student()
{
	fout.close();
	fin.close();
}

//ù��° ���� �̵�
void File_Manager_Student::MoveFirst()
{
	fin.seekg(47, ios::beg);
	fout.seekp(47, ios::beg);
}

//���� ���� �̵�, ������ ���̶�� ù��° ����
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

//���� �� �а� ���ڿ� ��ȯ ([] ����), Ŀ���� �б� �� ��ġ��
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

//�л� ������ȭ
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

//���� ������ �� ���
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
	if (GetCount() == 0)	//�ƹ��͵� ���ٸ� ó������ �߰�
	{
		cout << "ó��";
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

	cout << "�й�  �̸�  ����  �г�  ����  �̸���  ��ȭ��ȣ  �ּ�" << endl;
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