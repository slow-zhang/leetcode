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
    TreeNode *ans=NULL;
    int postorder(TreeNode* root,TreeNode* p, TreeNode* q) {
        if(root==NULL) return 0;
        int a=postorder(root->left,p,q);
        int b=postorder(root->right,p,q);
        int c=(root==q || root==p)?1:0;
        // printf("%d %d %d %d\n",root->val,a,b,c);
        if(a+b+c==2){
               if(ans==NULL) ans=root;
        }
        return a+b+c;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        postorder(root,p,q);
        return ans;
    }
};