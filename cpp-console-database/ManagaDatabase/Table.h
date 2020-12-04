#include <string>
using namespace std;

class Student
{
private:
	// NOT NULL
	string studentId; // 학번 -> PK (0 < length <= 10자리 이하)
	string name; // 이름 (0 < length)
	char sex; // 성별 (default m)
	short grade; // 학년 (default 1)
	short age; // 나이 (default 20)

	// NULLABLE
	string email; // 이메일 (must include @)
	string phoneNum; // 연락처 (not include - )
	string address; // 주소
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
	string classCode;	//과목코드 -> PK
	string className;	//과목명

	// NULLABLE
	string professor;	//교수 
	int grade;			//학점 
	string timePlan;	//시간표 -> '화(7,8,9)' 
	string classified;	//이수구분(전공,교양) 
	string evalType;	//평가 유형 -> 상대평가 or 절대평가
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
	string studentId;     //학번 -> PK / FK
	string classCode;     //과목코드 -> PK / FK
	string className;     //과목명
	string professor;       //교수

	// NULLABLE
	string timePlan;          //시간표
	string location;           //장소

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