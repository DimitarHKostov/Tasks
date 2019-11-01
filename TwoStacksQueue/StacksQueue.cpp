#include "StacksQueue.h"

void StacksQueue::reverse(std::vector<int>& source, std::vector<int>& target){
    while (source.size()>0)
    {
        target.push_back(source.back());
        source.pop_back();
    }
}

void StacksQueue::push(const int value){
    this->firstStack.push_back(value);
}

void StacksQueue::pop(){
    if(this->secondStack.size()==0){
        reverse(firstStack, secondStack);
    }
    this->secondStack.pop_back();
}

int StacksQueue::peek(){
    if(this->secondStack.size()==0){
        reverse(firstStack, secondStack);
    }
    return this->secondStack.back();
}