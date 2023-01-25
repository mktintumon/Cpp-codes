/*
    In a theme park, the Roller-Coaster ride is started only when a good
    number of riders line up in the counter (say 20 members). When the ride
    proceeds with these 20 members, a new set of riders will line up in the
    counter. This keeps continuing. Implement the above scenario of lining up
    and processing using arrays with Queue ADT.
*/

#include <iostream>
using namespace std;
#define MaxRider 20
struct Queue
{
    // structure for Queue ADT
    int Rider[MaxRider];
    int First;
    // begning of the Queue
    int Rear;
    // Ending of the queue
} r;
bool Queue_is_full()
{
    // return true if Queue is Full else return false
    return r.Rear == MaxRider - 1;
}
bool Queue_is_empty()
{
    // return true if Queue is empty else return false
    return r.Rear == -1;
}
void enqueue()
{
    // push rider in the queue
    int n;
    cout << "Enter rider number: ";
    cin >> n;
    if (!Queue_is_full())
        r.Rider[++r.Rear] = n;
    // increment rear whenever a rider is pushed in the queue
    else
        cout << "\nThis Queue is now full, allow riders to enter in Rollar Coaster to continue...\n";
}
void dequeue()
{
    // To empty the queue, and allow space for new riders
    if (!Queue_is_empty())
    {
        cout << "\nRider number " << r.Rider[r.First] << " is allowed to the Roller Coaster";
        r.First++;
    }
    else
        cout << "\nQueue is currently empty!!";
}
int main()
{
    r.First = 0;
    r.Rear = -1;
    int c;
    // initial value of first and rear of the queue
    cout << "\t\t\t****Menue****\n\n";
    while (c != 4)
    {
        cout << "Enter 1 : To allow the rider in the Queue\n";
        cout << "Enter 2 : To check if Queue is full and to allow all riders to enter the Roller Coaster\n";
        cout << "Enter 3 : To see all riders in Queue\n";
        cout << "Enter 4 : To Exit\n";
        cout << "Enter input: ";
        cin >> c;
        switch (c)
        {
        case 1:
            enqueue();
            // function to push rider in the queue
            break;
        case 2:
            if (Queue_is_full())
            {
                // check if queue is full
                for (int i = 1; i <= MaxRider; i++)
                {
                    dequeue();
                    if (i == MaxRider)
                        // if queue becomes empty reset the value of first and rear
                        r.First = 0, r.Rear = -1;
                }
                cout << endl;
            }
            else
                cout << "\nNot enough riders in the queue\n";
            // message when ride cannot operate
            break;
        case 3:
            cout << "\nCurrent Queue status is\nRider Number: ";
            // to display the riders in the queue
            if (r.Rear == -1)
                cout << "Queue is Empty";
            else
            {
                for (int i = 0; i <= r.Rear; i++)
                    // iterating over the array of riders
                    if (i != r.Rear)
                        cout << r.Rider[i] << ", ";
                    else
                        cout << r.Rider[i] << ".";
            }
            cout << endl;
            break;
        case 4:
            break;
        }
        cout << endl;
    }
    return 0;
}