#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef STUDENT
#define STUDENT
#include <iostream>
#include "DelimTextBuffer.h"
#include "LengthTextBuffer.h"
#include "FixedTextBuffer.h"
class Student
{
public:
	char Identifier[10]; char Name[11]; char Address[16];
	char DateOfFirstEnrollment[11]; int NumberOfCreditHours;
public:
	Student();
	Student& operator=(Student& s);
	void modify();
	void increaseNumberOfCreditHours(int hours);
	friend std::istream& operator >> (std::istream& stream, Student& s);
	friend std::ostream& operator << (std::ostream& stream, Student& s);
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