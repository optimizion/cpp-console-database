#pragma once
#include <string>
using namespace std;

/*─────────────────────
	프로그램에서 처리하는 하나의 학생 객체
	(DB 파일에서 수정할 놈을 불러오거나, 새로 테이블에 추가할 놈)

	*되도록이면 students 리스트 안에 넣어서 사용하십시오.
─────────────────────*/
class student
{
private:
	//필수 데이터 (생성 시 반드시 필요)
	string Id;			//식별자 (기본 키)
	string Name;		//이름

	//필수이나 공란이면 기본값을 대신 씀
	char Sex;			//성별 (기본 'm'(남))
	short Grade;		//학년 (기본 1)
	short Age;			//나이 (기본 20)

	//NULL 허용
	string Email;		//이메일
	string PhoneNum;	//연락처
	string Address;		//주소

public:
	student* Next;		//다음으로 연결된 학생 (Null이면 이 학생이 리스트 끝, 즉 Footer와 연결)

	student(string Id, string Name, char Sex, short Grade, short Age, string Email, string PhoneNum, string Address);

	//데이터 조회
	string GetId();
	string GetName();
	char GetSex();
	short GetGrade();
	short GetAge();
	string GetEmail();
	string GetPhoneNum();
	string GetAddress();

	void ConsoleOut();

	//데이터 수정
	void SetName(string a);
	bool SetSex(char a);
	bool SetGrade(short a);
	void SetAge(short a);
	void SetEmail(string a);
	void SetPhoneNum(string a);
	void SetAddress(string a);
};

student::student(string Id, string Name, char Sex = 'm', short Grade = 1, short Age = 20, string Email = "", string PhoneNum = "", string Address = "")
{
	this->Id = Id;
	SetName(Name);
	SetSex(Sex);
	SetGrade(Grade);
	SetAge(Age);
	SetEmail(Email);
	SetPhoneNum(PhoneNum);
	SetAddress(Address);

	Next = NULL;
}


/*─────────────────────
	속성에 해당하는 데이터를 반환
─────────────────────*/
//Id 반환
string student::GetId()
{
	return Id;
}

//이름 반환
string student::GetName()
{
	return Name;
}

//성을 반환
char student::GetSex()
{
	return Sex;
}

//학년 반환
short student::GetGrade()
{
	return Grade;
}

//나이 반환
short student::GetAge()
{
	return Age;
}

//이메일 반환
string student::GetEmail()
{
	return Email;
}

//연락처 반환
string student::GetPhoneNum()
{
	return PhoneNum;
}

string student::GetAddress()
{
	return Address;
}


/*─────────────────────
	속성 업데이트 (Id를 제외해서 업데이트 가능)
─────────────────────*/

//이름 업데이트
void student::SetName(string a)
{
	Name = a;
}

//성별 업데이트
bool student::SetSex(char a)
{
	if (a != 'm' && a != 'f')
		return false;	//오류: m과 f 이외의 문자가 있음.

	Sex = a;
	return true;	//정상처리
}

//학년 업데이트
bool student::SetGrade(short a)
{
	if (a < 1 || a > 4)
		return false;	//오류: 1~4 이외의 숫자

	Grade = a;
	return true;	//정상처리
}

//나이 업데이트
void student::SetAge(short a)
{
	Age = a;
}

//이메일 업데이트
void student::SetEmail(string a)
{
	Email = a;
}

//전화번호 업데이트
void student::SetPhoneNum(string a)
{
	PhoneNum = a;
}

void student::SetAddress(string a)
{
	Address = a;
}

//콘솔에 나타냅니다.
void student::ConsoleOut()
{
	cout << GetId() << "  " << GetName() << "  ";

	if (GetSex() == 'm')
		cout << "남  ";
	else
		cout << "여  ";

	cout << GetGrade() << "  " << GetAge() << "  ";

	if (GetEmail() == "")
		cout << "NULL  ";
	else
		cout << GetEmail() << "  ";
	if (GetPhoneNum() == "")
		cout << "NULL  ";
	else
		cout << GetPhoneNum() << "  ";
	if (GetAddress() == "")
		cout << "NULL  ";
	else
		cout << GetAddress() << "  ";

	cout << endl;
}