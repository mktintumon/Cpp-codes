#include<iostream>
using namespace std;

class DCLinkedList{
	class Node{
		public:
		int val;
		Node *prev, *next;
		Node(int n){
			val = n;
			prev = NULL;
			next = NULL;
		}
	};
	
	Node *head;
	int size;
	public:
		
	DCLinkedList(){
		head = NULL;
		size = 0;
	}
	
	void addAtFirst(int n){
		size++;
		Node *newN = new Node(n);
		if(head == NULL){
			head = newN;
			head->prev = newN;
			head->next = newN;
			return;
		}
		Node *temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = newN;
		newN->prev = temp;
		newN->next = head;
		head->prev = newN;
		head = newN;
	}
	
	void addAtEnd(int n){
		size++;
		Node *newN = new Node(n);
		if(head == NULL){
			head = newN;
			head->prev = newN;
			head->next = newN;
			return;
		}
		Node *temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = newN;
		newN->prev = temp;
		newN->next = head;
		head->prev = newN;
	}
	
	void addAtPos(int n, int pos){
		if(head == NULL){
			Node *newN = new Node(n);
			head = newN;
			head->next = newN;
			return;
		} 
		if(pos == 0){
			addAtFirst(n);
			return;
		}
		if(pos == size){
			addAtEnd(n);
			return;
		}
		pos--;
		Node* newN = new Node(n);
		Node* temp = head;
		while(pos > 0){
			temp = temp->next;
			pos--;
		}
		newN->prev = temp;
		newN->next = temp->next;
		temp->next->prev = newN;
		temp->next = newN;
		size++;
	}
	
	void deleteFisrt(){
		if(head == NULL){
			cout << "UnderFlow !!" << endl;
			return;
		}
		if(size == 1){
			head = NULL;
			size--;
			return;
		}
		size--;
		Node* temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = head->next;
		head->next->prev = temp;
		head = head->next;
	}
	
	void deleteEnd(){
		if(head == NULL){
			cout << "UnderFlow !!" << endl;
			return;
		}
		if(size == 1){
			head = NULL;
			size--;
			return;
		}
		size--;
		Node* temp = head;
		while(temp->next->next != head){
			temp = temp->next;
		}
		temp->next = head;
		head->prev = temp;
	}
	
	void deleteData(int data){
		if(head == NULL){
			cout << "UnderFlow !!" << endl;
			return;
		}
		if(data == head->val){
			deleteFisrt();
			return;
		}
		size--;
		Node* temp = head;
		while(temp->next->val != data){
			temp = temp->next;
		}
		temp->next->next->prev = temp;
		temp->next = temp->next->next;
	}
	
	void display(){
		if(head == NULL)
			return;
		Node* temp = head;
		while(temp->next != head){
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << temp->val << " " << endl;	
		cout << "Size : " << size << endl;
	} 
	 
};

 main(){
	DCLinkedList *list = new DCLinkedList();
	
	cout << "Choose any one..."<<endl ;
	cout << " 1. Add value at first"<<endl;
	cout << " 2. Add value at last"<<endl;
	cout << " 3. Add value at given position"<<endl;
	cout << " 4. Delete first"<<endl;
	cout << " 5. Delete last"<<endl;
	cout << " 6. Delete given data"<<endl;
	cout << endl;
	int n;
	
	do{
		cout << "Enter choice >>";
		cin >> n;
		switch(n){
			case 1:{
				cout <<"Enter value : ";
				int data;
				cin >> data;
				list->addAtFirst(data);
				cout << "LIST -> ";
				list->display();
				cout<<endl;
				break;
			}
			case 2:{
				cout <<"Enter value : ";
				int data;
				cin >> data;
				list->addAtEnd(data);
				cout << "LIST -> ";
				list->display();
				cout<<endl;
				break;
			}
			case 3:{
				cout <<"Enter value : ";
				int data, pos;
				cin >> data;
				cout << "Enter position :";
				cin >> pos;
				list->addAtPos(data, pos);
				cout << "LIST -> ";
				list->display();
				cout<<endl;
				break;
			}
			case 4:{
				list->deleteFisrt();
				cout << "LIST -> ";
				list->display();
				cout<<endl;
				break;
			}
			case 5:{
				list->deleteEnd();
				list->display();
				cout<<endl;
				break;
			}
			case 6:{
				cout <<"Enter value to delete : ";
				int data;
				cin >> data;
				list->deleteData(data);
				cout << "LIST -> ";
				list->display();
				cout<<endl;
				break;
			}
		}
	}while(n>0 && n < 7);
	
}