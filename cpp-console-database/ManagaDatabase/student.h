#pragma once
#include <string>
#include <iostream>
using namespace std;

/*─────────────────────
	프로그램에서 처리하는 하나의 학생 객체
	(DB 파일에서 수정할 놈을 불러오거나, 새로 테이블에 추가할 놈)
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

