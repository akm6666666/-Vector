#pragma once
namespace stl
{
  template <typename T>
  class VectorConstIterator{

   typedef VectorConstIterator<T> iterator;

   private:
      T *  m_pointer;

   public:
     VectorConstIterator():m_pointer(nullptr){}
     VectorConstIterator(T * pointer):m_pointer(pointer){}
     ~VectorConstIterator(){}


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

        m_pointer+=1;
        return *this;
    }

    iterator operator ++ (int){
        iterator it =*this;
        ++(*this);
        return  it;
    }

    iterator & operator +=(int n){

     m_pointer+=n;
     return *this;
    }

    iterator & operator --(){

        m_pointer-=1;
        return *this;
    }

    iterator & operator -- (int){
        iterator it=*this;
        --(*this);
        return it;
    }
    iterator  operator - (int n){
        iterator it = *this;
        it.m_pointer -=n;
        return it;
    }

    iterator & operator -= (int n){
        m_pointer-=n;
        return *this;
    }

    int operator - (const iterator & other) const{


        return m_pointer - other.m_pointer;

    }

   const T & operator * (){
        return  *m_pointer;
    }

   const T * operator -> (){
        return m_pointer;
    }


  };


}