# 🏦 Secure Banking System Simulation

A console-based financial application engineered to demonstrate **Encapsulation** and **State Management** in C++. This project simulates core banking operations while enforcing strict data validation and security protocols.

## ⚙️ System Architecture

### 1. Data Encapsulation (Security)
* **Private Members:** Critical data such as `balance` and `PIN` are strictly private. Direct access is blocked to prevent unauthorized manipulation.
* **Public Interfaces:** Access is controlled via validation layers (Getters/Setters) like `deposit()` and `withdraw()`.

### 2. Static State Management (Auto-ID)
* Implemented a `static` counter (`nextID`) shared across all instances.
* **Logic:** When a new `BankAccount` object is instantiated, the system automatically assigns a unique, incremental Account ID (e.g., 101, 102), simulating a real-world database primary key.

### 3. Object Lifecycle Management
* **Constructor:** Initializes account state with parameterized data and validates inputs.
* **Destructor:** Handles the safe termination of the object session, ensuring no dangling resources remain.

## 🚀 Usage

### Compilation & Execution
This project is built using standard C++ (compatible with C++11 and later).

1.  **Compile:**
    ```bash
    g++ BankingSystem.cpp -o bank_system
    ```
2.  **Run:**
    ```bash
    ./bank_system
    ```

### Workflow
1.  System initializes and prompts for user interaction.
2.  User can perform **Deposits** (Positive integer validation).
3.  User can perform **Withdrawals** (Requires PIN authentication + Balance check).
4.  User can **Change PIN** (Requires Old PIN verification).
5.  Session terminates and the **Destructor** logs the cleanup process.

---
*Developed by Saifullah Naseer.*
