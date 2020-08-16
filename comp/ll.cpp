#include <iostream>
#include <utility>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <stack>

struct Node{
	int data;
	Node* next;
	Node(int data, Node* next=nullptr):data(data), next(next){}
};

class LinkedList{
public:
	LinkedList();
	void addFront(int);
	void addEnd(int);
	void removeFront();
	void removeEnd();
	void print();
	int occurances(int);
	void remove(int);
	std::vector<std::pair<int, int>> hist();
	bool containsUnique();
	void reverse();
	~LinkedList();
private:
	void printHelper(Node*);
	void deleteHelper(Node*);
	Node* head;
};

LinkedList::LinkedList(){
	this->head=nullptr;
}

void LinkedList::addFront(int value){
	if(this->head==nullptr){
		this->head = new Node(value);
		return;
	}

	Node* newNode = new Node(value);
	newNode->next=head;
	head=newNode;
}

void LinkedList::addEnd(int value){
	if(this->head==nullptr){
		this->head = new Node(value);
		return;
	}

	Node* current = head;
	while(current->next!=nullptr){
		current=current->next;
	}
	current->next = new Node(value);
}

void LinkedList::removeFront(){
	if(this->head==nullptr){
		return;
	}

	if(this->head->next==nullptr){
		this->head=nullptr;
		return;
	}
	Node* next = this->head->next;
	this->head=nullptr;
	this->head=next;
}

void LinkedList::removeEnd(){
	if(this->head==nullptr){
		return;
	}
	if(this->head->next==nullptr){
		this->head=nullptr;
		return;
	}
	Node* current = this->head;
	while(current->next->next!=nullptr){
		current=current->next;
	}
	current->next=nullptr;
}

void LinkedList::printHelper(Node* start){
	if(start==nullptr){
		return;
	}
	std::cout << start->data << std::endl;
	printHelper(start->next);
}

void LinkedList::print(){
	this->printHelper(this->head);
}

LinkedList::~LinkedList(){
	this->deleteHelper(this->head);
}

void LinkedList::deleteHelper(Node* root){
	if(root==nullptr){
		return;
	}
	deleteHelper(root->next);
	delete root;
}

int LinkedList::occurances(int x){
	if(this->head==nullptr){
		return 0;
	}
	int cnt=0;
	while(head->next!=nullptr){
		if(head->data==x){
			cnt++;
		}
		head=head->next;
	}
	return cnt;
}

void LinkedList::remove(int x){
	if(this->head==nullptr){
		return;
	}
	while(this->head->data==x && this->head!=nullptr){
		this->head=this->head->next;
	}
	Node* current = this->head;
	while(current->next!=nullptr){
		if(current->next->data==x){
			current->next=current->next->next;
		}else{
			current=current->next;
		}
	}
}

//number of occurances of each element
std::vector<std::pair<int, int>> LinkedList::hist(){
	std::vector<std::pair<int, int>> result;
	std::unordered_set<int> used;

	Node* currentHead = this->head;
	Node* currentIterator = currentHead;
	int currentNum=1;

	while(currentHead!=nullptr){
		if(!used.contains(currentHead->data)){
			used.insert(currentHead->data);
			currentIterator=currentHead;
			while(currentIterator->next!=nullptr){
				if(currentIterator->next->data==currentHead->data){
					currentNum++;
				}
				currentIterator=currentIterator->next;
			}
			result.push_back(std::pair<int,int>(currentHead->data, currentNum));
		}
		currentHead=currentHead->next;
		currentNum=1;
	}
	delete currentHead;
	delete currentIterator;

	return result;
}

bool LinkedList::containsUnique(){
	std::unordered_set<int> found;
	Node* current = this->head;
	while(current!=nullptr){
		if(!found.contains(current->data)){
			found.insert(current->data);
		}else if(found.contains(current->data)){
			return false;
		}
		current=current->next;
	}
	return true;
}

void LinkedList::reverse(){
	Node* current = this->head;
	std::stack<int> stack;
	while(current!=nullptr){
		stack.push(current->data);
		current=current->next;
	}

	this->deleteHelper(this->head);
	this->head = new Node(stack.top());
	stack.pop();
	Node* it = this->head;
	while(!stack.empty()){
		it->next=new Node(stack.top());
		stack.pop();
		it=it->next;
	}
}

int main(){
	LinkedList a;
	a.addFront(10);
	a.addFront(20);
	a.addFront(30);
	a.addEnd(100);
	a.addEnd(200);
	
	return 0;
}