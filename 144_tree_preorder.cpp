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
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* tmp=s.top();
            s.pop();
            ans.push_back(tmp->val);
            if(tmp->right!=NULL)
                s.push(tmp->right);
            if(tmp->left!=NULL)
                s.push(tmp->left);
        }
        // ans.push_back(root->val);
        // preorderTraversal(root->left);
        // preorderTraversal(root->right);
        return ans;
    }
};