/*
    Students of a Programming class arrive to submit assignments. Their
    register numbers are stored in a LIFO list in the order in which the
    assignments are submitted. Write a program using array to display the
    register number of the ten students who submitted first. Register number of
    the ten students who submitted first will be at the bottom of the LIFO list.
    Hence pop out the required number of elements from the top so as to
    retrieve and display the first 10 students.
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack{
    int top;

public:
    int a[MAX];

    Stack()
    {
        top = -1;
    }

    void push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

void Stack::push(int x){
    if (top >= (MAX - 1)){
        cout << "Stack Overflow";
    }
    else{
        top++;
        a[top] = x;
        //cout << x << " pushed\n";
    }
}

int Stack::pop(){
    if (top < 0){
        cout << "Stack Underflow";
        return 0;
    }
    else{
        int x = a[top];
        top--;
        return x;
    }
}

int Stack::peek(){
    if (top < 0){
        cout << "Stack is Empty";
        return 0;
    }
    else{
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty(){
    return (top < 0);
}

void displayStudent(Stack st , int n){
    while(n > 10){
        st.pop();
        n--;
    }

    int* student = new int[10];
    for(int i=9 ; i>=0 ; i--){
        student[i] = st.peek();
        st.pop();
    }

    cout << endl;
    cout << "Marks of first 10 students : ";
    for(int i=0 ; i<10 ; i++){
        cout << student[i] << "," ;
    }
}

int main(){
    Stack st;
    int n;
    cout << "Number of students entries :";
    cin >> n;

    int* store = new int[n];
    int i = 0;
    while(i < n){
        cout << "Marks student " << (i+1) << " : " ;
        cin >> store[i];
        st.push(store[i]);
        i++;
    }

    displayStudent(st , n);

    return 0;
}