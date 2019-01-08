class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // val cannot find ,return null    
        if(root==NULL)
            return NULL;   

        // finded r
        if(root->val==val)
            return root;
        
        if(val <= root->val )
            return searchBST(root->left,val);
        else
            return searchBST(root->right,val);
    }
}