#pragma once
#include <string>
using namespace std;

/*������������������������������������������
	���α׷����� ó���ϴ� �ϳ��� �л� ��ü
	(DB ���Ͽ��� ������ ���� �ҷ����ų�, ���� ���̺� �߰��� ��)

	*�ǵ����̸� students ����Ʈ �ȿ� �־ ����Ͻʽÿ�.
������������������������������������������*/
class student
{
private:
	//�ʼ� ������ (���� �� �ݵ�� �ʿ�)
	string Id;			//�ĺ��� (�⺻ Ű)
	string Name;		//�̸�

	//�ʼ��̳� �����̸� �⺻���� ��� ��
	char Sex;			//���� (�⺻ 'm'(��))
	short Grade;		//�г� (�⺻ 1)
	short Age;			//���� (�⺻ 20)

	//NULL ���
	string Email;		//�̸���
	string PhoneNum;	//����ó
	string Address;		//�ּ�

public:
	student* Next;		//�������� ����� �л� (Null�̸� �� �л��� ����Ʈ ��, �� Footer�� ����)

	student(string Id, string Name, char Sex, short Grade, short Age, string Email, string PhoneNum, string Address);

	//������ ��ȸ
	string GetId();
	string GetName();
	char GetSex();
	short GetGrade();
	short GetAge();
	string GetEmail();
	string GetPhoneNum();
	string GetAddress();

	void ConsoleOut();

	//������ ����
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


/*������������������������������������������
	�Ӽ��� �ش��ϴ� �����͸� ��ȯ
������������������������������������������*/
//Id ��ȯ
string student::GetId()
{
	return Id;
}

//�̸� ��ȯ
string student::GetName()
{
	return Name;
}

//���� ��ȯ
char student::GetSex()
{
	return Sex;
}

//�г� ��ȯ
short student::GetGrade()
{
	return Grade;
}

//���� ��ȯ
short student::GetAge()
{
	return Age;
}

//�̸��� ��ȯ
string student::GetEmail()
{
	return Email;
}

//����ó ��ȯ
string student::GetPhoneNum()
{
	return PhoneNum;
}

string student::GetAddress()
{
	return Address;
}


/*������������������������������������������
	�Ӽ� ������Ʈ (Id�� �����ؼ� ������Ʈ ����)
������������������������������������������*/

//�̸� ������Ʈ
void student::SetName(string a)
{
	Name = a;
}

//���� ������Ʈ
bool student::SetSex(char a)
{
	if (a != 'm' && a != 'f')
		return false;	//����: m�� f �̿��� ���ڰ� ����.

	Sex = a;
	return true;	//����ó��
}

//�г� ������Ʈ
bool student::SetGrade(short a)
{
	if (a < 1 || a > 4)
		return false;	//����: 1~4 �̿��� ����

	Grade = a;
	return true;	//����ó��
}

//���� ������Ʈ
void student::SetAge(short a)
{
	Age = a;
}

//�̸��� ������Ʈ
void student::SetEmail(string a)
{
	Email = a;
}

//��ȭ��ȣ ������Ʈ
void student::SetPhoneNum(string a)
{
	PhoneNum = a;
}

void student::SetAddress(string a)
{
	Address = a;
}

//�ֿܼ� ��Ÿ���ϴ�.
void student::ConsoleOut()
{
	cout << GetId() << "  " << GetName() << "  ";

	if (GetSex() == 'm')
		cout << "��  ";
	else
		cout << "��  ";

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