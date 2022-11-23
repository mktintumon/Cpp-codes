/*
    To facilitate a thorough net surfing, any web browser has back and forward 
    buttons that allow the user to move backward and forward through a series 
    of web pages. To allow the user to move both forward and backward two 
    stacks are employed. When the user presses the back button, the link to the 
    current web page is stored on a separate stack for the forward button. As 
    the user moves backward through a series of previous pages, the link to 
    each page is moved in turn from the back to the forward stack.
    When the user presses the forward button, the action is the reverse of the 
    back button. Now the item from the forward stack is popped, and becomes 
    the current web page. The previous web page is pushed on the back stack. 
    Simulate the functioning of these buttons using array implementation of
    Stack. Also provide options for displaying the contents of both the stacks
    whenever required.
*/

#include <bits/stdc++.h>
using namespace std;
class Stack{
    int size;
    int top;
    int *s;

public:
    Stack() 
    {
        top = -1;
        size = 20;
        s = new int[size];
    }
    ~Stack()
    {
        delete[] s;
    }
    bool isEmpty(); 
    bool isFull();  
    void push(int val);
    int topEle();
    void pop();
    void show();
};

bool Stack::isEmpty(){
    if (top == -1)
        return true;
    else
        return false;
}

bool Stack::isFull(){
    if (top == size - 1)
        return true;
    else
        return false;
}

void Stack::push(int val){
    if (!isFull())
    {
        top++;
        s[top] = val;
    }
    else
    {
        cout << "overflow";
    }
}

int Stack::topEle(){
    return s[top];
}

void Stack::pop(){
    if (isEmpty())
    {
        cout << "stack underflow";
    }
    else
    {
        top--;
    }
}

void Stack::show(){
    for (int i = top; i >= 0; i--)
    {
        cout << s[i] << " " << flush;
    }
    cout << endl;
}

class Browser{
    int current_page;
    int last_page;
    Stack forward;
    Stack backward;

public:
    Browser()
    {
        current_page = 0;
    }
    int visit_newpage();
    int go_forward();
    int go_backward();
    void see_backward();
    void see_forward();
};

int Browser::visit_newpage(){
    if (current_page == 0)
    {
        current_page = 1;
        last_page = current_page;
    }
    else
    {
        backward.push(current_page);
        last_page++;
        current_page = last_page;
    }
    return current_page;
}

int Browser::go_backward(){
    if (backward.isEmpty())
    {
        cout << "NO BACKWARD AVAILABLE" << endl;
    }
    else
    {
        forward.push(current_page);
        current_page = backward.topEle();
        backward.pop();
    }
    return current_page;
}


int Browser::go_forward(){
    if (forward.isEmpty())
        cout << "NO FORDWARD AVAILABLE" << endl;
    else
    {
        backward.push(current_page);
        current_page = forward.topEle();
        forward.pop();
    }
    return current_page;
}

void Browser::see_backward(){
    if(backward.isEmpty()) cout << "NO BACKWARD CONTENT"<<endl;
    else{
        cout << "BACKWARD VIEW" << endl;
        backward.show();
        cout << endl;
    }
}

void Browser::see_forward(){
    if(forward.isEmpty()) cout << "NO FORWARD CONTENT"<<endl;
    else{
        cout << "FORWARD VIEW" << endl;
        forward.show();
    }
}

int main(){
    Browser browser;
    int choice, currently = 0;

    do{
        cout << "1.New\n2.forward\n3.backward\n4.display forward\n5.display backward\n6.exit" << endl;
        cout << "enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            currently = browser.visit_newpage();
            break;
        case 2:
            currently = browser.go_forward();
            break;
        case 3:
            currently = browser.go_backward();
            break;
        case 4:
            browser.see_forward();
            break;
        case 5:
            browser.see_backward();
            break;
        case 6:
            return 0;
            break;

        default:
            cout << "wrong choice";
            break;
        }

        cout << "****************************" << endl;
        cout << "********  PAGE => " << currently <<"  *******" << endl;
        cout << "****************************" << endl;

    } while (choice != 6);

    return 0;
}