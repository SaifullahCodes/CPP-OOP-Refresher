#include<iostream>
using namespace std;
class Vehicle{
    protected:
    string model;
    int id , rent;
    public:
    Vehicle(string model,int id){
        this->model=model;
        this->id=id;
    }
    virtual void calculateRent(int days) = 0;
    virtual ~Vehicle(){
        cout<<"Vehicle Deleted!"<<endl;
    }
};
class GPS{
    protected:
    string location;
    public:
    GPS(string location){
        this->location=location;
    }
    void track(){
        cout<<"Vehicle is currently at this location"<<endl;
    }
};
class ElectricCar : public Vehicle, public GPS{
    private:
    int* batteryStatus;
    public:
    ElectricCar(string model,int id,string location,int arr[3]): Vehicle(model,id),GPS( location){
        batteryStatus = new int[3];
        for(int i=0 ;i<3;i++){
            batteryStatus[i]=arr[i];
        }
    }
 
ElectricCar(const ElectricCar &other) : Vehicle(other), GPS(other) {
    this->batteryStatus = new int[3];
    for(int i = 0; i < 3; i++) {
        this->batteryStatus[i] = other.batteryStatus[i];
    }
    cout << "Deep Copy Created!" << endl;
}
void calculateRent(int days){
    rent=(days * 5000) + 1000;
    cout << "Rent for " << model << ": " << rent << " PKR" << endl;
}
~ElectricCar(){
    delete[] batteryStatus;
}
void drainBattery() {
        batteryStatus[0] = 0;
        cout << model << " Battery Drained to 0%!" << endl;
    }

    void showBattery() {
        cout << model << " Battery Level: " << batteryStatus[0] << "%" << endl;
    }
};
class Truck : public Vehicle{
    double loadCapacity;
    public:
    Truck(string model,int id,double loadCapacity):Vehicle(model,id){
        this->loadCapacity=loadCapacity;
    }
   void calculateRent(int days){
    rent=(days * 10000) + (loadCapacity * 100);
    cout << "Rent for Truck " << model << ": " << rent << " PKR" << endl;
}
};
int main(){
    Vehicle * fleet[2];
    int array[3]={30,95,150};
    fleet[0]=new ElectricCar("Tesla",123,"Pakistan",array);
    fleet[1]=new Truck("Honda",567,200);
    for(int i = 0; i < 2; i++) {
        fleet[i]->calculateRent(5); 
    }
    ElectricCar car1("Tesla",123,"Pakistan",array);
    ElectricCar car2 =car1;
    car2.drainBattery();
    car1.showBattery();
    for(int i = 0; i < 2; i++) {
        delete fleet[i];
    }

    return 0;

}