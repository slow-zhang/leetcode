/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //
    map<int ,int> mp;
    int subSum(TreeNode* root) {
        if(root==NULL) return 0;
        int l=subSum(root->left);
        int r=subSum(root->right);
        int s=l+r+root->val;
        if(mp.find(s)!=mp.end())
            mp[s]++;
        else
            mp[s]=0;
        return s;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        subSum(root);
        vector<int> ans;
        int smax=0;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            if(itr->second > smax){
                smax=itr->second;
                ans.clear();
                ans.push_back(itr->first);   
            }else if(itr->second==smax){
                ans.push_back(itr->first);    
            }
        }
        return ans;
    }
};