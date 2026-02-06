# 🚀 C++ OOP Refresher & Bank Management System

Welcome to my C++ repository! 
Here, I am revisiting core **Computer Science concepts** and implementing them in practical projects. This repository documents my journey from basic C++ syntax to advanced OOP concepts like Inheritance, Polymorphism, and Memory Management.

---

## 📂 Project: Simple Bank System
**Location:** `01 classes/BankingSystem.cpp`

A console-based banking application designed to practice **Encapsulation** and **Class Design**.

### ✨ Features
* **Secure Transactions:** Prevents unauthorized withdrawals using PIN verification.
* **Auto-Account Number:** Uses `static` variables to automatically generate unique Account IDs (e.g., 101, 102).
* **Data Validation:** Ensures no negative deposits or overdrafts are possible.
* **Safe Cleanup:** Implements `Destructor` (~BankAccount) to simulate secure session closing.

### 🛠️ Key Concepts Used
1.  **Classes & Objects:** Blueprints for Account creation.
2.  **Access Modifiers:** `private` for sensitive data (PIN, Balance), `public` for user actions.
3.  **Constructors:** Parameterized constructors with `this` pointer for initializing data.
4.  **Destructors:** To handle object lifecycle end-points.

---

## 🚀 How to Run Code
1.  **Clone the Repository:**
    ```bash
    git clone [https://github.com/YourUsername/CPP-OOP-Refresher.git](https://github.com/YourUsername/CPP-OOP-Refresher.git)
    ```
2.  **Compile the code:**
    ```bash
    g++ BankingSystem.cpp -o bankapp
    ```
3.  **Run the application:**
    ```bash
    ./bankapp
    ```

---

## 🔜 Roadmap (Upcoming Learning)
* [x] **Basics & Classes** (Completed)
* [ ] **Inheritance** (Creating Savings vs Current Accounts)
* [ ] **Polymorphism** (Overriding functions)
* [ ] **Pointers & Memory Management** (Deep Dive)

---
*Developed by a CS Final Year Student.*
