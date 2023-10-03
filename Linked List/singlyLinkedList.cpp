#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		//CONSTRUCTOR
		Node(int data){
			this->data = data;
			this->next = NULL;
		}
		//DESTRUCTOR
		~Node(){
			int value = this-> data;
			if(this->next!=NULL){
				delete next;
				this->next=NULL;
			}
			cout<<"MEMORY FREE FOR NODE WITH DATA " << value << endl;;
		}
		
};

void insertAtHead(Node* &head, int data){
	//refernce due to change in original linked list
	
	//new node creation
	Node* temp = new Node(data);
	temp->next = head;
	head = temp;
}

void insertAtTail(Node* &tail, int data){
	Node* temp = new Node(data);
	tail -> next = temp;
	tail = tail -> next;	
}

void insertAtPosition(Node* &head,Node* &tail,int pos, int data){
	//insert at first
	if(pos==1){
		insertAtHead(head,data);
		return;
	}
	Node* temp = head;
	int count = 1;
	while(count < (pos - 1)){
		temp = temp-> next;
		count++;
	}
	
	//insert at end position
	if(temp->next==NULL){
		insertAtTail(tail,data);
		return;
	}
	//creating a node for data
	Node* nodeToInsert = new Node(data);
	nodeToInsert -> next = temp -> next;
	temp -> next = nodeToInsert;
}

void deleteNode(Node* &head, int pos){
	//delete first node
	if(pos==1){
		Node* temp = head;
		head=head->next;
		temp -> next = NULL;
		delete temp;
	}
	else{
		//delete any node
		Node* cur = head;
		Node* prev = NULL;
		int cnt = 1;
		while(cnt<pos){
			prev = cur;
			cur = cur->next;
			cnt++;
		}
		prev -> next = cur -> next;
		cur -> next = NULL;
		delete cur;
		return;
	}
}

void display(Node* &head){
	Node* temp = head;
	while (temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}


int main()
{
	//created a new node
	Node *node1 = new Node(10);
	//cout << node1->data << endl;
	//cout << node1 -> next << endl;	
	
	//head pointed to node1
	Node* head = node1;
	Node* tail = node1;
	display(head);
	insertAtTail(tail,12);
	display(head);
	insertAtTail(tail,15);
	display(head);
	insertAtPosition(head,tail, 3, 22);
	display(head);
	deleteNode(head,4);
	display(head);
	cout << "tail "<<tail;
	return 0;
}
