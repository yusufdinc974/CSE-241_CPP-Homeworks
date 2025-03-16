// Course.h
#pragma once
#include <string>

namespace PA3 {
    class Student;  // Forward declaration

    class Course {
    private:
        std::string name;
        std::string code;
        Student** students;  // Dynamic array of pointers to Student objects
        int numStudents;     // Current number of students enrolled

    public:
        // Constructors
        Course();
        Course(const std::string& name, const std::string& code);

        // Copy constructor and assignment operator
        Course(const Course& other);
        Course& operator=(const Course& other);

        // Destructor
        ~Course();

        // Getters and Setters
        std::string getName() const { return name; };
        void setName(const std::string& newName) { name = newName; }

        std::string getCode() const { return code; }
        void setCode(const std::string& newCode) { code = newCode; }

        int getNumStudents() { return numStudents; };
        void setNumStudents(int num) {numStudents = num;};

        Student* getStudent(int index) const;

        // Student management
        bool addStudent(Student* student);
        bool removeStudent(Student* student);
        void printStudents() const;
    };
}
