#include "student.h"

//CONSTRUCTOR
Student::Student()
{
	(*this).studentID = "";
	(*this).firstName = "";
	(*this).lastName = "";
	(*this).emailAddress = "";
	(*this).age = 0;
	for (int i = 0; i < daysInCourse; i++) (*this).daysInCourseArray[i] = 0;
	(*this).degreeProgram = DegreeProgram::NONE;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourseArray[], DegreeProgram degreeProgram)
{
	(*this).studentID = studentID;
	(*this).firstName = firstName;
	(*this).lastName = lastName;
	(*this).emailAddress = emailAddress;
	(*this).age = age;
	for (int i = 0; i < daysInCourse; i++) (*this).daysInCourseArray[i] = daysInCourseArray[i];
	(*this).degreeProgram = degreeProgram;
}

Student::~Student() {} //DESTRUCTOR (NOTHING CREATED DYNAMICALLY)


string Student::getStudentID() { return studentID; }
string Student::getFirstName() { return firstName; }
string Student::getLastName() { return lastName; }
string Student::getEmailAddress() { return emailAddress; }
int Student::getAge() { return age; }
int* Student::getDaysInCourseArray() { return daysInCourseArray; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

void Student::setStudentID(string studentID) { studentID = studentID; }
void Student::setFirstName(string firstName) { firstName = firstName; }
void Student::setLastName(string lastName) { lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { emailAddress = emailAddress; }
void Student::setAge(int age) { age = age; }
void Student::setDaysInCourseArray(int daysInCourseArray[])
{
	for (int i = 0; i < daysInCourse; i++) daysInCourseArray[i] = daysInCourseArray[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { degreeProgram = degreeProgram; }

//PRINT HEADING
void Student::printHeader()
{
	//AWKWARD CODE FOR THE SAKE OF FORMATTING
	//I FELT ODD CODE WAS FORGIVABLE AS THE OUTPUT IS ALWAYS THE SAME
	cout << "Output format:\nID\tFIRST NAME\tLAST NAME\t" << std::left << std::setw(22) << "EMAIL ADDRESS\t" << "AGE\t" << std::left << std::setw(5) << "DAYS IN COURSE\t" << "DEGREE PROGRAM\n";
	cout << "-------------------------------------------------------------------------------------------------------\n";
}

//PRINT STUDENT INFORMATION
void Student::print()
{
	cout << getStudentID() << '\t'; //Using tab separated output and getters
	cout << std::left << std::setw(10) << getFirstName() << '\t';
	cout << std::left << std::setw(10) << getLastName() << '\t';
	cout << std::left << std::setw(20) << getEmailAddress() << '\t';
	cout << getAge() << '\t';
	cout << getDaysInCourseArray()[0] << ',';
	cout << getDaysInCourseArray()[1] << ',';
	cout << getDaysInCourseArray()[2] << '\t';
	cout << degreeProgramStrings[getDegreeProgram()] << '\n';
}