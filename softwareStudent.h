/*
Create the three following classes as subclasses of Student, using the files created in part B:
•   SecurityStudent
•   NetworkStudent
•   SoftwareStudent
Each subclass should override the getDegreeProgram() function. Each subclass should have a data member
to hold the enumerated type for the degree program using the types defined in part C.
*/
#pragma once
#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "student.h"

class SoftwareStudent : public Student
{
	using Student::Student;

public:
	virtual Degree getDegreeProgram() override;

private:
	Degree degreeType = SOFTWARE;

};


#endif // !SOFTWARESTUDENT_H


