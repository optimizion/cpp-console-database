#pragma once
#include <string>
#include <iostream>
using namespace std;

/*������������������������������������������
	���α׷����� ó���ϴ� �ϳ��� �л� ��ü
	(DB ���Ͽ��� ������ ���� �ҷ����ų�, ���� ���̺� �߰��� ��)
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

