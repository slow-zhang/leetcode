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
    int tmpmax=0x80000000;
    int maxPathSumofRoot(TreeNode* root){
        // 
        if(root==NULL) return 0;
        int v=root->val;
        if(root->left==NULL && root->right==NULL)
            return v;
        
        int l=maxPathSumofRoot(root->left);
        int r=maxPathSumofRoot(root->right);
        
        // 最大值不包括自己，在最左右的下面
        // 这里需要注意，必须要有才更新，否则空子树传
        // 来的0会对结果产生影响 [-1,-2]，
        if(root->left!=NULL){
            tmpmax=max(tmpmax,l);
        }
        if(root->right!=NULL){
            tmpmax=max(tmpmax,r);
        }
        
        // 最大值 包括自己，但是不向上传递
        tmpmax=max(tmpmax,max(v,v+l+r)); // l+r+v 这里如果lr 都是0x80000000 会反向越界错误
                                         // 只针对 空子树返回负最小值的情况，改为返回0消失
        printf("%d ",tmpmax);
        
        // 最大值包括上面节点，上面处理
        return max(v,max(v+l,v+r));
    }
    int maxPathSum(TreeNode* root) {
        // 这题需要往上传递参数，后续遍历更合适
        
        // 一个最长路径可能出现在的位置： 
        // 已经记录的位置
        //      左边子树里面l--记录在最大位置
        //      右边子树里面r--记录在最大位置
        // 包含自己：本次需要处理的
        //      max( v+l / v+r / v ) --todo -传递到上面
        //      v+l+r     --记录在最大位置
        //      l / r     --记录在最大位置
        return max(tmpmax,maxPathSumofRoot(root));
    }
};