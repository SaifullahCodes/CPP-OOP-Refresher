#include <iostream>
using namespace std;

// 1. Parent
class Enemy {
public:
virtual void attack() {
        cout << "Enemy attacks! (Parent wala function)" << endl;
    }
    };

// 2. Child 1
class Ninja : public Enemy {
public:
    void attack() {
        cout << "Ninja throws Shuriken! 🗡️" << endl;
    }
};

// 3. Child 2
class Monster : public Enemy {
public:
    void attack() {
        cout << "Monster spits Fire! 🔥" << endl;
    }
};

int main() {
    // Humne Pointer "Enemy" (Parent) ka banaya
    // Lekin Address "Ninja" (Child) ka diya.
    Enemy * e= new Ninja();

    // EXPECTATION: "Ninja throws Shuriken" print hona chahiye.
    // REALITY: Kya print hota hai? Check karein.
    e->attack(); 

    return 0;
}