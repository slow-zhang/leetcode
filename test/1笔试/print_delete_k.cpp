#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> cur;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cur.push_back(temp);
    }
    sort(cur.begin(), cur.end());
    int index_0 = -1;
    for (int i = 0; i < n; i++)
    {
        if (cur[i] == 0)
        {
            index_0 = i;
        }else{
            break;
        }
    }

    vector<int> del_seq;
    int i=1,pre_del=cur[0];
    printf("%d\n",cur[0]);
    while(i<k)
    {
        // cout<<i<<endl;
        // 全是 0
        if (index_0 == n - 1)
        {
            cout << 0 << endl;
            i++;
            continue;
        }
        // 输出判断
        int temp = cur[index_0 + 1];
        if(temp-pre_del>0){
            int t=temp-pre_del;
            printf("%d\n",t);
            pre_del=t;
            i++;
            index_0++;
            continue;
        }
        index_0++;;
    }
    return 0;
}
/*
// better
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e5 + 5;
int n, k;
int main() {
    set<int> S;
    cin >> n >> k;
    for (int i = 0, x; i < n; i++)
        scanf("%d", &x), S.insert(x);
    int pre = 0;
    while (k--) {
        if (S.empty()) printf("0\n");
        else {
            int x = *S.begin();
            S.erase(S.begin());
            printf("%d\n", x - pre);
            pre = x;
        }
    }
}

*/