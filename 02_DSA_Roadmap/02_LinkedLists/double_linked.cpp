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
class DoublyLinkedList
{
public:
    Node *head;
    DoublyLinkedList()
    {
        head = NULL;
    }
    void insertatStart(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void insertAtEnd(int val){
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node * temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev= temp;

    }
    void insertAtPosition(int pos , int val){
        if (head == NULL && pos!=0)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        if (pos == 0)
        {
            Node *newNode = new Node(val);
            newNode->next=head;
            head->prev=newNode;
            head = newNode;
            return;
        }
        int count=0;
        Node * temp = head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(pos>0&&pos<=count){
            Node * newNode =  new Node(val);
            Node * temp1= head;
            for(int i = 0 ; i < pos-1;i++){
                temp1=temp1->next;
            }
            newNode->prev= temp1;
            newNode->next=temp1->next;
            if(temp1->next!=NULL){
                temp1->next->prev=newNode;
            }
            temp1->next=newNode;
            return;
        }
        else{
            cout<<"invalid input"<<endl;
        }}
        void deleteAtStart(){
            if(head==NULL){
                cout<<"List is empty"<<endl;
                return;
            }
            if(head->next==NULL){
                delete head;
                head= NULL;
                cout<<"Node delted"<<endl;
                return;
            }
            Node * temp = head;
            head=head->next;
            head->prev=NULL;
            delete temp;
            cout<<"Node deleted"<<endl;

    }
    void  deleteAtEnd()
    {
          if(head==NULL){
                cout<<"List is empty"<<endl;
                return;
            }
            if(head->next==NULL){
                delete head;
                head= NULL;
                cout<<"Node delted"<<endl;
                return;
            }
            Node * temp = head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            Node *deleteNode = temp->next;
            temp->next=NULL;
            delete deleteNode;
            cout<<"Node  deleted"<<endl;
    }
    void deleteAtPosition(int pos){
        if(head==NULL){
                cout<<"List is empty"<<endl;
                return;
            }
            if(pos ==0){
                if(head->next==NULL){
                delete head;
                head= NULL;
                cout<<"Node delted"<<endl;
                return;
            }
            Node * temp =head;
            head= head->next;
            head->prev=NULL;
            delete temp;
            cout<<"Node deleted"<<endl;
            }
            int count = 0 ;
            Node * temp =head;
            do{
                count++;
                temp=temp->next;
            }while(temp!=NULL);
            if(pos>0&&pos<=count){
                Node * temp1 =head;
                for(int i =0;i<pos-1;i++){
                    temp1=temp1->next;
            }
            Node* nodeDelete = temp1->next;
            temp1->next=nodeDelete->next;
            if(nodeDelete->next != NULL){
                    nodeDelete->next->prev=temp1;

            }
            delete nodeDelete;
            cout<<"Node deleted"<<endl;
            }
            else{
                cout<<"Invalid position"<<endl;
            }
            
    }
    void display(){
        if(head==NULL){
            cout<<"List empty"<<endl;
            return;
        }
        Node * temp =head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void reverseDisplay(){
         if(head==NULL){
            cout<<"List empty"<<endl;
            return;
        }
        Node * temp = head;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp= temp->prev;
        }
        cout<<endl;


    }
    void actualReverse(){
         if(head==NULL){
            cout<<"List empty"<<endl;
            return;
        }
        Node * temp =NULL;
        Node * current = head;
        while(current!=NULL){
            temp = current->prev;
            current->prev=current->next;
            current->next= temp;
            current= current->prev;
        }
        if(temp!=NULL){
            head=temp->prev;
        }
    }
};
int main(){
    DoublyLinkedList l;
    l.insertatStart(10);
    l.insertatStart(20);
    l.insertatStart(30);
    // l.display();
    l.insertAtEnd(5);
    l.insertAtEnd(1);
    // l.display();
    l.insertAtPosition(2,45);
    // l.display();
    // l.deleteAtStart();
    // l.display();
    // l.deleteAtEnd();
    // l.display();
    //  l.deleteAtEnd();
    l.display();
    l.deleteAtPosition(2);
    l.display();
     l.deleteAtPosition(2);
    l.display();
    l.deleteAtPosition(9);
    l.display();
    l.reverseDisplay();
    l.actualReverse();
    l.display();

}