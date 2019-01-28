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
    int presum=0;
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return root;
        convertBST(root->right);
        presum+=root->val;
        root->val=presum;
        convertBST(root->left);
        return root;
    }
};