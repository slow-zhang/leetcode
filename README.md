leetcode
========

leetcode刷题记录与总结。

在本地跑的一些设置
--------
#### 1. 普通：
- 将leetcode白板中的内容copy到一个文件中，
- 修改main.cpp 中的最后一个include 内容为刚刚的文件，
- 输入
```bash
g++ main.cpp -std=c++11
./a.out 
```
-  将TestCase按行输入

####2. 树：
区别是不适用main.cpp 改而使用main_tree.cpp,其中树节点的定义在util.h 中。

####3. 图： 
暂未涉及。

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
    vector<int> row; // record every level ans
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        int size=q.size();
        // 使用size 得到每行的元素，直接按照leve进行bfs
        for(int i=0;i<size;i++){
            TreeNode* tmp=q.front();
            q.pop();
            // 下面这行替换为你需要的操作
            row.push_back(tmp->val);
            if(tmp->left!=NULL)
                q.push(tmp->left);
            if(tmp->right!=NULL)
                q.push(tmp->right);
        }
       // 下面这两行替换为你需要的操作
        ans.push_back(row);
        row.clear();
    }
    return ans;
}
````

- binary search
注意这里使用前开后闭的写法
```c++
// 函数返回版本
int start=0,end=size;
// [start,end)
while (start < end) {
    int mid = start + (end - start) / 2;
    if (array[mid] > k)
        end = mid;
    else if (array[mid] < k)
        start = mid + 1;
    else
        return mid;
}
return -1;

// 记录位置版本
int pos=-1;
int start=0,end=size;
// [start,end)
while (start < end) {
    int mid = start + (end - start) / 2;
    if (array[mid] > k)
        end = mid;
    else if (array[mid] < k)
        start = mid + 1;
    else
        pos=mid;
}
if(pos!=-1){
    //...
}
```

- BST :search

```c++
TreeNode* searchBST(TreeNode* root, int val) {
    // 找不到  
    // 这里也是val应该插入的位置 
    if(root==NULL)
        return NULL;   

    // finded 
    if(root->val==val)
        return root;
    
    if(val <= root->val )
        return searchBST(root->left,val);
    else
        return searchBST(root->right,val);
}
```

参考
----
- [vector](https://www.cnblogs.com/shrimp-can/p/5280566.html)
- [vector-官方文档](http://www.cplusplus.com/reference/vector/vector/)
- [io accelerate](https://blog.csdn.net/qq_32320399/article/details/81518476)
