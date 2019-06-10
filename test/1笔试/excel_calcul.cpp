#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

map<string,int> ans;
map<string,string> mp;
int N;
int opcmp[128]={0};

// 初始化 opcmp 用作运算符优先级比较
void init(){
    opcmp['+'] = 2;
    opcmp['-'] = 2;
    opcmp['*'] = 4;
    opcmp['/'] = 4;
}

//  从string 获取下一个token
string get_next_string(string &s)
{
    int p = s.find(" ");
    string tmp;
    if (p == string::npos)
    {
        tmp = s;
        s.clear();
        return tmp;
    }
    tmp = s.substr(0, p);
    s = s.substr(p + 1);
    return tmp;
}

// 这里声明一下，必须
int cal_node(string id);

// 获取token的值，同时处理相应的cell
int get_next_val(string &v){
    string s = get_next_string(v);
    if (isalpha(s[0]))  return cal_node(s);
    return stoi(s);
}

// 正好上面有 操作符等级，直接用
bool is_op(char c){
    return opcmp[c]>0;
}

int cal_op(char c,int v1,int v2){
    cout<<"cal"<<c<<","<<v1<<","<<v2<<endl;
    switch(c){
        case '+': return v1+v2;
        case '-': return v1-v2;
        case '/': return v1/v2;
        case '*': return v1*v2;
    }
}

// 主函数
int cal_node(string id){
    if (ans.count(id) == 1) return ans[id];
    string v = mp[id];
    stack<char> op;
    stack<int> value;
    // 一个个取
    while(!v.empty() || !op.empty()){
        cout<<"tmp:"<<v<<endl;
        if(v.empty()){
            char c = op.top();
            op.pop();
            int v1 = value.top();
            value.pop();
            int v2 = value.top();
            value.pop();
            value.push(cal_op(c, v2, v1));
            continue;
        }
        
        if(is_op(v[0])){
            char c=v[0];
            v=v.substr(2);
            
            while(!op.empty()){
                cout<<c<<endl;
                if(!op.empty() && opcmp[op.top()]>=opcmp[c]){
                    char c = op.top();
                    op.pop();
                    int v1 = value.top();
                    value.pop();
                    int v2 = value.top();
                    value.pop();
                    value.push(cal_op(c, v2, v1));
                }else{
                    break;
                }
            }
            op.push(c);
        }
        value.push(get_next_val(v));
    }
    ans[id]=value.top();
    return ans[id];
}

int main(){
    init();
    cin>>N;getchar();
    for(int i=0;i<N;i++){
        string str,k,v;
        getline(cin,str);
        int p=str.find(" ");
        k=str.substr(0,p);  
        v=str.substr(p+3);
        mp[k]=v;
    }
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        string t=itr->first;
        cal_node(t);
        
        cout<<t<<" = "<<ans[t]<<endl;
    }
    
}