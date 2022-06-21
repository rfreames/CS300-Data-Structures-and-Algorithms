/*
Ryan Reames
CS-300-T5598
6/16/2022
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "Course.h"

// Internal structure for tree node, taken from module five assignment
struct Node {
	Course course;
	Node* left;
	Node* right;

	Node() {
		left = nullptr;
		right = nullptr;
	}

	Node(Course aCourse) : Node() {
		course = aCourse;
	}
};

// Class declarations used in BinarySearchTree.cpp
class BinarySearchTree {

public:
	BinarySearchTree();
	void getFileData(string fileName);
	void Insert(Course newCourse);
	void findCourseInformation(string courseNumber);
	void printSampleSchedule();

private:
	Node* root;
	vector<Node> courses;
	void addNode(Node* courses, Course newCourse);
	void printCourseInformation(Node* courses, string courseNumber);
	void printAllCourses(Node* courses);

};

#endif // !BINARYSEARCHTREE_H
