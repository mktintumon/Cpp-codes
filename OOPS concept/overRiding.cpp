#include<iostream>
using namespace std;
  
class Base {
public:
    // virtual function -> to be overriding
    virtual void print()
    {
        cout << "print base class\n";
    }
  
    void show()
    {
        cout << "show base class\n";
    }
};
  
class Child : public Base {
public:
    void print()
    {
        cout << "print derived class\n";
    }
  
    void show()
    {
        cout << "show derived class\n";
    }
};
  
int main()
{
    Base *b;
    Child c;
    b = &c;
  
    // Virtual function, binded at runtime -> overriding
    b->print();
  
    // Non-virtual function, binded at compile time
    b->show();
    
    return 0;
}