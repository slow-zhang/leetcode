#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory>
#include <iostream>
#include <string>
using namespace std;
const int Msize = 100010;

unsigned int skl[Msize] = {0};
unsigned int dp[Msize] = {0};

typedef struct Order{
    int s;
    int e;
    Order(int _x,int _y):s(_x),e(_y){}
}Order;

bool can_order(vector<Order> &od,int m){
    int s=od[0].s;
    cout<<"ride "<<m<<endl;
    for(int i=0;i<od.size();i++){
        s=max(s,od[i].s);
        cout<<"mid:::"<<i<<":"<<s<<"->"<<od[i].e<<endl;
        if(s+m-1>od[i].e) return false;
        s=s+m;
    }
    return true;
}

    void
    print_arr(vector<Order> &p)
{
    for_each(p.begin(), p.end(), [](Order o) { cout << o.s << ","<<o.e<<" "; });
    cout << endl;
}

int main()
{
    int T, N, M;
    cin >> T;
    for (int num = 0; num < T; num++)
    {
        cin >> N >> M;
        int a,b;
        vector<Order> orders;
        for (int i = 0; i < M; i++){
            scanf("%d %d", &a,&b);
            orders.emplace_back(a,b);
        }
        sort(orders.begin(), orders.end(), [](Order o1, Order o2) -> bool {
            if(o1.s<o2.s)
                return true;
            if(o1.s==o2.s && o1.e<o2.e)
                return true;
            return false;
        });
        print_arr(orders);
        int over=orders[M-1].e-orders[0].s+1;
        int max=over/M;
        int i;
        for(i=max;i>=1;i--){
            if(can_order(orders,i))
                break;
        }        


        printf("Case #%d : %d\n",num+1,i);
        

    }
}