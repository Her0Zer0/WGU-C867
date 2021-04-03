/*
Demonstrate the program’s required functionality by adding a void main() function to roster.cpp, 
	which will contain the required function calls to achieve the following results:
1.  Print out to the screen, via your application, the course title, the programming language used,	
	your student ID, and your name.
2.  Create an instance of the Roster class called classRoster.
3.  Add each student to classRoster.
4.  Convert the following pseudo code to complete the rest of the main() function:
	classRoster.printAll();
	classRoster.printInvalidEmails();
loop through classRosterArray and for each element:
	classRoster.printAverageDaysInCourse(<current_object's student id>);
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");
	expected: the above line should print a message saying such a student with this ID was not found.
5.  Call the destructor to release the Roster memory.
*/

#include "pch.h"
#include <iostream>
#include <string>
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"
using namespace std;

//Modify the studentData table to include your personal information as the last item.
const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Robert,Smith,rsmi342@my.wgu.edu,37,23,32,45,SOFTWARE"
};

bool emailIsValid(string email) {
	//check if @ is greater than the beginning of the string and less than the end if returned
	bool checkForAt = (email.find('@') > 0 && email.find('@') < email.length()) ? true : false;
	//check if . is greater than the beginning of the string and less than the end if returned
	bool checkForPeriod = (email.find('.') > 0 && email.find('.') < email.length()) ? true : false;
	//check if ' ' is greater than the beginning of the string and less than the end if returned
	bool checkForSpace = (email.find(' ') > 0 && email.find(' ') < email.length()) ? true : false;
	//if @ is true, . is true, and ' ' is not true, it is a good email
	return (checkForAt && checkForPeriod && !checkForSpace  ? true : false);
}

int main()
{
	//1.  Print out to the screen, via your application, the course title, the programming language used, your student ID, and your name.
	cout << "Scripting and Programming-Applications-C867\t" << "Language: C++\t" << "StudentID: 000588816\t" << "Name: Robert Smith" << endl << endl;
	//2.  Create an instance of the Roster class called classRoster.
	Roster classRoster;
	Degree degree;


	//get data array size
	int sizeOfStudentDataArray = sizeof(studentData) / sizeof(studentData[0]);


	for (int i = 0; i < sizeOfStudentDataArray; ++i) {
		//loop through the string and seperate by comma
		string tempArray[9] = {}, token = "";
		int k = 0;
		
		for (int j = 0; j < studentData[i].length(); ++j) {

			
			//if char is equal to comma 
			//push to the tempArray and clear token
			if (studentData[i][j] == ',') {
				tempArray[k] = token;
				//clean token
				token = "";
				//iterate for the next push
				k++;
				continue;
			}

			//if char not equal to comma
			//store in token, then continue
			if (studentData[i][j] != ',') {
				token += studentData[i][j];
				
			}
			//one last push before we go
			if (j < studentData[i].length()) {
				tempArray[k] = token;
				
			}
			

		}//j for loop
		
		if (tempArray[8] == "NETWORK") {
			degree = NETWORK;
		}
		else if (tempArray[8]=="SECURITY") {
			degree = SECURITY;
		}
		else if (tempArray[8]=="SOFTWARE") {
			degree = SOFTWARE;
		}
		else {
			degree = UNKNOWN;
		}
		//add the student to the roster
		classRoster.add(tempArray[0], tempArray[1], tempArray[2], tempArray[3],(stoi(tempArray[4])), (stoi(tempArray[5])),(stoi(tempArray[6])), (stoi(tempArray[7])), degree);
	}//i for loop
	
	
	classRoster.printAll();
	
	cout << endl << endl;

	classRoster.printInvalidEmails();
	//loop through classRosterArray and for each element:
	//classRoster.printAverageDaysInCourse(/*current_object's student id*/);
	cout << endl << endl;

	int tempSize = classRoster.getRosterSize();
	cout << "Student ID:\tAvg. Days in Course:" << endl;

	for (int i = 0; i < tempSize; ++i) {
		classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getId());
	}

	

	cout << endl << endl;
	classRoster.printByDegreeProgram(SOFTWARE);

	cout << endl << endl;
	classRoster.remove("A3");

	cout << endl << endl;
	classRoster.remove("A3");
	//expected: the above line should print a message saying such a student with this ID was not found.
	cout << endl << endl;
	classRoster.~Roster();
	
	return 0;

}//end of main() function


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree deg) {

	int days[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
	//int sizeOfRoster = sizeof(classRosterArray) / sizeof(classRosterArray[0]);

	for (int i = 0; i < sizeOfRoster; ++i) {//loop through and find containers to fill
		//cout << deg << endl;

		if (classRosterArray[i] == nullptr) {//if we equal null, fill it with someting
			switch (deg) {
			case SOFTWARE:
				classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, days, deg);
				break;
			case SECURITY:
				classRosterArray[i] = new SecurityStudent(studentID, firstName,lastName, emailAddress, age, days, deg);
				break;
			case NETWORK:
				classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, days, deg);
				break;
			case UNKNOWN: //this one should never happen but just in case
				classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, days, deg);
				break;
			}//end switch
			break;//break out if needed, otherwise we could overwrite our work
		}//end nullptr check
	}//end roster loop

}//end of add function


void Roster::printAll() {
	//cout << this->getId() << tab <<setw(15)<< this->getFirstName() << tab << setw(15) << this->getLastName() << tab << setw(15) << this->getEmail() << tab << setw(15) << this->getAge() << tab << setw(15) << p[0] << "," << p[1] << "," << p[2] << tab << setw(15) << tempVal << endl;
	cout << "Student ID\t" << "First Name\t" << "Last Name\t" << "Email Address\t" << "\tAge\t" << "Days In Course\t" << "Degree" << endl;
	for (int i = 0; i < sizeOfRoster; ++i) {
		//if container is full, print.
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
	cout << left;
}//end of printAll function


void Roster::printInvalidEmails() {
	cout << "Student ID:\tInvalid EmailAddress:" << endl;

	for (int i = 0; i < sizeOfRoster; ++i) {
		if (classRosterArray[i] != nullptr) {
			//print results that come back as not true
			if (!emailIsValid(classRosterArray[i]->getEmail())) {
				cout << setw(8) << classRosterArray[i]->getId() << "\t" << setw(25) << classRosterArray[i]->getEmail()<<endl;
			}
					
		}
		else {
			cout << "Your search returned no results. " << endl;
		}
	}
	cout << left;
}

void Roster::printDaysInCourse(string studentID) {

	
	for (int i = 0; i < sizeOfRoster; ++i) {

		if (classRosterArray[i]->getId() == studentID) {
			cout << setw(8) << classRosterArray[i]->getId() << "\t\t" << classRosterArray[i]->getDaysInCourse()[0]<<","<<classRosterArray[i]->getDaysInCourse()[1]<<","<<classRosterArray[i]->getDaysInCourse()[2] << endl;
		}

	}
	cout << left;
}

void Roster::printByDegreeProgram(int deg) {

	cout << "Results Students By Degree: " << endl;
	for (int i = 0; i < sizeOfRoster; ++i) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getDegreeProgram() == deg) {
				classRosterArray[i]->print();
			}
		}
		
	}
	cout << left;
}

void Roster::remove(string studentID) {
	bool studentExist = false;

	for (int i = 0; i < sizeOfRoster; ++i) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getId() == studentID) {
			classRosterArray[i] = nullptr;
			studentExist = true;
			break;
		}
	}

	if (studentExist) {
		cout << "Record for Student ID " << studentID << " has been removed successfully." << endl;
	}
	else {
		cout << "Error 12345: Student ID " << studentID << " wasn't found.  Please check the spelling and try again." << endl;
	}
}
