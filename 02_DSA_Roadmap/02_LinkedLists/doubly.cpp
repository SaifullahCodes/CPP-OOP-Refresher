#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* prev; // <--- Ye Naya Mehman hai (Previous)
    Node(int val) {
        data = val; 
        next = NULL; 
        prev = NULL; 
    }
};
class LinkedList{
    public :
    Node * head;
    LinkedList(){
        head = NULL;
    }
    void insertStart(int value){
        Node * newNode = new Node(value);
        newNode->next= head;
        if(head!=NULL){
            head->prev= newNode;
        }
        head = newNode;
    }
    void insetEnd(int value){
        Node * newNode = new Node(value);
        if (head ==NULL){
            head= newNode;
            return;
        }
        Node * temp =head;
        while(temp->next!= NULL){
            temp=temp->next;
        }
        temp->next=newNode;

    }
     void displayList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->next != NULL)
            {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    LinkedList l;
    l.insertStart(10);
    l.insertStart(5);
    l.insertStart(1);
    l.insetEnd(15);
    l.insetEnd(20);
    l.displayList();
}