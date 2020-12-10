#include "ManageTable.h";

Student::Student() { this->studentId = ""; }
Student::Student(string studentId, string name, string sex, short grade, short age, string email, string phoneNum)
{
	this->studentId = studentId;
	this->name = name;
	this->sex = sex;
	this->grade = grade;
	this->age = age;
	this->email = email;
	this->phoneNum = phoneNum;
};

// student getter
string Student::getStudentId() { return this->studentId; }
string Student::getName() { return this->name; }
string Student::getSex() { return this->sex; }
short  Student::getGrade() { return this->grade; }
short  Student::getAge() { return this->age; }
string Student::getEmail() { return this->email; }
string Student::getPhoneNum() { return this->phoneNum; }

// student setter
void Student::setStudentId(string id) { this->studentId = id; }
void Student::setName(string name) { this->name = name; }
void Student::setSex(string sex) { this->sex = sex; }
void Student::setGrade(short grade) { this->grade = grade; }
void Student::setAge(short age) { this->age = age; }
void Student::setEmail(string email) { this->email = email; }
void Student::setPhoneNum(string phoneNum) { this->phoneNum = phoneNum; }

Subject::Subject() {}
Subject::Subject(string classCode, string className, string professor, int grade, string timePlan, string classified, string evalType)
{
	this->classCode = classCode;
	this->className = className;
	this->professor = professor;
	this->grade = grade;
	this->timePlan = timePlan;
	this->classified = classified;
	this->evalType = evalType;
};

//subject getter
string Subject::getClassCode() { return classCode; }
string Subject::getClassName() { return className; }
string Subject::getProfessor() { return professor; }
int    Subject::getGrade() { return grade; }
string Subject::getTimePlan() { return timePlan; }
string Subject::getClassified() { return classified; }
string Subject::getEvalType() { return evalType; }

//subject setter
void Subject::setClassCode(string classCode) { this->classCode = classCode; }
void Subject::setClassName(string className) { this->className = className; }
void Subject::setProfessor(string professor) { this->professor = professor; }
void Subject::setGrade(int grade) { this->grade = grade; }
void Subject::setTimePlan(string timePlan) { this->timePlan = timePlan; }
void Subject::setClassified(string classified) { this->classified = classified; }
void Subject::setEvalType(string evalType) { this->evalType = evalType; }


Course::Course() {}
Course::Course(string studentId, string classCode, string className, string professor, string timePlan, string location)
{
	this->studentId = studentId;
	this->classCode = classCode;
	this->className = className;
	this->professor = professor;
	this->timePlan = timePlan;
	this->location = location;
}

//course getter
string Course::getStudentId() { return studentId; }
string Course::getClassCode() { return classCode; }
string Course::getClassName() { return className; }
string Course::getProfessor() { return professor; }
string Course::getTimePlan() { return timePlan; }
string Course::getLocation() { return location; }
//course setter
void Course::setStudentId(string studentId) { this->studentId = studentId; }
void Course::setClassCode(string classCode) { this->classCode = classCode; }
void Course::setClassName(string className) { this->className = className; }
void Course::setProfessor(string professor) { this->professor = professor; }
void Course::setTimePlan(string timePlan) { this->timePlan = timePlan; }
void Course::setLocation(string location) { this->location = location; }

LoginInfo::LoginInfo() {}
LoginInfo::LoginInfo(string studentId, string password) { this->studentId = studentId; this->password = password; }

//loginInfo getter
string LoginInfo::getStudentId() { return studentId; }
string LoginInfo::getPassword() { return password; }
//loginInfo setter
void LoginInfo::setStudentId(string studentId) { this->studentId = studentId; }
void LoginInfo::setPassword(string password) { this->password = password; }


TableManager::TableManager() {}
void TableManager::createTable(TABLE table)
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
			cout << "������ �̹� �����մϴ�.";
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
			cout << "������ �̹� �����մϴ�.";
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
			cout << "������ �̹� �����մϴ�.";
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
			cout << "������ �̹� �����մϴ�.";
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
bool TableManager::deleteTable(TABLE table)
{
	switch (table)
	{
	case TABLE::STUDENT:
	{
		ifstream read;
		read.open("./table/student.txt");
		if (!read)
		{
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}
		else
		{
			read.close();
			char user_input;
			cout << "���� �����Ͻðڽ��ϱ�?(Y/N) : ";
			cin >> user_input;
			if (user_input == 'Y' || user_input == 'y')
			{
				remove("./table/student.txt");
				cout << "���������� �����Ǿ����ϴ�.\n";
				sleep_for(seconds(1));
				return true;
			}
			else if (user_input == 'N' || user_input == 'n')
			{
				cout << "�������� �ʾҽ��ϴ�.\n";
				sleep_for(seconds(1));
				return false;
			}
			else
			{
				cout << "�߸� �Է��Ͽ����ϴ�.\n";
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
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}
		else
		{
			read.close();
			char user_input;
			cout << "���� �����Ͻðڽ��ϱ�?(Y/N) : ";
			cin >> user_input;
			if (user_input == 'Y' || user_input == 'y')
			{
				remove("./table/subject.txt");
				cout << "���������� �����Ǿ����ϴ�.\n";
				sleep_for(seconds(1));
				return true;
			}
			else if (user_input == 'N' || user_input == 'n')
			{
				cout << "�������� �ʾҽ��ϴ�.\n";
				sleep_for(seconds(1));
				return false;
			}
			else
			{
				cout << "�߸� �Է��Ͽ����ϴ�.\n";
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
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}
		else
		{
			read.close();
			char user_input;
			cout << "���� �����Ͻðڽ��ϱ�?(Y/N) : ";
			cin >> user_input;
			if (user_input == 'Y' || user_input == 'y')
			{
				remove("./table/course.txt");
				cout << "���������� �����Ǿ����ϴ�.\n";
				sleep_for(seconds(1));
				return true;
			}
			else if (user_input == 'N' || user_input == 'n')
			{
				cout << "�������� �ʾҽ��ϴ�.\n";
				sleep_for(seconds(1));
				return false;
			}
			else
			{
				cout << "�߸� �Է��Ͽ����ϴ�.\n";
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
			cout << "������ �������� �ʽ��ϴ�.\n";
			sleep_for(seconds(1));
			return false;
		}
		else
		{
			read.close();
			char user_input;
			cout << "���� �����Ͻðڽ��ϱ�?(Y/N) : ";
			cin >> user_input;
			if (user_input == 'Y' || user_input == 'y')
			{
				remove("./table/loginInfo.txt");
				cout << "���������� �����Ǿ����ϴ�.\n";
				sleep_for(seconds(1));
				return true;
			}
			else if (user_input == 'N' || user_input == 'n')
			{
				cout << "�������� �ʾҽ��ϴ�.\n";
				sleep_for(seconds(1));
				return false;
			}
			else
			{
				cout << "�߸� �Է��Ͽ����ϴ�.\n";
				return false;
			}
		}
		break;
	}

	default:
		break;
	}
}
bool TableManager::hasTable(TABLE table)
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

StudentManager::StudentManager() {}
bool StudentManager::insertData(Student studentData)
{
	string studentId = studentData.getStudentId();
	string name = studentData.getName();
	string sex = studentData.getSex();
	short grade = studentData.getGrade();
	short age = studentData.getAge();
	string email = studentData.getEmail();
	string phoneNum = studentData.getPhoneNum();

	ifstream fin;
	string line, str;
	fin.open("./table/student.txt", ios::in);
	// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
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
		if (results[0] == studentId)
		{
			cout << "�̹� �ش� �й��� �����Ͱ� �����մϴ�." << endl;
			return false;
		}
	}

	ofstream fout;
	fout.open("./table/student.txt", ofstream::app);
	fout << studentId << "," << name << "," << sex << "," << grade << "," << age << "," << email << "," << phoneNum << endl;
	fin.close();
	fout.close();
	return true;
}
bool StudentManager::deleteData(string studentId)
{
	ifstream fin;
	string line, str;
	fin.open("./table/student.txt", ios::in);
	// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
	int pointer = fin.tellg(); // ���� ��ġ
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
		// �ش� id�� �����ϸ�
		if (results[0] == studentId)
		{
			//fout.seekp(pointer); // ����� ��ġ�� �̵�
			targetStart = pointer;
			//continue;
			//fin.close();
			//fout.close();
			//return true;
		}
		targetEnd = fin.tellg();
		pointer = fin.tellg(); // �� �� �а� �� ��ġ
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
	cout << "�ش� �л� ������ �������� �ʽ��ϴ�." << endl;
	fin.close();
	return false;
	//string Target;
	//cout << "������ �л��� �й��� �Է��Ͻÿ�.";
	//cin >> Target;

	/*File_Manager_Student Manager;
	if (Manager.Update(studentId))
		cout << "���������� �����Ͽ����ϴ�.";
	else
		cout << "������ �й��� ã�� �� �����ϴ�.";*/
}
bool StudentManager::updateData(string studentId)
{
	ofstream fout;
	ifstream fin;
	string line, str;
	fin.open("./table/student.txt", ios::in);
	fout.open("./table/student.txt", ios::out || ios::in);
	// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
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
			// �ش� id�� ������
			if (results[0] == studentId)
			{

				string name, email, phoneNum, sex;
				short grade, age;
				cout << "ex)�̸�,����,�г�,����,�̸���,�޴�����ȣ('-'����)" << endl;

				while (true)
				{
					try
					{
						cout << "Enter data : ";
						string user_input;
						vector<string> changedData;
						cin >> user_input;
						stringstream ss(user_input);
						while (getline(ss, user_input, ','))
						{
							changedData.push_back(user_input);
						}
						name = changedData.at(0);
						sex = changedData.at(1);
						grade = stoi(changedData.at(2));
						age = stoi(changedData.at(3));
						email = changedData.at(4);
						phoneNum = changedData.at(5);

						break;
					}
					catch (const exception& error)
					{
						cout << "�Է� ������ �߻��߽��ϴ�. �ٽ� �Է����ּ���." << endl << endl;
						sleep_for(seconds(1));
						continue;
					}
				}

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
	cout << "�ش� �й��� �������� �ʽ��ϴ�." << endl;
	sleep_for(seconds(1));
	fin.close();
	fout.close();
	return false;

}
Student StudentManager::queryStudentData(string studentId)
{
	ifstream fin;
	string line, str;
	fin.open("./table/student.txt", ios::in);
	// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
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
		// �ش� id�� �����ϸ�
		if (results[0] == studentId)
		{
			Student student;
			try
			{
				student.setStudentId(results.at(0));
				student.setName(results.at(1));
				student.setSex(results.at(2));
				student.setGrade(stoi(results.at(3)));
				student.setAge(stoi(results.at(4)));
				student.setEmail(results.at(5));
				student.setPhoneNum(results.at(6));
			}
			catch (const exception& error)
			{
				cout << "������ �߻��߽��ϴ�. ���������� �����ϼ��� *^^*" << endl << endl;
				sleep_for(seconds(2));
				continue;
			}

			fin.close();
			return student;
		}
	}
	fin.close();
	return Student();
}

SubjectManager::SubjectManager() {}
bool SubjectManager::insertData(Subject subjectData)
{
	string classCode = subjectData.getClassCode();
	string className = subjectData.getClassName();
	string professor = subjectData.getProfessor();
	int grade = subjectData.getGrade();
	string timePlan = subjectData.getTimePlan();
	string classified = subjectData.getClassified();
	string evalType = subjectData.getEvalType();

	ifstream fin;
	string line, str;
	fin.open("./table/subject.txt", ios::in);
	// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
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
		if (results[0] == classCode)
		{
			cout << "�̹� �ش� �����ڵ��� �����Ͱ� �����մϴ�." << endl;
			return false;
		}
	}

	ofstream fout;
	fout.open("./table/subject.txt", ofstream::app);
	fout << classCode << "," << className << "," << professor << "," << grade << "," << timePlan << "," << classified << "," << evalType << endl;
	fin.close();
	fout.close();
	return true;
}
bool SubjectManager::deleteData(string classCode)
{
	ifstream fin;
	string line, str;
	fin.open("./table/subject.txt", ios::in);
	// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
	int pointer = fin.tellg(); // ���� ��ġ
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
		// �ش� id�� �����ϸ�
		if (results[0] == classCode)
		{
			//fout.seekp(pointer); // ����� ��ġ�� �̵�
			targetStart = pointer;
		}
		targetEnd = fin.tellg();
		pointer = fin.tellg(); // �� �� �а� �� ��ġ
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
	cout << "�ش� ���� ������ �������� �ʽ��ϴ�." << endl;
	fin.close();
	return false;
}
bool SubjectManager::updateData(string classCode)
{
	ofstream fout;
	ifstream fin;
	string line, str;
	fin.open("./table/subject.txt", ios::in);
	fout.open("./table/subject.txt", ios::out || ios::in);
	// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
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
			// �ش� id�� ������
			if (results[0] == classCode)
			{

				string className, professor, timePlan, classified, evalType;
				int grade;
				cout << "ex)�����,������,����,�ð�ǥ(ȭ(789)),�̼�����(���� or ����),������(����� or ������)" << endl;

				while (true)
				{
					try
					{
						cout << "Enter data : ";
						string user_input;
						vector<string> changedData;
						cin >> user_input;
						stringstream ss(user_input);
						while (getline(ss, user_input, ','))
						{
							changedData.push_back(user_input);
						}
						className = changedData.at(0);
						professor = changedData.at(1);
						grade = stoi(changedData.at(2));
						timePlan = changedData.at(3);
						classified = changedData.at(4);
						evalType = changedData.at(5);

						break;
					}
					catch (const exception& error)
					{
						cout << "�Է� ������ �߻��߽��ϴ�. �ٽ� �Է����ּ���." << endl << endl;
						sleep_for(seconds(1));
						continue;
					}
				}

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
	cout << "�ش� �����ȣ�� �������� �ʽ��ϴ�." << endl;
	sleep_for(seconds(1));
	fin.close();
	fout.close();
	return false;
}
bool SubjectManager::querySubjectData()
{
	int first = 0;
	ifstream fin;
	string line, str;
	stringstream returnStream;
	fin.open("./table/subject.txt", ios::in);
	while (getline(fin, line))
	{
		if (first == 0)
		{
			first++;
			continue;
		}
		stringstream ss;
		vector<string> results;
		ss.str(line);
		while (getline(ss, str, ','))
		{
			results.push_back(str);
		}

		cout << "| ";
		for (int i = 0; i < results.size(); i++)
		{
			cout << results.at(i) << " | ";
		}
		cout << endl;
	}
	fin.close();
	return true;
}

CourseManager::CourseManager() {}
bool CourseManager::insertData(Course courseData)

{
	string studentId = courseData.getStudentId();
	string classCode = courseData.getClassCode();
	string className = courseData.getClassName();
	string professor = courseData.getProfessor();
	string timePlan = courseData.getTimePlan();
	string location = courseData.getLocation();

	ifstream fin;
	string line, str;
	fin.open("./table/course.txt", ios::in);
	// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
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
		if (results[0] == studentId && results[1] == classCode)
		{
			cout << "�̹� �ش� ���� �����Ͱ� �����մϴ�." << endl;
			return false;
		}
	}

	ofstream fout;
	fout.open("./table/course.txt", ofstream::app);
	fout << studentId << "," << classCode << "," << className << "," << professor << "," << timePlan << "," << location << endl;
	fin.close();
	fout.close();
	return true;
}
bool CourseManager::deleteData(string studentId, string classCode)
{
	ifstream fin;
	string line, str;
	fin.open("./table/course.txt", ios::in);
	// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
	int pointer = fin.tellg(); // ���� ��ġ
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
		// �ش� id�� �����ϸ�
		if (results[0] == studentId || results[1] == classCode)
		{
			//fout.seekp(pointer); // ����� ��ġ�� �̵�
			targetStart = pointer;
			//continue;
			//fin.close();
			//fout.close();
			//return true;
		}
		targetEnd = fin.tellg();
		pointer = fin.tellg(); // �� �� �а� �� ��ġ
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
	cout << "�ش� ���� ������ �������� �ʽ��ϴ�." << endl;
	fin.close();
	return false;
}
bool CourseManager::updateData(string studentId, string classCode)
{
	ofstream fout;
	ifstream fin;
	string line, str;
	fin.open("./table/course.txt", ios::in);
	fout.open("./table/course.txt", ios::out || ios::in);
	// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
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
		// �ش� ���� ������ �����ϸ�
		if (results[0] == studentId && results[1] == classCode)
		{
			string className, professor, timePlan, location;
			cout << "ex)�����,������,�ð�ǥ(ȭ(789)),���ǽ�(��(605))\n";

			while (true)
			{
				try
				{
					cout << "Enter data : ";
					string user_input;
					vector<string> changedData;
					cin >> user_input;
					stringstream ss(user_input);
					while (getline(ss, user_input, ','))
					{
						changedData.push_back(user_input);
					}
					className = changedData.at(0);
					professor = changedData.at(1);
					timePlan = changedData.at(2);
					location = changedData.at(3);

					break;
				}

				catch (const exception& error)
				{
					cout << "�Է� ������ �߻��߽��ϴ�. �ٽ� �Է����ּ���." << endl << endl;
					sleep_for(seconds(1));
					continue;
				}
			}

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
	cout << "�ش� ���� ������ �������� �ʽ��ϴ�." << endl;
	sleep_for(seconds(1));
	fin.close();
	fout.close();
	return false;
}
bool CourseManager::queryCourseData(string studentId)
{
	int first = 0;
	ifstream fin;
	string line, str;
	stringstream returnStream;
	fin.open("./table/course.txt", ios::in);
	while (getline(fin, line))
	{
		if (first == 0)
		{
			first++;
			continue;
		}
		stringstream ss;
		vector<string> results;
		ss.str(line);
		while (getline(ss, str, ','))
		{
			results.push_back(str);
		}
		if (results.at(0) == studentId)
		{
			cout << "| ";
			for (int i = 0; i < results.size(); i++)
			{
				cout << results[i] << " | ";
			}
			cout << endl;
		}

	}
	fin.close();
	return true;
}

LoginInfoManager::LoginInfoManager() {}
bool LoginInfoManager::insertData(LoginInfo loginData)
{
	string studentId = loginData.getStudentId();
	string password = loginData.getPassword();

	ifstream fin;
	string line, str;
	fin.open("./table/loginInfo.txt", ios::in);
	// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
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
		if (results[0] == studentId)
		{
			cout << "�̹� �ش� �α��� ���� �����Ͱ� �����մϴ�." << endl;
			return false;
		}
	}

	ofstream fout;
	fout.open("./table/loginInfo.txt", ofstream::app);
	fout << studentId << "," << password << endl;
	fin.close();
	fout.close();
	return true;
}
bool LoginInfoManager::deleteData(string studentId)
{
	ifstream fin;
	string line, str;
	fin.open("./table/loginInfo.txt", ios::in);
	// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
	int pointer = fin.tellg(); // ���� ��ġ
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
		// �ش� id�� �����ϸ�
		if (results[0] == studentId)
		{
			//fout.seekp(pointer); // ����� ��ġ�� �̵�
			targetStart = pointer;
			//continue;
			//fin.close();
			//fout.close();
			//return true;
		}
		targetEnd = fin.tellg();
		pointer = fin.tellg(); // �� �� �а� �� ��ġ
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
	cout << "�ش� �й��� �������� �ʽ��ϴ�." << endl;
	fin.close();
	return false;
}
bool LoginInfoManager::updatePassword(string studentId)
{
	ofstream fout;
	ifstream fin;
	string line, str;
	fin.open("./table/loginInfo.txt", ios::in);
	fout.open("./table/loginInfo.txt", ios::out || ios::in);
	// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
	int pointer = fin.tellg();
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
		// �ش� id�� ������
		if (results[0] == studentId)
		{
			string changePassword;
			fout.seekp(pointer);

			string currentPassword;
			cout << "���� ��й�ȣ�� �Է��ϼ��� : ";
			cin >> currentPassword;
			if (currentPassword != results[1])
			{
				cout << "��й�ȣ�� Ʋ���ϴ�." << endl;
				sleep_for(seconds(1));
				fin.close();
				fout.close();
				return false;
			}

			cout << "������ ��й�ȣ�� �Է��ϼ��� : ";
			cin >> changePassword;

			char user_input;
			cout << "���� �����Ͻðڽ��ϱ�?(Y/N) : ";
			cin >> user_input;
			if (user_input == 'Y' || user_input == 'y')
			{
				fout << studentId << "," << changePassword << endl;
				cout << "��й�ȣ�� �����Ͽ����ϴ�." << endl;
				fin.close();
				fout.close();
				return true;
			}
			else if (user_input == 'N' || user_input == 'n')
			{
				cout << "��й�ȣ ������ ����Ͽ����ϴ�." << endl;
				fin.close();
				fout.close();
				return false;
			}
		}
		else
		{
			pointer = fin.tellg();
			continue;
		}
	}
	cout << "�α��� ������ �������� �ʽ��ϴ�." << endl;
	sleep_for(seconds(1));
	fin.close();
	fout.close();
	return false;
}
bool LoginInfoManager::checkLogin(string studentId, string password)
{
	sleep_for(seconds(1));
	ifstream fin;
	string line, str;
	fin.open("./table/loginInfo.txt", ios::in);
	// studentId �����Ͱ� ���Ͽ� �����ϴ��� Ȯ��
	while (getline(fin, line))
	{
		stringstream ss;
		ss.str(line);
		vector<string> results;
		while (getline(ss, str, ','))
		{
			results.push_back(str);
		}
		// �ش� �α��� ������ ������
		if (results.at(0) == studentId && results.at(1) == password)
		{
			fin.close();
			return true;
		}
		else
		{
			continue;
		}
	}
	fin.close();
	return false;
}