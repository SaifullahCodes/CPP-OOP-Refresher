#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class Stack{
    Node * top;
    public:
    Stack(){
        top =NULL;
    }
    void push(int val){
        Node * newNode = new Node(val);
        newNode->next=top;
        top=newNode;
        cout<<newNode->data<<" added at stack"<<endl;
    }
    void pop(){
        if(top==NULL){
            cout<<"Stack is empty"<<endl;
            return;
        }
        Node * temp = top;
        cout<<top->data<<" deleted from stack "<<endl;
        top=top->next;
        delete temp;
    }
    void peek(){
        if(top==NULL){
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<top->data<<" at top of stack "<<endl;

    }
    void displayStack(){
        if(top==NULL){
            cout<<"Stack is empty"<<endl;
            return;
        }
        Node * temp = top;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main (){
    Stack list;
    list.push(10);
    list.push(20);
    list.push(30);
    list.push(40);
    list.push(50);
    list.peek();
    list.displayStack();
    list.pop();
    list.peek();
    list.pop();
    list.peek();
    list.displayStack();


}