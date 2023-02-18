#include "Roster.h"

int main()
{
	//STUDENT DATA TO BE PARSED
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Keith,Siefring,blank@yahoo.com,31,25,30,35,SOFTWARE"
	};

	const int rosterSize = 5;
	Roster classRoster; //INSTANCE OF ROSTER CLASS CREATED

	//OUTPUT OF ALL DATA FOR ALL STUDENTS
	for (int i = 0; i < rosterSize; i++) classRoster.parse(studentData[i]);//PARSING OF DATA IS CALLED, THIS IS WHERE THE PARSING ACTUALLY HAPPENS
	cout << "Displaying all students: " << std::endl;
	classRoster.printAll();
	cout << std::endl;

	//OUTPUT OF INVALID EMAILS
	cout << "Displaying students with invalid email addresses: " << std::endl;
	classRoster.printInvalidEmails();
	cout << std::endl;

	//OUTPUT OF AVERAGE DAYS IN COURSE
	cout << "Displaying average days to complete course: " << std::endl;
	for (int i = 0; i < rosterSize; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}

	//OUTPUT OF STUDENTS IN SOFTWARE DEGREE PROGRAM
	cout << "Displaying students in software degree program: " << std::endl;
	classRoster.printByDegreeProgram(SOFTWARE);

	//REMOVAL OF STUDENT
	cout << "Removing student with ID A3: " << std::endl;
	classRoster.remove("A3");
	cout << std::endl;

	//ATTEMPTED REMOVAL TO PROVE INITIAL REMOVAL HAPPENED
	cout << "Removing student with ID A3: " << std::endl;
	classRoster.remove("A3");
	cout << std::endl;

	system("pause");
	return 0;
}
