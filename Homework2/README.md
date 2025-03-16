# 📌 CSE241 – Object-Oriented Programming  
## 📝 Programming Assignment 2 (PA2)

### 🖥️ **Topics Covered:** C++, Operator Overloading, Sparse Matrices, File I/O  

---

## 📌 **Assignment Overview**
You will implement **SparseVector** and **SparseMatrix** classes, which store only **non-zero** values while behaving like regular vectors/matrices. Your implementation must support various operations, including arithmetic, transposition, and dot products.

---

## 📂 **Classes & Operators**
### **🔹 SparseVector Class**
Represents a **one-dimensional** sparse vector.

- ✅ **Constructors:** Initialize from a file.
- ✅ **Overloaded Operators:**
  - `+` → **Vector Addition**
  - `-` → **Vector Subtraction**
  - `-` → **Negation**
  - `=` → **Assignment**
  - `<<` → **Print to output stream**
- ✅ **Function:**
  - `dot()` → Computes **dot product** of two vectors.

---

### **🔹 SparseMatrix Class**
Represents a **two-dimensional** sparse matrix.

- ✅ **Constructors:** Initialize from a file.
- ✅ **Overloaded Operators:**
  - `+` → **Matrix Addition**
  - `-` → **Matrix Subtraction**
  - `-` → **Negation**
  - `=` → **Assignment**
  - `<<` → **Print to output stream**
  - `*` → **Matrix Multiplication**
- ✅ **Function:**
  - `transpose()` → Returns the **transpose** of the matrix.

---

## 🎯 **File Format**
### **📌 SparseVector Representation**
```
<index>:<value> <index>:<value> ...
```
📌 **Example:**
```
4:23.8 7:10.7 10:34 12:20 1012:5
```

### **📌 SparseMatrix Representation**
```
<row_index> <index>:<value> <index>:<value> ...
```
📌 **Example:**
```
3 3:24.6 4:5.5  
4 1:1.15  
8 5:6.4 8:34.1 9:13.1  
```

---

## 🔧 **Implementation Requirements**
✅ **File I/O:** Read from and write to text files.  
✅ **Efficient Storage:** Store only non-zero values.  
✅ **Operator Overloading:** Implement required operators.  
✅ **Avoid Hardcoded Values:** No magic numbers.  
✅ **Error Handling:** Handle missing or incorrect input files.  

---

## 🚀 **Driver Program**
Your classes will be tested using a **driver program** that:
1️⃣ **Creates SparseVector/SparseMatrix objects** from files.  
2️⃣ **Performs operations** (addition, subtraction, multiplication, etc.).  
3️⃣ **Writes results** to an output file.  

📌 **Example Driver Code:**
```cpp
#include "SparseVector.h"
#include "SparseMatrix.h"

int main() {
    SparseVector a1("a1.txt");
    cout << "a1: " << a1 << endl;
    a1 = a1 + a1;
    cout << "Updated a1: " << a1 << endl;

    SparseMatrix m1("m1.txt");
    cout << "Transpose of m1: " << m1.transpose() << endl;
}
```

---

🚀 **Good luck!** Happy coding! 🎯  
