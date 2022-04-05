#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef COURSEREGISTRATION
#define COURSEREGISTRATION
#include <iostream>
#include "DelimTextBuffer.h"
#include "LengthTextBuffer.h"
#include "FixedTextBuffer.h"
class CourseRegistration
{
public:
	char CourseIdentifier[20]; char StudentIdentifier[20][20];
	int NumberOfCreditHours; float CourseGrade; int StudentNum;
public:
	CourseRegistration();
	CourseRegistration& operator=(CourseRegistration& c);
	friend std::istream& operator >> (std::istream& stream, CourseRegistration& c);
	friend std::ostream& operator << (std::ostream& stream, CourseRegistration& c);
	void Clear();
	static int InitBuffer(FixedTextBuffer& Buffer);
	int Unpack(FixedTextBuffer& Buffer);
	int Pack(FixedTextBuffer& Buffer) const;
	static int InitBuffer(LengthTextBuffer& Buffer);
	int Unpack(LengthTextBuffer& Buffer);
	int Pack(LengthTextBuffer& Buffer) const;
	static int InitBuffer(DelimTextBuffer& Buffer);
	int Unpack(DelimTextBuffer& Buffer);
	int Pack(DelimTextBuffer& Buffer) const;
	void Print(std::ostream& stream);
};
#endif
