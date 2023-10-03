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

void insertNode(Node* &tail,int element, int data){
	//assuming that the lement is present in the list
	if(tail==NULL){
		Node* newNode = new Node(data);
		tail=newNode;
		newNode->next=newNode;
	}
	//non-empty list
	else{
		Node* cur = tail;
		while(cur->data != element){
			cur=cur->next;
		}
		//element found -> cur representing element node
		Node* temp = new Node(data);
		temp->next=cur->next;
		cur->next=temp;
	}
	
}

void deleteNode(Node* &tail, int value){
	//empty list
	if(tail==NULL) {
		cout<<"Empty List"<<endl;
		return;
	}
	else{	
		//non-empty
		//assuming that value is present in the list
		Node* prev = tail;
		Node* cur = prev -> next;
		while(cur->data!=value){
			prev = cur;
			cur = cur->next;
		}
		prev->next=cur->next;
		//for single node
		if(cur==prev){
			tail=NULL;
		}
		//>=2 modes
		else if(tail==cur){
			tail=prev;
		}
		cur->next=NULL;
		delete cur;
	}
}

void print(Node* tail){
	Node* temp = tail;
	if(tail==NULL){
		cout<<"EMPTY LIST"<<endl;
		return;	
	}
	do{
		cout << tail->data<<" ";
		tail=tail->next;
	}while(tail!=temp);
	cout<<endl;
}

int main(){
	Node* tail = NULL;
	insertNode(tail,5,3);
	print(tail);
	insertNode(tail,3,5);
	print(tail);
	deleteNode(tail,3);
	print(tail);
	return 0;
}
