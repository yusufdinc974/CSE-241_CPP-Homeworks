// Student.h
#pragma once
#include <string>

namespace PA3 {
    class Course;  // Forward declaration

    class Student {
    private:
        std::string name;
        int ID;
        Course** courses;  // Dynamic array of pointers to Course objects
        int numCourses;    // Current number of courses enrolled

    public:
        // Constructors
        Student();
        Student(const std::string& name, int ID);

        // Destructor
        ~Student();

        // Copy constructor and assignment operator
        Student(const Student& other);
        Student& operator=(const Student& other);

        // Getters and Setters
        std::string getName() const { return name; }
        void setName(const std::string& newName) { name = newName; }

        int getID() const { return ID; }
        void setID(int newID) { ID = newID; }

        int getNumCourses() const { return numCourses; };
        Course* getCourse(int index) const { return (index >= 0 && index < numCourses) ? courses[index] : nullptr; };


        // Course management
        bool addCourse(Course* course);
        bool dropCourse(Course* course);
        void printCourses() const;

    private:
        void clearCourses();
        void copyCoursesFrom(const Student& other);
    };
}
