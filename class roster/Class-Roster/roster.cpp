#include "roster.h" 
#include <vector>
#include <sstream>

//USED TO CHANGE PARSED DATA FROM STRING TO ENUM VALUES
DegreeProgram Roster::ToString(string eString) {
	if (eString == "SECURITY") return SECURITY;
	else if (eString == "NETWORK") return NETWORK;
	else if (eString == "SOFTWARE") return SOFTWARE;
	else return NONE;
}

//PARSE AND ADD
void Roster::parse(string data)
{
	std::vector<string> parsedData;
	std::stringstream sStream(data);
	while (sStream.good())
	{
		string substr;
		getline(sStream, substr, ',');
		parsedData.push_back(substr);
	}

	add(parsedData.at(0), parsedData.at(1), parsedData.at(2), parsedData.at(3), stoi(parsedData.at(4)), stoi(parsedData.at(5)), stoi(parsedData.at(6)), stoi(parsedData.at(7)), ToString(parsedData.at(8)));
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int dArray[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };
	classRosterArray[++lastStudent] = new Student(studentID, firstName, lastName, emailAddress, age, dArray, degreeProgram);
}

//DISPLAY DATA WITH TAB SEPARATED OUTPUT
void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastStudent; i++)
	{
		classRosterArray[i]->print();
	}
}

//PRINT BY DEGREE PROGRAM
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastStudent; i++)
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << std::endl;
}

//PRINT INVALID EMAILS
//EMAIL MUST CONTAIN '@' AND '.' EMAIL MUST NOT CONTAIN ANY SPACES
void Roster::printInvalidEmails()
{
	bool any = true;
	for (int i = 0; i <= Roster::lastStudent; i++)
	{
		string eAddress = (classRosterArray[i]->getEmailAddress());
		if ((eAddress.find('@') == string::npos) || (eAddress.find('.') == string::npos) || !(eAddress.find(' ') == string::npos))
		{
			any = false;
			cout << eAddress << ": " << classRosterArray[i]->getFirstName() << std::endl;
		}
	}
	if (any) cout << "NONE" << std::endl;
}

//PRINT AVERAGE DAYS IN COURSE
void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastStudent; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			cout << studentID << ":";
			cout << (classRosterArray[i]->getDaysInCourseArray()[0] +
				classRosterArray[i]->getDaysInCourseArray()[1] +
				classRosterArray[i]->getDaysInCourseArray()[2]) / 3.0 << std::endl;
		}
	}
	cout << std::endl;
}

//REMOVE STUDENT BY ID
void Roster::remove(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastStudent; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			success = true;
			if (i < rosterSize - 1)
			{
				Student* temp = classRosterArray[i];/*swap it with last book*/
				classRosterArray[i] = classRosterArray[rosterSize - 1];
				classRosterArray[rosterSize - 1] = temp;
			}
			Roster::lastStudent--;
		}
	}
	if (success)
	{
		cout << studentID << " removed from roster." << std::endl << std::endl;
		(*this).printAll();
	}
	else cout << studentID << " such a student with this ID was not found." << std::endl << std::endl;
}


//DESTRUCTOR
Roster::~Roster()
{
	cout << "Destruction of student data imminent." << std::endl << std::endl;
	for (int i = 0; i < rosterSize; i++)
	{
		cout << "Destroying student " << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}