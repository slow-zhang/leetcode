#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct V{
    char* p;
    // const V& operator =(const V& rhs){
    //     p=rhs.p;
    //     return rhs;
    // }
};

int main()
{
    vector<V> vec;
    V v1,v2,v3;
    vec.push_back(v1);
    vec.push_back(v2);
    vec.push_back(v3);
    char a[2]{"x"};
    char b[2]{"y"};
    char c[2]{"z"};
    vec[0].p=a;
    vec[0].p=b;
    vec[2].p=c;
    cout<<"inserted"<<endl;

    vec.erase(vec.begin());
    return 0;
}