#include <bits/stdc++.h>
using namespace std;

void bucketSort(int arr[] , int n){
    vector<int> bucket[n];
    int minEle = arr[0];
    int maxEle = arr[0];

    for(int i=0; i<n; i++){
        minEle = min(arr[i], minEle);
        maxEle = max(arr[i], maxEle);
    }

    int range = (maxEle - minEle) / n;

    // putting elements in buckets
    for(int i=0; i<n; i++){
        int idx = (arr[i] - minEle) / range;
        bucket[idx].push_back(arr[i]);
    }


    // Each vector sorting -> sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        sort(bucket[i].begin() , bucket[i].end());
    }


    // Merge all buckets
     int idx = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < bucket[i].size(); j++){
            arr[idx] = bucket[i][j];
            idx++;
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

    bucketSort(arr,n);

    cout << "Sorted array : ";
    for(int i=0; i<n; i++){
        cout<< arr[i] << " ";
    }
    return 0;
}