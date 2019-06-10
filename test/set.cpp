#include <set>
#include <iostream>

using namespace std;

int main(){
    set<int> s{1,2,3,4,5,6,7,8,9,100,120};
    auto itr=s.rbegin();
    cout<<*itr<<" ";
    itr++;
    cout<<*itr<<endl;
}