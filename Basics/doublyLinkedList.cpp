#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

class DoublyLL{
    public:
        Node* head;
        Node* tail;
        int size = 0;

        // constructor
        DoublyLL() { 
            head = NULL;
            tail = NULL;
        }

        // destructor
        ~DoublyLL() {}; 

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

void DoublyLL::addFirst(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = head;
    head->prev = temp;

    head = temp;
    if(size == 0) 
        tail = temp;

    size++;
}

void DoublyLL::addLast(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp->prev = tail;

    if(size == 0){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    size++;
}

void DoublyLL::addAtIndex(int idx , int data){
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
        temp->next->prev = node;

        temp->next = node;
        node->prev = temp;

        size++;
    }
}

void DoublyLL::deleteFirst(){
   if (size == 0) {
        cout << "List is empty"<< endl;
    } else if (size == 1) {
       head = tail = NULL;
       size = 0;
    } else {
       head->next->prev = NULL; 
       head = head->next;
       size--; 
    }
}

void DoublyLL::deleteLast(){
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

void DoublyLL::deleteAtIndex(int idx){
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
        for(int i = 0; i<idx ; i++){
            temp = temp->next;
        }
        
        // BUG
        // little diff from all implementations
        temp->prev->next = temp->next;  
        temp->next->prev = temp->prev;
        size--;
    }
}

void DoublyLL::display() {
    if (head->next == NULL) {
        cout << "List is empty!" << endl;
    }
    else {
        Node* temp = head;
        while (temp != NULL) {
            if(temp->prev == NULL){
                cout << "N" << " <- " << temp->data << " -> " << temp->next->data << endl;
            }
            else if(temp->next == NULL){
                cout << temp->prev->data << " <- " << temp->data << " -> " << "N" << endl;
            }
            else{
                cout << temp->prev->data << " <- " << temp->data << " -> " << temp->next->data << endl;
            }
            temp = temp->next;
        }
        cout << endl;
        cout <<"Size of the list : " << size << endl;
    }
}
 
int main(){
    DoublyLL* dll = new DoublyLL();
    dll->addLast(5);
    dll->addLast(6);
    dll->addLast(7);
    dll->addFirst(8);
    dll->addAtIndex(2,9);
    dll->deleteAtIndex(2);
    dll->deleteFirst();
    dll->deleteLast();
    //dll->deleteAtIndex(1); //---> BUG

    dll->display();

    return 0;
}