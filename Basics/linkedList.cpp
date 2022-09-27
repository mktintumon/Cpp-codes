#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList{
    public:
        Node* head;
        Node* tail;
        int size = 0;

        // constructor
        LinkedList() { 
            head = NULL;
            tail = NULL;
        }

        // destructor
        ~LinkedList() {}; 

        // ADDITION 
        void addLast(int data);
        void addFirst(int data);
        void addAtIndex(int idx , int data);

        // DELETION
        void deleteFirst();
        void deleteLast();
        void deleteAtIndex(int idx);

        //PRINT
        void display();
};

void LinkedList::addLast(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;

    if(size == 0){
        head = temp;
        tail = temp;
    }
    else{
        head->next = temp;
        tail = temp;
    }

    size++;
}

void LinkedList::addFirst(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = head;

    head = temp;
    if(size == 0) tail = temp;

    size++;
}

void LinkedList::addAtIndex(int idx , int data){
    if(idx < 0 || idx > size){
        cout << "Invalid index , Out of list size"<< endl; 
    }
    else if(idx == 0){
        addFirst(data);
    }
    else if(idx == size){
        addLast(data);
    }
    else{
        Node* node = new Node();
        node->data = data;

        Node* temp = head;
        for(int i = 0; i<idx-1 ; i++){
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;

        size++;
    }
}

void LinkedList::deleteFirst(){
   if (size == 0) {
        cout << "List is empty"<< endl;
    } else if (size == 1) {
       head = tail = NULL;
       size = 0;
    } else {
       head = head->next;
       size--; 
    }
}

void LinkedList::deleteLast(){
   if (size == 0) {
        cout << "List is empty"<< endl;
    } else if (size == 1) {
       head = tail = NULL;
       size = 0;
    } else {
       Node* temp = head;
       for(int i = 0; i < size-2 ; i++) {
            temp = temp->next;
       }

       tail = temp;
       tail->next = NULL;
       size--;
    }
}

void LinkedList::deleteAtIndex(int idx){
   if(idx < 0 || idx > size){
        cout << "Invalid index , Out of list size"<< endl; 
    }
    else if(idx == 0){
        deleteFirst();
    }
    else if(idx == size){
        deleteLast();
    }
    else{
        Node* node = new Node();

        Node* temp = head;
        for(int i = 0; i<idx-1 ; i++){
            temp = temp->next;
        }

        temp->next = temp->next->next;
        size--;
    }
}

void LinkedList::display() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
    }
    else {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        cout <<"Size of the list : " << size << endl;
    }
}

int main(){
    LinkedList* list = new LinkedList();
    list->addLast(1);
    list->addLast(2);
    list->addFirst(3);
    list->addFirst(4);
    list->addAtIndex(2,5);
    list->deleteFirst();
    list->deleteLast();
    list->deleteAtIndex(0);
 
    list->display();
    delete list;
    return 0;
}