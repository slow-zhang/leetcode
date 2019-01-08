#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        /// 1. x : 32bit signed interger
        /// 2. return 0 if reversed int overflow
            /// up-long -down int ; by median time
        /// 1/4 
       
        bool nflag=x<0;
        x=x<0 ?-x :x;
        
        
        int bits[20]={0};
        int num=0;
        do{
            bits[num++]=x%10;
            x/=10;
        }while(x!=0);
        
        x=0;
        int t;
        for(int i=0;i<num;i++){
            t=x;
            x=x*10+bits[i];  
        }
        if(t!=0 && x/t<10) return 0;
        return nflag? -x:x;
    }
};