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
    // construct [l,r) 
    TreeNode* constructTree(vector<int>& nums,int l,int r){
        // 这题是讲一个中序遍历的数组重建一棵树，这种题一个特点是需识别左右孩子的氛范围和根节点的范围，这种题中中序遍历时最简单的，其他三种会比较难处理一些
        // 这里采用递归建树，把最大的新建一个节点root，然后将在其左右的分别建树并将root的左右指针指向他们，之一传入l、r的处理
        if(l==r) return NULL;
        
        auto positr=max_element(nums.begin()+l, nums.begin()+r);
        int pos=distance(nums.begin()+l, positr);
        
        TreeNode *root=new TreeNode(*positr);
        // cout<<l<<","<<pos<<","<<r<<endl;
        root->left=constructTree(nums,l,l+pos);
        root->right=constructTree(nums,l+pos+1,r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        return constructTree(nums,0,nums.size());
    }
};