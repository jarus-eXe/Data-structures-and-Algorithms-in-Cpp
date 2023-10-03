#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *prev;
		Node *next;
		//CONSTRUCTOR
		Node(int data){
			this->data = data;
			this->next = NULL;
			this->prev = NULL;
		}
		~Node(){
			int val = this->data;
			if(next!=NULL){
				delete next;
				next = NULL;
			}
			cout << "Memory free with data "<<val<<endl;
		}
};
//traversing
void display(Node* &head){
	Node* temp = head;
	while (temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}
//getting length
int getLength(Node* head){
	int len =0;
	Node* temp = head;
	while (temp != NULL){
		len++;
		temp = temp -> next;
	}
	return len;
}

void insertAtHead(Node* &head,Node* &tail, int data){
	//empty list
	if(head==NULL){
		Node* temp = new Node(data);
		head = temp;	
		tail = temp;	
	}
	else{
		Node* temp = new Node(data);
		temp->next = head;
		head -> prev = temp;
		head = temp;
	}
}

void insertAtTail(Node* &tail, Node* &head,int data){
	if(tail==NULL){
		Node* temp = new Node(data);
		tail = temp;	
		head = temp;	
	}
	else{
		Node* temp = new Node(data);
		tail->next = temp;
		temp-> prev = tail;
		tail=temp;
	}
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int data){
	//insert at first
	if(pos==1){
		insertAtHead(head,tail,data);
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
		insertAtTail(tail,head,data);
		return;
	}
	//creating a node for data
	Node* nodeToInsert = new Node(data);
	nodeToInsert -> next = temp -> next;
	temp -> next -> prev = nodeToInsert;
	temp -> next = nodeToInsert;
	nodeToInsert->prev = temp;
}

void deleteNode(Node* &head, int pos){
	//delete first node
	if(pos==1){
		Node* temp = head;
		temp->next->prev=NULL;
		head = temp -> next;
		temp->next=NULL;
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
		cur -> prev = NULL;
		prev -> next = cur -> next;
		cur->next=NULL;
		delete cur;
		return;
	}
}


int main(){
	//Node* node1 = new Node(10);
	Node* head = NULL;
	Node* tail = NULL;
	//display(head);
	//cout<<getLength(head)<<endl;
	insertAtHead(head,tail,11);
	insertAtHead(head,tail,15);
	insertAtHead(head,tail,18);
	display(head);
	insertAtTail(tail,head,9);
	insertAtTail(tail,head,8);
	insertAtTail(tail,head,7);
	display(head);
	insertAtPosition(head,tail,3,99);
	insertAtPosition(head,tail,1,101);
	insertAtPosition(head,tail,9,919);
	display(head);
	deleteNode(head,1);
	display(head);
	deleteNode(head,6);
	display(head);
	deleteNode(head,7);
	display(head);
	return 0;
}
