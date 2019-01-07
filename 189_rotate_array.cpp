class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // if(nums.size()<=1) return ;
        k%=nums.size();
        int l= nums.size();
        reverse(nums.begin(),nums.begin()+l-k);
        reverse(nums.begin()+l-k,nums.begin()+l);
        reverse(nums.begin(),nums.begin()+l);
        return ;
    }
};