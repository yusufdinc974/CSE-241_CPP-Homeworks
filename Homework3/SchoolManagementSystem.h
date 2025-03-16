// SchoolManagementSystem.h
#pragma once
#include "student.h"
#include "course.h"

namespace PA3 {
    class SchoolManagementSystem {
    private:
        Student** students; // Dynamic array of pointers to Student objects
        Course** courses;   // Dynamic array of pointers to Course objects
        int numStudents;
        int numCourses;

    public:
        // Constructor and Destructor
        SchoolManagementSystem();
        ~SchoolManagementSystem();

        // Utility Methods
        bool addStudent(const std::string& name, int ID);
        bool removeStudent(int ID);
        Student* findStudent(int ID) const;

        bool addCourse(const std::string& name, const std::string& code);
        bool removeCourse(const std::string& code);
        Course* findCourse(const std::string& code) const;

        void printAllStudents() const;
        void printAllCourses() const;

        // Menu Functionality
        void runMenu();
        void studentMenu();
        void addStudentMenu(); //
        void selectStudentMenu();
        void courseMenu();
        void manageSelectedCourse(Course* selectedCourse);
        void listStudentsInCourse(Course* course);
        void addCourseMenu(); //wrong
        void addToCourseMenu(Student* selectedStudent);
        void dropFromCourseMenu(Student* selectedStudent);
    };
}
