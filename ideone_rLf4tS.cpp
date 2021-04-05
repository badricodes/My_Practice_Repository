#include <bits/stdc++.h>
using namespace std;


class Node{
	public:
	int val;
	Node *left, *right;
	Node(int x):val{x},left{NULL},right{NULL}{
		//cout << "Object Created with value " << x << "\n";
	}
};

void preorderRecursive(Node* root){
	if(!root)return;
	cout << root->val << " ";
	preorderRecursive(root->left);
	preorderRecursive(root->right);
}
void preorderIterative(Node* root){
	stack<Node*> st;
	st.push(root);
	while(!st.empty()){
		Node* node = st.top();
		st.pop();
		cout << node->val << " ";
		if(node->right) st.push(node->right);
		if(node->left) st.push(node->left);
	}
}
int fib(int n){
	if(n <= 2)
	return n-1;
	int firstCall = fib(n-1);
	int secondCall = fib(n-2);
	return firstCall + secondCall;
}

void traversalHelper(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->left = new Node(8);
	preorderIterative(root);
}



int power(int x, int n){
	if(n == 0)
		return 1;
	if(n == 1)
		return x;
	int halfPower = power(x,n/2);
	int result = halfPower*halfPower;
	if((n&1)){
		result *= x;
	}
	return result;
}

void printLine(int number, int n){
	if(number > n){
		cout << "\n";
		return;
	}
	cout << number << " ";
	printLine(number+1,n);
	cout << number << " ";
}

int numberOfWalls(int n){
	switch(n){
		case 0:return 0;
		case 1:return 1;
		case 2:return 1;
		case 3: return 1;
		case 4: return 2;
		case 5: return 4;
	}
	return numberOfWalls(n-1)+numberOfWalls(n-4);
}

string digits[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void printingDigitNames(int n){
	if(!n) return;
	
	printingDigitNames(n/10);
	int digit = n%10;
	cout << digits[digit] << " ";
}
int firstOcurrence(int* a, int n,int key){
	if(n == 0)
		return -1;
	if(a[0] == key)
		return 0;
	int result = firstOcurrence(a+1,n-1,key);
	return (result!=-1)?result+1:-1;
}

void bubbleSort(int* a,int n){
	if(n == 0) return;
	if(a[0] > a[1]){
		int temp = a[0];
		a[0] = a[1];
		a[1] = temp;
	}
	bubbleSort(a+1,n-1);
	
}
void helperBubbleSort(int* a, int n){
	if(n == 1)return;
	bubbleSort(a,n-1);
	helperBubbleSort(a,n-1);
}

template<class iterator,class T,class Comparator>
iterator search(iterator start,iterator end, T key, Comparator cmp){
	
	while(start != end){
		if(cmp(*start,key)){
			return start;
		}
		start++;
	}
	return end;
}


class Book{
	public:
	string name;
	int cost;
	Book(string name, int cost):name{name},cost{cost}{
	}
};

class BookCompare{
	public:
	bool operator()(Book a, Book b){
		return a.name == b.name && a.cost == b.cost;
	}
};


template<class T,class Key>
int search(T a,Key key){
	for(int index = 0; index < a.size();index++){
		if(a[index] == key)
			return index;
	}
	return -1;
}


int main() {
	list<Book> l;
	l.push_back(Book("C",100));
	l.push_back(Book("C++",200));
	l.push_back(Book("Java",200));
	l.push_back(Book("Python",300));
	l.push_back(Book("JavaScript",400));
	//list<Book>::iterator it = search(l.begin(),l.end(),Book("C++",400),BookCompare());
	//cout << ((it != l.end())?"Book Found":"Book Not Found");
	array<int> vc{1,2,3,4,5,6};
	cout << search(vc,3);
	return 0;
}