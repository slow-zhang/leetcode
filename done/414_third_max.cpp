#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    const long long empty=LLONG_MIN;
    long long a1,a2,a3;
    
    int thirdMax(vector<int>& a) {
        a1=a2=a3=empty;
        for(int i=0;i<a.size();i++){
            // 检查每一个数，如果大于第三大的数则加入，如果空直接加入；
            // add ： 相等跳过， 否则替换最小的再上升
            int tmp=a[i];
            if(tmp==a1 || tmp==a2 || tmp==a3) continue;
            if(tmp>a1) a1=tmp;
            if(a1>a2) swap(a1,a2);
            if(a2>a3) swap(a2,a3);
        }
        
        return a1==empty? a3 : a1;
    }
};