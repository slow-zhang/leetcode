/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> ans;
    vector<int> postorder(Node* root) {
        if(root==NULL) return ans;
        stack<Node*> s;
        s.push(root);
        Node* pre=NULL;
        
        while(!s.empty()){
            Node* tmp=s.top();
            cout<<tmp->val<<endl;
            if(tmp->children.size()==0
               || (pre!=NULL && 
                   find(tmp->children.begin(),tmp->children.end(),pre)!=tmp->children.end()
                   )
               ){
                s.pop();
                ans.push_back(tmp->val);
                pre=tmp;
            }else{
                for(int i=tmp->children.size()-1;i>=0;i--)
                    s.push(tmp->children[i]);
            }
        }
        
        
        return ans;
    }
};