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
    int val;
    Solution(){val=0;}
    bool isUnivalTree(TreeNode* root) {
        // 这题可以递归判断自己是否和左右孩子的值是否相等，这里使用一个变量记录也相似
        if(root==NULL) return true;
        if(val==0){
            val=root->val;
        }else if(root->val!=val){
            return false;
        }
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};