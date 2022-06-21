# CS300-T5598
Ryan Reames
6/21/2022

**Project One and Two Reflection**

**What was the problem you were solving in the projects for this course?**

For this course, we were given a list of comma separated values containing course information in a text file. The idea was to be able to get data from the file, load it into a data structure, and then sort the data so that it can be displayed or searched through.

**How did you approach the problem? Consider why data structures are important to understand.**

My approach to the problem was to use a binary search tree to hold course information from the given text file. Upon creation of the data structure data is automatically sorted, simplifying creating course schedules, and allowing for easy searching.

**How did you overcome any roadblocks you encountered while going through the activities or project?**

The primary issue I had while going through these projects was getting course data appropriately formatted for the tree structure in project two. I ended up solving this by first appending each text file line to a string vector, then separating each line in the vector into the various course attributes. To do this, I created temporary variables to hold values while looping through the vector. There was also a nested loop for course prerequisites, given that each course could have any number of prerequisites or none at all.

**How has your work on this project expanded your approach to designing software and developing programs?**

This project taught me a lot about the various data structures and algorithms used to search through them. While I ended up using a binary search tree, I also learned a lot about vectors, hash tables, linked lists, and various sorting algorithms.

**How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?**

While creating this project in C++ I created a class to hold course objects, and another to implement the binary search tree. Doing so allowed the main program to simply implement the menu and import the courses / tree, allowing better readability of the program. While this was similar to projects I had created previously, getting the extra practice has reinforced those concepts. On top of this, learning about various data structures and algorithms has given me a good starting point to create efficient programs based on the type of data being used, rather than using similar structures or algorithms for all programs I create.
