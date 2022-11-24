#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> main;
    stack<int> helper;

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
                helper.push(main.top());
                main.pop();
            }

            main.pop();

            stack<int> temp = main;
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
                helper.push(main.top());
                main.pop();
            }

            int val = main.top();
            cout << main.top() << endl;
            main.pop();
            helper.push(val);

            stack<int> temp = main;
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
                cout << main.top() << " ";
                int val = main.top();
                main.pop();
                helper.push(val);
            }
            stack<int> temp = main;
            main = helper;
            helper = temp; 
        }
    }
};
 
int main(){
    Queue q;

    cout << "1.Enqueue\n2.Dequeue\n3.size\n4.top\n5.display"<< endl;

    int n;
    do{
        cout << "Enter choice :";
        cin >> n;

        switch(n){
            case 1 :{
                int data;
                cout << "Enter data :";
                cin >> data;
                q.push(data);
                break;
            }
            case 2 :{
                q.pop();
                break;
            }
            case 3 :{
                q.size();
                break;
            }
            case 4 :{
                q.top();
                break;
            }
            case 5 :{
                cout << "Queue data => ";
                q.display();
                cout<<endl;
                break;
            }
        }
    }while(n>0 && n<6);
    
    return 0;
}