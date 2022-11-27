#include<iostream>
using namespace std;

int partition(int arr[] , int start, int end){
    int pivot = arr[end];

    int i = start-1;
    for(int j = start ; j <= end-1 ; j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    //exchange with pivot element
    int temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;

    return i+1;
}

void quickSort(int arr[] , int start , int end){
    if(start >= end) return;
    int pivot = partition(arr , start , end);
    quickSort(arr, start , pivot-1);
    quickSort(arr, pivot+1 , end);
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

    quickSort(arr,0,n-1);

    cout << "Sorted array : ";
    for(int i=0; i<n; i++){
        cout<< arr[i] << " ";
    }
    return 0;
}