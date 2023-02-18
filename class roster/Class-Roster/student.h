#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
public:
	const static int daysInCourse = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourseArray[daysInCourse];
	DegreeProgram degreeProgram;
public:
	//CONSTRUCTOR & DESTRUCTOR
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourseArray[], DegreeProgram degreeProgram);/*full constructor*/
	~Student();

	//GETTERS
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourseArray();
	DegreeProgram getDegreeProgram();

	//SETTERS
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourseArray(int daysInCourseArray[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//METHODS
	static void printHeader();
	void print();
};