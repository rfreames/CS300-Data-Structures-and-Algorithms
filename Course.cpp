/*
Ryan Reames
CS-300-T5598
6/16/2022
*/

#include "Course.h"
#include <iostream>

using namespace std;

// This class holds information for a single course, including number, name, prerequisites, and prerequisite count

Course::Course() {
	this->prereqCount = 0;
}

void Course::setCourseNumber(string cNumber) {
	this->courseNumber = cNumber;
}
void Course::setCourseName(string cName) {
	this->courseName = cName;
}
void Course::setCoursePrereq(string cPrereq) {
	this->coursePrereq.push_back(cPrereq);
}
void Course::setPrereqCount() {
	this->prereqCount = coursePrereq.size();
}
string Course::getCourseNumber() {
	return courseNumber;
}
string Course::getCourseName() {
	return courseName;
}
void Course::getCoursePrereq() {
	string prereqs;
	// Prints prereqs with comma following if there is an additional prereq afterwards, otherwise prints new line
	for (int i = 0; i < (coursePrereq.size()); i++) {
		if (i == (coursePrereq.size() - 1)) {
			cout << coursePrereq.at(i) << endl;
		}
		else {
			cout << coursePrereq.at(i) << ", ";
		}
	}
}
int Course::getPrereqCount() {
	return prereqCount;
}

void Course::deletePrereqs() {
	coursePrereq.clear(); // Used when looping through and reusing tempCourse value in BinarySearchTree
}

void Course::toString() {
	cout << courseNumber << ", " << courseName << ", "; 
	getCoursePrereq();
}