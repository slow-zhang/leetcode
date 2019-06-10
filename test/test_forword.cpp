#include <iostream>

template<class T>
void foo(T&& s){
    std::cout<<"ok";
}

int main(){
    int i=0;
    foo(i);
    foo(0);
    return 0;
}