#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <iterator>
#include <unordered_map>
#include <bits/stdc++.h>
#include <stack>
#include <utility>

struct node{
	int data;
	node* next;
	node(int data, node* next = nullptr):data(data), next(next){}
	node(){
		this->next=nullptr;
	}
};

void deleteLLNodes(node* root){
	if(root==nullptr){
		return;
	}
	deleteLLNodes(root->next);
	delete root;
}

void printLL(node* root){
	if(root==nullptr){
		return;
	}

	std::cout << root->data << std::endl;

	if(root->next!=nullptr){
		printLL(root->next);
	}
}

node* removeDuplicates(node* root){
	node *ptr1, *ptr2, *save;
	ptr1=root;
	while(ptr1!=nullptr && ptr1->next!=nullptr){
		ptr2 = ptr1;

		while(ptr2->next != nullptr){
			if(ptr1->data == ptr2->next->data){
				save=ptr2->next;
				ptr2->next=ptr2->next->next;
				delete save;
			}else{
				ptr2=ptr2->next;
			}
		}
		ptr1=ptr1->next;
	}
	return root;
}

int count(node* root, int x){
	int c=0;
	while(root!=nullptr){
		if(root->data==x){
			c++;
		}
		root=root->next;
	}
	return c;
}

node* range(int x, int y){
	node* a = new node(x);
	node* root=a;
	while(x<y){
		++x;
		a->next = new node(x);
		a=a->next;
	}
	return root;
}

node* removeAllX(node* root, int x){
	if(root==nullptr){
		return root;
	}

	while(root!=nullptr && root->data==x){
		root=root->next;
	}

	node* current = root;
	while(current->next!=nullptr){
		if(current->next->data==x){
			current->next=current->next->next;
		}else{
			current=current->next;
		}
	}
	return root;
}



int main(){
	node* ff = new node(50);
	node* ee = new node(50,ff);
	node* dd = new node(50,ee);
	node* cc = new node(30,dd);
	node* bb = new node(20,cc);
	node* aa = new node(10,bb);
	
	printLL(removeAllX(aa, 50));

	deleteLLNodes(aa);

	return 0;
}