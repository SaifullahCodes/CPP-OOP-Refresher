#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class CircularLinkedList
{
    Node *head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }
    void insertNodeAtStart(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void insertNodeAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }
        Node *temp = head->prev;
        temp->next = newNode;
        head->prev = newNode;
        newNode->prev = temp;
        newNode->next = head;
    }
    void insertAtPosition(int pos, int val)
    {
        if (head == NULL && pos != 0)
        {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 0)
        {
            Node *newNode = new Node(val);
            if (head == NULL)
            {
                head = newNode;
                newNode->next = head;
                newNode->prev = head;
                return;
            }
            newNode->next = head;
            newNode->prev = head->prev;
            Node *temp = head->prev;
            temp->next = newNode;
            head->prev = newNode;
            head = newNode;
            return;
        }
        Node *temp = head;
        int count = 0;

        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
        if (pos > 0 && pos <= count)
        {
            Node *temp2 = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp2 = temp2->next;
            }
            Node *newNode = new Node(val);
            newNode->next = temp2->next;
            newNode->prev = temp2;
            temp2->next->prev = newNode;
            temp2->next = newNode;
        }
        else
        {
            cout << "Invalid position" << endl;
        }
    }
    void deleteAtStart()
    {
        if (head == NULL)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        Node *temp = head;
        if (head->next == head)
        {
            delete head;
            head = NULL; // Head ko NULL karna zaroori hai
            cout << "Last remaining node deleted. List is now empty." << endl;
            return;
        }
        head = head->next;
        head->prev = temp->prev;
        temp->prev->next = head;
        delete temp;
        cout << "first node deleted" << endl;
    }
    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = NULL; // Head ko NULL karna zaroori hai
            cout << "Last remaining node deleted. List is now empty." << endl;
            return;
        }
        Node *temp = head->prev;
        head->prev = temp->prev;
        temp->prev->next = head;
        delete temp;
        cout << "last node deleted" << endl;
    }
    void deleteAtPosition(int pos){
        if (head == NULL)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        if (pos == 0)
        {
            if (head->next == head)
        {
            delete head;
            head = NULL; // Head ko NULL karna zaroori hai
            cout << "Last remaining node deleted. List is now empty." << endl;
            return;
        }
            Node * temp = head;
            head= head->next;
            temp->prev->next=head;
            head->prev=temp->prev;
            delete temp;
            return;
        }
        Node * temp = head;
        int count =0;
        do{
            count++;
            temp=temp->next;
        }while(temp->next!=head);
        if(pos>0&&pos<count){
            Node * temp1 = head;
            for(int i = 0;i<pos-1;i++){
                temp1=temp1->next;
            }
            Node * temp2 = temp1->next;
            temp1->next= temp2->next;
            temp2->next->prev= temp1;
            
            cout<<temp2->data<<"node delete at "<<pos<<endl;
            delete temp2;

        }

    }
    void reverseDisplayFun(){
        if(head==NULL || head->next==head) {
            return;
        }
        Node * current =head;
        Node * temp =NULL;
        do{
            temp = current->prev;
            current->prev= current->next;
            current->next=temp;
            current= current->prev;
        }while(current!=head);
        if(temp!=NULL){
            head=temp->prev;
        }

    }
    void display()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty" << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    void showReverse(){
        if (head == NULL)
        {
            cout << "Linked List is empty" << endl;
            return;
        }
        Node * temp = head->prev;
        Node * tail = temp;
        do{
            cout<<temp->data<<"->";
            temp =temp->prev;
        }while(temp!=tail);
    }
};
int main()
{
    CircularLinkedList l;
    l.insertNodeAtStart(10);
    l.insertNodeAtStart(5);
    l.insertNodeAtStart(1);
    // l.display();
    l.insertNodeAtEnd(15);
    l.insertNodeAtEnd(20);
    // l.display();
    l.insertAtPosition(2, 40);
    l.display();
//     l.deleteAtStart();
//     l.display();
//     l.deleteAtStart();
//     l.display();
//     l.deleteAtEnd();
//     l.display();
//    l.deleteAtPosition(1);
    // l.display();
    // l.reverseDisplayFun();
    l.display();
    l.showReverse();
}