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
#include <vector>
#include <sstream>

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
			fout.open("./table/student.txt", 1);
			if (!fout.is_open())
			{
				fout.open("./table/student.txt");
				fout << "[studentId,name,sex,grade,age,email,phoneNum]\n";
			}
			else
			{
				cout << "������ �̹� �����մϴ�.";
				sleep_for(seconds(1));
			}
			fin.open("./table/student.txt", 1);
			break;
		case TABLE::SUBJECT:
			fout.open("./table/subject.txt", 1);
			if (!fout.is_open())
			{
				fout.open("./table/subject.txt");
				fout << "[classCode,className,professor,grade,timePlan,classified,evalType]\n";
			}
			else
			{
				cout << "������ �̹� �����մϴ�.";
				sleep_for(seconds(1));
			}
			fin.open("./table/subject.txt", 1);
			break;
		case TABLE::COURSE:
			fout.open("./table/course.txt", 1);
			if (!fout.is_open())
			{
				fout.open("./table/course.txt");
				fout << "[studentId,classCode,className,professor,timePlan,location]\n";
			}
			else
			{
				cout << "������ �̹� �����մϴ�.";
				sleep_for(seconds(1));
			}
			fin.open("./table/course.txt", 1);
			break;
		case TABLE::LOGIN_INFO:
			fout.open("./table/loginInfo.txt", 1);
			if (!fout.is_open())
			{
				fout.open("./table/loginInfo.txt");
				fout << "[sudentId,password]\n";
			}
			else
			{
				cout << "������ �̹� �����մϴ�.";
				sleep_for(seconds(1));
			}
			fin.open("./table/loginInfo.txt", 1);
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
			read.open("./table/student.txt");
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
					remove("./table/student.txt");
					cout << "���������� �����Ǿ����ϴ�.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "�������� �ʾҽ��ϴ�.\n";
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
			read.open("./table/subject.txt");
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
					remove("./table/subject.txt");
					cout << "���������� �����Ǿ����ϴ�.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "�������� �ʾҽ��ϴ�.\n";
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
			read.open("./table/course.txt");
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
					remove("./table/course.txt");
					cout << "���������� �����Ǿ����ϴ�.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "�������� �ʾҽ��ϴ�.\n";
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
			read.open("./table/loginInfo.txt");
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
					remove("./table/loginInfo.txt");
					cout << "���������� �����Ǿ����ϴ�.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "�������� �ʾҽ��ϴ�.\n";
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
	bool hasTable(TABLE table)
	{
		switch (table)
		{

		case TableManager::STUDENT:
			if (_waccess(L"./table/student.txt", 0) != 0)
			{
				return false;
			}
			return true;
			break;
		case TableManager::SUBJECT:
			if (_waccess(L"./table/subject.txt", 0) != 0)
			{
				return false;
			}
			return true;
			break;
		case TableManager::COURSE:
			if (_waccess(L"./table/course.txt", 0) != 0)
			{
				return false;
			}
			return true;
			break;
		case TableManager::LOGIN_INFO:
			if (_waccess(L"./table/loginInfo.txt", 0) != 0)
			{
				return false;
			}
			return true;
			break;
		default:
			break;
		}
	}
};

class StudentManager : TableManager
{
public:
	void insertData(Student studentData)
	{
		/*
		string UserInput;

		string Id;
		string Name;
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
		cin >> UserInput;
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
		*/
		string studentId = studentData.getStudentId();
		string name = studentData.getName();
		string sex = studentData.getSex();
		short grade = studentData.getGrade();
		short age = studentData.getAge();
		string email = studentData.getEmail();
		string phoneNum = studentData.getPhoneNum();

		//File_Manager_Student Manager;
		//student a(Id, Name, Sex, Grade, Age, Email, PhoneNum, Address);
		//Manager.AddStudent(studentData);
		//Manager.MoveFirst();
		ofstream fout;
		fout.open("./table/student.txt", ofstream::app);
		fout << studentId << "," << name << "," << sex << "," << grade << "," << age << "," << email << "," << phoneNum << endl;
		fout.close();
	}

	bool deleteData(string studentId)
	{
		ifstream fin;
		string line, str;
		fin.open("./table/student.txt", ios::in);
		// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
		int pointer = fin.tellg(); // ���� ��ġ
		int targetStart = NULL;
		int targetEnd;
		while (getline(fin, line))
		{
			stringstream ss;
			vector<string> results;
			ss.str(line);
			//cout << line << endl;
			while (getline(ss, str, ','))
			{
				results.push_back(str);
			}
			// �ش� id�� �����ϸ�
			if (results[0] == studentId)
			{
				//fout.seekp(pointer); // ����� ��ġ�� �̵�
				targetStart = pointer;
				//continue;
				//fin.close();
				//fout.close();
				//return true;
			}
			targetEnd = fin.tellg();
			pointer = fin.tellg(); // �� �� �а� �� ��ġ
			if (targetStart != NULL)
			{
				ofstream newFileOut;
				newFileOut.open("./table/student1.txt", ios::out);
				fin.seekg(ios::beg);
				string str;
				while (fin.tellg() != targetStart)
				{
					getline(fin, str);
					newFileOut << str << endl;
				}
				fin.seekg(targetEnd);
				while (getline(fin, str))
				{
					newFileOut << str << endl;
				}
				newFileOut.close();

				fin.close();
				deleteTable(TABLE::STUDENT);
				rename("./table/student1.txt", "./table/student.txt");
				return true;
			}
		}
		cout << "�ش� �л� ������ �������� �ʽ��ϴ�." << endl;
		fin.close();
		return false;
		//string Target;
		//cout << "������ �л��� �й��� �Է��Ͻÿ�.";
		//cin >> Target;

		/*File_Manager_Student Manager;
		if (Manager.Update(studentId))
			cout << "���������� �����Ͽ����ϴ�.";
		else
			cout << "������ �й��� ã�� �� �����ϴ�.";*/
	}

	bool updateData(string studentId)
	{
		/*string UserInput;

		string Name;
		char Sex;
		int Grade;
		int Age;
		string Email;
		string PhoneNum;
		string Address;

		cout << "�̸��� �Է��ϼ���.->";
		cin >> Name;
		cout << "���� (��/��)->";
		cin >> UserInput;
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
		cin >> Address;*/
		ofstream fout;
		ifstream fin;
		string line, str;
		fin.open("./table/student.txt", ios::in);
		fout.open("./table/student.txt", ios::out || ios::in);
		// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
		int pointer = fin.tellg();
		while (getline(fin, line))
		{
			stringstream ss;
			ss.str(line);
			//cout << line << endl;
			while (getline(ss, str, ','))
			{
				vector<string> results;
				results.push_back(str);
				// �ش� id�� ������
				if (results[0] == studentId)
				{

					string name, email, phoneNum, sex;
					short grade, age;
					cout << "ex)�̸�,����,�г�,����,�̸���,�޴�����ȣ('-'����)" << endl;
					cout << "Enter data : ";
					string user_input;
					vector<string> changedData;
					cin >> user_input;
					stringstream ss(user_input);
					while (getline(ss, user_input, ','))
					{
						changedData.push_back(user_input);
					}
					name = changedData[0];
					sex = changedData[1];
					grade = stoi(changedData[2]);
					age = stoi(changedData[3]);
					email = changedData[4];
					phoneNum = changedData[5];
					fout.seekp(pointer);

					fout << studentId << "," << name << "," << sex << "," << grade << "," << age << "," << email << "," << phoneNum << endl;

					fin.close();
					fout.close();
					return true;
				}
				else
				{
					pointer = fin.tellg();
					break;
				}
			}
		}
		cout << "�ش� �й��� �������� �ʽ��ϴ�." << endl;
		sleep_for(seconds(1));
		fin.close();
		fout.close();
		return false;

	}
};

class SubjectManager : TableManager
{
public:
	void insertData(Subject subjectData)
	{
		string classCode = subjectData.getClassCode();
		string className = subjectData.getClassName();
		string professor = subjectData.getProfessor();
		int grade = subjectData.getGrade();
		string timePlan = subjectData.getTimePlan();
		string classified = subjectData.getClassified();
		string evalType = subjectData.getEvalType();

		ofstream fout;
		fout.open("./table/subject.txt", ofstream::app);
		fout << classCode << "," << className << "," << professor << "," << grade << "," << timePlan << "," << classified << "," << evalType << endl;
		fout.close();
	}

	bool deleteData(string classCode)
	{
		ifstream fin;
		string line, str;
		fin.open("./table/subject.txt", ios::in);
		// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
		int pointer = fin.tellg(); // ���� ��ġ
		int targetStart = NULL;
		int targetEnd;
		while (getline(fin, line))
		{
			stringstream ss;
			vector<string> results;
			ss.str(line);
			//cout << line << endl;
			while (getline(ss, str, ','))
			{
				results.push_back(str);
			}
			// �ش� id�� �����ϸ�
			if (results[0] == classCode)
			{
				//fout.seekp(pointer); // ����� ��ġ�� �̵�
				targetStart = pointer;
				//continue;
				//fin.close();
				//fout.close();
				//return true;
			}
			targetEnd = fin.tellg();
			pointer = fin.tellg(); // �� �� �а� �� ��ġ
			if (targetStart != NULL)
			{
				ofstream newFileOut;
				newFileOut.open("./table/subject1.txt", ios::out);
				fin.seekg(ios::beg);
				string str;
				while (fin.tellg() != targetStart)
				{
					getline(fin, str);
					newFileOut << str << endl;
				}
				fin.seekg(targetEnd);
				while (getline(fin, str))
				{
					newFileOut << str << endl;
				}
				newFileOut.close();

				fin.close();
				deleteTable(TABLE::SUBJECT);
				rename("./table/subject1.txt", "./table/subject.txt");
				return true;
			}
		}
		cout << "�ش� ���� ������ �������� �ʽ��ϴ�." << endl;
		fin.close();
		return false;
	}

	bool updateData(string classCode)
	{
		ofstream fout;
		ifstream fin;
		string line, str;
		fin.open("./table/subject.txt", ios::in);
		fout.open("./table/subject.txt", ios::out || ios::in);
		// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
		int pointer = fin.tellg();
		while (getline(fin, line))
		{
			stringstream ss;
			ss.str(line);
			//cout << line << endl;
			while (getline(ss, str, ','))
			{
				vector<string> results;
				results.push_back(str);
				// �ش� id�� ������
				if (results[0] == classCode)
				{

					string className, professor, timePlan, classified, evalType;
					int grade;
					cout << "ex)�����,������,����,�ð�ǥ(ȭ(789)),�̼�����(���� or ����),������(����� or ������)" << endl;
					cout << "Enter data : ";
					string user_input;
					vector<string> changedData;
					cin >> user_input;
					stringstream ss(user_input);
					while (getline(ss, user_input, ','))
					{
						changedData.push_back(user_input);
					}
					className = changedData[0];
					professor = changedData[1];
					grade = stoi(changedData[2]);
					timePlan = changedData[3];
					classified = changedData[4];
					evalType = changedData[5];
					fout.seekp(pointer);

					fout << classCode << "," << className << "," << professor << "," << grade << "," << timePlan << "," << classified << "," << evalType << endl;

					fin.close();
					fout.close();
					return true;
				}
				else
				{
					pointer = fin.tellg();
					break;
				}
			}
		}
		cout << "�ش� �����ȣ�� �������� �ʽ��ϴ�." << endl;
		sleep_for(seconds(1));
		fin.close();
		fout.close();
		return false;
	}
};

class CourseManager : TableManager
{
public:
	void insertData(Course courseData)
	{
		string studentId = courseData.getStudentId();
		string classCode = courseData.getClassCode();
		string className = courseData.getClassName();
		string professor = courseData.getProfessor();
		string timePlan = courseData.getTimePlan();
		string location = courseData.getLocation();

		ofstream fout;
		fout.open("./table/course.txt", ofstream::app);
		fout << studentId << "," << classCode << "," << className << "," << professor << "," << timePlan << "," << location << endl;
		fout.close();
		//for (i = 0; i < 2; i++) // i ����..? <<���� ����� ������ Ȯ���� ���� i�� 2�� �������׽��ϴ�
		//{
		//	cout << i + 1 << "��° ���� ������ �Է��Ͻÿ�." << endl;
		//	cout << endl << "�й��� �Է��Ͻÿ� : ";            //�й� �Է� �ޱ�
		//	cin >> studentId;
		//	cout << endl << "���� �ڵ带 �Է��Ͻÿ� : ";      //�����ڵ� �Է� �ޱ�
		//	cin >> classCode;
		//	cout << endl << "���� �̸��� �Է��Ͻÿ� : ";       //�����̸� �Է� �ޱ�
		//	cin >> className;
		//	cout << endl << "�������� �Է��Ͻÿ� : ";          //������ �Է� �ޱ�
		//	cin >> professor;
		//	cout << endl << "���� �ð��� �Է��Ͻÿ� : ";       //���� �ð� �Է� �ޱ�
		//	cin >> timePlan;
		//	cout << endl << "���� ��Ҹ� �Է��Ͻÿ� : ";       //���� ��� �Է� �ޱ�
		//	cin >> location;
		//	fout << studentId << "," << classCode << "," << className << "," << professor << "," << timePlan << "," << location << endl;
		//	cout << endl << studentId << "," << classCode << "," << className << "," << professor << "," << timePlan << "," << location << endl;
		//}
	}

	bool deleteData(string studentId, string classCode)
	{
		ifstream fin;
		string line, str;
		fin.open("./table/course.txt", ios::in);
		// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
		int pointer = fin.tellg(); // ���� ��ġ
		int targetStart = NULL;
		int targetEnd;
		while (getline(fin, line))
		{
			stringstream ss;
			vector<string> results;
			ss.str(line);
			//cout << line << endl;
			while (getline(ss, str, ','))
			{
				results.push_back(str);
			}
			// �ش� id�� �����ϸ�
			if (results[0] == studentId || results[1] == classCode)
			{
				//fout.seekp(pointer); // ����� ��ġ�� �̵�
				targetStart = pointer;
				//continue;
				//fin.close();
				//fout.close();
				//return true;
			}
			targetEnd = fin.tellg();
			pointer = fin.tellg(); // �� �� �а� �� ��ġ
			if (targetStart != NULL)
			{
				ofstream newFileOut;
				newFileOut.open("./table/course1.txt", ios::out);
				fin.seekg(ios::beg);
				string str;
				while (fin.tellg() != targetStart)
				{
					getline(fin, str);
					newFileOut << str << endl;
				}
				fin.seekg(targetEnd);
				while (getline(fin, str))
				{
					newFileOut << str << endl;
				}
				newFileOut.close();

				fin.close();
				deleteTable(TABLE::COURSE);
				rename("./table/course1.txt", "./table/course.txt");
				return true;
			}
		}
		cout << "�ش� ���� ������ �������� �ʽ��ϴ�." << endl;
		fin.close();
		return false;
	}

	bool updateData(string studentId, string classCode)
	{
		ofstream fout;
		ifstream fin;
		string line, str;
		fin.open("./table/course.txt", ios::in);
		fout.open("./table/course.txt", ios::out || ios::in);
		// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
		int pointer = fin.tellg();
		while (getline(fin, line))
		{
			stringstream ss;
			ss.str(line);
			vector<string> results;
			while (getline(ss, str, ','))
			{
				results.push_back(str);
			}
			// �ش� ���� ������ �����ϸ�
			if (results[0] == studentId && results[1] == classCode)
			{
				string className, professor, timePlan, location;
				cout << "ex)�����,������,�ð�ǥ(ȭ(789)),���ǽ�(��(605))\n";
				cout << "Enter data : ";
				string user_input;
				vector<string> changedData;
				cin >> user_input;
				stringstream ss(user_input);
				while (getline(ss, user_input, ','))
				{
					changedData.push_back(user_input);
				}
				className = changedData[0];
				professor = changedData[1];
				timePlan = changedData[2];
				location = changedData[3];
				fout.seekp(pointer);

				fout << studentId << "," << classCode << "," << className << "," << professor << "," << timePlan << "," << location << endl;

				fin.close();
				fout.close();
				return true;
			}
			else
			{
				pointer = fin.tellg();
				continue;
			}
		}
		cout << "�ش� ���� ������ �������� �ʽ��ϴ�." << endl;
		sleep_for(seconds(1));
		fin.close();
		fout.close();
		return false;
	}
};

class LoginInfoManager : TableManager
{
public:
	void insertData(LoginInfo loginData)
	{
		string studentId = loginData.getStudentId();
		string password = loginData.getPassword();
		ofstream fout;
		fout.open("./table/loginInfo.txt", ofstream::app);
		fout << studentId << "," << password << endl;
		fout.close();

	}

	bool deleteData(string studentId)
	{
		ifstream fin;
		string line, str;
		fin.open("./table/loginInfo.txt", ios::in);
		// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
		int pointer = fin.tellg(); // ���� ��ġ
		int targetStart = NULL;
		int targetEnd;
		while (getline(fin, line))
		{
			stringstream ss;
			vector<string> results;
			ss.str(line);
			//cout << line << endl;
			while (getline(ss, str, ','))
			{
				results.push_back(str);
			}
			// �ش� id�� �����ϸ�
			if (results[0] == studentId)
			{
				//fout.seekp(pointer); // ����� ��ġ�� �̵�
				targetStart = pointer;
				//continue;
				//fin.close();
				//fout.close();
				//return true;
			}
			targetEnd = fin.tellg();
			pointer = fin.tellg(); // �� �� �а� �� ��ġ
			if (targetStart != NULL)
			{
				ofstream newFileOut;
				newFileOut.open("./table/loginInfo1.txt", ios::out);
				fin.seekg(ios::beg);
				string str;
				while (fin.tellg() != targetStart)
				{
					getline(fin, str);
					newFileOut << str << endl;
				}
				fin.seekg(targetEnd);
				while (getline(fin, str))
				{
					newFileOut << str << endl;
				}
				newFileOut.close();

				fin.close();
				deleteTable(TABLE::LOGIN_INFO);
				rename("./table/loginInfo1.txt", "./table/loginInfo.txt");
				return true;
			}
		}
		cout << "�ش� �й��� �������� �ʽ��ϴ�." << endl;
		fin.close();
		return false;
	}

	bool updatePassword(string studentId)
	{
		ofstream fout;
		ifstream fin;
		string line, str;
		fin.open("./table/loginInfo.txt", ios::in);
		fout.open("./table/loginInfo.txt", ios::out || ios::in);
		// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
		int pointer = fin.tellg();
		while (getline(fin, line))
		{
			stringstream ss;
			ss.str(line);
			//cout << line << endl;
			while (getline(ss, str, ','))
			{
				vector<string> results;
				results.push_back(str);
				// �ش� id�� ������
				if (results[0] == studentId)
				{
					string changePassword;
					fout.seekp(pointer);

					cout << "������ ��й�ȣ�� �Է��ϼ��� : ";
					cin >> changePassword;
					fout << studentId << "," << changePassword << endl;

					fin.close();
					fout.close();
					return true;
				}
				else
				{
					pointer = fin.tellg();
					break;
				}
			}
		}
		cout << "�ش� id�� �������� �ʽ��ϴ�." << endl;
		sleep_for(seconds(1));
		fin.close();
		fout.close();
		return false;
	}
};
// �� �κе� ���Ͽ� �����? Yes
//cout << "-----------------------------------------------" << endl;
//cout << " Index �й� �̸� �����ȣ ����� ���� �ð� ���" << endl;
//cout << "-----------------------------------------------" << endl;