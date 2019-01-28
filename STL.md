# SLT usage 
> 每天学习一点STL 的用法，记录于此


## 1. universal
- size() begin() end() 
- itr 遍历
    // itr 是一个指针，数组: *itr  mp: itr->first 
    for(atuo itr=v.begin();v!=v.end();v++){
        cout<<*itr;
    }
- empty 
- erase(itr) erase(itr1,itr2) 
- erase(xx.find())

## 2. stack queue 
### common
size() 
empyt()
push() // 压入
pop() // 不返回

### stack 
top() // 返回栈顶元素

### queue
front() //返回队头元素
back() //返回队尾

## 3. vetctor 
###init :
typedef vector<int>  vint;
vint v1;//空
vint v2(v1); // 赋值构造 可以使用数组或者vector初始化
vint v3(n,i); // n个 值为i
vint v4(n); // n个 0

### 查询函数
max_size() //返回最大的能存储的数据量
push_back()
pop_back()
//查询最大值、最小值 `*itr` 可以得到值，`itr-begin()` 也可以得到差值
auto positr=max_element(nums.begin()+l, nums.begin()+r);
int pos=distance(nums.begin()+l, positr);


## 4. map 
> sorted by key , unique key  
> implemented by binary search tree ?

### init
typedef map<int,int> mpii;

mpii m;
mpii m(itr first,itr last);
mpii m(mp2);
//initialization list

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
    if(mp.find(s)!=mp.end())
        mp[s]++;
    else
        mp[s]=0;
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

## string 

### init 
- string s1;
- string s2(s1);
- string s3("ssss");
- string s4(n,'c'); //n个'c'

### fun
- s1+="under flow"连接
- s.earse(itr) / (itr,itr) / (n1,n2)   区间的话都是[n1,n2)
- s.find("abc") //找第一个abc
- reverse(itr,itr) [)
### 修改
- s.append(s2) 
- s2=s.sbustr(i,j)  // [i,i+j)
- s.replace(i,j,s2)  // [i,i+j) to s2
- assign // (s2) (s2,l) (s2,i,j) (n,'c')
- insert // (p,str) (p,str,i,j) (p,"abc",l) (p,"abc") 
        (p,n,'c') (itr,n,'c') (itr,c) (itr,itr1,itr2)

