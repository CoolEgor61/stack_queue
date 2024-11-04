
#ifndef mStack_h
#define mStack_h

#include "sqVector.h"

template<typename T> class mStack: private sqVector<T>
{
    using sqVector<T>::size;
    using sqVector<T>::capacity;
    using sqVector<T>::data;
public:
    // constuctor
    mStack() : sqVector<T>(0) {}
    // inheritage
    using sqVector<T>::isFull;
    using sqVector<T>::isEmpty;
    using sqVector<T>::size_;
    using sqVector<T>::capacity_;
    using sqVector<T>::pop_back;
    // methods
    void push(T elem)
    {
        if (!(this->isFull())) data[++size]=elem;
        else {
            this->resize(size_t(size_t((int)size+1)));
            data[size]=elem;
        }
    }
    void resize(int new_size)
    {
        T* mem=new T[new_size*2+2];
        if (mem!=0){
            std::copy(data,data+capacity,mem);
            delete[] data;
            size=new_size;
            capacity = new_size * 2 + 2;
            data=mem;
            mem = nullptr;
        }
    }
    void pop(){
        this->pop_back();
    }
    T top() { if (!(this->isEmpty())) return data[size]; else return 0; };
};

#endif 
