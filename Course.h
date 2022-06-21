/*
Ryan Reames
CS-300-T5598
6/16/2022
*/

// This file includes all declarations for the Course class

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

using namespace std;

class Course {
private:
	string courseNumber, courseName;
	vector<string> coursePrereq;
	int prereqCount = 0;

public:
	Course();
	void setCourseNumber(string cNumber);
	void setCourseName(string cName);
	void setCoursePrereq(string cPrereq);
	void setPrereqCount();
	string getCourseNumber();
	string getCourseName();
	void getCoursePrereq();
	int getPrereqCount();
	void deletePrereqs();
	void toString();
};
#endif // !COURSE_H
