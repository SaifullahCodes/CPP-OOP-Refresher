#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector <int> vec={1,2,3};
    cout<<"size is "<<vec.size()<<endl;
    
    vec.push_back(10);
    cout<<"size is "<<vec.size()<<endl;
    for(int val : vec){
        cout<<val<<endl;}
         vec.pop_back();
    cout<<"size is "<<vec.size()<<endl;
    for(int val : vec){
        cout<<val<<endl;}
        cout<<"fron value is "<<vec.front()<<endl;
        cout<<"back value is"<<vec.back()<<endl;
        cout<<"at value is"<<vec.at(2)<<endl;
    return 0 ;
}