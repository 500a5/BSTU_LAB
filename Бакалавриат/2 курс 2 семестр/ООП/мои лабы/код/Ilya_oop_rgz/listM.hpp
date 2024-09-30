
#pragma once
#ifndef UPDATE_H
#define UPDATE_H
#include <list>
#include <iterator>
#include <stdio.h>
#include <iostream>
using namespace std;

template <class T>
class MList : public list<T> {
public:
    T& operator[](int index) {
        if (this->size() <= index) throw out_of_range("Out of range!");
        typename MList<T>::iterator it;
        it = this->begin();
        advance(it, index);
        return *it;
    }
};
#endif