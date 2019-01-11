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
    // [l,r)
    TreeNode* construct_tree(vector<int>& nums,int l,int r) {
        if(r==l) return NULL;
        if(r-l==1)
            return new TreeNode(nums[l]);
        
        int mid=(r-l)/2+l;
        // cout<<l<<","<<mid<<","<<r<<endl;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=construct_tree(nums,l,mid);
        root->right=construct_tree(nums,mid+1,r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums,int l=-1,int r=-1) {
        if(nums.size()==0) return NULL;
        return construct_tree(nums,0,nums.size());
    }
};