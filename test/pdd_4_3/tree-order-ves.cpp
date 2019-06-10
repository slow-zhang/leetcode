#include <iostream>
#include <vector>
using namespace std;
vector<int> res;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void DFS(vector<int> &pv, vector<int> &iv, int ml, int mr, int pl, int pr)
{
    if (pl > pr)
        return;

    int pos = ml;
    while (iv[pos] != pv[pl])
    {
        pos++;
    }
    int ll = pos - ml;
    DFS(pv, iv, ml, ml + ll - 1, pl + 1, pl + ll);
    DFS(pv, iv, ml + ll + 1, mr, pl + 1 + ll, pr);
    cout << pv[pl] << " ";
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> pre;
    vector<int> in;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pre.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        in.push_back(temp);
    }
    DFS(pre, in, 0, n - 1, 0, n - 1);
    return 0;
}