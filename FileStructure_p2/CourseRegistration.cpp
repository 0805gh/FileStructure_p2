#include "CourseRegistration.h"
CourseRegistration::CourseRegistration()
{
	Clear();
}

CourseRegistration& CourseRegistration::operator=(CourseRegistration& c) {
	if (this == &c) return *this;
	delete[] CourseIdentifier;
	delete[] StudentIdentifier;
	NumberOfCreditHours = c.NumberOfCreditHours;
	CourseGrade = c.CourseGrade;
	strcpy(CourseIdentifier, c.CourseIdentifier);
	for (int i = 0; i < c.StudentNum; i++) {
		strcpy(StudentIdentifier[i], c.StudentIdentifier[i]);
	}
	return *this;
}

void CourseRegistration::Clear()
{
	CourseIdentifier[0] = 0; StudentIdentifier[0][0] = 0;
	NumberOfCreditHours = 0; CourseGrade = 0.0f; StudentNum = 0;
}
int CourseRegistration::InitBuffer(FixedTextBuffer& Buffer)
{
	int result;
	result = Buffer.AddField(20);
	result = result && Buffer.AddField(400);
	result = result && Buffer.AddField(10);
	result = result && Buffer.AddField(10);
	result = result && Buffer.AddField(10);
	return result;
}
int CourseRegistration::Unpack(FixedTextBuffer& Buffer)
{
	int result; char hours[10]; char grade[10]; char num[10];
	sprintf(hours, "%d", NumberOfCreditHours);
	sprintf(grade, "%.2f", CourseGrade);
	sprintf(num, "%d", StudentNum);
	Buffer.Clear();
	result = Buffer.Unpack(CourseIdentifier);
	for (int i = 0; i < StudentNum; i++) {
		result = result && Buffer.Unpack(StudentIdentifier[i]);
	}
	result = result && Buffer.Unpack(hours);
	result = result && Buffer.Unpack(grade);
	result = result && Buffer.Unpack(num);
	return result;
}
int CourseRegistration::Pack(FixedTextBuffer& Buffer) const
{
	int result; char hours[10]; char grade[10]; char num[10];
	sprintf(hours, "%d", NumberOfCreditHours);
	sprintf(grade, "%.2f", CourseGrade);
	sprintf(num, "%d", StudentNum);
	Buffer.Clear();
	result = Buffer.Pack(CourseIdentifier);
	for (int i = 0; i < StudentNum; i++) {
		result = result && Buffer.Pack(StudentIdentifier[i]);
	}
	result = result && Buffer.Pack(hours);
	result = result && Buffer.Pack(grade);
	result = result && Buffer.Pack(num);
	return result;
}
int CourseRegistration::InitBuffer(LengthTextBuffer& Buffer)
{
	return TRUE;
}
int CourseRegistration::Unpack(LengthTextBuffer& Buffer)
{
	int result; char hours[10]; char grade[10]; char num[10];
	sprintf(hours, "%d", NumberOfCreditHours);
	sprintf(grade, "%.2f", CourseGrade);
	sprintf(num, "%d", StudentNum);
	result = Buffer.Unpack(CourseIdentifier);
	for (int i = 0; i < StudentNum; i++) {
		result = result && Buffer.Unpack(StudentIdentifier[i]);
	}
	result = result && Buffer.Unpack(hours);
	result = result && Buffer.Unpack(grade);
	result = result && Buffer.Unpack(num);
	return result;
}
int CourseRegistration::Pack(LengthTextBuffer& Buffer) const
{
	int result; char hours[10]; char grade[10]; char num[10];
	sprintf(hours, "%d", NumberOfCreditHours);
	sprintf(grade, "%.2f", CourseGrade);
	sprintf(num, "%d", StudentNum);
	Buffer.Clear();
	result = Buffer.Pack(CourseIdentifier);
	for (int i = 0; i < StudentNum; i++) {
		result = result && Buffer.Pack(StudentIdentifier[i]);
	}
	result = result && Buffer.Pack(hours);
	result = result && Buffer.Pack(grade);
	result = result && Buffer.Pack(num);
	return result;
}
int CourseRegistration::InitBuffer(DelimTextBuffer& Buffer)
{
	return TRUE;
}
int CourseRegistration::Unpack(DelimTextBuffer& Buffer)
{
	int result; char hours[10]; char grade[10]; char num[10];
	sprintf(hours, "%d", NumberOfCreditHours);
	sprintf(grade, "%.2f", CourseGrade);
	sprintf(num, "%d", StudentNum);
	result = Buffer.Unpack(CourseIdentifier);
	for (int i = 0; i < StudentNum; i++) {
		result = result && Buffer.Unpack(StudentIdentifier[i]);
	}
	result = result && Buffer.Unpack(hours);
	result = result && Buffer.Unpack(grade);
	result = result && Buffer.Unpack(num);
	return result;
}
int CourseRegistration::Pack(DelimTextBuffer& Buffer) const
{
	int result; char hours[10]; char grade[10]; char num[10];
	sprintf(hours, "%d", NumberOfCreditHours);
	sprintf(grade, "%.2f", CourseGrade);
	sprintf(num, "%d", StudentNum);
	Buffer.Clear();
	result = Buffer.Pack(CourseIdentifier);
	for (int i = 0; i < StudentNum; i++) {
		result = result && Buffer.Pack(StudentIdentifier[i]);
	}
	result = result && Buffer.Pack(hours);
	result = result && Buffer.Pack(grade);
	result = result && Buffer.Pack(num);
	return result;
}
void CourseRegistration::Print(std::ostream& stream)
{
	stream << "Course Registration:\n"
		<< "\t Course Identifier '" << CourseIdentifier << "'\n"
		<< "\t Student Identifier '";
	for (int i = 0; i < StudentNum; i++) {
		if(i == StudentNum-1)
			stream << StudentIdentifier[i];
		else
			stream << StudentIdentifier[i] << " ";
	}
	stream << "'\n\t Number of Credit Hours '" << NumberOfCreditHours << "'\n"
		<< "\t Course Grade '" << CourseGrade << "'\n" << flush;
}
