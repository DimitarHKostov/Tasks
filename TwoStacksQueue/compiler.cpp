#include "StacksQueue.h"
#include <iostream>

int main(){
    StacksQueue a;
    a.push(5);
    a.push(6);
    a.push(7);
    a.pop();
    std::cout << a.peek() << std::endl;
}
