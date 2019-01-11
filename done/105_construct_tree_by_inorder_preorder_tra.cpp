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
    // [ml,mr) [pl,pr) 
    TreeNode* buildt(vector<int>& pv, vector<int>& iv,int ml,int mr,int pl,int pr) {
        // i m : minorder p:preorder
        if(ml==mr)
            return NULL;
        if(ml==mr-1) 
            return new TreeNode(iv[ml]);
        
        TreeNode *root=new TreeNode(pv[pl]);
        
        int pos=ml;
        while(iv[pos]!=pv[pl]) {
            pos++;   
        }
        printf("%d,%d,%d\n",ml,pos,mr);
        
        int ll=pos-ml;
        root->left=buildt(pv,iv,ml,ml+ll,pl+1,pl+1+ll);
        root->right=buildt(pv,iv,ml+ll+1,mr,pl+1+ll,pr);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 这题关键是利用好两种遍历的关系，其中前序遍历很好确定root ，通过root从中序遍历找到左右子树递归建树
        int s=inorder.size();
        return buildt(preorder,inorder,0,s,0,s);
    }
    
};