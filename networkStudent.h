/*
Create the three following classes as subclasses of Student, using the files created in part B:
•   SecurityStudent
•   NetworkStudent
•   SoftwareStudent
Each subclass should override the getDegreeProgram() function. Each subclass should have a data member 
to hold the enumerated type for the degree program using the types defined in part C.
*/
#pragma once
#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h"

using namespace std;

class NetworkStudent : public Student {
	using Student::Student;
public:

	virtual Degree getDegreeProgram() override;

private:
	//Student networkStudent;
	Degree degreeType = NETWORK;
};

#endif // !NETWORKSTUDENT_H

