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
    bool isCompleteTree(TreeNode* root) {
        // 直接利用BFS 特性，并且将NULL入queue
        if(root==NULL) return true;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tmp=NULL;
        bool flg=true; // 是否访问过空节点
        while(!q.empty()){
            tmp=q.front();
            q.pop();
            // 如果取过空 并且本节点不空
            if(flg==false && tmp!=NULL) return false;
            if(tmp==NULL){ // 如果取到空，flg 置false
                flg=false;
                continue;
            }
            // cout<<tmp->val<<" ";
            q.push(tmp->left);
            q.push(tmp->right);
        }
        return true;
    }
};