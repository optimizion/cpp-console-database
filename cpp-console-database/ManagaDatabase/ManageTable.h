#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include "student.h"
#include "Table.h"

using namespace std;


class FileManager
{
public:
	// ���� ����
	bool createFile()
	{

	}
	// ���� ����
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
	bool createTable(TABLE table)
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
			fin.open("student.txt", 1);
			break;
		case TABLE::SUBJECT:
			fout.open("subject.txt", 1);
			if (!fout.is_open())
			{
				fout.open("subject.txt");
				fout << "[classCode, className, professor, grade, timePlan, classified, evalType]\n";
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
			fin.open("course.txt", 1);
			break;
		case TABLE::LOGIN_INFO:
			fout.open("loginInfo.txt", 1);
			if (!fout.is_open())
			{
				fout.open("loginInfo.txt");
				fout << "[sudentId, password]\n";
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
			try
			{
				remove("student.txt");
			}
			catch (exception e)
			{
				cout << "�׷� ���� ����\n";
			}
			break;
		case TABLE::SUBJECT:
			try
			{
				remove("subject.txt");
			}
			catch (exception e)
			{
				cout << "�׷� ���� ����\n";
			}
			break;
		case TABLE::COURSE:
			try
			{
				remove("course.txt");
			}
			catch (exception e)
			{
				cout << "�׷� ���� ����\n";
			}
			break;
		case TABLE::LOGIN_INFO:
			try
			{
				remove("loginInfo.txt");
			}
			catch (exception e)
			{
				cout << "�׷� ���� ����\n";
			}
			break;
		default:
			break;
		}
	}
	bool hasTable(TABLE table) {}
};

class StudentManager : TableManager
{
public:
	bool createTable(TABLE table) {}

	void insertData()
	{
		/*cout << "�й��� �Է��ϼ���.->";
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

		StudentManager Manager;
		student a(Id, Name, Sex, Grade, Age, Email, PhoneNum, Address);

		Manager.AddStudent(a);

		MoveFirst();*/
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
			// ����ڰ� Ư�� Ű�� ������ �Է� ����
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

		for (int i = 0; i < 2; i++) { //for�� > ����� Ư��Ű�� ���߰� �ϴ� �� �߰�
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
		if (ch == 'Y' || ch == 'y') {
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
		else if (ch == 'N' || ch == 'n') {
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
	bool createTable(TABLE table) {}

	void insertData()
	{
		//file.open("") //���� ����
		//	cout << endl;

		////index ???
		//file.getline(StudentID, 8, ',');         //�й�
		//file.getline(name, 5, ',');              //�̸�
		//file.getline(subjectcode, 5, ',');       //�����ڵ�
		//file.getline(subjectname, 20, ',');      //�����
		//file.getline(professor, 5, ',');         //����
		//file.getline(time, 5, ',');              //�ð�
		//file.getline(place, 7, '\n');            //���


		//cout << endl << "�й��� �Է��Ͻÿ� : ";            //�й� �Է� �ޱ�
		//cin >> StudenID;

		//cout << endl << "������ �Է��Ͻÿ� : ";            //�̸� �Է� �ޱ�
		//cin >> name;

		//cout << endl << "���� �ڵ带 �Է��Ͻÿ� : ";       //�����ڵ� �Է� �ޱ�
		//cin >> subjectcode;

		//cout << endl << "���� �̸��� �Է��Ͻÿ� : ";       //�����̸� �Է� �ޱ�
		//cin >> subjectname;

		//cout << endl << "�������� �Է��Ͻÿ� : ";          //������ �Է� �ޱ�
		//cin >> professor;

		//cout << endl << "���� �ð��� �Է��Ͻÿ� : ";       //���� �ð� �Է� �ޱ�
		//cin >> time;

		//cout << endl << "���� ��Ҹ� �Է��Ͻÿ� : ";       //���� ��� �Է� �ޱ�
		//cin >> place;

		//cout << endl;
		//file << StudenID << "," << name << "," << subjectcode << "," << subjectname << "," << professor << "," << time << "," << place << "\n";  // myfile�� �Է¹��� ���� �����ϱ�

		//file.close(); //���� �ݱ�


		//�Ϻ��� �ڵ� �ƴ�
		//� ������ ������ ������, ��� �Է¹޾ƾ����� �����ؾ���.
	}

	void deleteData()
	{
		//insert�� ����� �ڵ�
	   //� ������ ������ ������, ��� ������ ������ �����ؾ���.
	   //������ �� ����ڰ� �⺻Ű�� �Է��ص� �����Ǵ���, ������ �� �Է��ؾ��ϴ��� �����ؾ���.
	}

	void updateData()
	{
		//insert�� ����� �ڵ�
		//� ������ ������ ������, ��� ������ ������ �����ؾ���.
		//������ �� ����ڰ� ������ �κи� �Է��ص� �Ǵ���, �� �Է��ؾ��ϴ��� �����ؾ���.    ex) �̸��� �����ϰ� ���� ���� �̸��� ������ �� �ִ���..??
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