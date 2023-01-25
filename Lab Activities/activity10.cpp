/*
Write a program to implement Radix Sort on a 1D array of Faculty structure
(contains faculty name, faculty_ ID, subject_ codes, class_ names), with key as
faculty_ ID. And count the number of swaps performed.

*/

#include <iostream>
#include <vector>
using namespace std;
class Faculty
{
public:
    string faculty_name;
    int faculty_id;
    string subject_codes;
    string class_names;
    void display()
    {
        cout << faculty_name << "\t\t\t" << faculty_id << "\t\t\t"
             << subject_codes << "\t\t\t" << class_names << endl;
    }
};
int getMax(vector<Faculty> &arr, int N)
{
    int m = arr[0].faculty_id;
    for (int i = 0; i < N; i++)
    {
        if (arr[i].faculty_id > m)
        {
            m = arr[i].faculty_id;
        }
    }
    return m;
}
void countSort(vector<Faculty> &arr, int N, int pos)
{
    int count[10] = {0};
    vector<Faculty> res(N);
    for (int i = 0; i < N; i++)
    {
        count[(arr[i].faculty_id / pos) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = N - 1; i >= 0; i--)
    {
        res[count[(arr[i].faculty_id / pos) % 10] - 1] = arr[i];
        count[(arr[i].faculty_id / pos) % 10]--;
    }
    for (int i = 0; i < N; i++)
    {
        arr[i] = res[i];
    }
}
void radixSort(vector<Faculty> &arr, int N)
{
    int max = getMax(arr, N);
    for (int pos = 1; max / pos > 0; pos *= 10)
    {
        countSort(arr, N, pos);
    }
}
int main()
{
    int fid;
    string fname, scode, cname;
    vector<Faculty> faculties;
    int n;
    cout << "Enter the number of faculty members : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter faculty name : ";
        cin >> fname;
        cout << "Enter faculty id : ";
        cin >> fid;
        cout << "Enter subject code : ";
        cin >> scode;
        cout << "Enter class name : ";
        cin >> cname;
        cout << endl;
        faculties.push_back({fname, fid, scode, cname});
    }
    radixSort(faculties, n);
    cout << endl
         << "Display Sorted Faculties : " << endl;
    cout << endl
         << "Faculty Name \t"
         << "Faculty Id \t"
         << "Subject Codes \t"
         << "Class Name" << endl;
    for (int i = 0; i < n; i++)
    {
        faculties[i].display();
    }
    return 0;
}
