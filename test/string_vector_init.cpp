#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

class Solution
{
  public:
    typedef struct Pos
    {
        int x, y;
    } Pos;
    vector<Pos> pq;

    vector<string> genstring(int n)
    {
        // 采取合适的策略 可以不用排序
        // sort(pq.begin(),pq.end(),cmp);

        vector<string> s(n, string(n - 1, '.'));
        return move(s);
    }

    vector<vector<string> > solveNQueens(int n)
    {
        vector<vector<string> > ans;
        ans.push_back(genstring(n));
        return ans;
    }
};

int main(){
    Solution s;
    s.solveNQueens(4);
    return 0;
}