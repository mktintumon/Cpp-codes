/*
    Write a program to implement Binary search on 1D array of Employee
    structure (contains employee_ name, emp_ no, emp_ salary), with key as
    emp_ no. And count the number of comparison happened.
*/

#include <bits/stdc++.h>
using namespace std;

// Employee
struct Employee{
    string name;
    int emp_no;
    int salary;
};

// Binary search function
int binarySearch(Employee arr[], int size, int key){
    int low = 0;
    int high = size - 1;
    int mid;
    int count = 0;
    while (low <= high){
        mid = low + (high - low) / 2;
        if (arr[mid].emp_no <key)
        {
            low = mid + 1;
        }
        else if (arr[mid].emp_no > key)
        {
            high = mid - 1;
        }
        else
        {
            cout << "Number of comparisons: " << count << endl;
            return mid;
        }
        count++;
    }
    cout << "Number of comparisons: " << count
         << endl;
    return -1;
}

int main()
{
    Employee arr[] = {{"Alice", 1, 50000}, {"Bob", 2, 55000}, {"Charlie", 3, 60000}, {"Dave", 4, 65000}};
    int key;
    cout << "Enter employee Id to search : "; 
    cin>>key;
    int index = binarySearch(arr, 4,key);
    if (index >= 0)
    {
        cout << "Employee found: " << arr[index].name << endl;
    }
    else
    {
        cout << "Employee not found." << endl;
    }
    return 0;
}
