#pragma once
//#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <thread>
#include <chrono>
#include <direct.h>
#include <sstream>
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

class Student
{
private:
	// NOT NULL
	string studentId; // �й� -> PK (0 < length <= 10�ڸ� ����)
	string name; // �̸� (0 < length)
	string sex; // ���� (default m)
	short grade; // �г� (default 1)
	short age; // ���� (default 20)

	// NULLABLE
	string email; // �̸��� (must include @)
	string phoneNum; // ����ó (not include - )
public:
	Student();
	Student(string studentId, string name, string sex = "m", short grade = 1, short age = 20, string email = NULL, string phoneNum = NULL);

	string getStudentId();
	string getName();
	string getSex();
	short getGrade();
	short getAge();
	string getEmail();
	string getPhoneNum();

	void setStudentId(string id);
	void setName(string name);
	void setSex(string sex);
	void setGrade(short grade);
	void setAge(short age);
	void setEmail(string email);
	void setPhoneNum(string phoneNum);
};
class Subject
{
private:
	// NOT NULL
	string classCode;	//�����ڵ� -> PK
	string className;	//�����

	// NULLABLE
	string professor;	//���� 
	int grade;			//���� 
	string timePlan;	//�ð�ǥ -> 'ȭ(7,8,9)' 
	string classified;	//�̼�����(����,����) 
	string evalType;	//�� ���� -> ����� or ������
public:
	Subject();
	Subject(string classCode, string className, string professor, int grade, string timePlan, string classified, string evalType);


	string getClassCode();
	string getClassName();
	string getProfessor();
	int getGrade();
	string getTimePlan();
	string getClassified();
	string getEvalType();

	void setClassCode(string classCode);
	void setClassName(string className);
	void setProfessor(string professor);
	void setGrade(int grade);
	void setTimePlan(string timePlan);
	void setClassified(string classified);
	void setEvalType(string evalType);
};
class Course
{
private:
	// NOT NULL
	string studentId;     //�й� -> PK / FK
	string classCode;     //�����ڵ� -> PK / FK
	string className;     //�����
	string professor;       //����

	// NULLABLE
	string timePlan;          //�ð�ǥ
	string location;           //���

public:
	Course();
	Course(string studentId, string classCode, string className, string professor, string timePlan, string location);

	string getStudentId();
	string getClassCode();
	string getClassName();
	string getProfessor();
	string getTimePlan();
	string getLocation();

	void setStudentId(string studentId);
	void setClassCode(string classCode);
	void setClassName(string className);
	void setProfessor(string professor);
	void setTimePlan(string timePlan);
	void setLocation(string location);

};
class LoginInfo
{
	// NOT NULL
	string studentId;
	string password;

public:
	LoginInfo();
	LoginInfo(string studentId, string password = "1234");

	string getStudentId();
	string getPassword();

	void setStudentId(string studentId);
	void setPassword(string password);

};

class TableManager
{
private:

public:
	TableManager();
	enum TABLE
	{
		STUDENT,
		SUBJECT,
		COURSE,
		LOGIN_INFO
	};
	// ���̺� ����
	void createTable(TABLE table);
	// ���̺� ����
	bool deleteTable(TABLE table);
	// ���̺� ���� ����
	bool hasTable(TABLE table);
};
class StudentManager : TableManager
{
public:
	StudentManager();
	bool insertData(Student studentData);
	bool deleteData(string studentId);
	bool updateData(string studentId);
	Student queryStudentData(string studentId);
};
class SubjectManager : TableManager
{
public:
	SubjectManager();
	bool insertData(Subject subjectData);
	bool deleteData(string classCode);
	bool updateData(string classCode);
	bool querySubjectData();
};
class CourseManager : TableManager
{
public:
	CourseManager();
	bool insertData(Course courseData);
	bool deleteData(string studentId, string classCode);
	bool updateData(string studentId, string classCode);
	bool queryCourseData(string studentId);
};
class LoginInfoManager : TableManager
{
public:
	LoginInfoManager();
	bool insertData(LoginInfo loginData);
	bool deleteData(string studentId);
	bool updatePassword(string studentId);
	bool checkLogin(string studentId, string password);
};