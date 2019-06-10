#include <string>
#include <map>
#include <iostream>
#include <queue>
// #include <priority_queue> // zai queue 里面

using namespace std;
int N,M,B,E;
const int inf=100000000;
// [1,N]

typedef struct Battery{
    int id;
    double contain;
    double input_pow; // 输入功率 可以增加
    double st,et; // 充电开始时间，当前功率结束时间
    double overtime;
    Battery(){}
    Battery(int c):contain(c),et(inf),input_pow(0){};
    void add_power(double p,int t){
        contain -= input_pow*(t-st);
        // if(contain<=0) return ;
        input_pow+=p;
        st=t;
    }
} Ba;
Ba b[210];


bool cmp(const Ba a,const Ba b) {
        return a.et<b.et;
}



int main()
{
    int N;
    cin >> N;
    for (int ii = 0; ii < N; ii++)
    {
        cin >> N >> M >> B >> E;

        vector< vector<int> > inp(N,vector<int>());
       
        
        
        for (int i = 1; i <= N; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            b[i].contain=tmp;
            b[i].et=inf;
            b[i].id=i;
        }

        for (int i = 0; i < M; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            inp[a].push_back(b);
        }

        b[B].input_pow=E;
        b[B].st=0;
        b[B].et=b[B].st+b[B].contain/b[B].input_pow;
       
        
        
        for(int i=1;i<=N;i++){
            sort(b+i,b+N+1,cmp);
            if(b[i].et==inf) break;
        }

        sort()
        for(int i=1;i<=N;i++){

        }
        

    }
}