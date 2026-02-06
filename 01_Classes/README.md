# 🏦 Bank Management System (Project 1)

This project demonstrates the basics of **Classes and Objects** in C++.

## 💡 Key Learnings
Is project mein maine ye concepts apply kiye:

1.  **Encapsulation:**
    * `balance` aur `pin` ko **Private** rakha taaky koi direct change na kar sake.
    * Sirf **Public** functions (`deposit`, `withdraw`) ke zariye access allowed hai.

2.  **Static Keyword:**
    * `static int nextID` use kiya taaky Account Number (101, 102...) khud generate hon.

3.  **Constructors:**
    * User jab account banata hai to `Parameterized Constructor` use hota hai values set karne ke liye.

## 🏃 How to Run
Is folder mein terminal khol kar ye command likhein:
```bash
g++ BankingSystem.cpp -o bankapp
./bankapp
