#include <bits/stdc++.h>
using namespace std;

/*
    FORMULA( if element idx is i )
    -> left child = 2*i + 1
    -> right child = 2*i + 2
    -> parent = (i-1) / 2  -> derived from above
    -> first non-leaf node idx =  n/2 - 1 
*/


void heapify(int arr[] , int n , int i){
    int max = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[max]){
        max = left;
    }

    if(right < n && arr[right] > arr[max]){
        max = right;
    }

    if(max != i){
        swap(arr[i] , arr[max]);
        heapify(arr,n,max);
    }
}

void heapSort(int arr[] , int n){
    // making max heap
    for(int i = n/2-1 ; i >= 0 ; i--){
        heapify(arr,n,i);
    }

    for (int i = n - 1; i >= 0; i--) {
        // swaping root with last leaf
        swap(arr[0], arr[i]);
    
        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
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

    heapSort(arr,n);

    cout << "Sorted array : ";
    for(int i=0; i<n; i++){
        cout<< arr[i] << " ";
    }
    return 0;
}