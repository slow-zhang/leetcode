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
    int ml=-1;
    
    int sumv(TreeNode* root,int s){
        if(root==NULL) return 0;
        int v=root->val;
        int l=sumv(root->left,v);
        int r=sumv(root->right,v);
        
        ml=max(ml,1+l+r);
        
        return s==v? max(1+l,1+r):0;
        
    }
    
    int longestUnivaluePath(TreeNode* root) {
        //124 简单版本，需要处理的情况少一些
        if(root==NULL) return 0;
        sumv(root,0);
        return ml-1;
    }
};