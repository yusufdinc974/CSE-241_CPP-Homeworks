// Course.cpp
#include "course.h"
#include "student.h"
#include <iostream>

namespace PA3 {
    // Default Constructor
    Course::Course() : name(""), code(""), students(nullptr), numStudents(0) {}

    // Parameterized Constructor
    Course::Course(const std::string& name, const std::string& code)
        : name(name), code(code), students(nullptr), numStudents(0) {}

    // Copy Constructor
    Course::Course(const Course& other)
        : name(other.name), code(other.code), numStudents(other.numStudents) {
        students = new Student*[numStudents];
        for (int i = 0; i < numStudents; ++i) {
            students[i] = other.students[i]; // Shallow copy, assumes students are managed elsewhere
        }
    }

    // Assignment Operator
    Course& Course::operator=(const Course& other) {
        if (this != &other) {
            delete[] students;
            name = other.name;
            code = other.code;
            numStudents = other.numStudents;
            students = new Student*[numStudents];
            for (int i = 0; i < numStudents; ++i) {
                students[i] = other.students[i]; // Shallow copy
            }
        }
        return *this;
    }

    // Destructor
    Course::~Course() {
        // Deallocate memory for each student
        for (int i = 0; i < numStudents; ++i) {
            delete students[i];
        }
        // Deallocate memory for the array of student pointers
        delete[] students;
    }


    // Getters and Setters implementations...

    bool Course::addStudent(Student* student) {
        if (student == nullptr) {
            std::cout << "Error: Null student pointer.\n";
            return false;
        }

        // Allocate memory for the students array
        if (students == nullptr) {
            students = new Student*[1];
        } else {
            // Allocate memory for an additional student
            Student** temp = new Student*[numStudents + 1];
            // Copy existing students to the new array
            for (int i = 0; i < numStudents; ++i) {
                temp[i] = students[i];
            }
            // Delete the old array
            delete[] students;
            students = temp;
        }

        // Add the new student
        students[numStudents++] = student;
        std::cout << "Student added successfully.\n";
        return true;
    }





    bool Course::removeStudent(Student* student) {
        int index = -1;
        for (int i = 0; i < numStudents; ++i) {
            if (students[i] == student) {
                index = i;
                break;
            }
        }
        if (index == -1) return false;  // Student not found

        Student** newStudents = new Student*[numStudents - 1];
        for (int i = 0, j = 0; i < numStudents; ++i) {
            if (i != index) {
                newStudents[j++] = students[i];
            }
        }
        numStudents--;
        delete[] students;
        students = newStudents;
        return true;
    }

    void Course::printStudents() const {
        std::cout << "Students in Course " << code << " - " << name << ": ";
        for (int i = 0; i < numStudents; ++i) {
            std::cout << students[i]->getName() << " (ID: " << students[i]->getID() << "), ";
        }
        std::cout << std::endl;
    }

    Student* Course::getStudent(int index) const {
        if (index >= 0 && index < numStudents) {
            return students[index];
        }
        return nullptr; // Index out of bounds
    }
}
