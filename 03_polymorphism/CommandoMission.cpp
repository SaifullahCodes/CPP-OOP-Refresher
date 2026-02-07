#include<iostream>
using namespace std;
class Commando{
    int health =100,power =10;
    public:
    void getHealth(){
        cout<<"Health of commando is "<<health<<endl;
    }
    void heal(int amount){
        health+=amount;
        cout<<amount<<" Health restored"<<endl;
    }
    void takeDamage(int amount){
        health-=amount;
        cout<<"Ouch! you take "<<amount<<"damage"<<endl;
    }
    void powerup(int amount){
        power+=amount;
        health+=amount;
        cout<<amount<<" Power increase"<<endl;
        cout<<amount<<" health increase"<<endl;
    }
    void status(){
        cout<<"Current health is "<<health<<endl;
        cout<<"Current power is "<<power<<endl;
    }
};
class GameItem{
    public:
    virtual void apply(Commando* c)=0;
};
class Medkit: public GameItem{
    public:
    void apply(Commando* c){
        c->heal(20);
        cout<<"Used Medkit"<<endl;
    }
};
class PoisonFlask :  public GameItem{
    public:
    void apply(Commando* c){
        c->takeDamage(30);
        cout<<"Stepped on poison"<<endl;

    }
};
class SuperSerum : public GameItem{
    public:
    void apply(Commando* c){
        c->powerup(50);
    }
};
int main(){
    Commando * hero = new Commando();
    GameItem* bag[3];
    bag[0]=new Medkit();
    bag[1]=new PoisonFlask();
    bag[2]=new SuperSerum();
    for(int i=0;i<3;i++){
        bag[i]->apply(hero);
        hero->status();
    }
    delete hero;

}
