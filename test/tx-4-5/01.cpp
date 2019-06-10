#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int inp[110][110] = {0};
// int max_down_length(vector<vector<int>> input)
bool vst[110][110];
int R, C;


int main()
{
    string s;
    cin >> s;
    int t=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') t++;
        else t--;
    }
    cout<< (t>=0) ? string(t,'0') : string(-t,'1');

   

    return 0;
}