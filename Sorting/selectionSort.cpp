#include<iostream>
using namespace std;

void swap(int* a , int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void selectionSort(int arr[],int n){
    for(int i = 0; i < n-1; i++){
        int min_idx = i;

        // searching for min value idx
        for(int j=i+1 ; j < n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }

        swap(&arr[i] , &arr[min_idx]);
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

    selectionSort(arr,n);

    cout << "Sorted array : ";
    for(int i=0; i<n; i++){
        cout<< arr[i] << " ";
    }
    return 0;
}