#include <string>
using namespace std;

class Student
{
private:
	// NOT NULL
	string studentId; // �й� -> PK (0 < length <= 10�ڸ� ����)
	string name; // �̸� (0 < length)
	char sex; // ���� (default m)
	short grade; // �г� (default 1)
	short age; // ���� (default 20)

	// NULLABLE
	string email; // �̸��� (must include @)
	string phoneNum; // ����ó (not include - )
	string address; // �ּ�
public:
	Student(string studentId, string name, char sex = 'm', short grade = 1, short age = 20, string email = NULL, string phoneNum = NULL, string address = NULL)
	{
		this->studentId = studentId;
		this->name = name;
		this->sex = sex;
		this->grade = grade;
		this->age = age;
		this->email = email;
		this->phoneNum = phoneNum;
		this->address = address;
	};
	// getter
	string getStudentId() { return this->studentId; }
	string getName() { return this->name; }
	char getSex() { return this->sex; }
	short getGrade() { return this->grade; }
	short getAge() { return this->age; }
	string getEmail() { return this->email; }
	string getPhoneNum() { return this->phoneNum; }
	string getAddress() { return this->address; }

	// setter
	void setStudentId(string id) { this->studentId = id; }
	void setName(string name) { this->name = name; }
	void setSex(char sex) { this->sex = sex; }
	void setGrade(short grade) { this->grade = grade; }
	void setAge(short age) { this->age = age; }
	void setEmail(string email) { this->email = email; }
	void setPhoneNum(string phoneNum) { this->phoneNum = phoneNum; }
	void setAddress(string address) { this->address = address; }

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
	Subject(string classCode, string className, string professor, int grade, string timePlan, string classified, string evalType)
	{
		this->classCode = classCode;
		this->className = className;
		this->professor = professor;
		this->grade = grade;
		this->timePlan = timePlan;
		this->classified = classified;
		this->evalType = evalType;
	};
	//getter
	string getClassCode() { return classCode; }
	string getClassName() { return className; }
	string getProfessor() { return professor; }
	int getGrade() { return grade; }
	string getTimePlan() { return timePlan; }
	string getClassified() { return classified; }
	string getEvalType() { return evalType; }

	//setter
	void setClassCode(string classCode) { this->classCode = classCode; }
	void setClassName(string className) { this->className = className; }
	void setProfessor(string professor) { this->professor = professor; }
	void setGrade(int grade) { this->grade = grade; }
	void setTimePlan(string timePlan) { this->timePlan = timePlan; }
	void setClassified(string classified) { this->classified = classified; }
	void setEvalType(string evalType) { this->evalType = evalType; }
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
	Course(string studentId, string classCode, string className, string professor, string timePlan, string location)
	{
		this->studentId = studentId;
		this->classCode = classCode;
		this->className = className;
		this->professor = professor;
		this->timePlan = timePlan;
		this->location = location;
	}
	//getter
	string getStudentId() { return studentId; }
	string getClassCode() { return classCode; }
	string getClassName() { return className; }
	string getProfessor() { return professor; }
	string getTimePlan() { return timePlan; }
	string getLocation() { return location; }
	//setter
	void setStudentId(string studentId) { this->studentId = studentId; }
	void setClassCode(string classCode) { this->classCode = classCode; }
	void setClassName(string className) { this->className = className; }
	void setProfessor(string professor) { this->professor = professor; }
	void setTimePlan(string timePlan) { this->timePlan = timePlan; }
	void setLocation(string location) { this->location = location; }
};

class LoginInfo
{
	// NOT NULL
	string studentId;
	string password;

public:
	LoginInfo(string studentId, string password = "1234") { this->studentId = studentId; this->password = password; }
	//getter
	string getStudentId() { return studentId; }
	string getPassword() { return password; }
	//setter
	void setStudentId(string studentId) { this->studentId = studentId; }
	void setPassword(string password) { this->password = password; }
};