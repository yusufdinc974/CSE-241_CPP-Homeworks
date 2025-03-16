# 📌 CSE241 – Object-Oriented Programming  
## 📝 Programming Assignment 4 (PA4)

### 🖥️ **Topics Covered:** C++, Inheritance, Polymorphism, Late Binding, Game Simulation  

---

## 📌 **Assignment Overview**
You will implement a **Robot Battle Simulation** using **object-oriented principles**.  
The game involves different **robot types**, each with unique attack behaviors, fighting in a **10x10 grid** until only one robot survives.

✅ **Use class inheritance & virtual functions for robots.**  
✅ **Implement dynamic memory allocation for robot instances.**  
✅ **Simulate movement, combat, and survival in a turn-based system.**  

🚨 **Key Concepts:**  
- Base class `Robot`.  
- Derived classes: `OptimusPrime`, `Robocop`, `Roomba`, `Bulldozer`, `Kamikaze`.  
- Robots have **strength, hitpoints, and unique attack rules**.  
- The game **runs in rounds** until only one robot remains.  

---

## 📂 **Classes & Implementation**
### **🔹 Robot Class (Base Class)**
- Members:
  - `type` → Defines the robot type.
  - `strength`, `hitpoints` → Defines combat attributes.
  - `name` → Unique identifier (`type_sequence_number` format, e.g., `robocop_0`).
- Functions:
  - **Virtual** `getDamage()` → Returns attack damage.
  - **Virtual** `move()` → Moves the robot in the grid.

---

### **🔹 Derived Robot Classes**
| **Robot Type** | **Special Abilities** |
|---------------|------------------|
| **OptimusPrime** | 15% chance to **double damage** |
| **Robocop** | 10% chance to inflict **tactical nuke (50 extra damage)** |
| **Roomba** | Attacks **twice per turn** |
| **Bulldozer** | No special ability, but **high HP (200)** |
| **Kamikaze** | **Inflicts damage equal to its HP, then dies** |

---

## 🎮 **Game Mechanics**
### **🔹 Setup**
- **10x10 grid** initialized with **5 robots** of each type.
- Robots are **placed randomly** with unique names (`<type>_<id>`).

### **🔹 Simulation Steps**
1️⃣ **Each robot moves** in a random direction (`up, down, left, right`).  
2️⃣ **If the target cell is occupied**, a **fight occurs** until one robot dies.  
3️⃣ **The last surviving robot wins**.  

📌 **Example Combat Sequence**
```
roomba_1(10) hits robocop_4(40) with 3  
The new hitpoints of robocop_4 is 37  
robocop_4(37) hits roomba_1(10) with 15  
The new hitpoints of roomba_1 is -5  
roomba_1 is dead.
```

---

## 📌 **Implementation Requirements**
✅ **Use late binding (virtual functions) for `getDamage()`.**  
✅ **Ensure dynamic memory management for all robot instances.**  
✅ **No hardcoded values for robot placement.**  
✅ **Game should continue until only one robot remains.**  

---

🚀 **Good luck!** Happy coding! 🎯  
