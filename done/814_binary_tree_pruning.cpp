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
    TreeNode* pruneTree(TreeNode* root) {
        // 这题可以通过从下到上的方式处理，如果叶节点的值为0则
        // 删除它（返回NULL），正好是先处理子树再处理自己的过
        // 程，使用后续遍历即可完成
        if(root==NULL) return root ;
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        if(root->left==NULL && root->right==NULL){
            return root->val==0 ? NULL : root;   
        }
        return root;
    }
};