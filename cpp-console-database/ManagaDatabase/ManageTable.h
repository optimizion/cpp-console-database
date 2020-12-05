#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include "student.h"
#include "Table.h"

using namespace std;


class FileManager
{
public:
	// 파일 생성
	bool createFile()
	{

	}
	// 파일 삭제
	// 포인터 이동
	// 한 줄 읽기
};

class TableManager : FileManager
{
private:

public:
	enum TABLE
	{
		STUDENT,
		SUBJECT,
		COURSE,
		LOGIN_INFO
	};
	// 테이블 생성
	bool createTable(TABLE table)
	{
		ofstream fout;
		ifstream fin;
		switch (table)
		{
		case TABLE::STUDENT:
			fout.open("student.txt", 1);
			if (!fout.is_open())
			{
				fout.open("student.txt");
				fout << "[studentId, name, sex, grade, age, email, phoneNum, address]\n";
			}
			fin.open("student.txt", 1);
			break;
		case TABLE::SUBJECT:
			fout.open("subject.txt", 1);
			if (!fout.is_open())
			{
				fout.open("subject.txt");
				fout << "[classCode, className, professor, grade, timePlan, classified, evalType]\n";
			}
			fin.open("subject.txt", 1);

			break;
		case TABLE::COURSE:
			fout.open("course.txt", 1);
			if (!fout.is_open())
			{
				fout.open("course.txt");
				fout << "[studentId, classCode, className, professor, timePlan, location]\n";
			}
			fin.open("course.txt", 1);
			break;
		case TABLE::LOGIN_INFO:
			fout.open("loginInfo.txt", 1);
			if (!fout.is_open())
			{
				fout.open("loginInfo.txt");
				fout << "[sudentId, password]\n";
			}
			fin.open("loginInfo.txt", 1);
			break;
		default:
			break;
		}
		fout.close();
		fin.close();
	}
	bool deleteTable(TABLE table)
	{
		switch (table)
		{
		case TABLE::STUDENT:
			try
			{
				remove("student.txt");
			}
			catch (exception e)
			{
				cout << "그런 파일 없음\n";
			}
			break;
		case TABLE::SUBJECT:
			try
			{
				remove("subject.txt");
			}
			catch (exception e)
			{
				cout << "그런 파일 없음\n";
			}
			break;
		case TABLE::COURSE:
			try
			{
				remove("course.txt");
			}
			catch (exception e)
			{
				cout << "그런 파일 없음\n";
			}
			break;
		case TABLE::LOGIN_INFO:
			try
			{
				remove("loginInfo.txt");
			}
			catch (exception e)
			{
				cout << "그런 파일 없음\n";
			}
			break;
		default:
			break;
		}
	}
	bool hasTable(TABLE table) {}
};

class StudentManager : TableManager
{
public:
	bool createTable(TABLE table) {}

	void insertData()
	{
		/*cout << "학번을 입력하세요.->";
		cin >> Id;
		cout << "이름을 입력하세요.->";
		cin >> Name;
		cout << "성별 (남/여)->";
		cin >> SexInput;
		if (SexInput == "남")
			Sex = 'm';
		else if (SexInput == "여")
			Sex = 'f';
		else
		{
			cout << "성별을 잘못 입력하셨습니다.";
			return;
		}
		cout << "학년을 입력하세요(1~4).";
		cin >> Grade;
		if (Grade < 1 || Grade > 4)
		{
			cout << "학년을 잘못 입력하셨습니다.";
			return;
		}
		cout << "나이를 입력하세요.";
		cin >> Age;
		cout << "이메일을 입력하세요.";
		cin >> Email;
		cout << "전화번호를 입력하세요.->";
		cin >> PhoneNum;
		cout << "주소를 입력하세요->";
		cin >> Address;

		StudentManager Manager;
		student a(Id, Name, Sex, Grade, Age, Email, PhoneNum, Address);

		Manager.AddStudent(a);

		MoveFirst();*/
	}

	void deleteData()
	{

	}

	void updateData()
	{
	}
};

class SubjectManager : TableManager
{
public:
	void insertData(Subject subjectData)
	{	//classCode, className, professor, grade, timePlan, classified, evalType
			//::해야할 것::
			// 사용자가 특정 키를 누르면 입력 멈춤
			// 중복 방지

		string classCode;
		string className;
		string professor;
		int grade;
		string timePlan;
		string classified;
		string evalType;

		vector<string> s;
		//파일 작성
		ofstream out("test.txt");
		/*if (out.fail()) {
			cout << "**파일이 존재하지 않습니다.**" << endl;
			cout << "**파일을 생성합니다.**" << endl;
			out.open("test.txt");
		}*/

		for (int i = 0; i < 2; i++) { //for문 > 사용자 특정키로 멈추게 하는 거 추가
			cout << "과목코드(A1111)->";
			cin >> classCode;
			out << classCode << " ";

			cout << "과목명->";
			cin >> className;
			out << className << " ";

			cout << "담당교수->";
			cin >> professor;
			out << professor << " ";

			cout << "학점->";
			cin >> grade;

			cout << "시간표(요일(교시))->";
			cin >> timePlan;
			out << timePlan << " ";

			cout << "이수구분(전공,교양)->";
			cin >> classified;
			out << classified << " ";

			cout << "평가유형->";
			cin >> evalType;
			out << evalType << endl;
		}
		out.close();
		char ch;
		cout << "입력한 데이터를 보시겠습니까?('Y/N') ";
		cin >> ch;
		if (ch == 'Y' || ch == 'y') {
			cout << "::작성한 과목 데이터 목록::" << endl;
			string open_file; //임시 데이터 저장 공간
			ifstream read_file; //파일 읽는 함수
			read_file.open("test.txt"); //파일 열기
			cout << ",----------------------------------------------------------------------." << endl;
			cout << "| 과목코드 | 과목명 | 담당교수 | 학점 | 시간표 | 이수구분 | 평가 유형 |" << endl;
			cout << "'----------------------------------------------------------------------'" << endl;

			while (!read_file.eof())
			{
				getline(read_file, open_file);
				cout << open_file << endl;
			}
			read_file.close();
		}
		else if (ch == 'N' || ch == 'n') {
			cout << "Good bye";
		}

	}

	void deleteData()
	{
	}

	void updateData()
	{
	}
};

class CourseManager : TableManager
{
public:
	bool createTable(TABLE table) {}

	void insertData()
	{
		//file.open("") //파일 열기
		//	cout << endl;

		////index ???
		//file.getline(StudentID, 8, ',');         //학번
		//file.getline(name, 5, ',');              //이름
		//file.getline(subjectcode, 5, ',');       //과목코드
		//file.getline(subjectname, 20, ',');      //과목명
		//file.getline(professor, 5, ',');         //교수
		//file.getline(time, 5, ',');              //시간
		//file.getline(place, 7, '\n');            //장소


		//cout << endl << "학번을 입력하시오 : ";            //학번 입력 받기
		//cin >> StudenID;

		//cout << endl << "성명을 입력하시오 : ";            //이름 입력 받기
		//cin >> name;

		//cout << endl << "과목 코드를 입력하시오 : ";       //과목코드 입력 받기
		//cin >> subjectcode;

		//cout << endl << "과목 이름을 입력하시오 : ";       //과목이름 입력 받기
		//cin >> subjectname;

		//cout << endl << "교수명을 입력하시오 : ";          //교수명 입력 받기
		//cin >> professor;

		//cout << endl << "수업 시간을 입력하시오 : ";       //수업 시간 입력 받기
		//cin >> time;

		//cout << endl << "수업 장소를 입력하시오 : ";       //수업 장소 입력 받기
		//cin >> place;

		//cout << endl;
		//file << StudenID << "," << name << "," << subjectcode << "," << subjectname << "," << professor << "," << time << "," << place << "\n";  // myfile에 입력받은 정보 저장하기

		//file.close(); //파일 닫기


		//완벽한 코드 아님
		//어떤 파일을 여닫을 것인지, 어떻게 입력받아야할지 구상해야함.
	}

	void deleteData()
	{
		//insert와 비슷한 코드
	   //어떤 파일을 여닫을 것인지, 어떻게 삭제할 것인지 구상해야함.
	   //삭제할 때 사용자가 기본키만 입력해도 삭제되는지, 정보를 다 입력해야하는지 생각해야함.
	}

	void updateData()
	{
		//insert와 비슷한 코드
		//어떤 파일을 여닫을 것인지, 어떻게 수정할 것인지 구상해야함.
		//수정할 떄 사용자가 수정할 부분만 입력해도 되는지, 다 입력해야하는지 생각해야함.    ex) 이름만 수정하고 싶을 때는 이름만 수정할 수 있는지..??
	}
};

class LoginInfoManager : TableManager
{
public:
	void insertData(LoginInfo loginData) {}

	void deleteData(string studentId) {}

	void updatePassword(string studentId) {}
};
// 이 부분도 파일에 쓸까요? Yes
//cout << "-----------------------------------------------" << endl;
//cout << " Index 학번 이름 과목번호 과목명 교수 시간 장소" << endl;
//cout << "-----------------------------------------------" << endl;