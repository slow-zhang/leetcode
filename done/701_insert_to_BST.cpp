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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // 其实就是一道遍历的题目，直接遍历，当达到空节点说明这就是应该插入的位置。
        if(root==NULL) {
            return new TreeNode(val);
        }
        if(val<root->val) {
            root->left=insertIntoBST(root->left,val);
        }else{
            root->right=insertIntoBST(root->right,val);
        }
        return root;
    }
};