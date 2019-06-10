#include <vector>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

template<class T>
inline void printvec(T &a){
    for(int i=0;i<a.size();i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}