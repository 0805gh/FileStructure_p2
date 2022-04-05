// test.cc
// Copyright 1997, Gregory A. Riccardi
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iomanip>
#include "DelimTextBuffer.h"
#include "LengthTextBuffer.h"
#include "FixedTextBuffer.h"
#include "Student.h"
#include "CourseRegistration.h"
#include <vector>
using namespace std;

//*
void testFixText ()
{
	int result;
	Student s; CourseRegistration c;
	FixedTextBuffer Buff1(5), Buff2(5);
	vector<FixedTextBuffer> buff_array1, buff_array2;
	vector<Student> student_array;
	vector<CourseRegistration> course_array;
	Student:: InitBuffer (Buff1);
	CourseRegistration::InitBuffer(Buff2);
	strcpy(s.Identifier, "202055512");
	strcpy(s.Name, "kihae");
	strcpy(s.Address, "busan");
	strcpy(s.DateOfFirstEnrollment, "2020-03-02");
	char num[10]; s.NumberOfCreditHours = 20;
	strcpy(num, "20");
	s.Print (cout);

	s.Pack(Buff1);
	Buff1.Print(cout);
	ofstream TestOut("FixedText.dat", ios::out);
	Buff1.Write(TestOut);
	strcpy(s.Name, "hi");
	s.Print(cout);
	s.Pack(Buff1);
	Buff1.Write(TestOut);
	TestOut.close();

	ifstream TestIn("FixedText.dat");
	FixedTextBuffer InBuff1(5), InBuff2(5);
	Student::InitBuffer(InBuff1);
	CourseRegistration::InitBuffer(InBuff2);
	Buff1.Read(TestIn);
	s.Unpack(Buff1);
	s.Print(cout);

	while (1)
	{
		int count;
		int select;
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Student object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cout << "Student Identifier : ";
				cin >> s.Identifier;
				cout << "Student Name : ";
				cin >> s.Name;
				cout << "Student Address : ";
				cin >> s.Address;
				cout << "Student Date of First Enrollment : ";
				cin >> s.DateOfFirstEnrollment;
				cout << "Student Number of Credit Hours : ";
				cin >> s.NumberOfCreditHours;
				s.Pack(Buff1);
				buff_array1.push_back(Buff1);
				student_array.push_back(s);
			}
			cout << "the number of Course object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++) 
			{
				cout << "Course Identifier : ";
				cin >> c.CourseIdentifier;
				cout << "Number of Credit Hours : ";
				cin >> c.NumberOfCreditHours;
				cout << "Course Grade : ";
				cin >> c.CourseGrade;
				cout << "Student Num : ";
				cin >> c.StudentNum;
				for (int j = 0; j < c.StudentNum; j++) {
					cout << "Student Identifier" << j + 1 << " : ";
					cin >> c.StudentIdentifier[j];
					for(int k = 0; k < student_array.size(); k++) {
						if (!strcmp(c.StudentIdentifier[j], student_array[k].Identifier)) {
							student_array[k].increaseNumberOfCreditHours(c.NumberOfCreditHours);
							break;
						}
					}
				}
				c.Pack(Buff2);
				buff_array2.push_back(Buff2);
				course_array.push_back(c);
			}
			break;
		case 2:
			// to display the array of Person objects into screen
			cout << ">>Student Print" << endl;
			for (int i = 0; i < student_array.size(); i++)
			{
				student_array[i].Print(cout);
			}
			cout << ">>Course Registration Print" << endl;
			for (int i = 0; i < course_array.size(); i++)
			{
				course_array[i].Print(cout);
			}
			break;
		case 3:
		{
			// to write the array of Person objects into a file
			ofstream fostream("FixedText.dat", ios::out | ios::in);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return;
			}
			
			for (int i = 0; i < buff_array1.size(); i++)
			{
				buff_array1[i].Write(fostream);
			}
			for (int i = 0; i < buff_array2.size(); i++)
			{
				buff_array2[i].Write(fostream);
			}
			cout << "Write completed!" << endl;
			fostream.close();
			break;
		}
		case 4:
		{
			// to read the array of Person records from the file
			ifstream fistream("FixedText.dat", ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return;
			}
			Student::InitBuffer(InBuff1);
			for (int i = 0; i < buff_array1.size(); i++)
			{
				buff_array1[i].Read(fistream);
				student_array[i].Unpack(buff_array1[i]);
				student_array[i].Print(cout);
			}
			CourseRegistration::InitBuffer(InBuff2);
			for (int i = 0; i < buff_array2.size(); i++)
			{
				buff_array2[i].Read(fistream);
				course_array[i].Unpack(buff_array2[i]);
				course_array[i].Print(cout);
			}
			fistream.close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
	}
}
//*/
/*
void testLenText ()
{
	cout << "\nTesting LengthTextBuffer"<<endl;
	Student s; CourseRegistration c;
	LengthTextBuffer Buff1(5), Buff2(5);
	vector<LengthTextBuffer> buff_array1, buff_array2;
	vector<Student> student_array;
	vector<CourseRegistration> course_array;
	Student::InitBuffer(Buff1);
	CourseRegistration::InitBuffer(Buff2);
	strcpy(s.Identifier, "202055512");
	strcpy(s.Name, "kihae");
	strcpy(s.Address, "busan");
	strcpy(s.DateOfFirstEnrollment, "2020-03-02");
	char num[10]; s.NumberOfCreditHours = 20;
	strcpy(num, "20");
	s.Print(cout);

	Buff1.Print(cout);
	cout << "pack student " << s.Pack(Buff1) << endl;
	Buff1.Print(cout);
	ofstream TestOut ("LengthText.dat", ios::out);
	Buff1.Write(TestOut);
	strcpy (s.Name, "hi");
	s.Print(cout);
	s.Pack(Buff1);
	Buff1.Write(TestOut);
	TestOut.close();

	cout << "+++++++++++++++++++++++++++++" << endl;
	ifstream TestIn ("LengthText.dat");
	LengthTextBuffer InBuff1(5), InBuff2(5);
	Student::InitBuffer(InBuff1);
	CourseRegistration::InitBuffer(InBuff2);
	Buff1.Read(TestIn);
	s.Unpack(Buff1);
	cout << "read " << Buff1.Read(TestIn) << endl;
	cout << "unpack " << s.Unpack(Buff1) << endl;
	s.Print(cout);
	cout << "read " << Buff1.Read(TestIn) << endl;
	cout << "unpack " << s.Unpack(Buff1) << endl;
	s.Print(cout);
	cout << "read " << Buff1.Read(TestIn) << endl;
	cout << "unpack " << s.Unpack(Buff1) << endl;
	s.Print(cout);
	
	while (1)
	{
		int count;
		int select;
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Student object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cout << "Student Identifier : ";
				cin >> s.Identifier;
				cout << "Student Name : ";
				cin >> s.Name;
				cout << "Student Address : ";
				cin >> s.Address;
				cout << "Student Date of First Enrollment : ";
				cin >> s.DateOfFirstEnrollment;
				cout << "Student Number of Credit Hours : ";
				cin >> s.NumberOfCreditHours;
				s.Pack(Buff1);
				buff_array1.push_back(Buff1);
				student_array.push_back(s);
			}
			cout << "the number of Course object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cout << "Course Identifier : ";
				cin >> c.CourseIdentifier;
				cout << "Number of Credit Hours : ";
				cin >> c.NumberOfCreditHours;
				cout << "Course Grade : ";
				cin >> c.CourseGrade;
				cout << "Student Num : ";
				cin >> c.StudentNum;
				for (int j = 0; j < c.StudentNum; j++) {
					cout << "Student Identifier" << j + 1 << " : ";
					cin >> c.StudentIdentifier[j];
					for (int k = 0; k < student_array.size(); k++) {
						if (!strcmp(c.StudentIdentifier[j], student_array[k].Identifier)) {
							student_array[k].increaseNumberOfCreditHours(c.NumberOfCreditHours);
							break;
						}
					}
				}
				c.Pack(Buff2);
				buff_array2.push_back(Buff2);
				course_array.push_back(c);
			}
			break;
		case 2:
			// to display the array of Person objects into screen
			cout << ">>Student Print" << endl;
			for (int i = 0; i < student_array.size(); i++)
			{
				student_array[i].Print(cout);
			}
			cout << ">>Course Registration Print" << endl;
			for (int i = 0; i < course_array.size(); i++)
			{
				course_array[i].Print(cout);
			}
			break;
		case 3:
		{
			// to write the array of Person objects into a file
			ofstream fostream("LengthText.dat", ios::out | ios::in);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return;
			}

			for (int i = 0; i < buff_array1.size(); i++)
			{
				buff_array1[i].Write(fostream);
			}
			for (int i = 0; i < buff_array2.size(); i++)
			{
				buff_array2[i].Write(fostream);
			}
			cout << "Write completed!" << endl;
			fostream.close();
			break;
		}
		case 4:
		{
			// to read the array of Person records from the file
			ifstream fistream("LengthText.dat", ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return;
			}
			Student::InitBuffer(InBuff1);
			for (int i = 0; i < buff_array1.size(); i++)
			{
				buff_array1[i].Read(fistream);
				student_array[i].Unpack(buff_array1[i]);
				student_array[i].Print(cout);
			}
			CourseRegistration::InitBuffer(InBuff2);
			for (int i = 0; i < buff_array2.size(); i++)
			{
				buff_array2[i].Read(fistream);
				course_array[i].Unpack(buff_array2[i]);
				course_array[i].Print(cout);
			}
			fistream.close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
	}
}
*/
/*
void testDelText()
{
	cout << "\nTesting DelimTextBuffer" << endl;
	Student s; CourseRegistration c;
	DelimTextBuffer Buff1(5), Buff2(5);
	vector<DelimTextBuffer> buff_array1, buff_array2;
	vector<Student> student_array;
	vector<CourseRegistration> course_array;
	Student::InitBuffer(Buff1);
	CourseRegistration::InitBuffer(Buff2);
	strcpy(s.Identifier, "202055512");
	strcpy(s.Name, "kihae");
	strcpy(s.Address, "busan");
	strcpy(s.DateOfFirstEnrollment, "2020-03-02");
	char num[10]; s.NumberOfCreditHours = 20;
	strcpy(num, "20");
	s.Print(cout);
	Buff1.Print(cout); //start with an empty buffer object
	cout << "pack person " << s.Pack(Buff1) << endl; //pack field values into the object
	Buff1.Print(cout);

	ofstream TestOut("DelimText.dat", ios::out);
	Buff1.Write(TestOut); //write the buffer contents to an output stream
	strcpy(s.Name, "hi");
	s.Print(cout);

	s.Pack(Buff1);
	Buff1.Write(TestOut);
	TestOut.close();

	cout << "+++++++++++++++++++++++++++++" << endl;
	ifstream TestIn("DelimText.dat");
	DelimTextBuffer InBuff1(5), InBuff2(5);
	Student::InitBuffer(InBuff1);
	CourseRegistration::InitBuffer(InBuff2);

	cout << "read " << Buff1.Read(TestIn) << endl;
	cout << "unpack " << s.Unpack(Buff1) << endl;
	s.Print(cout);

	cout << "read " << Buff1.Read(TestIn) << endl;
	cout << "unpack " << s.Unpack(Buff1) << endl;
	s.Print(cout);

	cout << "read " << Buff1.Read(TestIn) << endl;
	cout << "unpack " << s.Unpack(Buff1) << endl;
	s.Print(cout);

	while (1)
	{
		int count;
		int select;
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Student object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cout << "Student Identifier : ";
				cin >> s.Identifier;
				cout << "Student Name : ";
				cin >> s.Name;
				cout << "Student Address : ";
				cin >> s.Address;
				cout << "Student Date of First Enrollment : ";
				cin >> s.DateOfFirstEnrollment;
				cout << "Student Number of Credit Hours : ";
				cin >> s.NumberOfCreditHours;
				s.Pack(Buff1);
				buff_array1.push_back(Buff1);
				student_array.push_back(s);
			}
			cout << "the number of Course object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cout << "Course Identifier : ";
				cin >> c.CourseIdentifier;
				cout << "Number of Credit Hours : ";
				cin >> c.NumberOfCreditHours;
				cout << "Course Grade : ";
				cin >> c.CourseGrade;
				cout << "Student Num : ";
				cin >> c.StudentNum;
				for (int j = 0; j < c.StudentNum; j++) {
					cout << "Student Identifier" << j + 1 << " : ";
					cin >> c.StudentIdentifier[j];
					for (int k = 0; k < student_array.size(); k++) {
						if (!strcmp(c.StudentIdentifier[j], student_array[k].Identifier)) {
							student_array[k].increaseNumberOfCreditHours(c.NumberOfCreditHours);
							break;
						}
					}
				}
				c.Pack(Buff2);
				buff_array2.push_back(Buff2);
				course_array.push_back(c);
			}
			break;
		case 2:
			// to display the array of Person objects into screen
			cout << ">>Student Print" << endl;
			for (int i = 0; i < student_array.size(); i++)
			{
				student_array[i].Print(cout);
			}
			cout << ">>Course Registration Print" << endl;
			for (int i = 0; i < course_array.size(); i++)
			{
				course_array[i].Print(cout);
			}
			break;
		case 3:
		{
			// to write the array of Person objects into a file
			ofstream fostream("DelimText.dat", ios::out | ios::in);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return;
			}

			for (int i = 0; i < buff_array1.size(); i++)
			{
				buff_array1[i].Write(fostream);
			}
			for (int i = 0; i < buff_array2.size(); i++)
			{
				buff_array2[i].Write(fostream);
			}
			cout << "Write completed!" << endl;
			fostream.close();
			break;
		}
		case 4:
		{
			// to read the array of Person records from the file
			ifstream fistream("DelimText.dat", ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return;
			}
			Student::InitBuffer(InBuff1);
			for (int i = 0; i < buff_array1.size(); i++)
			{
				buff_array1[i].Read(fistream);
				student_array[i].Unpack(buff_array1[i]);
				student_array[i].Print(cout);
			}
			CourseRegistration::InitBuffer(InBuff2);
			for (int i = 0; i < buff_array2.size(); i++)
			{
				buff_array2[i].Read(fistream);
				course_array[i].Unpack(buff_array2[i]);
				course_array[i].Print(cout);
			}
			fistream.close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
	}
}
*/
int main(void)
{
	testFixText ();
	//testLenText ();
	//testDelText();
	system("pause");
	return 1;
}
