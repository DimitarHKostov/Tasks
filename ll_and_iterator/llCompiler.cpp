#include "LinkedList.cpp"
#include "Iterator.cpp"

const int sumOfElements(LinkedList& random){
    int sum = 0;
    for(int i:random){
        sum+=i;
    }
    return sum;
}

int main(){
    LinkedList a;
    a.pushEnd(10);
    a.pushEnd(20);
    a.pushEnd(30);
    a.pushFront(5);
    a.pushFront(2);
    a.popEnd();
    a.popFront();

    LinkedList b = a;
    a.print();

    std::cout << sumOfElements(a) << std::endl;
}