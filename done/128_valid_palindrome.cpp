#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool notan(char s){
        if((s<='z' && s>='a' )
             || (s<='9' && s>='0'))
            return false;
        return true;
           
    }
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        //if(s.size()<=1) return true;
        int i=0,j=s.size()-1;
        while(notan(s[i])) i++;
        while(notan(s[j])) j--;
        while(i<=j){
             // cout<<i<<","<<j<<endl;
            if(s[i]==s[j]){
                i++;j--;     
            }else{
                return false;   
            }
            while(notan(s[i])) i++;
            while(notan(s[j])) j--;
        }
        return true;
    }
};