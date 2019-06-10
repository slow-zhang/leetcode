

## 区别
> 推荐优先使用 unordered 类型
> 除非需要最后排序输出 or 输出前排序

map vs set
> xx map kv pair 
> xx set unique set 

unordered  vs ordered
> unordered : hash impl
> ordered    : rbtree 

## 通用初始化

推荐使用初始化列表
普通量  ： int b{3};  double eps{1e-6};
数组     :   int ar[3]{1,2,3};
vector  :  vector<int> va{1,2,3,3,5};
map     :  map<string,string> m{{"123","123"}};
类 class： 
    // ok 1
    struct A{int x,y};  A a{1,2};
    //  class B{int x,y};  B b{1,2};   这会报错
    // ok 2  必须一个对应的函数
   class B{
        int x,y;  
    public : 
        B(int x,int y){

        }
    };  
    B b{1,2}; 


## map 
常用初始化构建map
```c++
    if(mp.find(s)!=mp.end()) // mp.count(fff)  
        mp[s]++;
    else
        mp[s]=1;
```
```c++
    while(cin>>word)
        mp[word]++;  // 默认是0  然后++
```


### init
typedef map<int,int> mpii;

mpii m;
mpii m(itr first,itr last);
mpii m(mp2);

### function
max_size()
m[]
at()
swap 交换两个map
clear 
count(k) //1 find 0 not find 
itr Lower_bound & Upperbound // not find if equal

### insert
- 常用
    ```c++
    if(mp.find(s)!=mp.end()) // mp.count(fff)  
        mp[s]++;
    else
        mp[s]=0;
    ```
    ```c++
    while(cin>>word)
        mp[word]++;
    ```

- insert pair
    // return pair;it.first: itr , it.second :true false
    pair<> insert (pair<k,v>(..)) //insert(pair<int, int>(1, 1)); 
- 其他
    itr insert (value_type)    //map<int, string>::value_type (1, “student_one”)
    mp[k]=v     //nnlike the previous, this causes overwriting, so requires checking first
    void insert(mpitr,mpitr)
    void insert(initialization list)
    pair empalce(k,v) //effective insert


## code

```c++
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    {
        unordered_map<string,string> mp{{"123","234"},{"1","2"}};
        cout << mp["123"] << mp["1"] << endl;
        mp.erase("123");
        cout << mp["123"] << mp["1"] << endl;
    }
    {
        cout<<"testing map\n";
        map<string,string> mp2{{"1","1"}};
        mp2["123"]="124";
        mp2["3"]="4";
        cout << mp2["123"] << mp2["3"] << endl;
        mp2.erase("123");
        cout << mp2["123"] << mp2["3"] << endl;
        cout<<mp2.erase("0");;
    }
    {
        int b{3};
        double d{1e-6};

        int a[3]{123,234,345};
        vector<int> va{1, 2, 3, 3, 5};
        
        cout<<b<<d<<a[2]<<va[4]<<endl;
        
    }
    {
        struct A{
            int x,y;
        };
        A a{1,2};
        cout<<1<<a.x<<a.y<<endl;
    }
    {
        class B{
            int x,y;
            public:
            B(int a,int b):x(a),y(b){}
            void show(){cout<<x<<" "<<y<<endl;}
        };
        B b{2,3};
        b.show();
    }
    return 0;
}
```