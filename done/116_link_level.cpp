/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // 按照按层输出的层序遍历方式，使用pre指针链接到当前节点
        if(root==NULL) return ;
        queue<TreeLinkNode*> q;
        q.push(root);
        TreeLinkNode *pre;
        while(!q.empty()){
            int size=q.size();
            pre=NULL;
            for(int i=0;i<size;i++){
                TreeLinkNode *tmp=q.front();
                q.pop();
                if(pre!=NULL)
                    pre->next=tmp;
                pre=tmp;
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right); 
            }
            pre->next=NULL;
        }
        return ;
    }
};