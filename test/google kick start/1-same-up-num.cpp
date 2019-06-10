#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory>
#include <iostream>
#include <string>
using namespace std;
const int Msize=100010;

unsigned int skl[Msize]={0};
unsigned int dp[Msize]={0};

void print_arr(unsigned* p,int N){
    for_each(p, p + N, [](int x) { cout << x << " "; });
    cout << endl;
}


int main(){
    int T,N,P;
    cin>>T;
    for(int num=0;num<T;num++){
        cin>>N>>P;
        memset(dp,0,sizeof(unsigned)*N);
        for(int i=0;i<N;i++)
            scanf("%d",&skl[i]);
        sort(skl,skl+N);
        // print_arr(skl,N);
        for(int i=0;i<P;i++){
            dp[P-1]+=skl[i];
        }
        unsigned m=P*skl[P-1]-dp[P-1];
        // print_arr(dp,P);
        for(int i=P;i<N;i++){
            dp[i]=dp[i-1]+skl[i]-skl[i-P];
            m=min(m,P*skl[i]-dp[i]);
        }
        printf("Case #%d: %d\n",num+1,m);
    }
}