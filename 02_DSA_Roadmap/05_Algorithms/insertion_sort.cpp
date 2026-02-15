#include<iostream>
using namespace std;
void insertionSort( int array[], int n){
    for(int i = 1 ; i<n ; i++){
        int key = array[i];
        int j= i -1;
        while(j>=0 && array[j]>key){
            array[j+1]=array[j];
            j = j -1;
        }
        array[j+1]=key;
        }
        
        
    }
void printArray(int array[], int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int array[5]={9,3,2,5,1};
    int size = sizeof(array)/sizeof(array[0]);
    printArray(array,size);
    insertionSort(array,size);
    printArray(array,size);


}