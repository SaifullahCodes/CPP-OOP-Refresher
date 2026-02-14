#include <iostream>
using namespace std;
class Queue{
    int * arr;
    int capacity,front,rear;
    public:
    Queue(int size){
        capacity=size;
        arr = new int [size];
        rear=-1;
        front=-1;
    }
    
    ~Queue(){
        delete[] arr;
        cout<<"Memory free"<<endl;
    }
    void enqueue(int val){
        if(rear == capacity-1){
            cout<<"overflow"<<endl;
            return;
        }
        rear++;
        arr[rear]=val;
        if(front==-1){
            front=0;
        }
    }
    void dequeue(){
        if(front==-1|| front>rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<arr[front]<<"deleted from queue"<<endl;
        front ++;
    }
    void peek(){
         if(front==-1|| front>rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<arr[front]<<" is on front"<<endl;

    }

};
int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.peek();
    q.dequeue();
    q.peek();
}