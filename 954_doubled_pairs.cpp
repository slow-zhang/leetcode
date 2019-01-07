#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    
    static bool cmp(int &a1,int &a2) {
        if(abs(a1)!=abs(a2)) abs(a1)<abs(a2);
        else return a1<a2;
        
    }
    
    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(),A.end(),cmp);
        for(int i=0;i<A.size();i++){
            cout<<A[i]<<" ";
        }
        
        int ahsize=A.size()/2;
        for(int i=0;i<A.size();i++){
            if(i<ahsize){
                A[i] *=2;  
            }else{
                if(A[i]!=A[i-ahsize]) return false;    
            }
        }
        return true;
    }
};
