#include<iostream>
using namespace std;

void binarySearch(int arr[] , int left , int right , int key){
    if(left <= right){
        while(left <= right){
            int mid = (left + right) / 2;

            if(arr[mid] == key){
                cout<<"YEAH !!! Found";
                return;
            }
            else if(arr[mid] < key){
                return binarySearch(arr,mid+1,right,key);
            }
            else{
                return binarySearch(arr,left,mid-1,key);
            }
        }
    }
    cout << "Sorry!!! Not found";
    return;
}
 
int main(){
  int n;
  cout << "Enter size of array : ";
  cin>>n;
  int arr[n];

  cout << "Enter " << n << " numbers : "<< endl; 
  for(int i=0; i<n; i++){
     cin>>arr[i];
  }

  int key;
  cout<<"Enter key to search : ";
  cin>>key;

  binarySearch(arr,0,n-1,key);
  return 0;
}