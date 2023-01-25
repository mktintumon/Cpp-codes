/*
Assume in the Regional Passport Office, a multitude of applicants
arrive each day for passport renewal. A list is maintained in the database to store the renewed
passports arranged in the increased order of passport ID. The list already would contain their
cords renewed till the previous day. Apply Insertion sorting technique to place the current
day’s records in the list. Laterthe office personnel wish to sorting the records based on the
date of renewal so as to know the count of renewals done each day. Taking into consideration
the fact that each record has several fields (around 25 fields), follow Selection sorting logic to
implement the same.

*/
#include <iostream> 
using namespace std;

struct Date{
    int year, month, day;
};

struct passport{
    int id;
    struct Date d;
};

int compare(const struct Date d1,const struct Date d2){
    if (d1.year < d2.year)
        return 1;
    if (d1.year == d2.year && d1.month < d2.month)
        return 1;
    if (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day)
        return 1;
    return 0;
}

int main(){
    int i, j, min, n;
    struct passport t;
    struct passport p1[100], p2[100];

    cout << "Date of Renewal Should Be in The Format - DD MM YY (15 05 2002)" << endl << endl;
    cout << "Enter number of records: ";
    cin >> n;
    cout << "\nEnter records :\n ";
    for (i = 0; i < n; i++) {
        cout << "\nEnter The Passport ID:";
        cin >> p1[i].id;
        cout << "Enter the Date of Renewal: ";
        cin >> p1[i].d.day >> p1[i].d.month >> p1[i].d.year;
    }

    for (i = 0; i < n;i++){
        p2[i] = p1[i];
    }

    for (i = 1; i < n;i++){
        t = p1[i];
        j = i - 1;
        while (p1[j].id > t.id && j >= 0)
        {
            p1[j + 1] = p1[j];
            j--;
        }
        p1[j + 1] = t;
    }

    cout << "\n \n";
    cout << "Records Of Sorted Data Based On The Passport ID::\n ";
    for (i = 0; i < n; i++) {
        cout << "\nid:"; 
        cout << p1[i].id;
    cout << "\t\t\tdate: ";
    cout << p1[i].d.day << "-" << p1[i].d.month << "-" << p1[i].d.year;
    }

    cout << "\n \n";
    for (i = 0; i < n; i++){
        min = i;
        for (j = i + 1; j < n; j++){
            if (compare(p2[j].d,p2[min].d)){
                min = j;
            }
        }
    }

    t = p2[i];
    p2[i] = p2[min];
    p2[min] = t;

    cout << "records sorted based on date of renewal::\n ";
    for (i = 0; i < n; i++) {
        cout<< "\ndate: ";
        cout << p2[i].d.day << "-" << p2[i].d.month << "-" << p2[i].d.year;
        cout << "\t\t\tid: ";
        cout << p2[i].id << endl;
    }
}
  