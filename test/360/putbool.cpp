#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <limits>

using namespace std;
int col[10010] = {0};
int num = 0;

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/

// 0 for cannot
int check_ok(vector<int> &s, int numbocket)
{
    int ans = 0;
    for (auto t : s)
    {
        cout<<t<<",";
        if (t % numbocket == 0)
        {
            ans += t / numbocket;
        }
        else
        {
            return 0;
        }
    }
    cout<<endl;
    return ans;
}

int fun()
{
    vector<int> s;
    int m = 100000, oddnummax = 0;
    for (int i = 0; i < num; i++)
    {
        if (col[i] != 0)
        {
            s.push_back(col[i]);
            if (col[i] & 1)
                oddnummax = max(oddnummax, col[i]);
            m = min(m, col[i]);
        }
    }
    // if (m != oddnummax)
    //     return 0;
    int i = 2, j = m + 1;
    
    int ans = 1000000;
    while (i < j)
    {
        cout << i << ",," << j << endl;
        int midd = (j - i) / 2 + i;
        int tmp = check_ok(s, midd);
        cout << tmp << endl;
        if (tmp == 0)
        {
            j = midd;
        }
        else
        {
            i = midd + 1;
            ans = min(ans, tmp);
        }
    }
    for(int i=m;i>=2;i--){
        if(m%i != 0) continue;
        int t;
        if(t=check_ok(s,i) != 0) return t;

    }
    return ans == 1000000 ? 0 : ans;
}
/******************************结束写代码******************************/

int main()
{
    int res, bsize;
    cin >> bsize;
    if (bsize & 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < bsize; i++)
    {
        int t;
        scanf("%d", &t);
        num = max(num, t);
        col[t]++;
    }

    num++;
    res = fun();
    cout << res << endl;

    return 0;
}
// 