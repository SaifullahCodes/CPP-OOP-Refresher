#include <iostream>
using namespace std;
int binarySearch(int arr[],int size, int target){
   int start = 0 ;
   int end = size -1;
   while(size<=end){
      int mid = start + (end-start)/2;
      if(arr[mid]==target){
        return mid;
      }
      if(target>arr[mid]){
        start =mid+1;
      }
      else{
        end = mid -1;
      }

   }
   return -1;
}
int main(){
    int  arr[5]={1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 6;
   int result= binarySearch(arr,size,target);
   if (result != -1) {
        cout << "Target mil gaya Index: " << result << " par." << endl;
    } else {
        cout << "Target nahi mila!" << endl;
    }
    return 0;
}