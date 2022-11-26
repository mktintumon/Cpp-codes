#include<iostream>
using namespace std;

// cylinder
int volume(double r , int h){
    return (3.14 * r * r * h);
}

// cube
int volume(int a){
    return (a * a * a);
}

// cuboid
int volume(int l , int b , int h){
    return (l * b * h);
}
 
int main(){
  cout << "Volume of cylinder : " << volume(3 , 4) << endl;
  cout << "Volume of cube     : " << volume(3) << endl;
  cout << "Volume of cuboid   : " << volume(3 , 4 , 5) << endl;
  return 0;
}