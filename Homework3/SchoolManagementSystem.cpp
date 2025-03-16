// SchoolManagementSystem.cpp
#include "SchoolManagementSystem.h"
#include <iostream>
#include <string>
#include <sstream>

namespace PA3 {

    // Constructor
    SchoolManagementSystem::SchoolManagementSystem()
        : students(nullptr), courses(nullptr), numStudents(0), numCourses(0) {}

    // Destructor
    SchoolManagementSystem::~SchoolManagementSystem() {
        for (int i = 0; i < numStudents; i++) {
            delete students[i];
        }
        delete[] students;

        for (int i = 0; i < numCourses; i++) {
            delete courses[i];
        }
        delete[] courses;
    }


    // Add a student
    bool SchoolManagementSystem::addStudent(const std::string& name, int ID) {
        if (findStudent(ID) != nullptr) {
            return false; // Student already exists
        }

        Student** newStudents = new Student*[numStudents + 1];
        for (int i = 0; i < numStudents; i++) {
            newStudents[i] = students[i];
        }
        newStudents[numStudents] = new Student(name, ID);
        numStudents++;

        delete[] students;
        students = newStudents;

        return true;
    }


    // Remove a student
    bool SchoolManagementSystem::removeStudent(int ID) {
        int index = -1;
        for (int i = 0; i < numStudents; i++) {
            if (students[i]->getID() == ID) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            return false; // Student not found
        }

        delete students[index];
        for (int i = index; i < numStudents - 1; i++) {
            students[i] = students[i + 1];
        }
        numStudents--;

        return true;
    }

    Student* SchoolManagementSystem::findStudent(int ID) const {
        for (int i = 0; i < numStudents; i++) {
            if (students[i]->getID() == ID) {
                return students[i];
            }
        }
        return nullptr;
    }



    // Add a course
    bool SchoolManagementSystem::addCourse(const std::string& name, const std::string& code) {
        if (findCourse(code) != nullptr) {
            return false; // Course already exists
        }

        Course** newCourses = new Course*[numCourses + 1];
        for (int i = 0; i < numCourses; i++) {
            newCourses[i] = courses[i];
        }
        newCourses[numCourses] = new Course(name, code);
        numCourses++;

        delete[] courses;
        courses = newCourses;

        return true;
    }


    // Remove a course
    bool SchoolManagementSystem::removeCourse(const std::string& code) {
        int index = -1;
        for (int i = 0; i < numCourses; i++) {
            if (courses[i]->getCode() == code) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            return false; // Course not found
        }

        delete courses[index];
        for (int i = index; i < numCourses - 1; i++) {
            courses[i] = courses[i + 1];
        }
        numCourses--;

        return true;
    }


    // Find a course
    Course* SchoolManagementSystem::findCourse(const std::string& code) const {
        for (int i = 0; i < numCourses; i++) {
            if (courses[i]->getCode() == code) {
                return courses[i];
            }
        }
        return nullptr;
    }


    // Print all students
    void SchoolManagementSystem::printAllStudents() const {
        for (int i = 0; i < numStudents; i++) {
            std::cout << "Student ID: " << students[i]->getID() << ", Name: " << students[i]->getName() << std::endl;
        }
    }


    // Print all courses
    void SchoolManagementSystem::printAllCourses() const {
        for (int i = 0; i < numCourses; i++) {
            std::cout << "Course Code: " << courses[i]->getCode() << ", Name: " << courses[i]->getName() << std::endl;
        }
    }


    void SchoolManagementSystem::runMenu() {
        int choice;
        do {
            std::cout << "Main Menu\n";
            std::cout << "0: Exit\n1: Student\n2: Course\n3: List All Students\n4: List All Courses\n>> ";
            std::cin >> choice;

            switch (choice) {
                case 0: //exit
                    exit(1);
                    break;
                case 1: // Student Menu
                    studentMenu();
                    break;
                case 2: // Course Menu
                    courseMenu();
                    break;
                case 3: // List All Students
                    printAllStudents();
                    break;
                case 4: // List All Courses
                    printAllCourses();
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 0);
    }

    void SchoolManagementSystem::studentMenu() {
        int choice;
        do {
            std::cout << "Student Menu\n";
            std::cout << "0: Up\n1: Add Student\n2: Select Student\n>> ";
            std::cin >> choice;

            switch (choice) {
                case 0: //up
                    break;
                case 1: // Add Student
                    addStudentMenu();
                    break;
                case 2: // Select Student
                    selectStudentMenu();
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 0);
    }

    void SchoolManagementSystem::addStudentMenu() {
        std::string input, name, ID_str, word;
        int ID = 0;
        char buffer;

        std::cout << ">> ";
        if (std::cin.peek() == '\n') {
        std::cin.ignore();
        }
        std::getline(std::cin, input); // Get the line entered by the user
        std::stringstream ss(input);   // Create a string stream to parse the input

        while (ss >> word) {  // Iterate through each word in the input
            if (!name.empty()) { // If name is not empty, add a space before appending the next word
                name += " ";
            }
            if (ss.eof()) { // If end of file is reached, the last word is ID_str
                ID_str = word;
            } else {
                name += word;
            }
        }

        if (!ID_str.empty()) {
            ID = std::stoi(ID_str); // Convert ID string to an integer
        }

        if (!addStudent(name, ID)) {
            std::cout << "Unable to add student (might already exist).\n";
        }
    }


    void SchoolManagementSystem::selectStudentMenu() {
        int studentID;
        int ID = 0;
        std::string input, name, ID_str, word;
        std::cout << ">> ";
        if (std::cin.peek() == '\n') {
        std::cin.ignore();
        }
        std::getline(std::cin, input); // Get the line entered by the user
        std::stringstream ss(input);   // Create a string stream to parse the input

        while (ss >> word) {  // Iterate through each word in the input
            if (!name.empty()) { // If name is not empty, add a space before appending the next word
                name += " ";
            }
            if (ss.eof()) { // If end of file is reached, the last word is ID_str
                ID_str = word;
            } else {
                name += word;
            }
        }

        if (!ID_str.empty()) {
            ID = std::stoi(ID_str); // Convert ID string to an integer
        }
        studentID = ID;
        Student* selectedStudent = findStudent(studentID);
        if (selectedStudent == nullptr) {
            std::cout << "Student not found.\n";
            return;
        }

        int choice;
        do {
            std::cout << "Selected Student: " << selectedStudent->getName() << "\n";
            std::cout << "0: Up\n1: Delete Student\n2: Add to Course\n3: Drop from Course\n>> ";
            std::cin >> choice;

            switch (choice) {
                case 0: //up
                    break;
                case 1: // Delete Student
                    if (removeStudent(studentID)) {
                        std::cout << "Student removed successfully.\n";
                        return; // Exiting after deletion
                    } else {
                        std::cout << "Error removing student.\n";
                    }
                    break;
                case 2: // Add to Course
                    addToCourseMenu(selectedStudent);
                    break;
                case 3: // Drop from Course
                    dropFromCourseMenu(selectedStudent);
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 0);
    }

    void SchoolManagementSystem::addToCourseMenu(Student* selectedStudent) {
        if (selectedStudent == nullptr) {
            std::cout << "No student selected.\n";
            return;
        }

        int choice;
        do {
            std::cout << "Add to Course Menu\n";
            for (int i = 0; i < numCourses; i++) {
                // Assuming each course has a unique number starting from 1
                std::cout << i + 1 << ": " << courses[i]->getName() << " (" << courses[i]->getCode() << ")\n";
            }
            std::cout << "0: Up\nChoose a course to add the student to: ";
            std::cin >> choice;

            if (choice > 0 && choice <= numCourses) {
                if (selectedStudent->addCourse(courses[choice - 1])) {
                    courses[choice - 1]->addStudent(selectedStudent);
                    std::cout << "Student added to course successfully.\n";
                } else {
                    std::cout << "Failed to add student to course.\n";
                }
            }
        selectStudentMenu();
        } while (choice != 0);
    }

    void SchoolManagementSystem::dropFromCourseMenu(Student* selectedStudent) {
        if (selectedStudent == nullptr) {
            std::cout << "No student selected.\n";
            return;
        }

        int choice;
        do {
            std::cout << "Drop from Course Menu\n";
            selectedStudent->printCourses();
            std::cout << "0: Up\nChoose a course to drop the student from: ";
            std::cin >> choice;

            // Assuming courses are numbered in the order they are printed
            if (choice > 0 && choice <= selectedStudent->getNumCourses()) {
                if (selectedStudent->dropCourse(selectedStudent->getCourse(choice - 1))) {
                    std::cout << "Student dropped from course successfully.\n";
                } else {
                    std::cout << "Failed to drop student from course.\n";
                }
            }
        } while (choice != 0);
    }

    void SchoolManagementSystem::addCourseMenu() {
        std::string input, code, name;

        std::cout << ">> ";
        if (std::cin.peek() == '\n') {
        std::cin.ignore();
        }
        std::getline(std::cin, input); // Get the line entered by the user
        std::stringstream ss(input);   // Create a string stream to parse the input

        ss >> code; // Parse the input to get the course code
        std::getline(ss, name); // Read the remaining input as the course name

        if (!name.empty() && name[0] == ' ') { // Remove leading space from the name if it exists
            name.erase(0, 1);
        }

        if (!addCourse(name, code)) {
            std::cout << "Unable to add course (might already exist).\n";
        }
    }


    void SchoolManagementSystem::courseMenu() {
        int choice;
        Course* selectedCourse = nullptr;
        std::string courseCode;

        do {
            std::cout << "Course Menu\n";
            std::cout << "0: Up\n1: Add Course\n2: Select Course\n>> ";
            std::cin >> choice;

            switch (choice) {
                case 1: // Add Course
                    addCourseMenu();
                    break;
                case 2: // Select Course
                    std::cout << "Enter Course Code: ";
                    std::cin >> courseCode;
                    selectedCourse = findCourse(courseCode);
                    if (selectedCourse == nullptr) {
                        std::cout << "Course not found.\n";
                    } else {
                        manageSelectedCourse(selectedCourse);
                    }
                    break;
                default:
                    if(choice != 0){
                        std::cout << "Invalid choice. Please try again.\n";
                    }
                    break;
            }
        } while (choice != 0);
    }

    void SchoolManagementSystem::manageSelectedCourse(Course* selectedCourse) {
        int choice;
        do {
            std::cout << "Selected Course: " << selectedCourse->getName() << "\n";
            std::cout << "0: Up\n1: Delete Course\n2: List Students Registered\n>> ";
            std::cin >> choice;

            switch (choice) {
                case 1: // Delete Course
                    if (removeCourse(selectedCourse->getCode())) {
                        std::cout << "Course removed successfully.\n";
                        return; // Exit the submenu after deleting
                    } else {
                        std::cout << "Error removing course.\n";
                    }
                    break;
                case 2: // List Students Registered to the Course
                    listStudentsInCourse(selectedCourse);
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 0);
    }

    void SchoolManagementSystem::listStudentsInCourse(Course* course) {
        if (course == nullptr) {
            std::cout << "No course selected.\n";
            return;
        }

        std::cout << "Students registered in " << course->getName() << ":\n";

        int numStudents = course->getNumStudents(); // Ensure numStudents is being retrieved correctly
        if (numStudents == 0) {
            std::cout << "No students are currently registered in this course.\n";
            return;
        }

        for (int i = 0; i < numStudents; ++i) {
            Student* student = course->getStudent(i);
            if (student != nullptr) {
                std::cout << "ID: " << student->getID() << ", Name: " << student->getName() << "\n";
            } 
            else {
                std::cout << "Null student pointer encountered.\n";
            }
        }
    }




}