#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <thread>
#include <chrono>
#include "student.h"
#include "Table.h"
#include "File_Manager_Student.h"
#include <direct.h>

using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

class FileManager
{
public:
	// ���� ����
	void createFile()
	{

	}
	// ������ �̵�

	// �� �� �б�

};

class TableManager : FileManager
{
private:

public:
	enum TABLE
	{
		STUDENT,
		SUBJECT,
		COURSE,
		LOGIN_INFO
	};
	// ���̺� ����
	void createTable(TABLE table)
	{
		ofstream fout;
		ifstream fin;
		switch (table)
		{
		case TABLE::STUDENT:
			fout.open("student.txt", 1);
			if (!fout.is_open())
			{
				fout.open("student.txt");
				fout << "[studentId, name, sex, grade, age, email, phoneNum, address]\n";
			}
			else
			{
				cout << "������ �̹� �����մϴ�.";
				sleep_for(seconds(1));
			}
			fin.open("student.txt", 1);
			break;
		case TABLE::SUBJECT:
			fout.open("subject.txt", 1);
			if (!fout.is_open())
			{
				fout.open("subject.txt");
				fout << "[classCode, className, professor, grade, timePlan, classified, evalType]\n";
			}
			else
			{
				cout << "������ �̹� �����մϴ�.";
				sleep_for(seconds(1));
			}
			fin.open("subject.txt", 1);
			break;
		case TABLE::COURSE:
			fout.open("course.txt", 1);
			if (!fout.is_open())
			{
				fout.open("course.txt");
				fout << "[studentId, classCode, className, professor, timePlan, location]\n";
			}
			else
			{
				cout << "������ �̹� �����մϴ�.";
				sleep_for(seconds(1));
			}
			fin.open("course.txt", 1);
			break;
		case TABLE::LOGIN_INFO:
			fout.open("loginInfo.txt", 1);
			if (!fout.is_open())
			{
				fout.open("loginInfo.txt");
				fout << "[sudentId, password]\n";
			}
			else
			{
				cout << "������ �̹� �����մϴ�.";
				sleep_for(seconds(1));
			}
			fin.open("loginInfo.txt", 1);
			break;
		default:
			break;
		}
		fout.close();
		fin.close();
	}
	bool deleteTable(TABLE table)
	{
		switch (table)
		{
		case TABLE::STUDENT:
		{
			ifstream read;
			read.open("student.txt");
			if (!read)
			{
				cout << "������ �������� �ʽ��ϴ�.\n";
				sleep_for(seconds(1));
				return false;
			}
			else
			{
				read.close();
				char user_input;
				cout << "���� �����Ͻðڽ��ϱ�?(Y/N) : ";
				cin >> user_input;
				if (user_input == 'Y' || user_input == 'y')
				{
					remove("student.txt");
					cout << "������ ���������� �����Ǿ����ϴ�.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "������ �������� �ʾҽ��ϴ�.\n";
					sleep_for(seconds(1));
					return false;
				}
				else
				{
					cout << "�߸� �Է��Ͽ����ϴ�.\n";
					return false;
				}
			}
		}
		break;
		case TABLE::SUBJECT:
		{
			ifstream read;
			read.open("subject.txt");
			if (!read)
			{
				cout << "������ �������� �ʽ��ϴ�.\n";
				sleep_for(seconds(1));
				return false;
			}
			else
			{
				read.close();
				char user_input;
				cout << "���� �����Ͻðڽ��ϱ�?(Y/N) : ";
				cin >> user_input;
				if (user_input == 'Y' || user_input == 'y')
				{
					remove("subject.txt");
					cout << "������ ���������� �����Ǿ����ϴ�.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "������ �������� �ʾҽ��ϴ�.\n";
					sleep_for(seconds(1));
					return false;
				}
				else
				{
					cout << "�߸� �Է��Ͽ����ϴ�.\n";
					return false;
				}
			}
			break;
		}

		case TABLE::COURSE:
		{
			ifstream read;
			read.open("course.txt");
			if (!read)
			{
				cout << "������ �������� �ʽ��ϴ�.\n";
				sleep_for(seconds(1));
				return false;
			}
			else
			{
				read.close();
				char user_input;
				cout << "���� �����Ͻðڽ��ϱ�?(Y/N) : ";
				cin >> user_input;
				if (user_input == 'Y' || user_input == 'y')
				{
					remove("course.txt");
					cout << "������ ���������� �����Ǿ����ϴ�.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "������ �������� �ʾҽ��ϴ�.\n";
					sleep_for(seconds(1));
					return false;
				}
				else
				{
					cout << "�߸� �Է��Ͽ����ϴ�.\n";
					return false;
				}
			}
			break;
		}

		case TABLE::LOGIN_INFO:
		{
			ifstream read;
			read.open("loginInfo.txt");
			if (!read)
			{
				cout << "������ �������� �ʽ��ϴ�.\n";
				sleep_for(seconds(1));
				return false;
			}
			else
			{
				read.close();
				char user_input;
				cout << "���� �����Ͻðڽ��ϱ�?(Y/N) : ";
				cin >> user_input;
				if (user_input == 'Y' || user_input == 'y')
				{
					remove("loginInfo.txt");
					cout << "������ ���������� �����Ǿ����ϴ�.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "������ �������� �ʾҽ��ϴ�.\n";
					sleep_for(seconds(1));
					return false;
				}
				else
				{
					cout << "�߸� �Է��Ͽ����ϴ�.\n";
					return false;
				}
			}
			break;
		}

		default:
			break;
		}
	}
	bool hasTable(TABLE table) {}
};

class StudentManager : TableManager
{
public:
	void insertData()
	{
		string Id;
		string Name;
		string SexInput;
		char Sex;
		int Grade;
		int Age;
		string Email;
		string PhoneNum;
		string Address;

		cout << "�й��� �Է��ϼ���.->";
		cin >> Id;
		cout << "�̸��� �Է��ϼ���.->";
		cin >> Name;
		cout << "���� (��/��)->";
		cin >> SexInput;
		if (SexInput == "��")
			Sex = 'm';
		else if (SexInput == "��")
			Sex = 'f';
		else
		{
			cout << "������ �߸� �Է��ϼ̽��ϴ�.";
			return;
		}
		cout << "�г��� �Է��ϼ���(1~4).";
		cin >> Grade;
		if (Grade < 1 || Grade > 4)
		{
			cout << "�г��� �߸� �Է��ϼ̽��ϴ�.";
			return;
		}
		cout << "���̸� �Է��ϼ���.";
		cin >> Age;
		cout << "�̸����� �Է��ϼ���.";
		cin >> Email;
		cout << "��ȭ��ȣ�� �Է��ϼ���.->";
		cin >> PhoneNum;
		cout << "�ּҸ� �Է��ϼ���->";
		cin >> Address;

		File_Manager_Student Manager;

		student a(Id, Name, Sex, Grade, Age, Email, PhoneNum, Address);

		Manager.AddStudent(a);

		Manager.MoveFirst();
	}

	void deleteData()
	{

	}

	void updateData()
	{
	}
};

class SubjectManager : TableManager
{
public:
	void insertData(Subject subjectData)
	{	//classCode, className, professor, grade, timePlan, classified, evalType
			//::�ؾ��� ��::
			// �ߺ� ����

		string classCode;
		string className;
		string professor;
		int grade;
		string timePlan;
		string classified;
		string evalType;

		vector<string> s;
		//���� �ۼ�
		ofstream out("test.txt");
		/*if (out.fail()) {
			cout << "**������ �������� �ʽ��ϴ�.**" << endl;
			cout << "**������ �����մϴ�.**" << endl;
			out.open("test.txt");
		}*/

		for (int i = 0; i < 2; i++)
		{
			cout << "�����ڵ�(A1111)->";
			cin >> classCode;
			out << classCode << " ";

			cout << "�����->";
			cin >> className;
			out << className << " ";

			cout << "��米��->";
			cin >> professor;
			out << professor << " ";

			cout << "����->";
			cin >> grade;

			cout << "�ð�ǥ(����(����))->";
			cin >> timePlan;
			out << timePlan << " ";

			cout << "�̼�����(����,����)->";
			cin >> classified;
			out << classified << " ";

			cout << "������->";
			cin >> evalType;
			out << evalType << endl;
		}
		out.close();
		char ch;
		cout << "�Է��� �����͸� ���ðڽ��ϱ�?('Y/N') ";
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "::�ۼ��� ���� ������ ���::" << endl;
			string open_file; //�ӽ� ������ ���� ����
			ifstream read_file; //���� �д� �Լ�
			read_file.open("test.txt"); //���� ����
			cout << ",----------------------------------------------------------------------." << endl;
			cout << "| �����ڵ� | ����� | ��米�� | ���� | �ð�ǥ | �̼����� | �� ���� |" << endl;
			cout << "'----------------------------------------------------------------------'" << endl;

			while (!read_file.eof())
			{
				getline(read_file, open_file);
				cout << open_file << endl;
			}
			read_file.close();
		}
		else if (ch == 'N' || ch == 'n')
		{
			cout << "Good bye";
		}

	}

	void deleteData()
	{
	}

	void updateData()
	{
	}
};

class CourseManager : TableManager
{
public:
	void insertData()
	{
		string studentId;
		string classCode;
		string className;
		string professor;
		string timePlan;
		string location;

		int i;

		string out_line;
		ofstream fout;
		ofstream out("course.txt");

		for (i = 0; i < 2; i++) // i ����..? <<���� ����� ������ Ȯ���� ���� i�� 2�� �������׽��ϴ�
		{
			cout << i + 1 << "��° ���� ������ �Է��Ͻÿ�." << endl;

			cout << endl << "�й��� �Է��Ͻÿ� : ";            //�й� �Է� �ޱ�
			cin >> studentId;

			cout << endl << "���� �ڵ带 �Է��Ͻÿ� : ";      //�����ڵ� �Է� �ޱ�
			cin >> classCode;

			cout << endl << "���� �̸��� �Է��Ͻÿ� : ";       //�����̸� �Է� �ޱ�
			cin >> className;

			cout << endl << "�������� �Է��Ͻÿ� : ";          //������ �Է� �ޱ�
			cin >> professor;

			cout << endl << "���� �ð��� �Է��Ͻÿ� : ";       //���� �ð� �Է� �ޱ�
			cin >> timePlan;

			cout << endl << "���� ��Ҹ� �Է��Ͻÿ� : ";       //���� ��� �Է� �ޱ�
			cin >> location;

			fout << studentId << "," << classCode << "," << className << "," << professor << "," << timePlan << "," << location << endl;
			cout << endl << studentId << "," << classCode << "," << className << "," << professor << "," << timePlan << "," << location << endl;
		}
	}

	void deleteData()
	{

	}

	void updateData()
	{

	}
};

class LoginInfoManager : TableManager
{
public:
	void insertData(LoginInfo loginData) {}

	void deleteData(string studentId) {}

	void updatePassword(string studentId) {}
};
// �� �κе� ���Ͽ� �����? Yes
//cout << "-----------------------------------------------" << endl;
//cout << " Index �й� �̸� �����ȣ ����� ���� �ð� ���" << endl;
//cout << "-----------------------------------------------" << endl;