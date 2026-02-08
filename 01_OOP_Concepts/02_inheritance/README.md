# 🧬 C++ Inheritance & Memory Management

This module explores **Inheritance** (Single & Multiple) and **Advanced Memory Management** (Deep Copying) through two practical projects.

---

## 🎮 Project 1: Mini RPG Battle System
**File:** `RPG_Game.cpp`

A game simulation demonstrating **Single Inheritance** and **Protected Access Modifiers**.

### 🧠 Key Concepts
* **Single Inheritance:** `Warrior` and `Mage` classes inherit common attributes (Health, Name) from the parent `GameCharacter` class.
* **Protected Members:** Used `protected` access specifier for `health`, allowing child classes to modify it directly while keeping it hidden from the outside world.
* **Constructor Chaining:** Child constructors pass data to the Parent constructor using the Initialization List syntax (`: ParentClass(...)`).

---

## 📹 Project 2: Smart Security Camera
**File:** `SmartCamera.cpp`

A complex system simulation demonstrating **Multiple Inheritance** and **Manual Memory Management**.

### 🧠 Key Concepts
* **Multiple Inheritance:** The `SmartCamera` class inherits features from two independent parents:
    * `Device` (Hardware ID management)
    * `Internet` (Network Configuration)
* **Deep Copy vs Shallow Copy:** Implemented a custom **Copy Constructor** to perform Deep Copying. This ensures that when a camera object is duplicated, a new memory block is allocated for video data, preventing **Dangling Pointers**.
* **Heap Memory:** Used `new` and `delete` for dynamic allocation of video recording buffers.

---

## 🚀 How to Run

Navigate to this directory in your terminal:
```bash
cd "02_inheritance"
To Run the RPG Game:
Bash
g++ RPG_Game.cpp -o game
./game
To Run the Smart Camera:
Bash
g++ SmartCamera.cpp -o camera
./camera
Developed by Saifullah Naseer as part of the C++ Engineering Roadmap.
