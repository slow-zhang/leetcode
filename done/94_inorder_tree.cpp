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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return ans;
        
        stack<TreeNode*> s;
        s.push(root);
        while(root->left){
            s.push(root->left);
            root=root->left;
        }
        while(!s.empty()){
            TreeNode* tmp=s.top();
            s.pop();
            ans.push_back(tmp->val);
            if(tmp->right){
                s.push(tmp->right);
                tmp=tmp->right;
                while(tmp->left){
                    s.push(tmp->left);
                    tmp=tmp->left;
                }
            }
        }

        // inorderTraversal(root->left);
        // ans.push_back(root->val);
        // inorderTraversal(root->right);
        return ans;
    }
};