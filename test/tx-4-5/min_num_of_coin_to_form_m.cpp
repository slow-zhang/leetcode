#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int coin[110] = {0};

int m,n;
int sum=0;
int total_coin_num=0;

// 从大到小看
void find_min(int m,int index){
    if(index==1){
        sum+=m;
        total_coin_num+=m;
        cout << "using  1 " <<m << endl;
        return ;
    }
    int tmp_coin=coin[index-1]; // 当前coin 面额
    int tmp_cnt= (m+tmp_coin-1)/tmp_coin-1;
    if (index != n)
        if (m % tmp_coin == 0)
            tmp_cnt++;
    sum+=tmp_cnt*tmp_coin;
    
    total_coin_num+=tmp_cnt;
    m=tmp_coin-1;
    cout << "using " << tmp_coin << "," << tmp_cnt << "," << sum << endl;
    find_min(m,index-1);
    return ;
}

int main()
{
    cin>>m>>n;
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    sort(coin,coin+n);

    if(coin[0]!=1) return 0;// 输出-1

    find_min(m,n);

    if(sum<m)
        total_coin_num+=1;

    cout<<total_coin_num;
    return 0;
}