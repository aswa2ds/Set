//
// Created by Edward Martin on 2018/10/25.
//

#include "Set.h"

Set::Set(){
    setList = NULL;
    msize = 0;
    setsize = 200;
}

Set::Set(const Set &set) {
    setsize = set.setsize;
    msize = set.msize;
    setList = new int[setsize];
    for(int i(0); i < msize; ++i)
        setList[i] = set.setList[i];
}

Set::Set(int *element, int length) {
    setsize = 200;
    msize = 0;
    setList = new int[setsize];
    for(int i(0); i < length; ++i){
        for(int j(i + 1); j < length; ++j){
            if(element[i] > element[j]){
                int temp = element[i];
                element[i] = element[j];
                element[j] = temp;
            }
        }
    }
    for(int i(0); i < length; ++i){
        while(i >= 1 && i < length && element[i] == element[i-1])
            i++;
        if(i == length)
            break;
        setList[msize++] = element[i];
    }
}

Set::~Set() {
    msize = 0;
    setsize = 100;
    delete[] setList;
    setList = NULL;
}

void Set::add(int element) {
    if(msize == setsize)
        return;
    if(element < setList[0]){
        for(int j(msize-1); j >= 0; --j)
            setList[j+1] = setList[j];
        setList[0] = element;
        msize++;
    }
    for(int i(0); i < msize; ++i){
        if(setList[i] == element)
            break;
        if(i == msize - 1)
            setList[msize++] = element;
        if(setList[i] < element && setList[i] > element){
            msize++;
            for(int j(msize-2);  j > i+1; --j)
                setList[j+1] = setList[j];
            setList[i+1] = element;
        }
    }
}

bool Set::erase(int element) {
    bool isErased = false;
    for(int i(0); i < msize; ++i){
        if(setList[i] == element){
            for(int j(i+1); j < msize; ++j)
                setList[j-1] = setList[j];
            msize--;
            isErased = true;
            break;
        }
    }
    return isErased;
}

bool Set::contains (int element) {
    bool isContained = false;
    for(int i(0); i < msize; ++i){
        if(setList[i] == element){
            isContained = true;
            break;
        }
    }
    return isContained;
}

int Set::size(){ return msize; }

ostream &operator << (ostream &os, const Set &rset){
    if(rset.msize == 0) {
        os << "Empty";
        return os;
    }
    for(int i(0); i < rset.msize; ++i)
        os << rset.setList[i] << " ";
    return os;
}

Set operator + (const Set &lset, const Set &rset){
    Set set(lset);
    for(int i(0); i < rset.msize; ++i){
        if(!set.contains(rset.setList[i]))
            set.add(rset.setList[i]);
    }
    return set;
}

Set operator - (const Set &lset, const Set &rset){
    Set set(lset);
    for(int i(0); i < rset.msize; ++i){
        if(set.contains(rset.setList[i]))
            set.erase(rset.setList[i]);
    }
    //cout << set << endl;
    return set;
}

Set &Set::operator += (const Set &rset){
    for(int i(0); i < rset.msize; ++i){
        if(!this->contains(rset.setList[i]))
            this->add(rset.setList[i]);
    }
    return *this;
}

Set &Set::operator -= (const Set &rset){
    for(int i(0); i < rset.msize; ++i){
        if(this->contains(rset.setList[i]))
            this->erase(rset.setList[i]);
    }
    return *this;
}

Set operator | (const Set &lset, const Set &rset){
    return lset + rset;
}

Set operator & (const Set &lset, const Set &rset){
    return lset - (lset - rset);
}

bool operator == (const Set &lset, const Set &rset){
    bool isequal = true;
    if(lset.msize != rset.msize)
        return false;
    for(int i(0); i < lset.msize; ++i){
        if(lset.setList[i] != rset.setList[i])
            isequal = false;
    }
    return isequal;
}

bool operator != (const Set &lset, const Set &rset){
    return !(lset == rset);
}

bool operator > (const Set &lset, const Set &rset){
    return lset >= rset && lset != rset;
}
bool operator >= (const Set &lset, const Set &rset){
    bool iscontained = true;
    Set set(lset);
    for(int i(0); i < rset.msize; ++i){
        if(!set.contains(rset.setList[i]))
            iscontained = false;
    }
    return iscontained;
}
bool operator < (const Set &lset, const Set &rset){
    return rset > lset;
}
bool operator <= (const Set &lset, const Set &rset){
    return rset >= lset;
}

void *Set::operator new (size_t size){
    void *p = malloc(size);         //声明void*类型的指针 p 并根据输入参数调用malloc
    return p;
}

void Set::operator delete (void *p, size_t size){
    free(p);                        //释放p指针指向的空间
}