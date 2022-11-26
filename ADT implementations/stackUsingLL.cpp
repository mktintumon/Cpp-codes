#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class Stack{
    public:
        Node* top;
        int size = 0;

        // constructor
        Stack() { 
            top = NULL;
        }

        // destructor
        ~Stack() {}; 

        void push(int data);
        void pop();
        int peek();
        bool isEmpty();
        void display();
};

// add first 
void Stack::push(int data) {
    Node* temp = new Node();
    temp->data = data;

    if(size == 0){
        temp->next = NULL;
    }
    else{
        temp->next = top;
    }

    top = temp;   
    size++;
}

// remove first
void Stack::pop() {
    if (size == 0) {
        cout << "Stack is empty : UNDERFLOW"<< endl;
    } else if (size == 1) {
       top = NULL;
       size = 0;
    } else {
       top = top->next;
       size--; 
    }
}

int Stack::peek() {
    cout << "Top element is : " << top->data << endl;
}

bool Stack::isEmpty(){
    if(size == 0){
        cout << "Stack is empty"<< endl;
        return true;
    }
    else{
        cout << "Stack is NOT empty"<< endl;
        return false;
    }
} 

void Stack::display() {

    if (top == NULL) {
        cout << "Stack is empty!" << endl;
    }
    else {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        cout <<"Size of Stack : " << size << endl;
    }
}


int main(){
    Stack* st = new Stack();
    cout << "CHOOSE ANY ONE OPTION" << endl;
    cout << "========================" << endl;
    cout << "1. push()" << endl;
    cout << "2. pop()" << endl;
    cout << "3. top()" << endl;
    cout << "4. isEmpty()" << endl;
 
    int n;
    do{
        cout << "Enter choice :";
        cin >> n;

        switch(n){
            case 1 : {
                int data;
                cout << "Enter data :";
                cin >> data;
                st->push(data);
                cout <<"Stack -> ";
                st->display();
                cout<<endl;
                break;
            }
            case 2 : {
                st->pop();
                cout <<"Stack -> ";
                st->display();
                cout<<endl;
                break;
            }
            case 3 : {
                st->peek();
                cout <<"Stack -> ";
                st->display();
                cout<<endl;
                break;
            }
            case 4 : {
                st->isEmpty();
                cout <<"Stack -> ";
                st->display();
                cout<<endl;
                break;
            }
        }

    }while(n>0 && n<5);

   return 0;
}