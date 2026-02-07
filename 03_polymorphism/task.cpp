#include <iostream>
using namespace std;

// 1. Abstract Parent
class Enemy {
public:
    // Pure Virtual Function (Ye class ab 'Abstract' ho gayi)
    virtual void attack() = 0; 
    virtual ~Enemy() { cout << "Enemy Deleted" << endl;
    }
};

// 2. Child 1
class Zombie : public Enemy {
public:
    void attack() override {
        cout << "Zombie bites! 🧟" << endl;
    }
};

// 3. Child 2
class Dragon : public Enemy {
public:
    void attack() override {
        cout << "Dragon breathes fire! 🔥" << endl;
    }
};

int main() {
    // Array of Pointers (Jisme hum alag alag enemies rakhenge)
    Enemy* enemies[2];

    // Assignment:
    enemies[0] = new Zombie();
    enemies[1] = new Dragon();

    cout << "--- Game Loop Start ---" << endl;

    // TASK: Yahan ek FOR LOOP lagayein jo 0 se 1 tak chale
    // aur har enemy ka attack() call kare.
    // Hint: enemies[i]->attack();
    for(int i=0;i<2;i++)
    {
        enemies[i]->attack();
    }
    
    // ??? AAPKA CODE YAHAN ???

    return 0;
}