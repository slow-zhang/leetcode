
#include <iostream>
using namespace std;

class A
{
    virtual void x()
    {
        cout << "A:x\n";
    }
};

class B
{
    virtual  void x() 
    {
        cout << "B:x\n";
        
    }
};

class C: public A,public B
{

};

int main(){
   
    B *b=new A;
    b->x();
}
