#pragma once
#include "utils.h"

class Student
{
private:
	char* _fullname;
	char* _id;
	char* _dob;
	double* _marks;

public:
	Student();
	Student(const char*&, const char*&, const char*&, const double*);
	Student(const Student&);
	~Student();

public:
	Student& operator=(const Student&);

public:
	static Student parse(const string&);

public: 
	string toString();
	string toString(int);

public:
	// Cac getter
	char* fullname();
	char* id();
	char* dob();
	double stdAvg();
	string typeOfStudent();
};