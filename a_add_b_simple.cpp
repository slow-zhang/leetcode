#include "util.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>


class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // // o(n^2)
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             vector <int> a;
        //             a.push_back(i);
        //             a.push_back(j);
        //             return a;
        //         }
        //     }
        // }
        // set
        // set<int> st(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //     if(st.find(target-nums[i])!=st.end()){
        //         // find it and retrun 
        //         vector<int>ans;
        //         int a=target-nums[i];
        //         for(int j=0;j<nums.size();j++){
        //             if(i==j) break;
        //             if(a==nums[j]){
        //                 ans.push_back(min(i,j));
        //                 ans.push_back(max(i,j));
        //                 return ans;
        //             }
        //         }
        //     }
        // }
        map <int ,int >mp;
        for(int i=0;i<nums.size();i++){
            int tmp=nums[i];
            int a=target-nums[i];
            auto iter=mp.find(a);
            if(iter!=mp.end()){
              
                vector<int>ans;
                ans.push_back(iter->second);
                ans.push_back(i);
                return ans;     
            }
            mp[tmp]=i;
        }
    }
};
    }
};


int main(){
    Solution c;
    int a[]={3,2,4};
    vector<int>b (a,a+3);
    vector<int> ans=c.twoSum(b,8);
    for (int i=0;i<2;i++)
        cout<<ans[i]<<endl;
    return 0;
}