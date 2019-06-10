
/*
 * tree: int val ,vector<TreeNode*> childrens
 */
struct TreeNode{
    int val;
    vector<TreeNode*> childrens;
}

int timeForLeave(TreeNode* root){
    if(root==NULL) return 0;
    int m=0;
    for(auto t:root->childrens){
        m=max(dfs(t),m);
    }
    return m;
}

int dfs(TreeNode* root){
    if(root==NULL) return 0;
    int ans=0;
    for(auto t:root->childrens){
        ans+=dfs(p);
    }
    return 1+ans;
}