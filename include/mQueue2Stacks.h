
#ifndef mQueue2Stacks_h
#define mQueue2Stacks_h

#include "sqVector.h"
#include "mStack.h"

template<typename T> class mQueue2Stacks: private sqVector<mStack<T>>
{
private:
    using::sqVector<mStack<T>>::data;
    std::size_t size, capacity;
public:
    // constructor
    mQueue2Stacks() : size(data[0].size_() + data[1].size_()), capacity(data[0].capacity_() + data[1].capacity_()) {}
    // methods
    size_t size_() const noexcept { return data[0].size_() + data[1].size_(); };
    size_t capacity_() const noexcept { return data[0].capacity_()+data[1].capacity_(); };
    bool isEmpty() const noexcept { return (data[0].isEmpty() && data[1].isEmpty()); };
    bool isFull() const noexcept { return (data[0].isFull() && data[1].isFull()); };
    void push(T elem)
    {
        data[0].push(elem);
        size++;
    }
    void pop()
    {
        if(data[1].isEmpty()) {
            while(!data[0].isEmpty()) {
                T mem = data[0].top();
                data[1].push(mem);
                data[0].pop();
            }
        } else {
            data[1].pop();
        }
        size--;
    }
    T top()
    {
        if (!data[1].isEmpty()) {
            T mem = {};
            while (!data[1].isEmpty()) {
                mem=data[1].top();
                data[1].pop();
            }
            return mem;
        }
        return data[0].top();
    }
};

#endif
