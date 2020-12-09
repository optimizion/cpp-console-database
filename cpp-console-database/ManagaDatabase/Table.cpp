#include "Table.h"

Student::Student() {}
Student::Student(string studentId, string name, string sex, short grade, short age, string email, string phoneNum)
{
	this->studentId = studentId;
	this->name = name;
	this->sex = sex;
	this->grade = grade;
	this->age = age;
	this->email = email;
	this->phoneNum = phoneNum;
};

// student getter
string Student::getStudentId() { return this->studentId; }
string Student::getName() { return this->name; }
string Student::getSex() { return this->sex; }
short  Student::getGrade() { return this->grade; }
short  Student::getAge() { return this->age; }
string Student::getEmail() { return this->email; }
string Student::getPhoneNum() { return this->phoneNum; }

// student setter
void Student::setStudentId(string id) { this->studentId = id; }
void Student::setName(string name) { this->name = name; }
void Student::setSex(string sex) { this->sex = sex; }
void Student::setGrade(short grade) { this->grade = grade; }
void Student::setAge(short age) { this->age = age; }
void Student::setEmail(string email) { this->email = email; }
void Student::setPhoneNum(string phoneNum) { this->phoneNum = phoneNum; }

Subject::Subject() {}
Subject::Subject(string classCode, string className, string professor, int grade, string timePlan, string classified, string evalType)
{
	this->classCode = classCode;
	this->className = className;
	this->professor = professor;
	this->grade = grade;
	this->timePlan = timePlan;
	this->classified = classified;
	this->evalType = evalType;
};

//subject getter
string Subject::getClassCode() { return classCode; }
string Subject::getClassName() { return className; }
string Subject::getProfessor() { return professor; }
int    Subject::getGrade() { return grade; }
string Subject::getTimePlan() { return timePlan; }
string Subject::getClassified() { return classified; }
string Subject::getEvalType() { return evalType; }

//subject setter
void Subject::setClassCode(string classCode) { this->classCode = classCode; }
void Subject::setClassName(string className) { this->className = className; }
void Subject::setProfessor(string professor) { this->professor = professor; }
void Subject::setGrade(int grade) { this->grade = grade; }
void Subject::setTimePlan(string timePlan) { this->timePlan = timePlan; }
void Subject::setClassified(string classified) { this->classified = classified; }
void Subject::setEvalType(string evalType) { this->evalType = evalType; }


Course::Course() {}
Course::Course(string studentId, string classCode, string className, string professor, string timePlan, string location)
{
	this->studentId = studentId;
	this->classCode = classCode;
	this->className = className;
	this->professor = professor;
	this->timePlan = timePlan;
	this->location = location;
}

//course getter
string Course::getStudentId() { return studentId; }
string Course::getClassCode() { return classCode; }
string Course::getClassName() { return className; }
string Course::getProfessor() { return professor; }
string Course::getTimePlan() { return timePlan; }
string Course::getLocation() { return location; }
//course setter
void Course::setStudentId(string studentId) { this->studentId = studentId; }
void Course::setClassCode(string classCode) { this->classCode = classCode; }
void Course::setClassName(string className) { this->className = className; }
void Course::setProfessor(string professor) { this->professor = professor; }
void Course::setTimePlan(string timePlan) { this->timePlan = timePlan; }
void Course::setLocation(string location) { this->location = location; }

LoginInfo::LoginInfo() {}
LoginInfo::LoginInfo(string studentId, string password) { this->studentId = studentId; this->password = password; }

//loginInfo getter
string LoginInfo::getStudentId() { return studentId; }
string LoginInfo::getPassword() { return password; }
//loginInfo setter
void LoginInfo::setStudentId(string studentId) { this->studentId = studentId; }
void LoginInfo::setPassword(string password) { this->password = password; }