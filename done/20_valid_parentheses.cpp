#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // if(s.size()%2) return false;
        map<char,char> mp;
        mp['(']=')';
        mp['{']='}';
        mp['[']=']';
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            
            char tmp=s[i];
            if(mp.find(tmp)!=mp.end()){
                st.push(tmp);   
            }else{
                if(st.empty() || mp[st.top()] != tmp)
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};