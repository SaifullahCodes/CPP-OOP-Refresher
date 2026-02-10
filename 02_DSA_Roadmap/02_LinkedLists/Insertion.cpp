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
    void insetatPosition(int pos, int value)
    {
        if (pos == 0)
        {
            Node *newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *temp = head;
        int count = 0;
        while (temp != 0)
        {
            temp = temp->next;
            count++;
        }

        if (pos <= count)
        {
            Node *temp2 = head;
            for (int i; i < pos - 1; i++)
            {

                temp2 = temp2->next;
            }
            Node *newNode = new Node(value);
            newNode->next = temp2->next; // Right side joro
            temp2->next = newNode;       // Left side joro

            cout << "Node Inserted!" << endl;
        }
        else
        {
            cout << "Invalid Position!" << endl;
        }
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
    list.insetatPosition(4, 150);
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