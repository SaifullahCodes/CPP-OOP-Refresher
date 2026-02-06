# 📹 Smart Security Camera System (Complex Inheritance)

This project demonstrates **Advanced Memory Management** and **Multiple Inheritance** in C++.
It simulates a Smart Camera that inherits features from both a `Device` (Hardware) and `Internet` (Network).

## 🧠 Key Engineering Concepts

### 1. Multiple Inheritance
* The `SmartCamera` class inherits from two parent classes:
    * `Device` (Handling Hardware ID)
    * `Internet` (Handling IP Address)
* **Syntax:** `class SmartCamera : public Device, public Internet`

### 2. Deep Copy vs Shallow Copy (Crucial)
* Implemented a **Deep Copy Constructor** to handle dynamic memory safely.
* **Scenario:** When a camera object is copied, the system allocates *new* heap memory for video data instead of copying the pointer.
* **Benefit:** Prevents **Dangling Pointer** issues where two objects modify the same memory location.

### 3. Dynamic Memory Allocation (Heap)
* Used `new int[]` to allocate video recording buffer at runtime.
* Used `delete[]` in the **Destructor** to prevent memory leaks.

## 🚀 How to Run
1. Navigate to the directory:
   ```bash
   cd "02_inheritance"
