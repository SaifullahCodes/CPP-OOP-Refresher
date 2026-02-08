#include<iostream>
using namespace std;
class Person{
    protected:
    string name;
    public:
    Person(string name){
        this->name=name;
    }
    virtual void info()=0;
    virtual ~Person(){
        cout<<"Memory clear!!"<<endl;
    }
};
class Patient : public Person{
    int health;
    int bill;
    public:
    static int totalPatients;
    Patient (string name,int health,int bill): Person(name){
        this->health=health;
        this->bill=bill;
        totalPatients++;
    }
    ~Patient(){
        totalPatients--;
        cout<<"Memory clear!!"<<endl;
    }
    void info(){
        cout<<"Patient Name :"<<name<<endl;
        cout<<"Patient Health :"<<health<<endl;
        cout<<"Patient Bill :"<<bill<<endl;
    }
    void cure(int amount,int amount2){
        health+=amount;
        bill+=amount;
        cout<<amount<<" Health increased "<<endl;
        cout<<amount2<<" Bill Added "<<endl;
    }
    friend void audiotSystem(Patient *p);
};
int Patient::totalPatients = 0;   

    void audiotSystem(Patient *p){
        cout<<"Patient Bill is :"<<p->bill<<endl;
    }
class Doctor : public Person{
    int* surgeyList;
    int count;
    public:
    Doctor(string name,int array[],int count):Person(name){
        this->count = count;
        surgeyList= new int[count];
        for(int i=0;i<count;i++){
            surgeyList[i]=array[i];
        }
    }
    Doctor(Doctor &obj):Person(obj){
        
        count=obj.count;
        surgeyList= new int[count];
        for(int i=0;i<count;i++){
            surgeyList[i]=obj.surgeyList[i];
        }
    }
    ~Doctor(){
        delete[] surgeyList;
    }
    void treat (Patient *p){
        cout<<"Doctor called cure funstion "<<endl;
        p->cure(30,100);
    }
    void info(){
        cout<<"Doctor Name :"<<name<<endl;
        cout<<"Total surgey List is "<<count<<endl;
        for(int i = 0;i<count;i++){
            cout<<"Surgey No :"<<surgeyList[i]<<endl;
        }

    }
    void changeCode(int index,int newCode){
        surgeyList[index]=newCode;
    }
};
int main(){
    Patient *Ali=new Patient("Ali",90,300);
    Ali->info();
    
    int array[]={101,102,103};
    Doctor dr("Dr.strange",array,3);
    dr.treat(Ali);
    audiotSystem(Ali);
    Doctor dr2 = dr;
    dr.changeCode(0,201);
    dr.info();
    dr2.info();
    cout<<"Total patients are "<<Ali->totalPatients<<endl;
    delete Ali;
    cout<<"Total patients are "<<Ali->totalPatients<<endl;
    return 0;
}
 