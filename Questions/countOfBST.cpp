
#include<bits/stdc++.h>
using namespace std;

int countBST(int n) {
    if(n <= 1) return 1;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += countBST(i-1) * countBST(n-i);
    }

    return ans;
}


int main(){
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;
    
    int ans = countBST(n);
    cout << "Total no of BST possible :" << ans << endl;
}