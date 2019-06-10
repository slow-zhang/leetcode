#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


int inp[110][110]={0};
// int max_down_length(vector<vector<int>> input)
bool vst[110][110];
int R, C;

int dfs(int x,int y,int preh){
    if(x<0 || x>=R || y<0 ||y>=C) return 0;
    if(vst[x][y]==true) return 0;
    if(inp[x][y]>preh) return 0;
    vst[x][y]=true;
    
    int maxh=-1;
    maxh = max(maxh, dfs(x + 1, y, inp[x][y]));
    maxh = max(maxh, dfs(x - 1, y, inp[x][y]));
    maxh = max(maxh, dfs(x, y + 1, inp[x][y]));
    maxh = max(maxh, dfs(x, y - 1, inp[x][y]));

    vst[x][y]=false;
    return maxh+1;
}

int main(){
    cin>>R>>C;
    int maxx,maxy,maxh=-1;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            scanf("%d",&inp[i][j]);
            if(inp[i][j]>maxh){ // 小心可能最优解不是最高点，这个时候需要每个点遍历
                maxx=i;
                maxy=j;
                maxh=inp[i][j];
            }
        }
    }

    fill(vst[0],vst[0]+110*110,false);
    int ans=dfs(maxx,maxy,maxh);

    printf("%d",ans);

    return 0;
}