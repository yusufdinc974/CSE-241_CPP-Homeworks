# 📌 CSE241 – Object-Oriented Programming  
## 📝 Programming Assignment 6 (PA6)  

### 🖥️ **Topics Covered:** Java, Inheritance, Interfaces, Observer Pattern  

---

## 📌 **Assignment Overview**  
You will design a **dataset management system** using **object-oriented principles** in Java.  
The system will store different types of **media objects** while using the **observer pattern**  
to notify `Player` and `Viewer` objects about dataset changes.

✅ **Use interfaces & class inheritance.**  
✅ **Implement the Observer Pattern for real-time dataset updates.**  
✅ **Simulate adding, removing, and interacting with media objects.**  

🚨 **No file I/O is required**; the program runs entirely in the terminal.

---

## 📂 **Class Structure & Interfaces**  
### **🔹 Base Class: `Media`**  
- Parent class for **all media types**.  

### **🔹 Media Subclasses**  
| **Class** | **Visual?** | **Playable?** |  
|-----------|------------|--------------|  
| `Text` | ❌ Non-Visual | ❌ Non-Playable |  
| `Audio` | ❌ Non-Visual | ✅ Playable |  
| `Video` | ✅ Visual | ✅ Playable |  
| `Image` | ✅ Visual | ❌ Non-Playable |  

### **🔹 Interfaces**  
| **Interface** | **Implemented By** | **Purpose** |  
|--------------|----------------|------------|  
| `Playable` | `Audio`, `Video` | Defines playable objects |  
| `NonPlayable` | `Text`, `Image` | Defines non-playable objects |  
| `Visual` | `Video`, `Image` | Identifies visual objects |  
| `NonVisual` | `Audio`, `Text` | Identifies non-visual objects |  

---

## 🎮 **Simulation Features**  
### **🔹 Dataset Management (`Dataset` Class)**  
- Stores all **media objects** (`Audio`, `Video`, `Image`, `Text`).  
- Supports **adding/removing** objects dynamically.  
- Notifies **Player and Viewer** objects when relevant changes occur.  

### **🔹 Observers (`Player` & `Viewer`)**  
- `Player` objects:
  - Receive updates **only for playable objects**.
  - Can **navigate** between playable items (`next()`, `previous()`).  
- `Viewer` objects:
  - Receive updates **only for non-playable objects**.
  - Can **navigate** between viewable items (`next()`, `previous()`).  

---

## 📌 **Example Usage**  
```java
// Create dataset
Dataset ds = new Dataset();

// Create observers
Player p1 = new Player();
Player p2 = new Player();
Viewer v1 = new Viewer();
Viewer v2 = new Viewer();

// Register observers
ds.register(p1);
ds.register(p2);
ds.register(v1);
ds.register(v2);

// Add media objects
ds.add(new Image("image1", "1080x720", "metadata"));
ds.add(new Audio("song1", "3:45", "artist info"));
ds.add(new Video("video1", "10:00", "description"));
ds.add(new Text("article1", "content"));

// Interact with observers
p1.currently_playing().info();
ds.remove(p1.currently_playing());
```

---

## 📌 **Implementation Requirements**  
✅ **Observer Pattern:** Ensure dataset **notifies relevant observers only**.  
✅ **Proper Exception Handling:** Handle cases like **empty playlists**.  
✅ **Dynamic Object Management:** Use **lists** for media storage.  
✅ **No Unnecessary Memory Usage:** Avoid redundant object copies.  

---

🚀 **Good luck!** Happy coding! 🎯  
