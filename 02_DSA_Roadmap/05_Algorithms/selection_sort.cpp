#include<iostream>
using namespace std;
void selectionSort( int array[], int n){
    for(int i = 0 ; i<n-1 ; i++){
        int min = i;
       
        for(int j= i+1 ; j<n;j++){
            if(array[j]<array[min]){
                min = j;
            }
        }
        if(min!=i){
            int temp = array[i];
            array[i]=array[min];
            array[min]=temp;
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
    int array[5]={9,3,2,5,1};
    int size = sizeof(array)/sizeof(array[0]);
    printArray(array,size);
    selectionSort(array,size);
    printArray(array,size);


}