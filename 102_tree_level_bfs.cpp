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
    
    void level_dfs(TreeNode* root,int level,vector<vector<int>> &ans){
        if(root==NULL) return;
        //注意当进入的新的一行的时候需要添加新行。
        if(level>=ans.size()){
            // cout<<level<<","<<ans.size()<<","<<root->val<<endl;
            ans.push_back(vector<int>());   
        }
        level_dfs(root->left,level+1,ans);
        ans[level].push_back(root->val);
        level_dfs(root->right,level+1,ans);
        return ;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
       // 这题可以直接采用queue版本的按层输出的层需遍历，也可以采用递归按行加入 
        vector< vector<int>> ans;
        if(root==NULL) return ans;
        level_dfs(root,0,ans);
        // 以下注释掉部分时 level tree bfs
//         vector<int> row;
//         queue<TreeNode*> q;
//         q.push(root);
        
//         while(!q.empty()){
//             int size=q.size();
//             for(int i=0;i<size;i++){
//                 TreeNode* tmp=q.front();
//                 q.pop();
//                 row.push_back(tmp->val);
//                 if(tmp->left!=NULL)
//                     q.push(tmp->left);
//                 if(tmp->right!=NULL)
//                     q.push(tmp->right);
//             }
//             ans.push_back(row);
//             row.clear();
//         }
        return ans;
    }
};