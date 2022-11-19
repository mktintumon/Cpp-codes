#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
    for(int i=1 ; i<n ; i++){
        int key = arr[i];
        int j = i-1;

        while(arr[j] > key && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
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

    insertionSort(arr,n);

    cout << "Sorted array : ";
    for(int i=0; i<n; i++){
        cout<< arr[i] << " ";
    }

    return 0;
}