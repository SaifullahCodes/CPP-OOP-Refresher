#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void insertAtStart(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Node added at start " << endl;
    }
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            cout << "Node added at end " << endl;
        }
    }
    void insertAtPosition(int pos, int value)
    {
        Node *newNode = new Node(value);

        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;
        int index = 0;

        while (temp != NULL && index < pos - 1)
        {
            temp = temp->next;
            index++;
        }

        if (temp == NULL)
        {
            cout << "Position is out of bound" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Node added at position " << pos << endl;
    }
    void deleteFirstNode()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == NULL)
        {
            Node *temp = head;
            head = NULL;
            delete temp;
            cout << "Last Node Deleted (List is now empty)" << endl;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *newNode = temp->next;
        temp->next = NULL;
        delete newNode;
        cout << "Node deleted at end" << endl;
    }
    void DisplayList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->next != NULL)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList list;
    list.insertAtStart(20);
    list.insertAtStart(10);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.DisplayList();
    cout << endl;
    list.insertAtPosition(2, 5);
    list.deleteFirstNode();
    list.deleteAtEnd();
    list.DisplayList();
    return 0;
}