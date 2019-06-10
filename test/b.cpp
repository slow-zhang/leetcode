#include <vector>
#include <cstdio>
#include <string>
#include "util.h"
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    string sa = to_string(a);
    string sb = to_string(b);
    return a > b;
}
bool cmpv(vector<int> a1, vector<int> a2)
{
    int len = min(a1.size(), a2.size());
    for (int i = 0; i < len; i++)
    {
        if (a1[i] != a2[i])
            return cmp(a1[i], a2[i]);
    }
    return a1.size() > a2.size();
}

class Subset
{
  public:
    void gen(vector<vector<int>> &ans, vector<int> &va, vector<int> &tmp, int i, int n)
    {
        if (i == n)
        {
            if (tmp.size() != 0)
                ans.push_back(tmp);
            return ;
        }
        tmp.push_back(va[i]);
        gen(ans, va, tmp, i + 1, n);
        tmp.pop_back();
        gen(ans, va, tmp, i + 1, n);
        
    }

    vector<vector<int>> getSubsets(vector<int> &va, int n)
    {
        // write code here
        vector<vector<int>> ans;

        sort(va.begin(), va.end(), cmp);
        printvec(va);
        vector<int> tmp;
        gen(ans, va, tmp, 0, n);
        for(int i=0;i<ans.size();i++) printvec(ans[i]);
        sort(ans.begin(), ans.end(), cmpv);
        return ans;
    }
};
bool chkParenthesis(string A, int n)
{
    // write code here
    int cnt = 0;
    if (n & 1)
        return false;
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
        if (A[i] == '(')
            cnt++;
        else if (A[i] == ')')
            if (--cnt < 0)
                return false;
            else
                return false;
    }
    return true;
}
int main(){
    // int N,a;
    // cin>>N;
    // vector<int> va(N);
    // for(int i=0;i<N;i++){
    //     scanf("%d",&a);
    //     va[i]=a;
    // }
    
    // Subset s;
    // s.getSubsets(va,N);
    cout << chkParenthesis("()()((()))",12);
     return 0;
}