
#ifndef sqVector_h
#define sqVector_h

#include <iostream>

template<typename T> class sqVector
{
protected:
    std::size_t size;
    std::size_t capacity;
    T* data;
public:
    // constructors/destructor
    sqVector(std::size_t sz=0) : size(sz), capacity(sz*2+2)
    {
        data = new T[capacity];
    }
    
    sqVector(T* arr, std::size_t sz) : size(sz), capacity(sz*2+2)
    {
        data = new T[capacity];
        if (data==0) throw std::bad_alloc(); else std::copy(arr, arr+sz, data);
    }
    
    sqVector(const sqVector& t) : size(t.size), capacity(t.capacity)
    {
        data = new T[capacity];
        if (data==0) throw std::bad_alloc(); else std::copy(t.data, t.data+t.size, data);
    }
    
    sqVector(const sqVector&& t) noexcept
    {
        data=nullptr;
        swap(*this, t);
    }
    
    ~sqVector()
    {
        delete[] data;
        data=nullptr;
    }
    // operator =
    sqVector& operator=(const sqVector& v)
    {
        if (&v==this) return *this;
        if (size!=v.size)
        {
            T* p = new T[v.size];
            delete[] data;
            data=p;
            size=v.size;
        }
        std::copy(v.data,v.data+v.size,data);
        return *this;
    }
    
    sqVector& operator=(const sqVector&& v) noexcept
    {
        delete[] data;
        data=nullptr;
        swap(*this, v);
        return *this;
    }
    
    friend void swap(sqVector &lhs, sqVector &rhs)
    {
        std::swap(lhs.size,rhs.size);
        std::swap(lhs.capacity,rhs.capacity);
        std::swap(lhs.data,rhs.data);
    }
    // sizes
    size_t size_() const noexcept { return size; };
    size_t capacity_() const noexcept { return capacity; };
    bool isEmpty() const noexcept { return (size==0); };
    bool isFull() const noexcept { return (size==capacity-1); };
    // comparations
    bool operator==(const sqVector &t) const noexcept
    {
        if (size!=t.size) return 0;
        else for (std::size_t i=0;i<size;i++)
            if (data[i]!=t.data[i]) return 0;
        return 1;
    }
    bool operator!=(const sqVector &t) const noexcept
    {
        return (!(*this==t));
    }
    // indexation
    T operator[](std::size_t ind)
    {
        return data[ind];
    }
    const T operator[](std::size_t ind) const
    {
        return data[ind];
    }
    // methods
    T top() { if (!(this->isEmpty())) return data[size-1]; else return 0; };
    void push_back(T elem)
    {
        if(!(this->isFull())) data[size++]=elem;
        else throw std::out_of_range("Out of range");
    }
    void push_front(T elem)
    {
        insert(elem,0);
    }
    void pop_back()
    {
        if (!(this->isEmpty())) size--;
    }
    void pop_front()
    {
        erase(0);
    }
    void insert(T elem, std::size_t ind)
    {
        if(!(this->isFull()))
        {
            for (std::size_t i=size;i>ind;i--)
                data[i]=data[i-1];
            data[ind]=elem; size++;
        } else throw std::out_of_range("Out of range!");
    }
    void erase(std::size_t ind)
    {
        if (!(this->isEmpty()))
        {
            for (std::size_t i=ind; i<size-1;i++)
                data[i]=data[i+1];
            size--;
        }
    }
};

#endif
