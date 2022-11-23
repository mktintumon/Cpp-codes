#include<iostream>
using namespace std;

void merge(int arr[], int low , int mid , int high , int n){
    int i = low;
    int j = mid + 1;
    int k = low;

    int ans[n]; 

    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            ans[k] = arr[i];
            i++;
            k++;
        }
        else{
            ans[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i <= mid){
      ans[k] = arr[i];
      k++;
      i++;
    }

    while(j <= high){
      ans[k] = arr[j];
      k++;
      j++;
    }
    
    // deep copy
    for (int i = low; i <= high; i++) {
        arr[i] = ans[i];
    }
}

void mergeSort(int arr[] , int low , int high , int n){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(arr , low , mid , n);
        mergeSort(arr , mid+1 , high , n);

        merge(arr , low , mid , high , n);
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

    mergeSort(arr,0,n-1,n);

    cout << "Sorted array : ";
    for(int i=0; i<n; i++){
        cout<< arr[i] << " ";
    }

    return 0;
}