#include <string>
#include <iostream>
#include <map>

using namespace std;

string minWindow(string s, string t)
{
    if (s.size() <= 0)
        return "";
    if (t.size() <= 0)
        return "";

    map<char, int> mp;
    for (auto c : t)
    {
        mp[c]++;
    }

    int left = t.size(); // 剩余多少
    int start = 0;       //
    int minl = INT_MAX;
    string ans = "";

    for (int i = 0; i < s.size(); ++i)
    {
        cout << start << " " << i << endl;
        if (mp.count(s[i]) == 1)
        { // 存在 就访问他
            if (--mp[s[i]] >= 0)
                left--;
        }
        if (left == 0)
        {
            int pres = start - 1;
            while (pres != start)
            { // 如果未能前进  退出
                cout << start << ",";
                pres = start;
                cout<<"mp["<<s[start]<<"]:"<<mp.count(s[start])<<endl;
                while (mp.count(s[start]) == 0)
                { // 当前未指中t中
                    start++;
                }

                if (mp.count(s[start]) == 1)
                { // 当前多出来的t中的元素
                    if (mp[s[start]] < 0)
                    {
                        mp[s[start]]++;
                        start++;
                    }
                }
            }
            if (minl > i - start + 1)
            {
                minl = i - start + 1;
                ans = s.substr(start, minl);
            }
        }
    }
    return ans;
}

int main(){
    string s="ajibjiocjonbioabhc";
    string t="abc";
    // cin>>s>>t;
    cout<<minWindow(s,t);
    return 0;
}
