#include "pch.h"
#include "student.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student() {

}

Student::Student(string id,string fname,string lname,string email,int age,int days[],Degree deg) {
	studentId = id;
	firstName = fname;
	lastName = lname;
	emailAddress = email;
	this->age = age;
	setDaysInCourse(days);
	setDegree(deg);
}

Student::~Student() {
	//destructicons transform
}

void Student::setId(string id) {
	studentId = id;
}

void Student::setFirstName(string fname) {
	firstName = fname;
}

void Student::setLastName(string lname) {
	lastName = lname;
}

void Student::setEmail(string email) {
	emailAddress = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysInCourse(int days[]) {
	for (int i = 0; i < 3; ++i) {
		daysInCourse[i] = days[i];
	}
	
}

void Student::setDegree(Degree deg) {
	degreeType = deg;

}

string Student::getId() {
	return studentId;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmail() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int *Student::getDaysInCourse() {

	return daysInCourse;
}

Degree Student::getDegreeProgram() {
	return degreeType;
};