#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> main;
    queue<int> helper;

public:
    int size(){
        cout << main.size() << endl;
        return main.size();
    }

    void push(int val){
        main.push(val);
    }

    void pop(){
        if(main.size() == 0){
            cout << "Underflow" << endl;
        }
        else{
            while(main.size() != 1){
                helper.push(main.front());
                main.pop();
            }

            main.pop();

            queue<int> temp = main;
            main = helper;
            helper = temp; 
        }
    }

    int top(){
        if(main.size() == 0){
            cout << "Underflow" << endl;
            return -1;
        }
        else{
            while(main.size() != 1){
                helper.push(main.front());
                main.pop();
            }

            int val = main.front();
            cout << main.front() << endl;
            main.pop();
            helper.push(val);

            queue<int> temp = main;
            main = helper;
            helper = temp; 
        }
    }

    void display(){
        if(main.size() == 0){
            cout << "Empty ";
        }
        else{
            while(main.size() != 0){
                cout << main.front() << " ";
                int val = main.front();
                main.pop();
                helper.push(val);
            }
            queue<int> temp = main;
            main = helper;
            helper = temp; 
        }
    }
};
 
int main(){
    Stack s;

    cout << "1.push\n2.pop\n3.size\n4.top\n5.display"<< endl;

    int n;
    do{
        cout << "Enter choice :";
        cin >> n;

        switch(n){
            case 1 :{
                int data;
                cout << "Enter data :";
                cin >> data;
                s.push(data);
                break;
            }
            case 2 :{
                s.pop();
                break;
            }
            case 3 :{
                s.size();
                break;
            }
            case 4 :{
                s.top();
                break;
            }
            case 5 :{
                cout << "Stack data => ";
                s.display();
                cout<<endl;
                break;
            }
        }
    }while(n>0 && n<6);
    
    return 0;
}