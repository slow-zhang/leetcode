class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int l=a.size();
        if(l<=1) return ;
        
        int i=0,j=0;
        while(j<l){
            if(a[j]!=0) a[i++]=a[j++];
            else j++;
        }
        while(i<l)
            a[i++]=0;
        return ;
    }
};