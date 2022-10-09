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
		cout << temp->val << " ";	
		cout << endl;
	} 
	
	void displayWithArrow(){
		if(head == NULL)
			return;
		Node* temp = head;
		cout << size << endl;
		while(temp->next != head){
			if(temp->prev != NULL)
				cout << temp->prev->val << " <- ";
			cout << temp->val << " -> ";
			if(temp->next != NULL)
				cout << temp->next->val << " ";
			temp = temp->next;
			cout <<endl;
		}
		if(temp->prev != NULL)
			cout << temp->prev->val << " <- ";
		cout << temp->val << " -> ";
		if(temp->next != NULL)
			cout << temp->next->val << " ";
		temp = temp->next;
		cout <<endl;
	}
	 
};

 main(){
	DCLinkedList *list = new DCLinkedList();
	cout << "LinkedList" << endl<<endl;
	cout << "Choose any one..."<<endl ;
	cout << " 1. Add value at first"<<endl;
	cout << " 2. Add value at last"<<endl;
	cout << " 3. Add value at given position"<<endl;
	cout << " 4. Delete first"<<endl;
	cout << " 5. Delete last"<<endl;
	cout << " 6. Delete given data"<<endl;
	cout << " 7. Display"<<endl;
	cout << " 8. Display with arrow"<<endl;
	cout << endl;
	int n;
	
	do{
		cout << ">>";
		cin >> n;
		switch👎{
			case 1:{
				cout <<"Enter value : ";
				int data;
				cin >> data;
				list->addAtFirst(data);
				cout<<endl;
				break;
			}
			case 2:{
				cout <<"Enter value : ";
				int data;
				cin >> data;
				list->addAtEnd(data);
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
				cout<<endl;
				break;
			}
			case 4:{
				list->deleteFisrt();
				cout<<"Item deleted successfully !!";
				cout<<endl<<endl;
				break;
			}
			case 5:{
				list->deleteEnd();
				cout<<"Item deleted successfully !!";
				cout<<endl<<endl;
				break;
			}
			case 6:{
				cout <<"Enter value to delete : ";
				int data;
				cin >> data;
				list->deleteData(data);
				cout<<"Item deleted successfully !!";
				cout<<endl<<endl;
				break;
			}
			case 7:{
				cout << "List : ";
				list->display();
				cout<<endl;
				break;
			}
			case 8:{
				cout << "List : ";
				list->displayWithArrow();
				cout<<endl;
				break;
			}
		}
	}while(n>0 && n < 9);
	
}