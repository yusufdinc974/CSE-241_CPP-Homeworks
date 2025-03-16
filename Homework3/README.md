# 📌 CSE241 – Object-Oriented Programming  
## 📝 Programming Assignment 3 (PA3)

### 🖥️ **Topics Covered:** C++, Dynamic Memory, Class Design, Interactive Menu  

---

## 📌 **Assignment Overview**
You will implement a **School Management System** that allows users to:
✅ **Manage students** (add, delete, assign courses).  
✅ **Manage courses** (add, delete, list registered students).  
✅ **Use dynamic memory** to store student and course records.  

🚨 **Restrictions:**  
- **No STL containers (vectors, lists, etc.).**  
- **No global or local fixed-size arrays.**  
- **All objects must be dynamically allocated.**  

---

## 📂 **Classes & Implementation**
### **🔹 Student Class**
- Members: `name`, `ID`, **dynamically allocated** array of course references.  
- Functions:
  - Getters & Setters.
  - Constructor & Destructor.

### **🔹 Course Class**
- Members: `name`, `code`, **dynamically allocated** array of student references.  
- Functions:
  - Getters & Setters.
  - Constructor & Destructor.

### **🔹 SchoolManagementSystem Class**
- Stores **dynamic arrays** of students and courses.  
- Implements **menu-driven functionality** to manage records.

---

## 🎮 **Interactive Menu System**
📌 **User navigates the menu to perform operations.**  
```
Main Menu:
0 → Exit  
1 → Student Menu  
2 → Course Menu  
3 → List All Students  
4 → List All Courses  
```

### **🔹 Student Menu**
```
0 → Up  
1 → Add Student (User enters name & ID)  
2 → Select Student (Enter name & ID)  
   0 → Up  
   1 → Delete Student  
   3 → Add Student to Course  
   4 → Drop Student from Course  
```

### **🔹 Course Menu**
```
0 → Up  
1 → Add Course (Enter course code & name)  
2 → Select Course  
   0 → Up  
   1 → Delete Course  
   2 → List Registered Students  
```

---

## 📌 **Implementation Requirements**
✅ **Use dynamic memory** for student & course storage.  
✅ **Delete dynamically allocated memory** when not needed.  
✅ **No unnecessary object copies.**  
✅ **Ensure error handling:** If the user enters invalid input, reprint the menu.  
✅ **Strict output format:** Only display menu items (no extra prints).  

---

## 🎯 **Example Run**
```
Main Menu:
1 → Student Menu  
2 → Course Menu  
3 → List All Students  
4 → List All Courses  
>> 1

Student Menu:
1 → Add Student  
2 → Select Student  
>> 1  
>> James Webb 123456

Student Menu:
1 → Add Student  
2 → Select Student  
>> 2  
>> James Webb 123456  

Student Actions:
1 → Delete Student  
3 → Add Student to Course  
4 → Drop Student from Course  
```

---

🚀 **Good luck!** Happy coding! 🎯  
