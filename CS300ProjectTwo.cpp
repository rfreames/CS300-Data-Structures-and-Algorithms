/*
Ryan Reames
CS-300-T5598
6/16/2022
*/

// Module Seven Project Two

/*
This program accepts input from a CSV file, loads the data into a binary search tree structure, can output a full course list, or print a specific course and its prerequisites.
*/

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	int userChoice = 0;
	string userCourse = "";
	string clearInput = "";
	string fileName = "ABCU_Advising_Program_Input.txt"; // Data source
	Course course;
	BinarySearchTree tree;

	cout << "Welcome to the course planner!\n" << endl;
	while(userChoice != 4) {
		while (userChoice > 4 || userChoice < 1 || cin.fail()) {

			try {
				cout << "1. Load data structure" << endl;
				cout << "2. Print course list" << endl;
				cout << "3. Print course" << endl;
				cout << "4. Exit\n" << endl;
				cout << "What would you like to do? ";

				cin >> userChoice;

				if (userChoice == 1) {
					system("CLS");
					tree.getFileData(fileName);
				}
				else if (userChoice == 2) {
					system("CLS");
					cout << "Here is a sample schedule:\n" << endl;
					tree.printSampleSchedule();
					cout << endl;
				}
				else if (userChoice == 3) {
					cout << "What course do you want to know about? Enter course number: ";
					cin >> userCourse;
					// Transforms user input to capital letters where applicable
					transform(userCourse.begin(), userCourse.end(), userCourse.begin(), ::toupper);
					system("CLS");
					tree.findCourseInformation(userCourse);
					
				}
				else if (userChoice == 4) {
					cout << "\nThank you for using the course planner!" << endl;
					break;
				}
				else if (cin.fail() || userChoice > 4 || userChoice < 1) {
					system("CLS");
					throw runtime_error ("Invalid choice.\n");
				}

				userChoice = 0;
			}
			
			catch (runtime_error& excpt) {
				cout << excpt.what() << endl;
				cin.clear();
				getline(cin, clearInput); // Used to clear excess input (ex. multiple spaces between incorrect values)
			}
		}
	}
}