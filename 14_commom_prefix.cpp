#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    /// cal [spos, spos+a),[spos+a, spos+a+b);
    int sublongestCommonPrefix(vector<string>& strs,int spos,int a,int b){
        cout<<spos<<","<<a<<","<<b<<" ";
        int prefix1=strs[spos].size();
        int prefix2=strs[spos+a].size();
        if(a>=2) prefix1=sublongestCommonPrefix(strs,spos,a/2,a-a/2);
        if(b>=2) prefix2=sublongestCommonPrefix(strs,spos+a,b/2,b-b/2);
        int prefix=min(prefix1,prefix2);
        for(int i=prefix-1;i>=0;i--){
            if(strs[spos][i]!=strs[spos+a][i])  prefix=i;
        }
        return prefix;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int ssize=strs.size();
        if(ssize==0) return "";
        if(ssize==1) return strs[0];
        // [0,ssize/2),[ssize/2,ssize)
        int prefix=sublongestCommonPrefix(strs,0,ssize/2,ssize-ssize/2);
        
        string ans=strs[0];
        return ans.substr(0,prefix);

        // int ssize=strs.size();
        // if(ssize==0) return "";
        // string ans=strs[0];
        // int prefix=ans.size();
        // for(int i=1;i<ssize;i++){
        //     for(int j=0;j<prefix;j++){
        //         if(ans[j]!=strs[i][j]){
        //             prefix=j;
        //             break;
        //         }
        //     }
        // }
        // return ans.substr(0,prefix);
    }
    
    
};




