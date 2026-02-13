#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Node added at start" << endl;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            cout << "Node added at end" << endl;
        }
    }

    void insertAtPosition(int pos, int value) {
        Node* newNode = new Node(value);

        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        int index = 0;

        while (temp != NULL && index < pos - 1) {
            temp = temp->next;
            index++;
        }

        if (temp == NULL) {
            cout << "Position is out of bound" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Node added at position " << pos << endl;
    }

    void deleteFirstNode() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout<<"First node deleted"<<endl;
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == NULL) {
            Node* temp = head;
            head = NULL;
            delete temp;
            cout << "Last Node Deleted" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = NULL;
        delete nodeToDelete;
        cout << "Node deleted at end" << endl;
    }

    void deleteAtPosition(int pos) {
        if (head == NULL) return;

        if (pos == 0) {
            deleteFirstNode();
            return;
        }

        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        if (pos < count) {
            Node* prev = head;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }

            Node* nodeToDelete = prev->next;
            prev->next = nodeToDelete->next;
            delete nodeToDelete;
            cout << "Node deleted at position " << pos << endl;
        }
        else {
            cout << "Position out of range" << endl;
        }
    }

    void DisplayList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtStart(20);
    list.insertAtStart(10);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.DisplayList();
    
    list.insertAtPosition(-3, 5);
    list.DisplayList();
    
    list.deleteFirstNode();
    list.DisplayList();
    
    list.deleteAtEnd();
    list.DisplayList();
    
    list.deleteAtPosition(2);
    list.DisplayList();
    
    return 0;
}