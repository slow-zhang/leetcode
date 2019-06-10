class Solution {
public:
    int climbStairs(const int n) {
        int step[n+2];
        step[0]=1;
        step[1]=1;
        for(int i=2;i<=n;i++){
            step[i]=step[i-1]+step[i-2];   
        }
        return step[n];
    }
};