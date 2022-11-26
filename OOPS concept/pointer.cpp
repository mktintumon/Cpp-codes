#include<iostream>
using namespace std;
int main(){
    // pointer --> its a data type contains address of other data type
    int a = 5;
    int* b = &a;

    // & --> address operator
    cout << "Adress of a is : " << &a << endl;   
    cout << "Adress of a is : " << b << endl;   

    // * --> Dereference operator --> value of variable
    cout << "Value at address b is : " << *b << endl;

    // Pointer to Pointer
    int** c = &b;
    cout << "Adress of b is : " << &b << endl;   
    cout << "Adress of b is : " << c << endl;  
    
    cout << "Value at address c is : " << *c << endl;   
    cout << "Value at add(c(add(b))) : " << **c << endl;  


    // ARRAYS WITH POINTER

    int array[5] = { 0, 1, 2, 3, 4};

    // pointer start with 0th index
    int* p = array;
    cout << *p << endl;
    
    // first print then increment
    cout << *(p++) << endl;
    
    // first increment then print
    cout << *(++p) << endl;

    // normal way
    cout << *(p+1) << endl;

    return 0;
}