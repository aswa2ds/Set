//
// Created by Edward Martin on 2018/10/25.
//

#ifndef SET_SET_H
#define SET_SET_H

#include <iostream>
using namespace std;

class Set {
private:
    int *setList;
    int setsize;
    int msize;
public:
    Set();
    Set(const Set &set);
    Set(int element[], int length);
    ~Set();
    void add(int element);
    bool erase(int element);
    bool contains(int element);
    int size();
    friend ostream &operator << (ostream &os, const Set &rset);
    friend Set operator + (const Set &lset, const Set &rset);
    friend Set operator - (const Set &lset, const Set &rset);
    friend Set operator | (const Set &lset, const Set &rset);
    friend Set operator & (const Set &lset, const Set &rset);
    friend bool operator == (const Set &lset, const Set &rset);
    friend bool operator != (const Set &lset, const Set &rset);
    friend bool operator > (const Set &lset, const Set &rset);
    friend bool operator >= (const Set &lset, const Set &rset);
    friend bool operator < (const Set &lset, const Set &rset);
    friend bool operator <= (const Set &lset, const Set &rset);
    void *operator new (size_t size);
    void operator delete(void *p, size_t size);
    Set &operator += (const Set &rset);
    Set &operator -= (const Set &rset);

};


#endif //SET_SET_H
