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
#include <vector>
#include <sstream>

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
			fout.open("./table/student.txt", 1);
			if (!fout.is_open())
			{
				fout.open("./table/student.txt");
				fout << "[studentId,name,sex,grade,age,email,phoneNum]\n";
			}
			else
			{
				cout << "파일이 이미 존재합니다.";
				sleep_for(seconds(1));
			}
			fin.open("./table/student.txt", 1);
			break;
		case TABLE::SUBJECT:
			fout.open("./table/subject.txt", 1);
			if (!fout.is_open())
			{
				fout.open("./table/subject.txt");
				fout << "[classCode,className,professor,grade,timePlan,classified,evalType]\n";
			}
			else
			{
				cout << "파일이 이미 존재합니다.";
				sleep_for(seconds(1));
			}
			fin.open("./table/subject.txt", 1);
			break;
		case TABLE::COURSE:
			fout.open("./table/course.txt", 1);
			if (!fout.is_open())
			{
				fout.open("./table/course.txt");
				fout << "[studentId,classCode,className,professor,timePlan,location]\n";
			}
			else
			{
				cout << "파일이 이미 존재합니다.";
				sleep_for(seconds(1));
			}
			fin.open("./table/course.txt", 1);
			break;
		case TABLE::LOGIN_INFO:
			fout.open("./table/loginInfo.txt", 1);
			if (!fout.is_open())
			{
				fout.open("./table/loginInfo.txt");
				fout << "[sudentId,password]\n";
			}
			else
			{
				cout << "파일이 이미 존재합니다.";
				sleep_for(seconds(1));
			}
			fin.open("./table/loginInfo.txt", 1);
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
			read.open("./table/student.txt");
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
					remove("./table/student.txt");
					cout << "정상적으로 삭제되었습니다.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "삭제되지 않았습니다.\n";
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
			read.open("./table/subject.txt");
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
					remove("./table/subject.txt");
					cout << "정상적으로 삭제되었습니다.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "삭제되지 않았습니다.\n";
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
			read.open("./table/course.txt");
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
					remove("./table/course.txt");
					cout << "정상적으로 삭제되었습니다.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "삭제되지 않았습니다.\n";
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
			read.open("./table/loginInfo.txt");
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
					remove("./table/loginInfo.txt");
					cout << "정상적으로 삭제되었습니다.\n";
					sleep_for(seconds(1));
					return true;
				}
				else if (user_input == 'N' || user_input == 'n')
				{
					cout << "삭제되지 않았습니다.\n";
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
	bool hasTable(TABLE table)
	{
		switch (table)
		{

		case TableManager::STUDENT:
			if (_waccess(L"./table/student.txt", 0) != 0)
			{
				return false;
			}
			return true;
			break;
		case TableManager::SUBJECT:
			if (_waccess(L"./table/subject.txt", 0) != 0)
			{
				return false;
			}
			return true;
			break;
		case TableManager::COURSE:
			if (_waccess(L"./table/course.txt", 0) != 0)
			{
				return false;
			}
			return true;
			break;
		case TableManager::LOGIN_INFO:
			if (_waccess(L"./table/loginInfo.txt", 0) != 0)
			{
				return false;
			}
			return true;
			break;
		default:
			break;
		}
	}
};

class StudentManager : TableManager
{
public:
	void insertData(Student studentData)
	{
		/*
		string UserInput;

		string Id;
		string Name;
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
		cin >> UserInput;
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
		*/
		string studentId = studentData.getStudentId();
		string name = studentData.getName();
		string sex = studentData.getSex();
		short grade = studentData.getGrade();
		short age = studentData.getAge();
		string email = studentData.getEmail();
		string phoneNum = studentData.getPhoneNum();

		//File_Manager_Student Manager;
		//student a(Id, Name, Sex, Grade, Age, Email, PhoneNum, Address);
		//Manager.AddStudent(studentData);
		//Manager.MoveFirst();
		ofstream fout;
		fout.open("./table/student.txt", ofstream::app);
		fout << studentId << "," << name << "," << sex << "," << grade << "," << age << "," << email << "," << phoneNum << endl;
		fout.close();
	}

	bool deleteData(string studentId)
	{
		ifstream fin;
		string line, str;
		fin.open("./table/student.txt", ios::in);
		// studentId 데이터가 파일에 존재하는지 확인
		int pointer = fin.tellg(); // 시작 위치
		int targetStart = NULL;
		int targetEnd;
		while (getline(fin, line))
		{
			stringstream ss;
			vector<string> results;
			ss.str(line);
			//cout << line << endl;
			while (getline(ss, str, ','))
			{
				results.push_back(str);
			}
			// 해당 id가 존재하면
			if (results[0] == studentId)
			{
				//fout.seekp(pointer); // 저장된 위치로 이동
				targetStart = pointer;
				//continue;
				//fin.close();
				//fout.close();
				//return true;
			}
			targetEnd = fin.tellg();
			pointer = fin.tellg(); // 한 줄 읽고 난 위치
			if (targetStart != NULL)
			{
				ofstream newFileOut;
				newFileOut.open("./table/student1.txt", ios::out);
				fin.seekg(ios::beg);
				string str;
				while (fin.tellg() != targetStart)
				{
					getline(fin, str);
					newFileOut << str << endl;
				}
				fin.seekg(targetEnd);
				while (getline(fin, str))
				{
					newFileOut << str << endl;
				}
				newFileOut.close();

				fin.close();
				deleteTable(TABLE::STUDENT);
				rename("./table/student1.txt", "./table/student.txt");
				return true;
			}
		}
		cout << "해당 학생 정보가 존재하지 않습니다." << endl;
		fin.close();
		return false;
		//string Target;
		//cout << "삭제할 학생의 학번을 입력하시오.";
		//cin >> Target;

		/*File_Manager_Student Manager;
		if (Manager.Update(studentId))
			cout << "성공적으로 제거하였습니다.";
		else
			cout << "제거할 학번을 찾을 수 없습니다.";*/
	}

	bool updateData(string studentId)
	{
		/*string UserInput;

		string Name;
		char Sex;
		int Grade;
		int Age;
		string Email;
		string PhoneNum;
		string Address;

		cout << "이름을 입력하세요.->";
		cin >> Name;
		cout << "성별 (남/여)->";
		cin >> UserInput;
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
		cin >> Address;*/
		ofstream fout;
		ifstream fin;
		string line, str;
		fin.open("./table/student.txt", ios::in);
		fout.open("./table/student.txt", ios::out || ios::in);
		// studentId 데이터가 파일에 존재하는지 확인
		int pointer = fin.tellg();
		while (getline(fin, line))
		{
			stringstream ss;
			ss.str(line);
			//cout << line << endl;
			while (getline(ss, str, ','))
			{
				vector<string> results;
				results.push_back(str);
				// 해당 id가 맞으면
				if (results[0] == studentId)
				{

					string name, email, phoneNum, sex;
					short grade, age;
					cout << "ex)이름,성별,학년,나이,이메일,휴대폰번호('-'제외)" << endl;
					cout << "Enter data : ";
					string user_input;
					vector<string> changedData;
					cin >> user_input;
					stringstream ss(user_input);
					while (getline(ss, user_input, ','))
					{
						changedData.push_back(user_input);
					}
					name = changedData[0];
					sex = changedData[1];
					grade = stoi(changedData[2]);
					age = stoi(changedData[3]);
					email = changedData[4];
					phoneNum = changedData[5];
					fout.seekp(pointer);

					fout << studentId << "," << name << "," << sex << "," << grade << "," << age << "," << email << "," << phoneNum << endl;

					fin.close();
					fout.close();
					return true;
				}
				else
				{
					pointer = fin.tellg();
					break;
				}
			}
		}
		cout << "해당 학번이 존재하지 않습니다." << endl;
		sleep_for(seconds(1));
		fin.close();
		fout.close();
		return false;

	}
};

class SubjectManager : TableManager
{
public:
	void insertData(Subject subjectData)
	{
		string classCode = subjectData.getClassCode();
		string className = subjectData.getClassName();
		string professor = subjectData.getProfessor();
		int grade = subjectData.getGrade();
		string timePlan = subjectData.getTimePlan();
		string classified = subjectData.getClassified();
		string evalType = subjectData.getEvalType();

		ofstream fout;
		fout.open("./table/subject.txt", ofstream::app);
		fout << classCode << "," << className << "," << professor << "," << grade << "," << timePlan << "," << classified << "," << evalType << endl;
		fout.close();
	}

	bool deleteData(string classCode)
	{
		ifstream fin;
		string line, str;
		fin.open("./table/subject.txt", ios::in);
		// studentId 데이터가 파일에 존재하는지 확인
		int pointer = fin.tellg(); // 시작 위치
		int targetStart = NULL;
		int targetEnd;
		while (getline(fin, line))
		{
			stringstream ss;
			vector<string> results;
			ss.str(line);
			//cout << line << endl;
			while (getline(ss, str, ','))
			{
				results.push_back(str);
			}
			// 해당 id가 존재하면
			if (results[0] == classCode)
			{
				//fout.seekp(pointer); // 저장된 위치로 이동
				targetStart = pointer;
				//continue;
				//fin.close();
				//fout.close();
				//return true;
			}
			targetEnd = fin.tellg();
			pointer = fin.tellg(); // 한 줄 읽고 난 위치
			if (targetStart != NULL)
			{
				ofstream newFileOut;
				newFileOut.open("./table/subject1.txt", ios::out);
				fin.seekg(ios::beg);
				string str;
				while (fin.tellg() != targetStart)
				{
					getline(fin, str);
					newFileOut << str << endl;
				}
				fin.seekg(targetEnd);
				while (getline(fin, str))
				{
					newFileOut << str << endl;
				}
				newFileOut.close();

				fin.close();
				deleteTable(TABLE::SUBJECT);
				rename("./table/subject1.txt", "./table/subject.txt");
				return true;
			}
		}
		cout << "해당 과목 정보가 존재하지 않습니다." << endl;
		fin.close();
		return false;
	}

	bool updateData(string classCode)
	{
		ofstream fout;
		ifstream fin;
		string line, str;
		fin.open("./table/subject.txt", ios::in);
		fout.open("./table/subject.txt", ios::out || ios::in);
		// studentId 데이터가 파일에 존재하는지 확인
		int pointer = fin.tellg();
		while (getline(fin, line))
		{
			stringstream ss;
			ss.str(line);
			//cout << line << endl;
			while (getline(ss, str, ','))
			{
				vector<string> results;
				results.push_back(str);
				// 해당 id가 맞으면
				if (results[0] == classCode)
				{

					string className, professor, timePlan, classified, evalType;
					int grade;
					cout << "ex)과목명,교수명,학점,시간표(화(789)),이수구분(전공 or 교양),평가유형(상대평가 or 절대평가)" << endl;
					cout << "Enter data : ";
					string user_input;
					vector<string> changedData;
					cin >> user_input;
					stringstream ss(user_input);
					while (getline(ss, user_input, ','))
					{
						changedData.push_back(user_input);
					}
					className = changedData[0];
					professor = changedData[1];
					grade = stoi(changedData[2]);
					timePlan = changedData[3];
					classified = changedData[4];
					evalType = changedData[5];
					fout.seekp(pointer);

					fout << classCode << "," << className << "," << professor << "," << grade << "," << timePlan << "," << classified << "," << evalType << endl;

					fin.close();
					fout.close();
					return true;
				}
				else
				{
					pointer = fin.tellg();
					break;
				}
			}
		}
		cout << "해당 과목번호가 존재하지 않습니다." << endl;
		sleep_for(seconds(1));
		fin.close();
		fout.close();
		return false;
	}
};

class CourseManager : TableManager
{
public:
	void insertData(Course courseData)
	{
		string studentId = courseData.getStudentId();
		string classCode = courseData.getClassCode();
		string className = courseData.getClassName();
		string professor = courseData.getProfessor();
		string timePlan = courseData.getTimePlan();
		string location = courseData.getLocation();

		ofstream fout;
		fout.open("./table/course.txt", ofstream::app);
		fout << studentId << "," << classCode << "," << className << "," << professor << "," << timePlan << "," << location << endl;
		fout.close();
		//for (i = 0; i < 2; i++) // i 범위..? <<값이 제대로 들어가는지 확인을 위해 i를 2번 증가시켰습니다
		//{
		//	cout << i + 1 << "번째 수강 정보를 입력하시오." << endl;
		//	cout << endl << "학번을 입력하시오 : ";            //학번 입력 받기
		//	cin >> studentId;
		//	cout << endl << "과목 코드를 입력하시오 : ";      //과목코드 입력 받기
		//	cin >> classCode;
		//	cout << endl << "과목 이름을 입력하시오 : ";       //과목이름 입력 받기
		//	cin >> className;
		//	cout << endl << "교수명을 입력하시오 : ";          //교수명 입력 받기
		//	cin >> professor;
		//	cout << endl << "수업 시간을 입력하시오 : ";       //수업 시간 입력 받기
		//	cin >> timePlan;
		//	cout << endl << "수업 장소를 입력하시오 : ";       //수업 장소 입력 받기
		//	cin >> location;
		//	fout << studentId << "," << classCode << "," << className << "," << professor << "," << timePlan << "," << location << endl;
		//	cout << endl << studentId << "," << classCode << "," << className << "," << professor << "," << timePlan << "," << location << endl;
		//}
	}

	bool deleteData(string studentId, string classCode)
	{
		ifstream fin;
		string line, str;
		fin.open("./table/course.txt", ios::in);
		// studentId 데이터가 파일에 존재하는지 확인
		int pointer = fin.tellg(); // 시작 위치
		int targetStart = NULL;
		int targetEnd;
		while (getline(fin, line))
		{
			stringstream ss;
			vector<string> results;
			ss.str(line);
			//cout << line << endl;
			while (getline(ss, str, ','))
			{
				results.push_back(str);
			}
			// 해당 id가 존재하면
			if (results[0] == studentId || results[1] == classCode)
			{
				//fout.seekp(pointer); // 저장된 위치로 이동
				targetStart = pointer;
				//continue;
				//fin.close();
				//fout.close();
				//return true;
			}
			targetEnd = fin.tellg();
			pointer = fin.tellg(); // 한 줄 읽고 난 위치
			if (targetStart != NULL)
			{
				ofstream newFileOut;
				newFileOut.open("./table/course1.txt", ios::out);
				fin.seekg(ios::beg);
				string str;
				while (fin.tellg() != targetStart)
				{
					getline(fin, str);
					newFileOut << str << endl;
				}
				fin.seekg(targetEnd);
				while (getline(fin, str))
				{
					newFileOut << str << endl;
				}
				newFileOut.close();

				fin.close();
				deleteTable(TABLE::COURSE);
				rename("./table/course1.txt", "./table/course.txt");
				return true;
			}
		}
		cout << "해당 수강 정보가 존재하지 않습니다." << endl;
		fin.close();
		return false;
	}

	bool updateData(string studentId, string classCode)
	{
		ofstream fout;
		ifstream fin;
		string line, str;
		fin.open("./table/course.txt", ios::in);
		fout.open("./table/course.txt", ios::out || ios::in);
		// studentId 데이터가 파일에 존재하는지 확인
		int pointer = fin.tellg();
		while (getline(fin, line))
		{
			stringstream ss;
			ss.str(line);
			vector<string> results;
			while (getline(ss, str, ','))
			{
				results.push_back(str);
			}
			// 해당 수강 정보가 존재하면
			if (results[0] == studentId && results[1] == classCode)
			{
				string className, professor, timePlan, location;
				cout << "ex)과목명,교수명,시간표(화(789)),강의실(아(605))\n";
				cout << "Enter data : ";
				string user_input;
				vector<string> changedData;
				cin >> user_input;
				stringstream ss(user_input);
				while (getline(ss, user_input, ','))
				{
					changedData.push_back(user_input);
				}
				className = changedData[0];
				professor = changedData[1];
				timePlan = changedData[2];
				location = changedData[3];
				fout.seekp(pointer);

				fout << studentId << "," << classCode << "," << className << "," << professor << "," << timePlan << "," << location << endl;

				fin.close();
				fout.close();
				return true;
			}
			else
			{
				pointer = fin.tellg();
				continue;
			}
		}
		cout << "해당 수강 정보가 존재하지 않습니다." << endl;
		sleep_for(seconds(1));
		fin.close();
		fout.close();
		return false;
	}
};

class LoginInfoManager : TableManager
{
public:
	void insertData(LoginInfo loginData)
	{
		string studentId = loginData.getStudentId();
		string password = loginData.getPassword();
		ofstream fout;
		fout.open("./table/loginInfo.txt", ofstream::app);
		fout << studentId << "," << password << endl;
		fout.close();

	}

	bool deleteData(string studentId)
	{
		ifstream fin;
		string line, str;
		fin.open("./table/loginInfo.txt", ios::in);
		// studentId 데이터가 파일에 존재하는지 확인
		int pointer = fin.tellg(); // 시작 위치
		int targetStart = NULL;
		int targetEnd;
		while (getline(fin, line))
		{
			stringstream ss;
			vector<string> results;
			ss.str(line);
			//cout << line << endl;
			while (getline(ss, str, ','))
			{
				results.push_back(str);
			}
			// 해당 id가 존재하면
			if (results[0] == studentId)
			{
				//fout.seekp(pointer); // 저장된 위치로 이동
				targetStart = pointer;
				//continue;
				//fin.close();
				//fout.close();
				//return true;
			}
			targetEnd = fin.tellg();
			pointer = fin.tellg(); // 한 줄 읽고 난 위치
			if (targetStart != NULL)
			{
				ofstream newFileOut;
				newFileOut.open("./table/loginInfo1.txt", ios::out);
				fin.seekg(ios::beg);
				string str;
				while (fin.tellg() != targetStart)
				{
					getline(fin, str);
					newFileOut << str << endl;
				}
				fin.seekg(targetEnd);
				while (getline(fin, str))
				{
					newFileOut << str << endl;
				}
				newFileOut.close();

				fin.close();
				deleteTable(TABLE::LOGIN_INFO);
				rename("./table/loginInfo1.txt", "./table/loginInfo.txt");
				return true;
			}
		}
		cout << "해당 학번이 존재하지 않습니다." << endl;
		fin.close();
		return false;
	}

	bool updatePassword(string studentId)
	{
		ofstream fout;
		ifstream fin;
		string line, str;
		fin.open("./table/loginInfo.txt", ios::in);
		fout.open("./table/loginInfo.txt", ios::out || ios::in);
		// studentId 데이터가 파일에 존재하는지 확인
		int pointer = fin.tellg();
		while (getline(fin, line))
		{
			stringstream ss;
			ss.str(line);
			//cout << line << endl;
			while (getline(ss, str, ','))
			{
				vector<string> results;
				results.push_back(str);
				// 해당 id가 맞으면
				if (results[0] == studentId)
				{
					string changePassword;
					fout.seekp(pointer);

					cout << "변경할 비밀번호를 입력하세요 : ";
					cin >> changePassword;
					fout << studentId << "," << changePassword << endl;

					fin.close();
					fout.close();
					return true;
				}
				else
				{
					pointer = fin.tellg();
					break;
				}
			}
		}
		cout << "해당 id가 존재하지 않습니다." << endl;
		sleep_for(seconds(1));
		fin.close();
		fout.close();
		return false;
	}
};
// 이 부분도 파일에 쓸까요? Yes
//cout << "-----------------------------------------------" << endl;
//cout << " Index 학번 이름 과목번호 과목명 교수 시간 장소" << endl;
//cout << "-----------------------------------------------" << endl;