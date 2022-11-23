/*
    Write a program to implement a 3-stacks of size ‘m’ in an array of size ‘n’ 
    with all the basic operations such as IsEmpty(i), Push(i), Pop(i), IsFull(i) 
    where ‘i’ denotes the stack number (1,2,3), m = n/3. Stacks are not 
    overlapping each other. Leftmost stack facing the left direction and other 
    two stacks are facing in the right direction.
*/

#include <bits/stdc++.h>
using namespace std;
class StackInArray
{
    int *A;
    int size;
    int top1, top2, top3;

public:
    StackInArray(int n);
    ~StackInArray();
    bool isEmpty(int i);
    bool isFull(int i);
    void push(int value, int stackNumber);
    void pop(int stackNumber);
    void display(int stackNumber);
};

void StackInArray::display(int stackNumber)
{
    switch (stackNumber)
    {
    case 1:
        if (isEmpty(1))
        {
            cout << "stack1 is empty" << endl;
        }
        else
        {
            int p = top1;
            cout << "stack1=>";
            while (p != (size / 3))
                cout << A[p++] << " ";
            cout << endl;
        }
        break;
    case 2:
        if (isEmpty(2))
        {
            cout << "stack2 is empty" << endl;
        }
        else
        {
            int p = top2;
            cout << "stack2=>";
            while (p != ((size / 3) - 1))
                cout << A[p--] << " ";
            cout << endl;
        }
        break;
    case 3:
        if (isEmpty(3))
        {
            cout << "stack3 is empty" << endl;
        }
        else
        {
            int p = top3;
            cout << "stack3=>";
            while (p != (2 * (size / 3) - 1))
                cout << A[p--] << " ";
            cout << endl;
        }
        break;
    default:
        cout << "enter valid staCK number";
        break;
    }
}
void StackInArray::pop(int stackNumber)
{
    switch (stackNumber)
    {
    case 1:
        if (isEmpty(1))
            cout << "stack is empty";
        else
        {
            cout << "poped element is=>" << A[top1++];
        }
        cout << endl;
        break;
    case 2:
        if (isEmpty(2))
            cout << "stack is empty";
        else
        {
            cout << "poped element is=>" << A[top2--];
        }
        cout << endl;
        break;
    case 3:
        if (isEmpty(3))
            cout << "stack is empty";
        else
        {
            cout << "poped element is=>" << A[top3--];
        }
        cout << endl;
        break;
    default:
        cout << "enter valid staCK number";
        break;
    }
}

void StackInArray::push(int value, int stackNumber)
{
    switch (stackNumber)
    {
    case 1:
        if (!isFull(1))
        {
            top1--;
            A[top1] = value;
        }
        else
            cout << "stack is full" << endl;
        break;
    case 2:
        if (!isFull(2))
        {
            top2++;
            A[top2] = value;
        }
        else
            cout << "stack is full" << endl;
    case 3:
        if (!isFull(3))
        {
            top3++;
            A[top3] = value;
        }
        else
            cout << "stack3 is full" << endl;

    default:
        cout << "enter valid staCK number";
        break;
    }
}

bool StackInArray::isFull(int i)
{
    switch (i)
    {
    case 1:
        if (top1 == 0)
            return true;
        else
            return false;
        break;
    case 2:
        if (top2 == (2 * (size / 3) - 1))
            return true;
        else
            return false;
        break;
    case 3:
        if (top3 == size - 1)
            return true;
        else
            return false;
        break;
    default:
        cout << "enter valid staCK number";
        break;
    }
}

bool StackInArray::isEmpty(int i)
{
    switch (i)
    {
    case 1:
        if (top1 == (size / 3))
            return true;
        else
            return false;
        break;
    case 2:
        if (top2 == (size / 3) - 1)
            return true;
        else
            return false;
        break;
    case 3:
        if (top3 == (2 * (size / 3)) - 1)
            return true;
        else
            return false;
        break;
    default:
        cout << "please select valid stack number";
        break;
    }
}

int main()
{
    return 0;
}