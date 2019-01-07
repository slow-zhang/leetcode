class Solution {
public:
    /// [l,r)
    int binsearch(vector<int>& nums, int t,int l,int r){
        if(l==r)return l;
        if(r==l+1){
            if(t<=nums[l])
                return l;
            else
                return r;
        }
        
        int mid=(r-l)/2+l;
        if(t>nums[mid]) 
            l=mid+1;
        else
            r=mid;
        return binsearch(nums,t,l,r);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return binsearch(nums,target,0,nums.size());
    }
};