class Solution {
public:
    int rob(vector<int>& a) {
        if(a.size()==0) return 0;
        if(a.size()==1) return a[0];
        int gain[10000];
        gain[0]=a[0];
        gain[1]=max(a[0],a[1]);
        for(int i=2;i<a.size();i++){
            gain[i]=max(gain[i-2]+a[i],gain[i-1]);
        }
        return gain[a.size()-1];
    }
};