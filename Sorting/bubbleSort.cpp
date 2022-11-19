#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0; i<n-1 ; i++){
        int count = 0;
        for(int j=0 ; j<n-1-i ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
        if(count == 0){
            break;
        }
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

    bubbleSort(arr,n);

    cout << "Sorted array : ";
    for(int i=0; i<n; i++){
        cout<< arr[i] << " ";
    }
 
    return 0;
}