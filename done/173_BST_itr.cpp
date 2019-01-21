/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> ans;
    
    void pushr(TreeNode* root){
        TreeNode* tmp=root;
        while( tmp != NULL ){
            ans.push(tmp);
            tmp=tmp->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        pushr(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* tmp=ans.top();
        ans.pop();
        pushr(tmp->right);
        return tmp->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !ans.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */