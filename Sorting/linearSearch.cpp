#include<iostream>
using namespace std;

void linearSearch(int arr[] , int n , int key){
    for(int i=0; i<n; i++){
        if(arr[i] == key){
            cout << "Found the key ";
            return;
        }
    }

    cout << "Key NOT found";
    return;
}
 
int main(){
    int n;
  cout << "Enter size of array : ";
  cin>>n;
  int arr[n];

  cout << "Enter " << n << " numbers : "; 
  for(int i=0; i<n; i++){
     cin>>arr[i];
  }

  int key;
  cout<<"Enter key to search : ";
  cin>>key;

  linearSearch(arr,n,key);
    return 0;
}