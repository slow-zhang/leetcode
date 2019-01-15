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
    map <int,vector<TreeNode*> > ans;
    int cnted[30];
    Solution(){
        for(int i=0;i<30;i++) cnted[i]=0;
    }
        
    vector<TreeNode*> allPossibleFBT(int N){
        // 一个递归思想，输入N， 结果为  fn=求和fi*fn-i-1 ；
        if(cnted[N]==1) return ans[N];
        cnted[N]=1;
        vector<TreeNode*> tmp;
        if(N==1){
            tmp.push_back(new TreeNode(0));
            ans[N]=tmp;
            return tmp;
        }
        TreeNode * root;
        if(N==3){
            root=new TreeNode(0); 
            root->left=new TreeNode(0);
            root->right=new TreeNode(0);
            tmp.push_back(root);
            ans[N]=tmp;
            return tmp;
        }
        
        for(int i=1;i<=N-2;i+=2){
            auto l=allPossibleFBT(i);
            int lsize=l.size();
            auto r=allPossibleFBT(N-i-1);
            int rsize=r.size();
            // cout<<i<<","<<N-i-1<<":"<<lsize<<","<<rsize<<endl;
            // for(int k=0;k<lsize*rsize;k++){
            //     root=new TreeNode(0);
            //     root->left=l[k%lsize];
            //     root->right=r[k%rsize];
            //     tmp.push_back(root);
            // }
            for(int s1=0;s1<lsize;s1++)
                for(int s2=0;s2<rsize;s2++){
                    root=new TreeNode(0);
                    root->left=l[s1];
                    root->right=r[s2];
                    tmp.push_back(root);
                }
            // for(int k=0;k<lsize*rsize;k++){
            //     root=new TreeNode(0);
            //     root->left=l[k%lsize];
            //     root->right=r[k%rsize];
            //     tmp.push_back(root);
            // }
        }
        ans[N]=tmp;
        return tmp;
    }
};