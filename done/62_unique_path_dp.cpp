class Solution {
public:
    
    int uniquePaths(int m, int n) {
        
        long long p[101][101];
        for(int i=0;i<101;i++){
            p[i][0]=p[0][i]=0;   
        }
        p[1][1]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1 && j==1) continue;
                p[i][j]=p[i-1][j]+p[i][j-1];
            }
        }
        
        return p[m][n];
    }
};