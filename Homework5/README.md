# 📌 CSE241 – Object-Oriented Programming  
## 📝 Programming Assignment 5 (PA5)

### 🖥️ **Topics Covered:** C++ STL, Exception Handling, Templates, File I/O  

---

## 📌 **Assignment Overview**
You will implement a **Catalog Management System** that:  
✅ **Reads structured data from a file (`data.txt`).**  
✅ **Executes commands (`commands.txt`).**  
✅ **Generates a log (`output.txt`).**  
✅ **Uses STL containers and class templates where needed.**  
✅ **Handles exceptions for missing fields, duplicate entries, and invalid commands.**  

🚨 **Efficiency is key**—use STL containers where applicable.  

---

## 📂 **File Formats & Parsing**
### **🔹 `data.txt` (Catalog Data)**
- **First line** → Describes the format of catalog entries.
- **Subsequent lines** → Contain individual catalog entries.

📌 **Example Format**
```
title:string:single|author:string:multi|year:integer:single|tag:string:multi  
Hilbert Spaces With Applications|Lokenath Debnath:Piotr Mikusinski|2005|Mathematics:Set Theory  
```
- Fields can be **single-value (`single`)** or **multi-value (`multi`)**.
- Multi-values are **colon-separated (`:`)**.

---

### **🔹 `commands.txt` (Operations)**
1️⃣ **Search Command**  
- Format: `search <value> in <field_name>`  
- Searches for entries that **match the value (partially or fully)**.

📌 **Example**
```
search "Joe" in "artist"
```
🟢 **Output**
```
Professor Satchafunkilus and the Musterion of Rock|Joe Satriani|2008|Guitar Virtuoso
```

2️⃣ **Sort Command**  
- Format: `sort <field_name>`  
- Sorts the catalog **in ascending order** based on the specified field.

📌 **Example**
```
sort "title"
```
🟢 **Output**
```
Physical Graffiti|Led Zeppelin|1975|Rock  
Professor Satchafunkilus and the Musterion of Rock|Joe Satriani|2008|Guitar Virtuoso  
Return Of The Mother Head's Family Reunion|Richie Kotzen|2007|Rock:Guitar Virtuoso  
```

---

## 🚨 **Exception Handling & Logging (`output.txt`)**
The system must log all operations and exceptions.  

### **📌 Exceptions**
| **Error Case** | **Log Message** |
|---------------|------------------|
| Missing field in an entry | `Exception: missing field` |
| Duplicate first field value | `Exception: duplicate entry` |
| Invalid command format | `Exception: command is wrong` |

📌 **Example Log**
```
title|artist|year|genre  
Exception: duplicate entry  
Twelve Monkeys|||Sci-Fi:Thriller|Bruce Willis:Madeleine Stowe:Brad Pitt  
Exception: missing field  
3 unique entries  
search "Monkeys" in "title"  
Twelve Monkeys|Terry Gilliam|1995|Mystery:Sci-Fi:Thriller|Bruce Willis:Madeleine Stowe:Brad Pitt  
```

---

## 📌 **Implementation Requirements**
✅ **Use STL containers (`map`, `vector`, `set`, etc.).**  
✅ **Use C++ Templates for generalized data handling.**  
✅ **Avoid hardcoded values.**  
✅ **Do NOT repeatedly parse the same data—store it efficiently.**  

---

🚀 **Good luck!** Happy coding! 🎯  
