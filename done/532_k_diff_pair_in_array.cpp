#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        // answer of network
        if (k < 0) return 0;
        
        unordered_map<int, int> m;
        for (int n : a) m[n]++;
        int cnt = 0;
        for (auto p : m) {
          if ((!k && p.second > 1)
            || (k && m.count(p.first + k))) ++cnt;
        }
        return cnt;
        if(a.size()==1) return 0;
        sort(a.begin(),a.end());
        //deduplication
        int ans=0;
        int i=0,j=1;
        int olda=0,oldb=k+1;
        while(j<a.size()){
            if(a[j]-a[i]==k){
                if(olda==a[i]&&oldb==a[j]){
                    ans--;
                }
                olda=a[i];
                oldb=a[j];
                
                ans++;
                i++;
                j++;
                // cout<<i<<","<<j<<endl;
            }
            else if(a[j]-a[i]<k){
                j++;
            }else{
                i++;   
            }
            if(i==j)j++;
        }
        return ans;
    }
};