#include <iostream>
#include "vector.h"
using namespace stl;
using namespace std;

int main(){

    Vector<int> v,v2;
    for(int i=0;i<10;i++){

        v.push_back(i);
        v2.push_back(i+2);
    }
    
    v.show();
    v2.show();
    v.swap(v2);
    v.show();
    v2.show();
    v.assgin(5,200);
    v.show();
    v.resize(15,2);
    v.show();
    v.reserve(20);
    v.show();
/*
 为什么不能直接使用对象来指定迭代器，既然迭代器是在一个类中，并且它不是静态类型

 回答：
类型成员（如 iterator）是编译时的概念，而对象实例（如 v）是运行时的概念。
在编译时，编译器需要知道类型信息，而这种信息不能通过运行时对象（如 v）来提供。

假设可以通过对象来访问类型，如 v.iterator，那么编译器需要在编译时知道 v 的类型，
但类型本身是在编译时确定的，这样就造成了一个矛盾。

说人话
模板是在编译时获取类型，但对象是运行时才产生，因此不能

*/
 
/*iterator就是类然后封装了一个指针，相当于二次封装。
    for(int * it=v.begin().m_pointer;it!=v.end().m_pointer;it++){
    
         cout<<it<<",<";//&t地址一直不变，it指的是一个类的地址，*it因为重载了符号，所以返回的是类中指针的那个值。
         cout<<*it<<endl;
      
    }
*/
 v.insert(v.begin()+2,2,999);
 
    cout<<"iterator :\n";
    for(auto it = v.begin();it!=v.end();it++){
        cout<<*it << ",";
    }
v.erase(v.begin());
 v.show();
v.erase(v.begin(),v.end()-5);
  v.show();
    return 0;
}