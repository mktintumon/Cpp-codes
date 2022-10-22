#include<iostream>
using namespace std;

// works
int sum(int a , int b){
  return a+b;
}

// this function will not work
// example -> song transfer by bluetooth , any changes made on 
//            transfered song will not impact on our device song
void swap(int a, int b){
  int temp = a;
  a = b;
  b = temp;
}

// CALL BY REFERENCE using POINTERS -> works
void swapPointer(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}


// CALL BY REFERENCE using C++ reference variables
void swapRefVar(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}


int main(){
  //actual values
  int a = 5 , b = 6;
  cout << "Sum is : " << sum(a,b) << endl;

  cout << "value of a : " << a << " and value of b : " << b << endl;

  //swap(a,b); -> not work -> just make copy and pass the values

  //swapPointer(&a , &b); // -> this passes the address -> works

  swapRefVar(a , b);

  cout << "value of a : " << a << " and value of b : " << b << endl;
  return 0;
}