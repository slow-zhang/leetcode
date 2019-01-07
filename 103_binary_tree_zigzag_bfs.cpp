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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *level_head=NULL;
        int level_num=0;
        vector<int> vans;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        while(!q.empty()){
            TreeNode *tmp=q.front();
            q.pop();
            if(level_head==tmp){
                level_head=NULL;
                if(level_num&1!=0){ //奇数层
                    reverse(vans.begin(),vans.end());
                }
                ans.push_back(vans);
                vans.clear();
                level_num++;
            }
            vans.push_back(tmp->val);
            if(tmp->left!=NULL){
                if(level_head==NULL)
                    level_head=tmp->left;
                q.push(tmp->left);
            }
            if(tmp->right!=NULL){
                if(level_head==NULL)
                    level_head=tmp->right;
                q.push(tmp->right);
            } 
        }
        if(level_num&1!=0){ //奇数层
            reverse(vans.begin(),vans.end());
        }
        ans.push_back(vans);
        return ans;
    }
};