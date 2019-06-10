#include <string>
#include <map>
#include <iostream>

using namespace std;
int d3[10010] = {0};
int d5[20010] = {0};

map<int, char> mp;
void init()
{
    for (int i = 0; i <= 9; i++)
    {
        mp[i] = '0' + i;
    }
    for (int i = 10; i < 32; i++)
    {
        mp[i] = 'A' + i - 10;
    }
}
int main()
{
    init();
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {

        string s;
        cin >> s;

        int len = s.size();
        // 高位补0
        while (s.size() % 3 != 0)
        {
            s.insert(0, "0");
        }
        int num3 = s.size() / 3;

        // 从高到低存放
        for (int i = 0; i < num3; i++)
        {
            d3[i] = stoi(s.substr(i * 3, 3));
            cout<<d3[i]<<" ";
        }
        // 不用合到一起，直接转换为5bit一个
        for (int i = 0; i < num3; i++)
        {
            int tmp = d3[i];
            d5[i * 2] = tmp >> 5;
            d5[i * 2 + 1] = tmp & 0x1f;
            cout<<d5[i*2]<<","<<d5[i*2+1]<<",";
        }

        string ans;
        // 转化，注意第一个可能为0
        for (int i = 0; i < num3 * 2; i++)
        {
            ans += mp[d5[i]];

            cout<<ans<<endl;
        }
        if (ans[0] == '0')
        {
            ans.erase(ans.begin());
        }

        cout <<endl<< ans << endl;
    }
}