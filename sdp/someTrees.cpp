#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <iterator>
#include <unordered_map>
#include <bits/stdc++.h>
#include <stack>
#include <utility>

struct BinTreeNode{
	int data;
	BinTreeNode *left, *right;
	BinTreeNode(int data, BinTreeNode *l=nullptr, BinTreeNode *r=nullptr){
		this->data=data;
		this->left=l;
		this->right=r;
	}	
};

int max(int a, int b){
	return a > b ? a : b;
}

void deleteNodes(BinTreeNode* root){
	if(root==nullptr){
		return;
	}
	deleteNodes(root->left);
	deleteNodes(root->right);
	delete root;
}

int height(BinTreeNode* root){
	if(root==nullptr){
		return 0;
	}
	int ld = height(root->left);
	int rd = height(root->right);
	return ld > rd ? ld + 1: rd + 1;
}

int countEvens(BinTreeNode* root){
	if(root==nullptr){
		return 0;
	}
	if(root->data%2==0){
		return 1 + countEvens(root->left) + countEvens(root->right);
	}
	return countEvens(root->left) + countEvens(root->right);
}

bool fundPred(int a){
	return a>10;
}

int searchCount(BinTreeNode* root, bool(*p)(int)){
	if(root==nullptr){
		return 0;
	}
	if(p(root->data)){
		return 1 + searchCount(root->left, p) + searchCount(root->right,p);
	}
	return searchCount(root->left, p) + searchCount(root->right,p);
}

int leavesCount(BinTreeNode* root){
	if(root==nullptr){
		return 0;
	}
	if(root->left==nullptr && root->right==nullptr){
		return 1;
	}
	return leavesCount(root->left)+leavesCount(root->right);
}

int maxLeaf(BinTreeNode* root, int& max){
	if(root==nullptr){
		return -1;
	}
	while(root->right!=nullptr){
		root=root->right;
	}
	return root->data;
}

void print(BinTreeNode* root){
	if(root==nullptr){
		return;
	}
	print(root->left);
	print(root->right);
	std::cout << root->data << std::endl;
}

const bool isVisited(std::vector<int>& visited, const int& data){
	for(int i=0; i < visited.size(); ++i){
		if(data==visited[i]){
			return true;
		}
	}
	return false;
}

void dfsHelper(BinTreeNode* root, std::vector<int> visited){
	visited.push_back(root->data);
	std::cout << root->data << std::endl;

	if(root->left!=nullptr){
		if(!isVisited(visited, root->left->data)){
			visited.push_back(root->left->data);
			dfsHelper(root->left, visited);
		}
	}

	if(root->right!=nullptr){
		if(!isVisited(visited, root->right->data)){
			visited.push_back(root->right->data);
			dfsHelper(root->right, visited);
		}
	}
}

void dfs(BinTreeNode* root){
	std::vector<int> visited;
	return dfsHelper(root, visited);
}

void bfs(BinTreeNode* root){
	std::vector<int> visited;
	visited.push_back(root->data);
	std::queue<BinTreeNode*> queue;
	queue.push(root);

	while(!queue.empty()){
		BinTreeNode* gettingOut = queue.front();
		queue.pop();

		std::cout << gettingOut->data << std::endl;

		if(gettingOut->left != nullptr && !isVisited(visited, gettingOut->left->data)){
			visited.push_back(gettingOut->left->data);
			queue.push(gettingOut->left);
		}

		if(gettingOut->right != nullptr && !isVisited(visited, gettingOut->right->data)){
			visited.push_back(gettingOut->right->data);
			queue.push(gettingOut->right);
		}
		gettingOut=nullptr;
	}
}

int nodeNumber(BinTreeNode* root){
	if(root==nullptr){
		return 0;
	}
	return 1 + nodeNumber(root->left) + nodeNumber(root->right);
}

int nodeSum(BinTreeNode* root){
	if(root==nullptr){
		return 0;
	}
	return root->data + nodeSum(root->left) + nodeSum(root->right);
}

bool isBalanced(BinTreeNode* root){
	if(root==nullptr){
		return 1;
	}

	int lh, rh;
	lh=height(root->left);
	rh=height(root->right);
	if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)){
		return 1;
	}

	return 0;
}

void insert(BinTreeNode* &root, const int value){
	if(root==nullptr){
		root = new BinTreeNode(value);
		return;
	}
	if(value > root->data){
		insert(root->right, value);
		return;
	}
	insert(root->left, value);
}

BinTreeNode* buildTree(std::vector<BinTreeNode*> h){
	BinTreeNode* root = new BinTreeNode(h[0]->data);
	for(int i = 1; i < h.size(); i++){
		insert(root,h[i]->data);
	}
	return root;
}

bool identicalRecursive(BinTreeNode* first, BinTreeNode* second){
	if(first==nullptr && second==nullptr){
		return true;
	}
	if(first!=nullptr && second!=nullptr){
		return first->data == second->data && identicalRecursive(first->left, second->left) && identicalRecursive(first->right, second->right);
	}
	return 0;
}

bool identicalIterative(BinTreeNode* first, BinTreeNode* second){
	if(first==nullptr && second==nullptr){
		return false;
	}

	if(first==nullptr){
		return false;
	}

	if(second==nullptr){
		return false;
	}

	std::stack<std::pair<BinTreeNode*, BinTreeNode*>> stack;
	stack.push(std::pair<BinTreeNode*, BinTreeNode*>(first,second));
	while(!stack.empty()){
		BinTreeNode* x = stack.top().first;
		BinTreeNode* y = stack.top().second;
		stack.pop();
		if(x->data != y->data){
			return false;
		}

		if(x->left!=nullptr && y->left!=nullptr){
			stack.push(std::pair<BinTreeNode*, BinTreeNode*>(x->left, y->left));
		}else if(x->left!=nullptr || y->left != nullptr){
			return false;
		}

		if(x->right!=nullptr && y->right!=nullptr){
			stack.push(std::pair<BinTreeNode*, BinTreeNode*>(x->right, y->right));
		}else if(x->right!=nullptr || y->right!=nullptr){
			return false;
		}
	}
	return true;
}

BinTreeNode* mirror(BinTreeNode* root){
	if(root==nullptr){
		return root;
	}
	mirror(root->right);
	mirror(root->left);
	
	BinTreeNode* temp=root->left;
	root->left=root->right;
	root->right=temp;
	return root;
}

int main(){
	BinTreeNode* g = new BinTreeNode(3);
	BinTreeNode* d = new BinTreeNode(4,g);
	BinTreeNode* e = new BinTreeNode(9);
	BinTreeNode* b = new BinTreeNode(8,d,e);
	BinTreeNode* f = new BinTreeNode(12);
	BinTreeNode* c = new BinTreeNode(15,f);
	BinTreeNode* a = new BinTreeNode(10,b,c);

	BinTreeNode* gk = new BinTreeNode(3);
	BinTreeNode* dk = new BinTreeNode(4,gk);
	BinTreeNode* ek = new BinTreeNode(9);
	BinTreeNode* bk = new BinTreeNode(8,dk,ek);
	BinTreeNode* fk = new BinTreeNode(12);
	BinTreeNode* ck = new BinTreeNode(15,fk);
	BinTreeNode* ak = new BinTreeNode(10,bk,ck);

	std::vector<BinTreeNode*> h;
	h.push_back(a);
	h.push_back(b);
	h.push_back(c);
	h.push_back(d);
	h.push_back(e);
	h.push_back(f);
	h.push_back(g);
	
	std::cout<<identicalIterative(a,ak);

	deleteNodes(a);
	deleteNodes(ak);
	return 0;
}