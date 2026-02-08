#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    Node(int data)
    {
        next = NULL;
        this->data = data;
    }
};
class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = 0;
    }
    void insertAtStart(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void insetAtEnd(int Value)
    {
        Node *newNode = new Node(Value);
        Node *temp = head;
        if (head == 0)
        {
            head = newNode;
        }
        else
        {
            while (temp->next != 0)
            {
                temp = temp->next;
            }
        }
        temp->next = newNode;
    }
    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    LinkedList list;
    list.insertAtStart(10);
    list.insertAtStart(20);
    list.insetAtEnd(100);
    list.insetAtEnd(200);
    list.insetAtEnd(100);
    list.display();
    // Node *n1=new Node(3);
    // Node *n2 =new Node(4);
    // n1->next=n2;
    // Node *temp = n1;
    // while(temp!=0){
    //     cout<<temp->data<<endl;
    //     temp=temp->next;
    // }
    return 0;
}