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

        LinkedList() { 
            head = NULL;
            tail = NULL;
        }

        ~LinkedList() {}; 
 
        void addLast(int data);
        void addFirst(int data);
        void addAtIndex(int idx , int data);
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
        tail->next = temp;
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

void reverse(LinkedList* list){
    Node* prev = NULL;
    Node* curr = list->head;

    while(curr != NULL){
        Node* forward = curr->next;
        curr->next = prev;

        prev = curr;
        curr = forward;
    }

    Node* temp = list->head;
    list->head = list->tail;
    list->tail = temp;
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
        cout <<"Size of list : " << size << endl;
    }
}

int main(){
    LinkedList* list = new LinkedList();
    cout << "CHOOSE ANY ONE OPTION" << endl;
    cout << "========================" << endl;
    cout << "1. Add last" << endl;
    cout << "2. Add First" << endl;
    cout << "3. Add At Any Index" << endl;
    cout << "4. Reverse LIST" << endl;
 
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
                cout<<"Original List :";
                list->display();
                cout<<endl;
                cout << "Reverse list :";
                reverse(list);
                list->display();
                break;
            }
        }
        }while(n>0 && n<5);
    return 0;
}