// Student.cpp
#include "student.h"
#include "course.h"  // Include the Course header
#include <iostream>

namespace PA3 {
    // Default Constructor
    Student::Student() : name(""), ID(-1), courses(nullptr), numCourses(0) {}

    // Parameterized Constructor
    Student::Student(const std::string& name, int ID)
        : name(name), ID(ID), courses(nullptr), numCourses(0) {}

    // Copy Constructor
    Student::Student(const Student& other)
        : name(other.name), ID(other.ID), numCourses(other.numCourses) {
        courses = new Course*[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            courses[i] = other.courses[i]; // Shallow copy, assumes courses are managed elsewhere
        }
    }

    // Assignment Operator
    Student& Student::operator=(const Student& other) {
        if (this != &other) {
            delete[] courses;
            name = other.name;
            ID = other.ID;
            numCourses = other.numCourses;
            courses = new Course*[numCourses];
            for (int i = 0; i < numCourses; ++i) {
                courses[i] = other.courses[i]; // Shallow copy
            }
        }
        return *this;
    }

    // Destructor
    Student::~Student() {
        delete[] courses;
    }

    // Getters and Setters implementations...

    // Course management
    bool Student::addCourse(Course* course) {
        Course** newCourses = new Course*[numCourses + 1];
        for (int i = 0; i < numCourses; ++i) {
            newCourses[i] = courses[i];
        }
        newCourses[numCourses++] = course;
        delete[] courses;
        courses = newCourses;
        return true;
    }

    bool Student::dropCourse(Course* course) {
        int index = -1;
        for (int i = 0; i < numCourses; ++i) {
            if (courses[i] == course) {
                index = i;
                break;
            }
        }
        if (index == -1) return false;  // Course not found

        Course** newCourses = new Course*[numCourses - 1];
        for (int i = 0, j = 0; i < numCourses; ++i) {
            if (i != index) {
                newCourses[j++] = courses[i];
            }
        }
        numCourses--;
        delete[] courses;
        courses = newCourses;
        return true;
    }

    void Student::printCourses() const {
        std::cout << "Courses for Student ID " << ID << ": ";
        for (int i = 0; i < numCourses; ++i) {
            std::cout << courses[i]->getName() << " (" << courses[i]->getCode() << "), ";
        }
        std::cout << std::endl;
    }
}
