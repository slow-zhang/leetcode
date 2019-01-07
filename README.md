leetcode
========
leetcode 
- [cn](leetcode-cn.com)
- [en](leetcode.com)


一些模板的总结
--------

- 加速io操作
```c++
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
```
- BFS tree
```c++
// return by level 
vector<vector<int>> levelOrder(TreeNode* root) {
    vector< vector<int>> ans;
    if(root==NULL) return ans;
    vector<int> row;
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
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

参考
----
- [vector](https://www.cnblogs.com/shrimp-can/p/5280566.html)
- [vector-官方文档](http://www.cplusplus.com/reference/vector/vector/)
- [io accelerate](https://blog.csdn.net/qq_32320399/article/details/81518476)
