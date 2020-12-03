#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "student.h"
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
};

class StudentManager : TableManager
{
public:
	bool createTable(TABLE table) {}

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

		StudentManager Manager;
		student a(Id, Name, Sex, Grade, Age, Email, PhoneNum, Address);

		Manager.AddStudent(a);
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
	bool createTable(TABLE table)
	{

	}
	void insertData()
	{
		//1. �迭 �ȿ� �ֱ� ,�� ����
		//2. �ߺ��� ������ ����

		ifstream write_data;
		write_data.open("");
		if (write_data.is_open())
		{

		}

		write_data.close();

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
	bool createTable(TABLE table) {}

	void insertData() {}

	void deleteData() {}

	void updateData() {}
};
// �� �κе� ���Ͽ� �����? Yes
//cout << "-----------------------------------------------" << endl;
//cout << " Index �й� �̸� �����ȣ ����� ���� �ð� ���" << endl;
//cout << "-----------------------------------------------" << endl;