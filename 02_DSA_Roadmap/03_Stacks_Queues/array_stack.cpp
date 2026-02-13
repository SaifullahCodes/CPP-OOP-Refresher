#include <iostream>
using namespace std;
class Stack{
    int *array;
    int top;
    int capacity;
    public:
    Stack(int size){
        capacity = size;
        array = new int[capacity];
        top=-1;
    }
    ~Stack(){
        delete[] array;
        cout<<"Memory cleaned "<<endl;
    }
    void push ( int value){
        if(top==capacity -1){
            cout<<"stack overflow"<<endl;
            return;
        }
        top++;
        array[top]=value;
        cout<<value<<" added in stack"<<endl;
    }
    void pop(){
        if ( top == -1){
            cout<<"stack already empty"<<endl;
            return;
        }
        cout<<array[top]<<" value deleted from stack"<<endl;
        top--;
    }
    void peek(){
        if (top==-1){
            cout<<"Stack empty"<<endl;
            return;
        }
        cout<<"First value at stack is "<<array[top]<<endl;

    }
};
int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.peek();
    s.pop();
    s.peek();
    return 0;
}