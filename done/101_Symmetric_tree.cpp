#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "util.h"
class Solution {
public:   
    
    bool isSame(TreeNode* l,TreeNode* r){
        if(l==NULL&&r==NULL) return true;   
        if((l==NULL && r!=NULL) ||(l!=NULL &&r==NULL))
                return false;
        if(l->val!=r->val) return false;
        return isSame(l->left,r->right) 
            && isSame(l->right,r->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL) return true;
        return isSame(root->left,root->right);
        
        
        
        // iteratively
        if(root ==NULL) return true;
        
        queue<TreeNode*> q1;
        q1.push(root->left);
        queue<TreeNode*> q2;
        q2.push(root->right);
        TreeNode *l,*r;
        while(!q1.empty() && !q2.empty()){
            l=q1.front(),r=q2.front();
            
            q1.pop(),q2.pop();
            // 都为空，try next
            if(l==NULL&&r==NULL) continue;
            
            
            // 其中一个为空
            if((l==NULL && r!=NULL) ||(l!=NULL &&r==NULL))
                return false;
            
            
            // cout<< l->val <<","<<r->val<<" ";
            
            // 值不等
            if(l->val != r->val) return false;

            q1.push(l->left);
            q1.push(l->right);
            q2.push(r->right);
            q2.push(r->left);
            
        }
        if(q1.empty() && q2.empty()) return true;
        return false;
    }
};