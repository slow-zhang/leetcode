class Solution {
public:
    void swapii(int &a1,int &a2){
        if(a1==a2) return ;
        a1^=a2;a2^=a1;a1^=a2;
    }

    
    int removeElement(vector<int>& nums, int val) {
        
/// swap remove
        int i=0, j=nums.size()-1;
        // swapii(nums[0],nums[1]);
        while(i<=j){
            if(nums[i]==val)
                swapii(nums[i],nums[j--]);
            else
                i++;
        }
        return j+1;

/// erase for last
        // int s=nums.size();
        // for(int i=s-1;i>=0;i--){
        //     if(nums[i]==val) {
        //         nums.erase(nums.begin()+i);
        //         i;s--;
        //     }
        // }
        // return s;
        
/// eraase for begins
//         int s=nums.size();nums.erase(nums.begin()+0,nums.begin()+1);
//         for(int i=0;i<s;i++){
//             if(nums[i]==val) {
//                 nums.erase(nums.begin()+i);
//                 i--;s--;
//             }
//         }
//         return s;
    }
};