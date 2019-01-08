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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return ans;
        
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* pre=NULL;
        while(!s.empty()){
            TreeNode* tmp=s.top();
            // cout<<"on:"<<tmp->val<<endl;
            if((pre==tmp->left && tmp->right==NULL)
               || (pre!=NULL && pre==tmp->right )
               || (!tmp->left && !tmp->right) )
            {
                ans.push_back(tmp->val);
                pre=tmp;
                s.pop();
            }
            else if(pre==NULL || (pre!=tmp->left && pre!=tmp->right) )
            {
                // cout<<"newin:"<<tmp->val<<endl;
                if(tmp->left!=NULL ){
                    s.push(tmp->left);
                }
                else if(tmp->right!=NULL){
                    s.push(tmp->right);
                }
            }
            else if(tmp->right!=NULL)
            {
                s.push(tmp->right);   
            }
           
        }
        // postorderTraversal(root->left);
        // postorderTraversal(root->right);
        // ans.push_back(root->val);
        return ans;
    }
};