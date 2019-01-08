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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
        // cout<<sum<<" "<<root->val<<endl;
        // 这个剪枝本题不适用，存在val负数的节点
        //if(root->val > sum) return false;
        if(root->val==sum 
           && (root->left==root->right)){
            return true;   
        }
        return hasPathSum(root->left,sum- (root->val))
            || hasPathSum(root->right,sum- (root->val));
    }
};