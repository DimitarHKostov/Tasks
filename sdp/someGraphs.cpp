#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <iterator>
#include <unordered_map>
#include <bits/stdc++.h>
#include <stack>
#include <utility>
#include <unordered_map>
#include <list>
#include <iterator>


template <class T>
struct Node{
	T data;
	std::vector<Node<T>> adjtable;
	Node(T data): data(data){}

	void addEdge(const Node<T>& y){
		this->adjtable.push_back(y);
	}

	bool operator==(const Node<T>& other) const{
		return this->data == other.data;
	}
};

template<class T>
struct Graph{
	std::vector<Node<T>> nodes;

	void pushNode(Node<T>& value){
		nodes.push_back(value);
	}

	void orientedEdge(Node<T>& x, Node<T>& y){
		for(Node<T>& i: this->nodes){
			if(i.data == x.data){
				i.addEdge(y);
				return;
			}
		}
	}

	void notOrientedEdge(Node<T>& x, Node<T>& y){
		for(Node<T>& i: this->nodes){
			if(i.data==x.data){
				i.addEdge(y);
				break;
			}
		}

		for(Node<T>& i: this->nodes){
			if(i.data==y.data){
				i.addEdge(x);
				return;
			}
		}
	}
};

template <class T>
void print(Graph<T>& g){
	for(Node<T>& i: g.nodes){
		std::cout << i.data << " has edge to: " << std::endl;
		for(Node<T>& j : i.adjtable){
			std::cout << j.data << std::endl;
		}
		std::cout << std::endl;
	}
}

template<class T>
struct MyHashFunction {
   size_t operator()(const Node<T>& node) const{
      return node.data*2654435761 % 2^32;
   }
};

template <class T>
Node<T> locate(Graph<T>& g, Node<T> node){
	for(Node<T>& i: g.nodes){
		if(i.data==node.data){
			return i;
		}
	}
}

template<typename T>
void BFS(Graph<T>& g, T start){
	std::queue<Node<T>> queue;
	std::unordered_map<Node<T>, bool, MyHashFunction<T>> map;
	
	for(Node<T>& i: g.nodes){
		if(i.data==start){
			queue.push(i);
			map[i]=true;
		}else{
			map[i]=false;
		}
	}
	
	while(!queue.empty()){
		Node<T> gettingOut = queue.front();
		queue.pop();
		std::cout << gettingOut.data << std::endl;

		for(Node<T>& i : locate(g, gettingOut).adjtable){
			if(map[i]==false){
				map[i]=true;
				queue.push(i);
			}
		}
	}
}

template<class T>
void DFSHelper(Graph<T>& g, Node<T>& start, std::unordered_map<Node<T>, bool, MyHashFunction<T>>& visited){
	visited[start]=true;
	std::cout << start.data << std::endl;

	for(Node<T>& i: locate(g,start).adjtable){
		if(visited[i]==false){
			visited[i]=true;
			DFSHelper(g, i, visited);
		}
	}
}

template<class T> 
void DFS(Graph<T>& g, T start){
	std::unordered_map<Node<T>, bool, MyHashFunction<T>> visited;
	for(Node<T>& i : g.nodes){
		if(i.data == start){
			DFSHelper(g, i, visited);
		}
	}
}

//works only if edges aren`t oriented
template <class T>
int numOfIsolatedVertices(Graph<T>& g){
	int cnt=0;
	for(Node<T>& i: g.nodes){
		if(i.adjtable.size()==0){
			cnt++;
		}
	}
	return cnt;
}

template<class T>
std::vector<Node<T>> cantbefound(Graph<T>&g, T start){
	//using BFS
	std::queue<Node<T>> queue;
	std::unordered_map<Node<T>, bool, MyHashFunction<T>> map;
	
	for(Node<T>& i: g.nodes){
		if(i.data==start){
			queue.push(i);
			map[i]=true;
		}else{
			map[i]=false;
		}
	}
	
	while(!queue.empty()){
		Node<T> gettingOut = queue.front();
		queue.pop();

		for(Node<T>& i : locate(g, gettingOut).adjtable){
			if(map[i]==false){
				map[i]=true;
				queue.push(i);
			}
		}
	}

	std::vector<Node<T>> res;
	for(std::pair<Node<T>, bool> p: map){
		if(p.second==false){
			res.push_back(p.first);
		}
	}
	return res;
}

int main(){
	Graph<int> g;

	Node<int> a(4);
	Node<int> b(7);
	Node<int> c(5);
	Node<int> d(2);
	Node<int> e(1);
	Node<int> f(8);
	Node<int> h(9);

	g.pushNode(a);
	g.pushNode(b);
	g.pushNode(c);
	g.pushNode(d);
	g.pushNode(e);
	g.pushNode(f);
	g.pushNode(h);

	g.orientedEdge(a,b);
	g.orientedEdge(a,f);
	g.orientedEdge(f,c);
	g.orientedEdge(f,d);
	g.orientedEdge(c,a);
	g.orientedEdge(c,e);
	g.orientedEdge(e,b);

	print<int>(g);

	return 0;
}