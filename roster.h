/*
Create a Roster class (roster.cpp) by doing the following:
1.  Create an array of pointers, classRosterArray, to hold the data provided in the studentData table.
2.  Create a student object for each  student in the data table by using the subclasses NetworkStudent,
	SecurityStudent, and SoftwareStudent, and populate classRosterArray.
a.  Apply pointer operations when parsing each  set of data identified in the studentData table.
b.  Add each student object to classRosterArray.
3.  Define the following functions:
a.  public void add(string studentID, string firstName, string lastName, string emailAddress, 
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, < degree program >) that sets 
	the instance variables from part D1 and updates the roster.
b.  public void remove(string studentID) that removes students from the roster by student ID. If the 
	student ID does not exist, the function prints an error message indicating that the student was not found.
c.  public void printAll() that prints a complete tab-separated list of student data using accessor 
	functions with the provided format: 1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 
	[tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through 
	all  the students in classRosterArray and call the print() function for each student.
d.  public void printDaysInCourse(string studentID) that correctly prints a student’s average number 
	of days in the three courses. The student is identified by the studentID parameter.
e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid 
	email addresses to the user
Note: A valid email should include an at sign ('@') and period ('.') and should not include a space 
(' ').
f.  public void printByDegreeProgram(int degreeProgram) that prints out student information for a degree
	program specified by an enumerated type
*/
#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"

class Roster {
public:
	Student * classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree deg);
	void remove(string studentID);
	void printAll();
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int deg);
	int getRosterSize() {
		return sizeOfRoster;
	}
	~Roster() {
		//destruction is on it's way
	}
private:
	int sizeOfRoster = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
};

#endif // !ROSTER_H

