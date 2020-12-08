#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <thread>
#include <chrono>
#include "student.h"
#include "Table.h"
#include "File_Manager_Student.h"
#include <direct.h>

using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

class FileManager
{
public:
	// 파일 생성
	void createFile()
	{

	}
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
	void createTable(TABLE table)
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
			else
			{
				cout << "파일이 이미 존재합니다.";
				sleep_for(seconds(1));
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
			else
			{
				cout << "파일이 이미 존재합니다.";
				sleep_for(seconds(1));
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
			else
			{
				cout << "파일이 이미 존재합니다.";
				sleep_for(seconds(1));
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
			else
			{
				cout << "파일이 이미 존재합니다.";
				sleep_for(seconds(1));
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
		{
			ifstream read;
			read.open("student.txt");
			if (!read)
			{
				cout << "파일이 존재하지 않습니다.\n";
				sleep_for(seconds(1));
				return false;
			}
			else
			{
				read.close();
				char user_input;
				cout << "정말 삭제하시겠습니까?(Y/N) : ";
				cin >> user_input;
				if (user_input == 'Y' || user_input == 'y')
				{
					remove("student.txt");
					cout << "파일이 정상적으로 삭제되었습니다.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "파일이 삭제되지 않았습니다.\n";
					sleep_for(seconds(1));
					return false;
				}
				else
				{
					cout << "잘못 입력하였습니다.\n";
					return false;
				}
			}
		}
		break;
		case TABLE::SUBJECT:
		{
			ifstream read;
			read.open("subject.txt");
			if (!read)
			{
				cout << "파일이 존재하지 않습니다.\n";
				sleep_for(seconds(1));
				return false;
			}
			else
			{
				read.close();
				char user_input;
				cout << "정말 삭제하시겠습니까?(Y/N) : ";
				cin >> user_input;
				if (user_input == 'Y' || user_input == 'y')
				{
					remove("subject.txt");
					cout << "파일이 정상적으로 삭제되었습니다.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "파일이 삭제되지 않았습니다.\n";
					sleep_for(seconds(1));
					return false;
				}
				else
				{
					cout << "잘못 입력하였습니다.\n";
					return false;
				}
			}
			break;
		}

		case TABLE::COURSE:
		{
			ifstream read;
			read.open("course.txt");
			if (!read)
			{
				cout << "파일이 존재하지 않습니다.\n";
				sleep_for(seconds(1));
				return false;
			}
			else
			{
				read.close();
				char user_input;
				cout << "정말 삭제하시겠습니까?(Y/N) : ";
				cin >> user_input;
				if (user_input == 'Y' || user_input == 'y')
				{
					remove("course.txt");
					cout << "파일이 정상적으로 삭제되었습니다.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "파일이 삭제되지 않았습니다.\n";
					sleep_for(seconds(1));
					return false;
				}
				else
				{
					cout << "잘못 입력하였습니다.\n";
					return false;
				}
			}
			break;
		}

		case TABLE::LOGIN_INFO:
		{
			ifstream read;
			read.open("loginInfo.txt");
			if (!read)
			{
				cout << "파일이 존재하지 않습니다.\n";
				sleep_for(seconds(1));
				return false;
			}
			else
			{
				read.close();
				char user_input;
				cout << "정말 삭제하시겠습니까?(Y/N) : ";
				cin >> user_input;
				if (user_input == 'Y' || user_input == 'y')
				{
					remove("loginInfo.txt");
					cout << "파일이 정상적으로 삭제되었습니다.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "파일이 삭제되지 않았습니다.\n";
					sleep_for(seconds(1));
					return false;
				}
				else
				{
					cout << "잘못 입력하였습니다.\n";
					return false;
				}
			}
			break;
		}

		default:
			break;
		}
	}
	bool hasTable(TABLE table) {}
};

class StudentManager : TableManager
{
public:
	void insertData()
	{
		string Id;
		string Name;
		string SexInput;
		char Sex;
		int Grade;
		int Age;
		string Email;
		string PhoneNum;
		string Address;

		cout << "학번을 입력하세요.->";
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

		File_Manager_Student Manager;

		student a(Id, Name, Sex, Grade, Age, Email, PhoneNum, Address);

		Manager.AddStudent(a);

		Manager.MoveFirst();
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

		for (int i = 0; i < 2; i++)
		{
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
		if (ch == 'Y' || ch == 'y')
		{
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
		else if (ch == 'N' || ch == 'n')
		{
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
	void insertData()
	{
		string studentId;
		string classCode;
		string className;
		string professor;
		string timePlan;
		string location;

		int i;

		string out_line;
		ofstream fout;
		ofstream out("course.txt");

		for (i = 0; i < 2; i++) // i 범위..? <<값이 제대로 들어가는지 확인을 위해 i를 2번 증가시켰습니다
		{
			cout << i + 1 << "번째 수강 정보를 입력하시오." << endl;

			cout << endl << "학번을 입력하시오 : ";            //학번 입력 받기
			cin >> studentId;

			cout << endl << "과목 코드를 입력하시오 : ";      //과목코드 입력 받기
			cin >> classCode;

			cout << endl << "과목 이름을 입력하시오 : ";       //과목이름 입력 받기
			cin >> className;

			cout << endl << "교수명을 입력하시오 : ";          //교수명 입력 받기
			cin >> professor;

			cout << endl << "수업 시간을 입력하시오 : ";       //수업 시간 입력 받기
			cin >> timePlan;

			cout << endl << "수업 장소를 입력하시오 : ";       //수업 장소 입력 받기
			cin >> location;

			fout << studentId << "," << classCode << "," << className << "," << professor << "," << timePlan << "," << location << endl;
			cout << endl << studentId << "," << classCode << "," << className << "," << professor << "," << timePlan << "," << location << endl;
		}
	}

	void deleteData()
	{

	}

	void updateData()
	{

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