/*
    In a theme park, the Roller-Coaster ride is started only when a good
    number of riders line up in the counter (say 20 members). When the ride
    proceeds with these 20 members, a new set of riders will line up in the
    counter. This keeps continuing. Implement the above scenario of lining up
    and processing using arrays with Queue ADT.
*/

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class Queue{
    public:
        Node* front;
        Node* rear;
        int size = 0;

        // constructor
        Queue() { 
            front = NULL;
            rear = NULL;
        }

        // destructor
        ~Queue() {}; 

        void enqueue(int data);
        void dequeue();
        int peek();
        bool isEmpty();
        void display();
};

// add first element to queue -> backside
void Queue::enqueue(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = rear;

    rear = temp;
    if(size == 0) 
      front = temp;

    size++;
}

// remove last element from queue -> frontside
void Queue::dequeue() {
    if (size == 0) {
        cout << "Queue is empty"<< endl;
    } else if (size == 1) {
       front = rear = NULL;
       size = 0;
    } else {
       Node* temp = rear;
       for(int i = 0; i < size-2 ; i++) {
            temp = temp->next;
       }

       front = temp;
       front->next = NULL;
       size--;
    }
}

int Queue::peek() {
    if(size == 0) cout << "Queue is empty"<< endl;
    else cout << "Front element is : " << front->data << endl;
}

bool Queue::isEmpty(){
    if(size == 0){
        cout << "Queue is empty"<< endl;
        return true;
    }
    else{
        cout << "Queue is NOT empty"<< endl;
        return false;
    }
} 

void Queue::display() {
    if (front == NULL && rear == NULL) {
        cout << "Queue is empty!" << endl;
    }
    else {
        Node* temp = rear;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        cout <<"Size of the Queue : " << size << endl;
    }
}
 
int main(){
  Queue* qu = new Queue();
    qu->enqueue(5);
    qu->enqueue(6);
    qu->enqueue(7);
    qu->enqueue(8);
    qu->enqueue(9);
    qu->dequeue();
    qu->dequeue();
    qu->peek();
    qu->isEmpty();

    qu->display();

  return 0;
}