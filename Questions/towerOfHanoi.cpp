#include <bits/stdc++.h>
using namespace std;

void toh(int n , char A , char B , char C){
     if(n == 0) return;

    //move all disc except lowest one from a to c
    toh(n-1, A, C, B);

    cout <<"Move disk "<<n<<" from rod "<<A<<" to rod "<<B<< endl;

    //move lowest one to b and all disc from c to b
    toh(n-1, C, B, A);
}
 
int main(){
    int n;
    cout << "Enter count of Disk :" ;
    cin>>n;

    toh(n , 'A' , 'B' , 'C');
    return 0;
}