#pragma once
class Iterator{
private:
    Node* obj;
    Iterator(Node*);
public:
    int& operator*();
    bool operator==(const Iterator&) const;
    bool operator!=(const Iterator&) const;
    Iterator& operator++();

    friend class LinkedList;
};