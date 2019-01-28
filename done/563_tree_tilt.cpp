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
    int ans=0;
    int sum(TreeNode* root) {
        if(root==NULL) return 0;
        int l=sum(root->left);
        int r=sum(root->right);
        ans+=abs(l-r);
        return l+r+root->val;
    }
    int findTilt(TreeNode* root) {
        if(root==NULL) return 0;
        sum(root);
        return ans;;
    }
};