#include<iostream>
using namespace std;
class GameCharacter
{
    protected:
    string name;
    int health;
    public:
    GameCharacter(string name, int health){
        this->name=name;
        this->health=health;
    }
    void takeDamage(int amount){
        health-=amount;
        cout<<name<<" took "<<amount<<" damage. Health is now "<<health<<endl;
    }
};
class Warrior : public GameCharacter{
    private:
    int shieldpower;
    public:
    Warrior(string name, int health,int shieldpower) : GameCharacter(name,health){
        this->shieldpower=shieldpower;
    }
    void swingSword(){
        cout<<"Warrior "<<name<<" swings sword forcefully! "<<endl;
    }
};
class Mage : public GameCharacter{
    public:
    int mana;
    Mage(string name, int health,int mana) : GameCharacter(name,health){
        this->mana=mana;
    }
    void castSpell(){
        if(mana>10){
            cout<<"Mage "<<name<<" casts a Fireball!"<<endl;
            mana-=10;
        }
        else{
            cout<<"Out of Mana!"<<endl;
        }
    }

};
int main() {
    // 1. Warrior banaya (Naam: Arthur, Health: 100, Shield: 50)
    Warrior w("Arthur", 100, 50);
    
    // 2. Mage banaya (Naam: Merlin, Health: 60, Mana: 100)
    Mage m("Merlin", 60, 100);

    cout << "--- Battle Start ---" << endl;

    // Warrior attack kar raha hai
    w.swingSword();
    
    // Mage ko damage hua (Warrior ne mara)
    m.takeDamage(20);

    // Mage ne jawab mein Jadu kiya
    m.castSpell();
    m.castSpell(); // Doosri bar jadu

    // Mage ki health check karein
    m.takeDamage(50); // Mage marne wala ho jayega

    return 0;
}