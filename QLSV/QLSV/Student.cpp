#include "Student.h"

Student::Student()
{
	_fullname = nullptr;
	_id		  = nullptr;
	_dob	  = nullptr;
	_marks    = nullptr;
}

Student::Student(const char*& fullname, const char*& id, const char*& dob, const double* marks)
{
	_fullname = new char[strlen(fullname) + 1];
	strcpy(_fullname, fullname);

	_id = new char[strlen(id) + 1];
	strcpy(_id, id);

	_dob = new char[strlen(dob) + 1];
	strcpy(_dob, dob);

	_marks = new double[3];
	for (int i = 0; i < 3; i++) {
		_marks[i] = marks[i];
	}
}

Student::Student(const Student& other)
{
	_fullname = new char[strlen(other._fullname) + 1];
	strcpy(_fullname, other._fullname);

	_id = new char[strlen(other._id) + 1];
	strcpy(_id, other._id);

	_dob = new char[strlen(other._dob) + 1];
	strcpy(_dob, other._dob);

	_marks = new double[3];
	for (int i = 0; i < 3; i++) {
		_marks[i] = other._marks[i];
	}
}

Student::~Student()
{
	delete[] _fullname;
	delete[] _id;
	delete[] _dob;
	delete[] _marks;
}

Student& Student::operator=(const Student& other)
{
	if (_fullname != nullptr) {
		delete[] _fullname;
		delete[] _id;
		delete[] _dob;
		delete[] _marks;
	}
	else if (this == &other) {
		return *this;
	}
	
	if (other._fullname != nullptr) {
		_fullname = new char[strlen(other._fullname) + 1];
		strcpy(_fullname, other._fullname);

		_id = new char[strlen(other._id) + 1];
		strcpy(_id, other._id);

		_dob = new char[strlen(other._dob) + 1];
		strcpy(_dob, other._dob);

		_marks = new double[3];
		for (int i = 0; i < 3; i++) {
			_marks[i] = other._marks[i];
		}
	}

	return *this;
}

Student Student::parse(const string& target)
{
	stringstream stream(target);
	string buffer;
	char delim = ',';

	Student result;
	
	getline(stream, buffer, delim);
	result._fullname = new char[buffer.length() + 1];
	strcpy(result._fullname, (char*)buffer.c_str());
	buffer.clear();
	

	getline(stream, buffer, delim);
	result._id = new char[buffer.length() + 1];
	strcpy(result._id, (char*)buffer.c_str());
	buffer.clear();
	
	getline(stream, buffer, delim);
	result._dob = new char[buffer.length() + 1];
	strcpy(result._dob, (char*)buffer.c_str());
	buffer.clear();
	
	result._marks = new double[3];
	for (int i = 0; i < 3; i++) {
		getline(stream, buffer, delim);
		result._marks[i] = stod(buffer);
		buffer.clear();
	}

	return result;
}

string Student::toString()
{
	stringstream builder;
	builder << "Student=[name=" << _fullname
		<< ", id=" << _id
		<< ", dob=" << _dob
		<< ", marks=[" << _marks[0] << ", " << _marks[1] << ", " << _marks[2]
		<< "]]";

	return builder.str();
}

string Student::toString(int)
{
	stringstream builder;
	builder << _fullname << "," << _id << "," << _dob
		<< "," << _marks[0] << "," << _marks[1] << "," << _marks[2];
	
	return builder.str();
}

char* Student::fullname()
{
	return _fullname;
}

char* Student::id()
{
	return _id;
}

char* Student::dob()
{
	return _dob;
}

double Student::stdAvg()
{
	double result = _marks[0] * 0.25 + _marks[1] * 0.25 + _marks[2] * 0.5;
	return result;
}

string Student::typeOfStudent()
{
	string result;
	double avg = this->stdAvg();

	if (8 <= avg) {
		result = "Gioi";
	}
	else if (7 <= avg && avg < 8){
		result = "Kha";
	}
	else if (5 <= avg && avg < 7) {
		result = "Trung binh";
	}
	else {
		result = "Yeu";
	}
	return result;
}
