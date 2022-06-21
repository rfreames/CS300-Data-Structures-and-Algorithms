/*
Ryan Reames
CS-300-T5598
6/16/2022
*/

// This class is used to get comma separated course values from a file and input them into a binary search tree.
// The class can print information for a single course or print a sample course schedule in alphanumeric order.

#include <fstream>
#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}

// Public function to use addNode
void BinarySearchTree::Insert(Course newCourse) {
	// Used only for first value added to tree.
	if (root == nullptr) {
		root = new Node(newCourse);
	}
	else {
		this->addNode(root, newCourse);
	}
}

// Public function to use printCourseInformation
void BinarySearchTree::findCourseInformation(string courseNumber) {
	printCourseInformation(root, courseNumber);
}

// Public function to use printAllCourses
void BinarySearchTree::printSampleSchedule() {
	printAllCourses(root);
}

// Loads data from file and loads into tree
void BinarySearchTree::getFileData(string fileName) {
	string tempParam;
	vector<string> tempAllLines, loopCourseValues, courseNames;
	Course tempCourse;
	ifstream inFS;
	int paramCount = 0;

	// Attempt to open file and throw error if unable to open.
	try {
		inFS.open(fileName);
		if (inFS.fail()) {
			throw runtime_error("Unable to open file " + fileName);
		}
	}
	catch (runtime_error& excpt){
		cout << excpt.what() << endl;
		exit(0);
	}

	// Text file provided is different encoding - this clears extra symbols at start of file
	inFS.get();
	inFS.get();
	inFS.get();

	// Adds each individual line to tempAllLines vector as separate objects
	while (getline(inFS, tempParam)) {
		tempAllLines.push_back(tempParam);
	}

	// Loops through each object in tempAllLines
	for (int i = 0; i < tempAllLines.size(); i++) {
		// Splits objects based on commas and adds to loopCourseValues
		while (tempAllLines.at(i).find(',') != 0) {
			if (tempAllLines.at(i).length() == 0) {
				break;
			}
			// Sets tempParam string to substring of each temp object, then pushes back to loopCourseValues
			tempParam = tempAllLines.at(i).substr(0, tempAllLines.at(i).find(','));
			loopCourseValues.push_back(tempParam);
			// Value that was used is removed from temp
			tempAllLines.at(i).erase(0, tempParam.length());
			// Reassigns tempAllLines object to continue after most recently found comma
			tempAllLines.at(i) = tempAllLines.at(i).substr((tempAllLines.at(i).find(',') + 1), tempAllLines.at(i).length());
		};
		// Sets tempCourse parameters based on location of strings in loopCourseValues vector
		tempCourse.setCourseNumber(loopCourseValues.at(0));
		tempCourse.setCourseName(loopCourseValues.at(1));
		if (loopCourseValues.size() > 2) { // Prereq loop
			for (int j = 2; j < loopCourseValues.size(); j++) {
				tempCourse.setCoursePrereq(loopCourseValues.at(j));
			}
		}
		loopCourseValues.clear(); // Used for next string object in tempAllLines
		tempCourse.setPrereqCount();
		Insert(tempCourse); // Adds tempCourse to tree
		tempCourse.deletePrereqs(); // Resets prereq counter
	}
	cout << "Loaded " << tempAllLines.size() << " courses.\n" << endl;
}

// Adds objects to tree structure
void BinarySearchTree::addNode(Node* courses, Course newCourse) {
	Node* current = courses; // Used for root node when called by Insert function

	// Determines whether course is greater or less than current node assigns to tree when finding null pointer
	while (current != nullptr) {
		if (current->course.getCourseNumber().compare(newCourse.getCourseNumber()) > 0) {
			if (current->left == nullptr) {
				current->left = new Node(newCourse);
				return;
			}
			else {
				current = current->left;
			}
		}
		else {
			if (current->right == nullptr) {
				current->right = new Node(newCourse);
				return;
			}
			else {
				current = current->right;
			}
		}
	}
	current->left = nullptr;
	current->right = nullptr;
}

// Used to search for and then display display single course's information
void BinarySearchTree::printCourseInformation(Node* courses, string courseNumber) {
	Node* current = courses;

	while(current != nullptr) {
		// If match is found, course data is displayed.
		if (current->course.getCourseNumber().compare(courseNumber) == 0) {
			cout << current->course.getCourseNumber() << ", " << current->course.getCourseName() << endl;
			if (current->course.getPrereqCount() > 0) {
				cout << "Prerequisites: ";
				current->course.getCoursePrereq();
			}
			else {
				cout << "No prerequisites for this course." << endl;
			}
			cout << endl;
			return;
		}
		else if (current->course.getCourseNumber().compare(courseNumber) > 0) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	system("CLS");
	// Only reached if course match is not found
	cout << "Course " << courseNumber << " not found.\n" << endl;
}

// Uses in-order tree traversal to display courses from smallest alphanumeric value to largest
void BinarySearchTree::printAllCourses(Node* courses) {
	Node* current = courses; // Generally used for root

	if (current != nullptr) {
		printAllCourses(current->left);
		cout << current->course.getCourseNumber() << ", " << current->course.getCourseName() << endl;
		printAllCourses(current->right);
	}
}