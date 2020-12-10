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
	string studentId; // 학번 -> PK (0 < length <= 10자리 이하)
	string name; // 이름 (0 < length)
	string sex; // 성별 (default m)
	short grade; // 학년 (default 1)
	short age; // 나이 (default 20)

	// NULLABLE
	string email; // 이메일 (must include @)
	string phoneNum; // 연락처 (not include - )
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
	string classCode;	//과목코드 -> PK
	string className;	//과목명

	// NULLABLE
	string professor;	//교수 
	int grade;			//학점 
	string timePlan;	//시간표 -> '화(7,8,9)' 
	string classified;	//이수구분(전공,교양) 
	string evalType;	//평가 유형 -> 상대평가 or 절대평가
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
	string studentId;     //학번 -> PK / FK
	string classCode;     //과목코드 -> PK / FK
	string className;     //과목명
	string professor;       //교수

	// NULLABLE
	string timePlan;          //시간표
	string location;           //장소

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
	// 테이블 생성
	void createTable(TABLE table);
	// 테이블 삭제
	bool deleteTable(TABLE table);
	// 테이블 존재 여부
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