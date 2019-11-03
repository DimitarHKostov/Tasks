#pragma once
#include "Iterator.h"

int& Iterator::operator*(){
    return this->obj->data;
}

Iterator& Iterator::operator++(){
    assert(this->obj!=nullptr);
    obj=obj->next;
    return *this;
}

bool Iterator::operator==(const Iterator& it) const{
    return this->obj == it.obj;
}

bool Iterator::operator!=(const Iterator& it) const{
    return this->obj != it.obj;
}