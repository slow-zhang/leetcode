#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

map<string, int> mp; // 义工14个 【1，13】
void init()
{
    mp["A"] = 1;
    mp["2"] = 2;
    mp["3"] = 3;
    mp["4"] = 4;
    mp["5"] = 5;
    mp["6"] = 6;
    mp["7"] = 7;
    mp["8"] = 8;
    mp["9"] = 9;
    mp["10"] = 10;
    mp["J"] = 11;
    mp["Q"] = 12;
    mp["K"] = 13;
}
int main()
{
    init();

    int N;
    cin >> N;
    for (int ii = 0; ii < N; ii++)
    {
        int M;
        cin>>M;
        vector< int > inp(14,0);

        for(int i=0;i<M;i++){
            string s;
            cin>>s;
            inp[mp[s]]++;
        }
        int ans=0;
        // 不同顺子长度
        for(int i=5;i<=13;i++){
            // cout<<"s"<<i;
            // 不同的起始点
            for(int j=i;j<=13;j++){
                int len=0;
                int sum=1;
                // 长度为i
                for(int k=j;k>=1;k--){
                    len++;
                    sum *= inp[k];
                    if (len == i)
                    {
                        ans+=sum;
                        break;
                    }
                    if(inp[k]==0) break;
                }
            }
        }

        cout <<endl<< ans << endl;
    }
}