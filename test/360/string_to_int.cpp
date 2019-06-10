#include <string.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int nums[20]={0};

bool isnum(char c){
    return (c >= '0' && c <= '9');
}

int transform_string_to_int(string s)
{
    long long ans=0;
    int i = 0;
    while(s[i] == '0') {
        i++;
    }

    // case 00000234 , 0000324.23
    // error 0909.324hh  h 0
    for (; i < s.size(); ++i)
    {
        if(s[i] == '.') {
            while( ++i < s.size() ){
                if(!isnum(s[i])) return 0;
            }
            return ans;
            break;
        }
        if(isnum(s[i])) {
            ans = ans * 10 + s[i] - '0';
        }else {
            return 0;
        }
    }
    return ans > INT_MAX ? 0 : ans;
}

int main(){
    string s;
    cin>>s;
    cout << transform_string_to_int(s);
}