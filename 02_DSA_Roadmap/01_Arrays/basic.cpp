#include <iostream>
using namespace std;

int main() {
    for(int i = 1; i <= 5; i++) {
        
        // 1. SPACES KA LOOP (Pehle khali jagah)
        for(int s = 1; s <= (5 - i); s++) { 
            cout << " "; 
        }

        // 2. STARS KA LOOP (Phir sitaray)
        for(int j = 1; j <= (2*i)-1; j++) {  // <--- Yahan kya ayega?
            cout << "*";
        }

        cout << endl; // New Line
    }
    return 0;
}