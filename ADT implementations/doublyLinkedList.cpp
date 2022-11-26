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
        cout <<"Size of list : " << size << endl;
    }
    
}
 
int main(){
    DoublyLL* list = new DoublyLL();
    cout << "CHOOSE ANY ONE OPTION" << endl;
    cout << "========================" << endl;
    cout << "1. Add last" << endl;
    cout << "2. Add First" << endl;
    cout << "3. Add At Any Index" << endl;
    cout << "4. Delete last" << endl;
    cout << "5. Delete First" << endl;
    cout << "6. Delete At Any Index" << endl;
 
    int n;
    do{
        cout << "Enter choice :";
        cin >> n;

        switch(n){
            case 1 : {
                int data;
                cout << "Enter data :";
                cin >> data;
                list->addLast(data);
                cout << "LIST -> ";
                list->display();
                cout<<endl;
                break;
            }
            case 2 : {
                int data;
                cout << "Enter data :";
                cin >> data;
                list->addFirst(data);
                cout << "LIST -> ";
                list->display();
                cout<<endl;
                break;
            }
            case 3 : {
                int data;
                int idx;
                cout << "Enter data :";
                cin >> data;
                cout << "Enter index :";
                cin >> idx;
                list->addAtIndex(idx , data);
                cout << "LIST -> ";
                list->display();
                cout<<endl;
                break;
            }
            case 4 : {
                list->deleteLast();
                cout << "Data deleted" << endl;
                cout << "LIST -> ";
                list->display();
                cout<<endl;
                break;
            }
            case 5 : {
                list->deleteFirst();
                cout << "Data deleted" << endl;
                cout << "LIST -> ";
                list->display();
                cout<<endl;
                break;
            }
            case 6 : {
                int idx;
                cout << "Enter index to delete :";
                cin >> idx;
                list->deleteAtIndex(idx);
                cout << "Data deleted" << endl; 
                cout << "LIST -> ";
                list->display();
                cout<<endl;
                break;
            }
        }
    }while(n>0 && n<7);

    return 0;
}