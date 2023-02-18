#pragma once
#include "student.h"

class Roster
{
public:
	int lastStudent = -1;
	const static int rosterSize = 5;
	Student* classRosterArray[rosterSize];

public:
	//PARSE, ADD, PRINTING, ETC
	void parse(string data);
	void add(string StudentID,
		string FirstName,
		string LastName,
		string EmailAddress,
		int StudentAge,
		int DaysInCourse1,
		int DaysInCourse2,
		int DaysInCourse3,
		DegreeProgram degreeprogram);
	void printAll();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	void remove(string studentID);
	DegreeProgram ToString(string eString);
	~Roster();
};