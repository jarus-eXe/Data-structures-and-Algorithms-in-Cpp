/*Basic implementation of Stack using Arrays*/

#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

class Stack{
	private:
		int top;
		int arr[5];
		
	public:
		Stack(){
			top = -1;
			for(int i=0;i<5;i++){
				arr[i] = 0;
			}
		}
		
		bool isEmpty(){
			if(top == -1)	//empty stack
				return true;
			else
				return false;	
		}
		
		bool isFull(){
			if(top == 4) return true;
			else return false;
		}
		
		void push(int val){
			if(isFull()){
				cout << "Stack Overflow" << endl;
			}
			else{
				top++; 		//0
				arr[top] = val;
			}
		}
		
		int pop(){
			if(isEmpty()){ 
				cout << "Stack Underflow" << endl;
				return 0;
			}
			else {
				int popValue = arr[top];
				arr[top]=0;
				top--;
				return popValue;
			}
		}
		
		int count(){
			return (top+1);
		}
		
		int peek(int pos){
			if(isEmpty()){
				cout << "Stack Underflow" << endl;
				return 0;
			}
			else{
				return arr[pos];
			}
		}
		
		void change(int pos, int val){
			arr[pos] = val;
			cout << "Value changed at the location " << pos << endl;
		} 
		
		void display(){
			cout << "All values in the Stack are: " << endl;
			for(int i = 4; i>=0; i--){		//big to small for looking like a stack
				cout << arr[i] << " ";
			}cout << endl;
		}
};

int main(){
	Stack s1;
	int opt, posi, value;
	
	do{
		cout << "What operation you want to perform? Select Option Number, Enter 0 to Exit." << endl;
		cout << "1.Push" << endl;
		cout << "2.Pull" << endl;
		cout << "3.isEmpty" << endl;
		cout << "4.isFull" << endl;
		cout << "5.Peek" << endl;
		cout << "6.Count" << endl;
		cout << "7.Change" << endl;
		cout << "8.Display" << endl;
		cout << "9.Clear Screen" << endl;		
	
		cin >> opt;
		switch(opt){
			case 0:
				break;
			case 1:
				cout << "Enter an item to push in the stack" << endl;
				cin >> value;
				s1.push(value);
				break;
			case 2:
				cout << "Pop Function called - Poped Value: " << s1.pop() << endl;
				break;
			case 3:
				if(s1.isEmpty()){ cout<<"Stack is Empty" << endl; }
				else { cout << "Stack is not Empty" << endl; } break;
			case 4:
				if(s1.isFull()) { cout << "Stack is Full" << endl; }
				else { cout << "Stack is not Full" << endl; } break;
			case 5:
				cout << "Enter the position you want to peek: "<<endl;
				cin >> posi;
				cout << "Peek function called - Value at Position " << posi << " is " << s1.peek(posi) << endl;
				break;
			case 6:
				cout << "Count function called - Number of terms in the stack are: " << s1.count() << endl;
				break;
			case 7:
				cout << "Change function called -> " << endl;
				cout << "Enter the position of the item you want to change: ";
				cin >> posi;
				cout << endl;
				cout << "Enter the value of the item you want to change: ";
				cin >> value;
				s1.change(posi, value);
				break;
			case 8:
				cout << "Display Function Called -> " << endl;
				s1.display();
				break;
			case 9:
				system("clear");
				break;
			default:
				cout << "Enter proper option number" << endl;
		}
	
	}while(opt!=0);

	return 0;
}
