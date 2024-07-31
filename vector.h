#pragma once
#include <stdexcept>
#include <cstring>
#include "vector_const_iterator.h"
#include "vector_iterator.h"
#include "vector_reverse_iterator.h"

namespace stl{

 template <typename T>
 class Vector{
    public:
        typedef VectorIterator<T> iterator;
        typedef VectorConstIterator<T> const_iterator;
        typedef VectorReverseIterator<T> Reverse_iterator;
    public:
        Vector();
        ~Vector();

        T & at(int index);
        const T & at(int index) const;

        T & front();
        const  T & front() const;
        
        T & back();
        const T & back() const;
        
        T * data();
        const T * data() const;

        T & operator [] (int index);
        const T & operator [] (int index) const;

        void push_back(const T & value);
        void pop_back();

        void show() const;
        //初始化存储n个值为value的元素
        void assgin(int n,const T & value);

        void swap(Vector<T> & other);

        bool empty() const;
        int size() const;
        int capacity() const;

        void resize(int n);
        void resize(int n,const T & value);
        void reserve(int n);

        void clear();
        iterator begin();
        iterator end();
        

        iterator insert(const iterator & pos,const T & value);//加上const 就可以编译成功不知道为什么
        iterator insert(const iterator & pos,int n,const T & value);

        iterator erase(const iterator & pos);
        iterator erase(iterator first,iterator second);
        const_iterator cbegin() const;
        const_iterator cend() const;

        Reverse_iterator rbegin();
        Reverse_iterator rend();

        
    private:
        T* m_data;
        int m_size;
        int m_capacity;
    private:
        bool is_basic_type();

 };


#include "vector.inl"

}
