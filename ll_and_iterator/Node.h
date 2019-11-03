#pragma once
struct Node{
    int data;
    Node* previous;
    Node* next;
    Node(int data, Node* previous=nullptr, Node* next=nullptr):data(data), previous(previous), next(next){}
};