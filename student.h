/*
For the Student class, do the following:
Create the base class Student in the files student.h and student.cpp, which includes each  of the following variables:
•   student ID
•   first name
•   last name
•   email address
•   age
•   array of number of days to complete each course
•   degree types
Note: Degree type should be populated in subclasses only.

Create each of the following functions in the Student class:
a.  an accessor (i.e., getter) for each  instance variable from part D1
b.  a mutator (i.e., setter) for each instance variable from part D1
Note: All access and changes to the instance variables of the Student class should be done through the accessor and mutator functions.
c.  constructor using all  of the input parameters provided in the table
d.  virtual print() to print specific student data
e.  destructor
f.  virtual getDegreeProgram()
Note: Leave the implementation of the getDegreeProgram() function empty.
*/

#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
using namespace std;


class Student {

private:
	string studentId{}, firstName{}, lastName{}, emailAddress{};
	int age{}, daysInCourse[3];
	Degree degreeType;

public:
	//default constructor
	Student();
	//constructor
	Student(string, string, string, string, int, int days[], Degree);
	//deconstructor
	~Student();
	//Set student id
	void setId(string);
	//Set first name
	void setFirstName(string);
	//Set last name
	void setLastName(string);
	//Set Email 
	void setEmail(string);
	//Set Age
	void setAge(int);
	//Set Number of days to complete each course
	void setDaysInCourse(int days[]);
	//Set Degree
	void setDegree(Degree);

	string getId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int *getDaysInCourse();
	
	virtual void print() {
		string tab = "\t";
		int *p = this->getDaysInCourse();
		string tempVal{};

		if (this->getDegreeProgram() == NETWORK) {
			tempVal = "NETWORK";
		}
		else if (this->getDegreeProgram() == SECURITY) {
			tempVal = "SECURITY";
		}else if(this->getDegreeProgram() == SOFTWARE){
			tempVal = "SOFTWARE";
		}
		else {
			tempVal = "UNKNOWN";
		}
		cout << this->getId() << tab <<setw(15)<< this->getFirstName() << tab << setw(15) << this->getLastName() << tab << setw(25) << this->getEmail() << tab << setw(2) << this->getAge() << tab << p[0] << "," << p[1] << "," << p[2] << tab << setw(8) << tempVal <<endl;
	}
	virtual Degree getDegreeProgram();
};
#endif
