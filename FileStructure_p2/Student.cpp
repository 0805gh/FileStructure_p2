#include "Student.h"
#include <iostream>
using namespace std;

Student::Student()
{
	Clear();
}

void Student::Clear() 
{
	Identifier[0] = 0; Name[0] = 0; Address[0] = 0;
	DateOfFirstEnrollment[0] = 0; NumberOfCreditHours = 0;
}
int Student::InitBuffer(FixedTextBuffer& Buffer)
{
	int result;
	result = Buffer.AddField(10);
	result = result && Buffer.AddField(11);
	result = result && Buffer.AddField(16);
	result = result && Buffer.AddField(11);
	result = result && Buffer.AddField(10);
	return result;
}
int Student::Unpack(FixedTextBuffer& Buffer)
{
	int result; char num[10];
	sprintf(num, "%d", NumberOfCreditHours);
	Buffer.Clear();
	result = Buffer.Unpack(Identifier);
	result = result && Buffer.Unpack(Name);
	result = result && Buffer.Unpack(Address);
	result = result && Buffer.Unpack(DateOfFirstEnrollment);
	result = result && Buffer.Unpack(num);
	return result;
}
int Student::Pack(FixedTextBuffer& Buffer) const
{
	int result; char num[10];
	sprintf(num, "%d", NumberOfCreditHours);
	Buffer.Clear();
	result = Buffer.Pack(Identifier);
	result = result && Buffer.Pack(Name);
	result = result && Buffer.Pack(Address);
	result = result && Buffer.Pack(DateOfFirstEnrollment);
	result = result && Buffer.Pack(num);
	return result;
}
int Student::InitBuffer(LengthTextBuffer& Buffer)
{
	return TRUE;
}
int Student::Unpack(LengthTextBuffer& Buffer)
{
	int result; char num[10];
	sprintf(num, "%d", NumberOfCreditHours);
	result = Buffer.Unpack(Identifier);
	result = result && Buffer.Unpack(Name);
	result = result && Buffer.Unpack(Address);
	result = result && Buffer.Unpack(DateOfFirstEnrollment);
	result = result && Buffer.Unpack(num);
	return result;
}
int Student::Pack(LengthTextBuffer& Buffer) const
{
	int result; char num[10];
	sprintf(num, "%d", NumberOfCreditHours);
	Buffer.Clear();
	result = Buffer.Pack(Identifier);
	result = result && Buffer.Pack(Name);
	result = result && Buffer.Pack(Address);
	result = result && Buffer.Pack(DateOfFirstEnrollment);
	result = result && Buffer.Pack(num);
	return result;
}
int Student::InitBuffer(DelimTextBuffer& Buffer)
{
	return TRUE;
}
int Student::Unpack(DelimTextBuffer& Buffer)
{
	int result; char num[10];
	sprintf(num, "%d", NumberOfCreditHours);
	result = Buffer.Unpack(Identifier);
	result = result && Buffer.Unpack(Name);
	result = result && Buffer.Unpack(Address);
	result = result && Buffer.Unpack(DateOfFirstEnrollment);
	result = result && Buffer.Unpack(num);
	return result;
}
int Student::Pack(DelimTextBuffer& Buffer) const
{
	int result; char num[10];
	sprintf(num, "%d", NumberOfCreditHours);
	Buffer.Clear();
	result = Buffer.Pack(Identifier);
	result = result && Buffer.Pack(Name);
	result = result && Buffer.Pack(Address);
	result = result && Buffer.Pack(DateOfFirstEnrollment);
	result = result && Buffer.Pack(num);
	return result;
}
void Student::Print(std::ostream& stream)
{
	stream << "Student:\n"
		<< "\t Identifier '" << Identifier << "'\n"
		<< "\t Name '" << Name << "'\n"
		<< "\t Address '" << Address << "\n"
		<< "\t Date Of First Enrollment '" << DateOfFirstEnrollment << "'\n" 
		<< "\t Number of Credit Hours '" << NumberOfCreditHours << "'\n" << flush;
}

Student& Student::operator=(Student& s) {
	if (this == &s) return *this;
	delete[] Identifier;
	delete[] Name;
	delete[] Address;
	delete[] DateOfFirstEnrollment;
	NumberOfCreditHours = s.NumberOfCreditHours;
	strcpy(Identifier, s.Identifier);
	strcpy(Name, s.Name);
	strcpy(Address, s.Address);
	strcpy(DateOfFirstEnrollment, s.DateOfFirstEnrollment);
	return *this;
}

void Student::modify() {
	int num;
	cout << "Enter the number : " << endl;
	cin >> num;
	switch (num) {
	case 1:
	{
		char id[10];
		cout << "Enter the new Identifier : " << endl;
		cin >> id;
		delete[] Identifier;
		strcpy(Identifier, id);
		break;
	}
	case 2:
	{
		char name[11];
		cout << "Enter the new Name : " << endl;
		cin >> name;
		delete[] Name;
		strcpy(Name, name);
		break;
	}
	case 3:
	{
		char ad[16];
		cout << "Enter the new Address : " << endl;
		cin >> ad;
		delete[] Address;
		strcpy(Address, ad);
		break;
	}
	case 4:
	{
		char date[11];
		cout << "Enter the new Date Of First Enrollment : " << endl;
		cin >> date;
		delete[] DateOfFirstEnrollment;
		strcpy(DateOfFirstEnrollment, date);
		break;
	}
	case 5:
	{
		cout << "Enter the new Number Of Credit Hours : " << endl;
		cin >> NumberOfCreditHours;
		break;
	}
	}
}

void Student::increaseNumberOfCreditHours(int hours)
{
	NumberOfCreditHours += hours;
}
