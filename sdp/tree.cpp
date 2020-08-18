#include <iostream>

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int data, Node* left=nullptr, Node* right=nullptr):data(data), left(left), right(right){}
};

class binTree{
public:
	binTree();
	void insert(int);
	void print();
	void mirrorNegative();
	int height();
	bool isBalanced();
	void remove(int);
	void removeEvenAddSum();
	~binTree();
private:
	Node*& minP(Node*&);
	void removeHelper(Node*&, int);
	void readHelper(int&, Node*);
	bool ibHelper(Node*);
	int heightHelper(Node*);
	void mnHelper(Node*);
	void deleteHelper(Node*);
	void printHelper(Node*);
	void insertHelper(Node*&, int);
	Node* root;
};

binTree::binTree(){
	this->root=nullptr;
}

Node*& binTree::minP(Node*& root){
	if(root==nullptr){
		return root;
	}
	while(root&&root->left){
		root=root->left;
	}
	return root;
}

bool binTree::isBalanced(){
	return this->ibHelper(this->root);
}

void binTree::remove(int x){
	return this->removeHelper(this->root, x);
}

void binTree::removeHelper(Node*& root, int x){
	if (root == nullptr){
        return;
    }
    if (x < root->data){
        removeHelper (root->left, x);
    } else if (root->data < x){
        removeHelper (root->right, x);
    } else if (root->right == nullptr){        
        Node* save = root;
        root = root->left;
        delete save;
    } else{
        Node *&minimal = minP (root->right);
        Node *saveMinAdd = minimal;
        minimal = minimal->right;
        saveMinAdd->left = root->left;
        saveMinAdd->right = root->right;
        Node* saveCurrentAddr = root;
        root = saveMinAdd;
        delete saveCurrentAddr;
    }
}

bool binTree::ibHelper(Node* root){
	if(root==nullptr){
		return true;
	}
	int l=heightHelper(root->left);
	int r=heightHelper(root->right);
	if(abs(l-r)<=1 && ibHelper(root->left) && ibHelper(root->right)){
		return true;
	}
	return false;
}

int binTree::heightHelper(Node* root){
	if(root==nullptr){
		return 0;
	}
	int l=heightHelper(root->left);
	int r=heightHelper(root->right);

	if(l>r){
		return l+1;
	}
	return r+1;
}

int binTree::height(){
	return this->heightHelper(this->root);
}

void binTree::readHelper(int& sum, Node* root){
	if(root==nullptr){
		return;
	}
	readHelper(sum, root->left);
	readHelper(sum, root->right);
	if(root->data%2==0){
		sum+=root->data;
		remove(root->data);
	}
}

void binTree::removeEvenAddSum(){
	int sum = 0;
	this->readHelper(sum, this->root);
	this->insert(sum);
}

void binTree::mnHelper(Node* root){
	if(root==nullptr){
		return;
	}
	mnHelper(root->left);
	mnHelper(root->right);
	Node* temp = root->left;
	root->left=root->right;
	root->right=temp;
	root->data = -root->data;
}

void binTree::mirrorNegative(){
	this->mnHelper(this->root);
}

void binTree::deleteHelper(Node* root){
	if(root==nullptr){
		return;
	}
	deleteHelper(root->left);
	deleteHelper(root->right);
	delete root;
}

binTree::~binTree(){
	this->deleteHelper(this->root);
}

void binTree::insertHelper(Node*& root, int value){
	if(root==nullptr){
		root = new Node(value);
		return;
	}
	if(value > root->data){
		insertHelper(root->right, value);
		return;
	}
	insertHelper(root->left, value);
}

void binTree::insert(const int value){
	return this->insertHelper(this->root, value);
}

void binTree::print(){
	return this->printHelper(this->root);
}

void binTree::printHelper(Node* root){
	if(root==nullptr){
		return;
	}
	printHelper(root->left);
	printHelper(root->right);
	std::cout << root->data << std::endl;
}

int main(){
	binTree a;
	a.insert(20);
	a.insert(30);
	a.insert(50);
	a.insert(10);
	a.insert(21);
	a.insert(5);
	a.removeEvenAddSum();
	
	a.print();

	return 0;
}