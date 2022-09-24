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

    return 0;
}