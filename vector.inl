
template <typename T>
 Vector<T>::  Vector():m_data(nullptr),m_size(0),m_capacity(0) {}
   
 template <typename T>  
    Vector<T>:: ~Vector(){
        if(m_data!=nullptr){
            delete[] m_data;
        }
        m_size=0;
        m_capacity=0;
    }
 
template <typename T>  
  T & Vector<T>:: at(int index){
      
     if(index <0 || index > m_size){
        throw std::out_of_range("out of range");
     }
      return m_data[index];

  }

template <typename T> 
const T & Vector<T>:: at(int index) const{

     if(index <0 || index > m_size){
        throw std::out_of_range("out of range");
     }
      return m_data[index];
}



template <typename T> 
T & Vector<T>:: front(){

  return m_data[0];
}
template <typename T> 
const  T & Vector<T>:: front() const{
    return m_data[0];
}

template <typename T>         
T & Vector<T>:: back(){

    return m_data[m_size-1];
}

template <typename T>  
const T & Vector<T>:: back() const{

    return m_data[m_size-1];
}
template <typename T>  
T * Vector<T>::data(){

  return m_data;
}
template <typename T>  
const T * Vector<T>::data() const{

    return m_data;
}

template <typename T>  
 T & Vector<T>::operator [] (int index){

   return m_data[index];
 }
 template <typename T>  
const T & Vector<T>::operator [] (int index) const{


    return m_data[index];
}
 template <typename T>  
void Vector<T>:: push_back(const T & value){
    if(m_size<m_capacity){

        m_data[m_size]=value;
        m_size++;
        return;
    }

    if(m_capacity ==0){

        m_capacity=1;

    }else {

        m_capacity *=2;
       //std:: cout<<"has resize()"<<std::endl;
    }

    T * data=new T[m_capacity];

    if(is_basic_type()){
      //memcpoy处理源不能和目的区域重叠，memmove可以
      memcpy(data,m_data,m_size*sizeof(T));

    }else{
      for(int i=0;i<m_size;i++){

        data[i]=m_data[i];
      }
    }
    
     
     if(m_data !=nullptr){

        delete [] m_data;
        m_data = nullptr;
     }

     m_data=data;
     m_data[m_size]=value;
     m_size++;
}

 template <typename T>  
  void Vector<T>:: pop_back(){
    if(m_size>0)
      m_size--;

  }

  template <typename T>
  void Vector<T>:: show() const{


    std::cout<<"size:"<<m_size<< ",capacity:"<<m_capacity<< std::endl;
      for(int i=0;i<m_size;i++){

        std::cout<<m_data[i]<<", ";

      }
      std::cout<<std::endl;
 }

template <typename T>
 void Vector<T>:: assgin(int n,const T & value){

    if(m_capacity>=n){

        for(int i=0;i<n;i++){
            m_data[i]=value;
        }
    return;

    }

    if(m_data !=nullptr){
        delete [] m_data;
        m_data =nullptr;
        m_size=0;
        m_capacity=0;
    }

    while(m_capacity<n){

        if(m_capacity ==0){
            m_capacity = 1;
        }else {
            m_capacity*=2;
        }
    }

    m_data=new T[m_capacity];
    for(int i=0;i<n;i++){
        m_data[i]=value;
    }
    m_size=n;

 }
template <typename T>
void  Vector<T>::swap(Vector<T> & other){

  if(this == &other)
    return;

T * data=other.m_data;
int size=other.m_size;
int capacity=other.m_capacity;

other.m_data=m_data;
other.m_capacity=m_capacity;
other.m_data=m_data;


m_data=data;
m_capacity=capacity;
m_data=data;


}
template <typename T>
  bool  Vector<T>::empty() const{

   return m_size==0;
  }
  template <typename T>
int Vector<T>:: size() const{

  return m_size;
}
template <typename T>
int Vector<T>:: capacity() const{

return m_capacity;

}

template <typename T>
void Vector<T>:: resize(int n){
   resize(n,T());
}
template <typename T>
void Vector<T>:: resize(int n,const T & value){

    if(n<m_size){
    m_size=n;
    return;
  }


  if(n<m_capacity){

    for(int i=m_size;i<n;i++){
        m_data[i]=value;
    }
    m_size=n;
    return;
  }

  while(m_capacity<n){

    if(m_capacity==0){
        m_capacity=1;
    }else{
        m_capacity*=2;
    }

  }

  T * data=new T[m_capacity];
  for(int i=0;i<m_size;i++){
    data[i]=m_data[i];
  }
   
   for(int i=m_size;i<n;i++){
    data[i]=value;
   }

   if(m_data!=nullptr){
    delete [] m_data;
    m_data=nullptr;
   }

   m_data=data;
   m_size=n;


}

template <typename T>
void Vector<T>:: reserve(int n){
  
  if(m_capacity > n){
    return;
  }
  
  while(m_capacity <n){
    if(m_capacity==0){
        m_capacity=1;
    }else {
        m_capacity*=2;
        
    }
  }

  T * data=new T[m_capacity];
  for(int i=0;i<m_size;i++){
     data[i]=m_data[i];
  }
  if(m_data!=nullptr){
     delete [] m_data;
     m_data=nullptr;
  }

  m_data=data;

}

/*
 Vector<T>::iterator 时，可能会将 iterator 误解为其他类型的标识符（如变量或成员函数）。
 为了避免这种混淆，你需要使用 typename 关键字来明确告知编译器 iterator 是一个类型。
*/
template <typename T>
typename Vector<T>::iterator Vector<T>:: begin(){

   return iterator(m_data);
}

template <typename T>
typename Vector<T>::iterator Vector<T>:: end(){
   return iterator(m_data + m_size);
}

template <typename T>
typename  Vector<T>:: const_iterator Vector<T>:: cbegin() const{


    return const_iterator(m_data);
}

template <typename T>
typename  Vector<T>:: const_iterator Vector<T>:: cend() const{

    return const_iterator(m_data+m_size);
}


template <typename T>
typename Vector<T>:: Reverse_iterator Vector<T>:: rbegin(){
    return Reverse_iterator(m_data+m_size-1);
}
template <typename T>
typename Vector<T>::  Reverse_iterator  Vector<T>:: rend(){

    return Reverse_iterator(m_data-1);
}

template <typename T>
typename Vector<T>:: iterator Vector<T>:: insert(const iterator & pos,const T & value){

  return insert(pos,1,value);
}
template <typename T>
typename Vector<T>:: iterator Vector<T>:: insert(const iterator & pos,int n,const T & value){
    int size=pos-begin();
    if(m_size+n <= m_capacity){
       for(int i=m_size;i>size;i--){
           m_data[i+n-1]=m_data[i-1];
       }

        for(int i=0;i<n;i++){
          m_data[size+i]=value;
        }

        m_size+=n;

       // return iterator(m_data+size);
      return pos;
    }

    while(m_size+n > m_capacity){
      if(m_capacity==0){
        m_capacity=1;
      }else{
        m_capacity*=2;
      }
    }

    T * data =new T[m_capacity];
    for(int i=0;i<size;i++){
      data[i]=m_data[i];
    }

    for(int i=0;i<n;i++){
       data[size+i]=value;
    }

    for(int i=size;i<m_size;i++){
      data[i+n]=m_data[i];
    }

    if(m_data!=nullptr){
      delete [] m_data;
      m_data=nullptr;
    }

    m_data=data;
    m_size+=n;

    return pos;
}

template <typename T>
typename Vector<T> :: iterator Vector<T>:: erase( const iterator & pos){
    if(end()==pos) {
      throw std::out_of_range("out of range");
    }
    if(end()-pos==1){
      m_size-=1;
      return end();
    }

    int size=pos-begin();
    for(int i=size;i<m_size-1;i++){
      m_data[i]=m_data[i+1];
    }
    m_size-=1;
    return pos;
}

template <typename T>
typename Vector<T>:: iterator Vector<T>:: erase(iterator first,iterator second){

    int f=first-begin();
    int c=second-begin();
    int n=c-f;
    if(is_basic_type()){

      memmove(m_data+f,m_data+c,(m_size-c)*sizeof(T));
    }else {

      for(int i=0;i<m_size-c;i++){
      m_data[i+f]=m_data[i+c];
    }
    }
   
    m_size-=n;
    return first;
}
 template <typename T>       
   void Vector<T>::  clear(){

     m_size=0;
    
     


   }   

template <typename T>
    bool Vector<T>:: is_basic_type(){

     if(std::is_pointer<T>::value){
      return true;
     }

      return (typeid(T) == typeid(bool) || 
      typeid(T)==typeid(char) ||
      typeid(T)==typeid(unsigned char) ||
      typeid(T)==typeid(short) ||
      typeid(T)==typeid(unsigned short) ||
      typeid(T)==typeid(int) ||
      typeid(T)==typeid(unsigned int) ||
      typeid(T)==typeid(long) ||
      typeid(T)==typeid(unsigned long) ||
      typeid(T)==typeid(float) ||
      typeid(T)==typeid(double)  );

    }