#include<bits/stdc++.h>
using namespace std;

// set is the subset
void targetSumSubsets(vector<int> arr,int idx,string set,int sum,int target) {
  if (sum > target) return; // backtracking

  if (idx == arr.size()) {
    if (sum == target) {
      cout << set << "." << endl;
    }
    return;
  }

  string val = to_string(arr[idx]);

  targetSumSubsets(arr, idx + 1, set + val + ", ", sum + arr[idx], target);
  targetSumSubsets(arr, idx + 1, set , sum , target);
}


int main() {
  int n, target;
  cout << "Enter size : ";
  cin >> n;

  cout << "Enter " << n << " numbers : ";
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Enter target sum : ";
  cin >> target;
  cout << endl;

  cout << "All possible subsets : " << endl;
  targetSumSubsets(arr, 0, "", 0, target);
}