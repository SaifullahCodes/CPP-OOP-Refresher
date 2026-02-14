#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Queue
{
public:
    Node *front;
    Node *rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int val)
    {
        Node *newNode = new Node(val);
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
            newNode->next = NULL;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue empty" << endl;
            return;
        }
        Node *nodetoDelete = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        cout << nodetoDelete->data << " Node delted" << endl;
        delete nodetoDelete;
    }
    void peek()
    {
        if (front == NULL)
        {
            cout << "Queue empty" << endl;
            return;
        }

        cout << front->data << " value at front" << endl;
    }
    void displayList()
    {
        if (front == NULL)
        {
            cout << "Queue empty" << endl;
            return;
        }
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
    }
};
int main()
{
    Queue list;
    list.enqueue(10);
    list.enqueue(20);
    list.enqueue(30);
    list.enqueue(30);
    list.enqueue(30);
    list.enqueue(30);
    list.peek();
    list.dequeue();
    list.peek();
    list.displayList();
}