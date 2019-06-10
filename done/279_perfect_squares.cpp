class Solution {
public:
    int numSquares(int n) {
        if(n<=1) return n;
        int numsq[10000];
        if(n>=10000) return 1314;
        numsq[0]=0;
        numsq[1]=1;
        for(int i=2;i<=n;i++){
            numsq[i]=i;
            for(int j=0;j*j<=i;j++){
                   numsq[i]=min(numsq[i],1+numsq[i-j*j]);
            }
        }
        return numsq[n];
    }
};