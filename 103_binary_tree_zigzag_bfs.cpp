/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // 102 使用率level tree bfs 的模板，这里采用一个指针指示每层的开始，在奇数层入ans之前reverse一次，达到题目的要求，当然使用102的解法都是ok的
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