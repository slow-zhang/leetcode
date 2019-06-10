
#include <vector>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;
int ad[][2]={
    {1,0},
    {0,1},
    {1,1},
    {1,-1}
};

int inpoint[100][2];

// flg 指出还有哪些没有切掉 
// direct [0-3]   fxfy是父节点的位置，通过这个可以消除一条线上的

int core(vector<vector<int> > flg,int fx,int fy,int direct,int left){
    cout << "infun1 " << left << endl;
    if (left == 0)
        return 0;
    // 先处理线
    flg[fx][fy]=0;
    left--;
    if (left == 0)
        return 1;
    for(int i=-40;i<=40;i++){ 
        int tx=fx+i*ad[direct][0];
        int ty=fy+i*ad[direct][1];

        if(tx>=0 && tx<40 
            && ty>=0  && ty<50
            && flg[tx][ty]==1 )
        {
            left--;
            flg[tx][ty]=0;
        }
    }
    cout<<"infun "<<left<<endl;
    if (left == 0)
        return 1;
    //找到下一个
    for(int i=0;i<36;i++){
        if ( flg[inpoint[i][0]][inpoint[i][1]] == 1 ){
            
            int m=1000;
            for(int d=0;d<4;d++){
                int tmp=core(flg,inpoint[i][0],inpoint[i][1],d,left);
                if(tmp==0) continue;
                m=min(tmp+1,m);
            }
            return m;
        }
    }
    return 1;
}

int main(){
    int N,x,y;
    cin>>N;
    vector<vector<int> >scrn(40,vector<int>(50,0));
    for(int num=0;num<N;num++){
        cin>>x>>y;
        inpoint[num][0]=x;
        inpoint[num][1]=y;
        scrn[x][y]=1;
    }

    int m=1000;
    for(int i=0;i<4;i++){
        int tmp=core(scrn,x,y,i,N);
        cout<<tmp<<" "<<endl<<endl;
        if(tmp==0) continue;
        m=min(m,tmp);
    }
    cout<< m <<endl;
}