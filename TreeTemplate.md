
<!-- TOC -->

- [BST :search](#bst-search)
- [BFS、层序遍历](#bfs层序遍历)
- [按行输出的层序遍历](#按行输出的层序遍历)
- [中序遍历、二叉搜索树模板](#中序遍历二叉搜索树模板)
- [后序遍历](#后序遍历)

<!-- /TOC -->

####   BST :search

```c++
TreeNode* searchBST(TreeNode* root, int val) {
    // 找不到  // 这里也是val应该插入的位置 
    if(root==NULL)
        return NULL;   
    // finded 
    if(root->val==val)
        return root;
    if(val <= root->val )
        return searchBST(root->left,val);
    else
        return searchBST(root->right,val)
}
```

####  BFS、层序遍历 
```c++
vector<int> levelOrder(TreeNode* root) {
    vector<int> ans;
    if(root==NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode* tmp=q.front();
        q.pop();
        row.push_back(tmp->val);
        if(tmp->left!=NULL)
            q.push(tmp->left);
        if(tmp->right!=NULL)
            q.push(tmp->right);
    }
    return ans;
}
````

#### 按行输出的层序遍历
```c++
// 按行输出g
vector<vector<int>> levelOrder(TreeNode* root) {
    vector< vector<int>> ans;
    if(root==NULL) return ans;
    vector<int> row; // record every level ans
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        // 使用size 得到每行的元素，直接按照leve进行bfs
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* tmp=q.front();
            q.pop();
            row.push_back(tmp->val);
            if(tmp->left!=NULL)
                q.push(tmp->left);
            if(tmp->right!=NULL)
                q.push(tmp->right);
        }
        ans.push_back(row);
        row.clear();
    }
    return ans;
}
````

####  中序遍历、二叉搜索树模板 

```c++
// 二叉搜索树的中序遍历时有序序列
// 由于中序遍历为 左 中 右，我们再访问当前节点之前要访问其左子树，
// 所以我们使用栈，在访问当前节点之前将所有左子树入栈，最后一个
// 进入的节点必定是没有左子树的节点，我们访问它，并将他的右子树
// 用同样的方式访问。
vector<int> inorderTraversal(TreeNode* root) {
    if(root==NULL) return ans;
    vector<int> ans;
    stack<TreeNode*> s;
    s.push(root);
    while(root->left){
        s.push(root->left);
        root=root->left;
    }
    while(!s.empty()){
        TreeNode* tmp=s.top();
        s.pop();
        ans.push_back(tmp->val);
        if(tmp->right){
            s.push(tmp->right);
            tmp=tmp->right;
            while(tmp->left){
                s.push(tmp->left);
                tmp=tmp->left;
            }
        }
    }
    return ans;
}
```

####  后序遍历

```c++
vector<int> postorderTraversal(TreeNode* root) {
    if(root==NULL) return ans;
    vector<int> ans;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* pre=NULL;
    while(!s.empty()){
        TreeNode* tmp=s.top();
        if( (!tmp->left && !tmp->right) 
            || (pre!=NULL && (pre==tmp->right || pre==tmp->left)))
        {
            ans.push_back(tmp->val);
            pre=tmp;
            s.pop();
        }
        else 
        {
            if(tmp->right!=NULL){
                s.push(tmp->right);
            }
            if(tmp->left!=NULL ){
                s.push(tmp->left);
            }
        }
    }
    return ans;
}
```