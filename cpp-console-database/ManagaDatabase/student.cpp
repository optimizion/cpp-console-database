#include "student.h"


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