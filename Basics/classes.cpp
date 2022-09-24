#include<iostream>
using namespace std;

class Candidate{
    private :
       int salary , mobile ;
    public :
       int RegisterNo; 
       string address , company ; 

       // declare here but define later
       void setInfo(int s , int m , int reg);

       // declare here and define here only
       void getInfo(){
          cout << "Company: " << company << endl;
          cout << "Register No: " << RegisterNo << endl;
          cout << "Address: " << address << endl;
          cout << "Mobile: " << mobile << endl;
          cout << "salary: " << salary << endl;
       } 
};//semicolon important

// scope resolution operator ::
void Candidate :: setInfo(int s , int m , int reg){
    salary = s;
    mobile = m;
    RegisterNo = reg;
}

int main(){
    Candidate mohit;
    // mohit.salary = 10000000; --> Error : its private
    mohit.address = "vellore";
    mohit.company = "Goldman sachs";
    mohit.setInfo(5000000 , 9905866861 , 2022700800);
    mohit.getInfo();

    return 0;
}