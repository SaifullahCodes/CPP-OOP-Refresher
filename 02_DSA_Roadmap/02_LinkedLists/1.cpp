#include <iostream>
using namespace std;

// 1. Node Class
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
}; // <--- Ye Semicolon Zaroori hai!

// 2. LinkedList Class
class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    // --- Insert Start ---
    void insertAtStart(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Node added at start: " << value << endl;
    }

    // --- Insert End ---
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        // Agar list khali hai
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Node added at end: " << value << endl;
    }

    // --- Insert Position (Fixed Logic) ---
    void insertAtPosition(int pos, int value)
    {
        // Case 1: Start par lagana hai
        if (pos == 0)
        {
            insertAtStart(value);
            return;
        }

        Node *temp = head;

        // Loop chalao 'pos - 1' tak
        for (int i = 0; i < pos - 1; i++)
        {

            // Safety Check: Agar list choti hai
            if (temp == NULL)
            {
                cout << "Invalid Position!" << endl;
                return;
            }
            temp = temp->next;
        }

        // Loop ke baad Safety Check
        if (temp == NULL)
        {
            cout << "Invalid Position!" << endl;
            return;
        }

        // Ab Insert karo
        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Inserted " << value << " at Position " << pos << endl;
    }
    void deleteFirst(){
        if(head == NULL){
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        Node * temp = head;

        head = head->next;
        delete temp;
        cout<<"First Node deleted"<<endl;
    }
    void deleteEnd(){
        if(head==0){
            cout<<"Linked List is empty"<<endl;
            return;
        }
        if(head->next==NULL){
            Node * temp =head;
            head= NULL;
            delete temp;
            cout<<"Node deleted";
            return ;
        }
        Node * temp = head;
        while(temp->next->next!=NULL){
            temp= temp->next;
        }
        Node *nextNode = temp->next;
        temp->next=NULL;
        delete nextNode;
        cout<<"Node deleted"<<endl;

    }
    void deleteposition(int pos ){
        if(pos == 0){
            Node * temp = head;
            head = head->next;
            delete temp;
            cout<<"Node deleted"<<endl;
            return;
        }
        int count=1;
        Node * temp = head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        if(pos<=count){
            Node * temp2 = head;
            for(int i = 0 ; i < pos-1; i++){
                if(temp2==NULL){
                    cout<<"Invalid position"<<endl;
                    return;
                }
                temp2=temp2->next;
            }
            Node * prevNode = temp2->next;
            temp2->next= prevNode->next;
            delete prevNode;
            cout<<"Node deleted at"<<pos<<endl;
        }
        else{
            cout<<"Invalid positiomn"<<endl;
        }

    }

        // --- Display ---
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
    Node* reverseList(Node* head) {
    Node *prev = NULL;      // 1. Pichle node ka record
    Node *current = head;   // 2. Wo banda jiska connection torta hai
    Node *next = NULL;      // 3. Agle bande ko bachane wala (taaky list gum na ho)

    while(current != NULL) {
        next = current->next;  // Rasta save karo (Agay kon khara hai?)
        current->next = prev;  // CONNECTION ULTA KARO (Piche hath pakro)
        prev = current;        // Ab pichle ko ek kadam agay lao
        current = next;        // Ab mojooda bande ko ek kadam agay lao
    }
    return prev; // Sab khatam honay par 'prev' naya Head ban jayega
}
    void displayReverse(Node* temp) {
        if (temp == NULL) return; // Base Case: Aakhir mein puhanch gaye

        displayReverse(temp->next); // Aglay node ko call karo (Pehle aakhir tak jao)
        
        cout << temp->data << " ";  // Wapsi (backtracking) par print karo
    }
}; // <--- Ye Semicolon BOHT Zaroori hai!

// 3. Main Function
int main()
{
    LinkedList list;

    list.insertAtStart(10);
    list.insertAtStart(5);
    list.insertAtStart(1);

    cout << "Initial List: ";
    list.displayList(); // Output: 1 -> 5 -> 10

    list.insertAtEnd(20);

    cout << "After End Insert: ";
    list.displayList(); // Output: 1 -> 5 -> 10 -> 20

    list.insertAtPosition(2, 99);

    cout << "After Position Insert: ";
    list.displayList(); // Output: 1 -> 5 -> 99 -> 10 -> 20
    // list .deleteFirst();
    // list.displayList();
    // list.deleteEnd();
    // list.displayList();
    list.deleteposition(4);
    list.displayList();
    // Ghalat:
    // list.reverseList(list.head); 
    
    // Sahi:
    // list.head = list.reverseList(list.head); // Naya head update karo
    // cout << "List after permanent reverse: ";
    list.displayReverse(list.head);
    list.displayList();


    return 0;
}