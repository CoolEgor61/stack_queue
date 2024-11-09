
#ifndef mQueue_h
#define mQueue_h

#include "sqVector.h"

template<typename T> class mQueue: private sqVector<T>
{
    using sqVector<T>::size;
    using sqVector<T>::capacity;
    using sqVector<T>::data;
    std::size_t front, back;
public:
    // constructor
    mQueue() : sqVector<T>(0), front(0), back(0) {}
    // inheritage
    using sqVector<T>::isFull;
    using sqVector<T>::isEmpty;
    using sqVector<T>::size_;
    using sqVector<T>::capacity_;
    using sqVector<T>::resize;
    // methods
    void push(T elem)
    {
        if (this->isFull()) this->resize(size_t(size_t((int)size + 1)));
        data[back]=elem;
        size++;
        if (back==capacity-1) back=0;
        else back++;
    }
    void pop()
    {
        if(!this->isEmpty()){
            if(front==capacity-1) front=0;
            else front++;
            size--;
        }
    }
    T get_front()
    {
        return data[front];
    }
    T get_back()
    {
        if (back==0) return data[capacity-1];
        else return data[back-1];
    }
};

#endif
