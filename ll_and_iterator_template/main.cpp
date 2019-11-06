//#include "Node.hpp"
#include "LinkedList.hpp"
//#include "Iterator.hpp"

template <class T>
void test(LinkedList<T>& p){
    p.print();
}

int main(){

   LinkedList<int> a;
   a.pushFront(6);
   a.pushFront(10);
   a.pushEnd(50);
   //a.popEnd();
   //a.popFront();
   //a.print();

   LinkedList<int> b = a;
   //test(b);

    for (int i : a){
        std::cout << i << std::endl;
    }
}