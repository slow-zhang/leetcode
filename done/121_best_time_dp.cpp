class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans=0;
        int gain[100000];
        gain[0]=0;
        for(int i=1;i<p.size();i++){
            gain[i]=max(0,gain[i-1]+p[i]-p[i-1]);
            ans=max(gain[i],ans);
        }
        return ans;
    }
};