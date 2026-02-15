#include<iostream>
using namespace std;
void bubbleSort( int array[], int n){
    for(int i = 0 ; i<n-1 ; i++){
        bool flag = false;
        for(int j= 0 ; j<n-1-i;j++){
            if(array[j]>array[j+1]){
                int temp= array[j+1];
                array[j+1]=array[j];
                array[j]=temp;
                flag = true;
            }
        }
        if(flag==false){
                break;
            }
    }
}
void printArray(int array[], int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<",";
    }
    cout<<endl;
}
int main(){
    int array[5]={1,3,2,5,4};
    int size = sizeof(array)/sizeof(array[0]);
    printArray(array,size);
    bubbleSort(array,size);
    printArray(array,size);


}