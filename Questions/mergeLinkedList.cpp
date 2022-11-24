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
        void deleteLast();
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

LinkedList* merge(LinkedList* list1, LinkedList* list2){
    LinkedList* newList = new LinkedList();
    Node* temp1 = list1->head;
    Node* temp2 = list2->head;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data <= temp2->data){
            newList->addLast(temp1->data);
            temp1 = temp1->next;
        }
        else{
            newList->addLast(temp2->data);
            temp2 = temp2->next;
        }
    }

    if(temp1 == NULL){
        while(temp2 != NULL){
            newList->addLast(temp2->data);
            temp2 = temp2->next;
        }
    }

    if(temp2 == NULL){
        while(temp1 != NULL){
            newList->addLast(temp1->data);
            temp1 = temp1->next;
        }
    }

    return newList;
}

int main(){
    LinkedList* list1 = new LinkedList();
    LinkedList* list2 = new LinkedList();

    list1->addLast(21);
    list1->addLast(31);
    list1->addLast(41);
    list1->addLast(51);

    list2->addLast(15);
    list2->addLast(25);
    list2->addLast(35);
    list2->addLast(45);

    list1->display();
    cout<<endl;
    list2->display();
    cout<<endl;

    LinkedList* list3 = merge(list1, list2);
    list3->display();

    return 0;
}