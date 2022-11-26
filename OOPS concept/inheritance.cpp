#include <iostream>
using namespace std;

/*
  SYNTAX :

  class {derived-class-name} : {visibility mode} {base-class-name}{
    class members / functions / methods etc ....
  }


  FACTS :
  1 -> Default visibility mode is private
  2 -> Private memebers are never inherited
  3 -> Public visibility mode :
            -> public members of the base class becomes
               public members of the derived class
  4 -> private visibility mode :
            -> public members of the base class becomes
               private members of the derived class
*/

// BASE class
class Account{
    public:
        float salary = 60000;
};


// Derived class
class Programmer : public Account{
    public:
        float bonus = 5000;
};


// Derived class
class Developer : public Programmer{
    public:
        float expense = 40000;
};


int main()
{
    Developer d;
    cout << "Salary: " << d.salary << endl;
    cout << "Bonus: " << d.bonus << endl;
    cout << "Expense: " << d.expense << endl;

    return 0;
}