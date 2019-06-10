#include <iostream>
#include <iterator>
#include <string>

using namespace std;

template< class T>
class Myiter{
    // a++ 、++a、 ==、 !=、 Con、 Concopy 、*  

};

template< class T>
class Myvector;

template<class T>
std::ostream& operator<<(std::ostream &os, Myvector<T> rhs){
    os<<rhs.data_[0];
    return os;
}

template< class T>
class Myvector{
    // inline, static member function, 
    // 构造函数 析构函数（基础成员变量不需要） 
    // const 函数  member ,针对返回引用: 使用两个返回，
    // this 指针 检查两个calss 是否相同 ; copy()  return *this
    //  iter class  --
public:
    friend std::ostream& operator<<(std::ostream &os,  Myvector<T> rhs);
    typedef Myiter<T> iterator;//所有类型迭代器用同一个名字，便于写出更通用的代码
    Myvector(int s )
        : length_(0) // 需要类初始化时，使用这种方式，普通变量无所谓
        , end_(s)
        {
        data_ = new T[s];
    }
    Myvector(const Myvector &rhs) //  复制构造函数可以访问 private 变量
        :length_(rhs.length_),end_(rhs.end_)
    {
        data_ = new T[end_];
        for(int i=0;i<length_;i++){
            data_[i]=rhs.data_[i];
        }
    }
    ~Myvector(){// TODO 什么时候不需要呢
        delete[] data_;
    }
    void push(T a){
        data_[length_++]=a;
    }

    void print(){
        for(int i=0;i<length_;i++){
            std::cout<<data_[i]<<" ";
        }
        std::cout<<std::endl;
        // std::ostream_iterator<std::string> os(std::cout," ");
        // std::copy(data_,data_+length_,os);
    }

  


    //////////// iter
    // begin() end() size() []

private:
    T* data_;
    // int start_;
    int end_;
    int length_;
};



// function object  函数对象 传给泛型算法
class LessThan{
public:
    LessThan(int v):val_(v){}
    
    bool operator()(int val){
        return val<val_;
    }

private:
    int val_;
};





void test(){
    Myvector<int> v(10);
    v.push(1);
    v.print();
    v.push(2);
    v.print();
    // std::cout<<v<<endl;

    Myvector<int> v2=v;
    v2.print();

    std::cout<<v;

    // for(auto itr=v.begin(),itr!=v.end();it++){
    //     std::cout<<*it<<" ";
    // }


}


int main(){
    test();
    return 0;
}