#include <iostream>

using namespace std;

class A
{
  public:
    virtual void pvf() { cout << "va\n"; }
    virtual void vf() { cout << "A" << endl; }
    void f() { cout << "non vit A\n"; }
};

class B : public A
{
  public:
    void pvf() { cout << "vb\n"; }
    void vf()  { cout << "B" << endl; }
    void f() { cout << "non vit B\n"; }
};

int main(){

    {
        A *a = new B;
        a->pvf();
        a->vf();
        a->f();
    }
    {
        A *a = new A;
        a->vf();
        a->f();
    }
}