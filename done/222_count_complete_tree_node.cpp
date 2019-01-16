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
    int countLeft(TreeNode* root){
        if(root==NULL) return 0;
        
        int l=0;
        TreeNode* tmp=root;
        while(tmp!=NULL){
            l++;
            tmp=tmp->left;
        }
        // cout<<root->val<<" "<<l<<endl;
        return l;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        // 满树  深度n 节点2^n-1
        // 如果左右两边相等，说明左边是满树，否则右边是满树
        int lroot=countLeft(root->left);
        int lr=countLeft(root->right);
        return lr==lroot ? (1+(1<<lroot)-1+countNodes(root->right))
            : (1+(1<<lr)-1+countNodes(root->left));
    }
};