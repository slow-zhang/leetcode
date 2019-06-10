#include <iostream>
#include <iomanip> //这个头文件是声明一些 “流操作符”的
//比较常用的有:setw(int);//设置显示宽度，left//right//设置左右对齐。 setprecision(int);//设置浮点数的精确度。
#include <queue>
#include <vector>
using namespace std;
// 哈夫曼树的结点结构
struct element
{
    int weight;                 // 权值域
    element* lchild, *rchild, *parent; // 该结点的左、右、双亲结点在数组中的下标
    element(int w)
        :weight(w),lchild(NULL),rchild(NULL),parent(NULL){
    }
    element(element* p1,element* p2)
        :lchild(p1),rchild(p2),parent(NULL){
            weight=p1->weight + p2->weight;
    }
};

class cmp{
    public:
    bool operator() (element* a,element* b){
        return a->weight > b->weight;
    }
};

priority_queue<element*,vector<element*>,cmp> q;

// 哈夫曼算法
// n个叶子结点的权值保存在数组w中
element* HuffmanTree(int w[], int n)
{
    for(int i=0;i<n;i++){
        q.push(new element(w[i]));
    }
    while(q.size() != 1){
        auto tp1=q.top();q.pop();
        auto tp2=q.top();q.pop();
        auto p=new element(tp1,tp2);
        tp1->parent=p;
        tp2->parent=p;
        q.push(p);
    }
    return q.top();
}
// 打印哈夫曼树
void print_tree(element* root){
    if(root==NULL) return ;
    printf("v:%d\n",root->weight);
    print_tree(root->lchild);
    print_tree(root->rchild);
}


int main()
{
    int x[]{5, 29, 7, 8, 14, 23, 3, 11};     // 权值集合
    element* root= HuffmanTree(x, 8);
    print_tree(root);
    system("pause");
    return 0;
}