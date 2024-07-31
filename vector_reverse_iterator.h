#pragma once
namespace stl
{
  template <typename T>
  class VectorReverseIterator{

   typedef VectorReverseIterator<T> iterator;

   private:
      T *  m_pointer;

   public:
     VectorReverseIterator():m_pointer(nullptr){}
     VectorReverseIterator(T * pointer):m_pointer(pointer){}
     ~VectorReverseIterator(){}


    bool operator == (const iterator & other) const{
        return m_pointer==other.m_pointer;
    }

    bool operator != (const iterator & other) const{
        return m_pointer!=other.m_pointer;
    }


    iterator & operator = (const iterator & other){
        if(this == &other){
            return *this;
        }
        m_pointer=other.m_pointer;
        return *this;
    }

    iterator & operator ++(){

        m_pointer-=1;
        return *this;
    }

    iterator operator ++ (int){
        iterator it =*this;
        ++(*this);//与调用的是前置++,并不是对直接对（*this)表示对对象的引用，并不能对对象进行+-操作，
        return  it;
    }

    iterator & operator +=(int n){

     m_pointer-=n;
     return *this;
    }

    iterator & operator --(){

        m_pointer+=1;
        return *this;
    }

    iterator & operator -- (int){
        iterator it=*this;
        --(*this);
        return it;
    }
    iterator  operator - (int n){
        iterator it = *this;
        it.m_pointer +=n;
        return it;
    }

    iterator & operator -= (int n){
        m_pointer+=n;
        return *this;
    }

    int operator - (const iterator & other) const{


        return m_pointer - other.m_pointer;

    }

    T & operator * (){
        return  *m_pointer;
    }

    T * operator -> (){
        return m_pointer;
    }


  };


}