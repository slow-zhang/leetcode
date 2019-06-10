#include <queue>
#include <string>
#include <iostream>

using namespace std;

const int maxn=10010;
int gid=0;

typedef struct A
{
    int id;
    int pr;
    A(int p) : pr(p)
    {
        id = gid++;
    }
    void disp() const
    {
        cout << id << "," << pr << endl;
    }
} A;


istream &operator>>(istream &os, A& a)
{
    os  >> a.pr ;
    return os;
}

ostream &operator<<(ostream &os,const A a) 
{
    os << a.id << ":" << a.pr;
    return os;
}

struct cmp
{ // 对于sort 是从小到大，对于堆就是大顶堆
    bool operator () (const A& a,const A& b){
        return a.pr<b.pr;
    }
};
struct cmp2
{ 
    bool operator () (const A &a, const A &b)
    {
        return a.pr >b.pr;
    }
};

void struct_test2()
{
    cout << "class with < for >:\n";
    priority_queue<A, vector<A>, cmp2> q;
    q.push(12);
    q.push(1);
    // q.top().disp();
    cout << q.top() << endl;
    q.push(14);
    // q.top().disp();
    cout << q.top() << endl;
    q.pop();
    q.pop();
    // q.top().disp();
    cout << q.top() << endl;
    q.push(15);
    // q.top().disp();
    cout << q.top() << endl;
}

void struct_test(){
    cout << "class with < for <:\n";
    priority_queue<A,vector<A>,cmp> q;
    q.push(12);
    q.push(1);
    // q.top().disp();
    cout << q.top() << endl;
    q.push(14);
    // q.top().disp();
    cout << q.top() << endl;
    q.pop();
    q.pop();
    // q.top().disp();
    cout << q.top() << endl;
    q.push(15);
    // q.top().disp();
    cout << q.top() << endl;
}

void struct_emplace_test()
{
    cout << "class with emplace:\n";
    priority_queue<A, vector<A>, cmp> q;
    q.emplace(12);
    q.emplace(1);
    // q.top().disp();
    cout << q.top() << endl;
    q.emplace(14);
    // q.top().disp();
    cout << q.top() << endl;
    q.pop();
    q.pop();
    // q.top().disp();
    cout << q.top() << endl;
    q.emplace(15);
    // q.top().disp();
    cout << q.top() << endl;
}

void simple_default()
{
    cout << "less:\n";
    priority_queue<int> q;
    q.push(12);
    q.push(1);
    cout << q.top() << endl;
    q.push(14);
    cout << q.top() << endl;
    q.pop();
    q.pop();
    cout << q.top() << endl;
    q.push(15);
    cout << q.top() << endl;
}

void simple_greater()
{
    cout << "greater:\n";
    priority_queue<int,vector<int>,greater<int> > q;
    q.push(12);
    q.push(1);
    cout << q.top() << endl;
    q.push(14);
    cout << q.top() << endl;
    q.pop();
    q.pop();
    cout << q.top() << endl;
    q.push(15);
    cout << q.top() << endl;
}

int main(){
    simple_default();
    simple_greater();
    cout<<"so,default: 大根堆\n";

    struct_test();
    struct_test2();
    struct_emplace_test();

    return 0;
}