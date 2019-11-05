#pragma once
#include "LinkedList.h"
#include <iostream>
#include <cassert>

LinkedList::LinkedList(){
    this->size=0;
    this->head=nullptr;
    this->last=nullptr;
}

void LinkedList::pushEnd(int value){
    if (this->head==nullptr)
    {
        this->head=new Node(value);
        this->last=this->head;
    }else{
        this->last->next=new Node(value, this->last);
        this->last=this->last->next;
    }
    ++size;
}

void LinkedList::pushFront(int value){
    if(this->head==nullptr){
        this->head=new Node(value);
        this->last=this->head;
    }else{
        Node* newNode=new Node(value);
        newNode->next=this->head;
        this->head=newNode;
    }
    ++size;
}

void LinkedList::popEnd(){
    if(this->head==nullptr){
        return;
    }else{
        if(this->head->next==nullptr){
            delete this->head;
            this->head=nullptr;
        }else{
            Node* crr = this->last->previous;
            delete this->last;
            this->last=crr;
            crr->next=nullptr;
        }
        --size;
    }
}

LinkedList::LinkedList(const LinkedList& other):LinkedList(){
    copy(other);
}

void LinkedList::popFront(){
    if(this->head==nullptr){
        return;
    }else{
        if(this->head->next==nullptr){
            delete this->head;
            this->head=nullptr;
        }else{
            Node* crr = this->head->next;
            delete this->head;
            this->head=crr;
            this->head->previous=nullptr;
        }
        --size;
    }
}

void LinkedList::deleteall(Node* start){
    if (start==nullptr)
    {
        return;
    }
    deleteall(start->next);
    delete start;
}

LinkedList::~LinkedList(){
    deleteall(this->head);
}

const int LinkedList::getSize() const{
    return this->size;
}

void LinkedList::print(){
    Node* crr = this->head;
    while (crr!=nullptr)
    {
        std::cout << crr->data << std::endl;
        crr=crr->next;
    }   
}

void LinkedList::copy(const LinkedList& l){
    Node* crr = l.head;

    while(crr!=nullptr)
    {
       this->pushEnd(crr->data);
       crr=crr->next;
    }
    this->size=l.getSize();
}

LinkedList& LinkedList::operator=(const LinkedList& other){
    if (this!=&other)
    {
        deleteall(this->head);
        this->head=nullptr;
        copy(other);
    }
    return *this;
}

Iterator::Iterator(Node* start){
    this->obj=start;
}

Iterator LinkedList::end(){
    return Iterator(nullptr);
}

Iterator LinkedList::begin(){
    return Iterator(this->head);
}
