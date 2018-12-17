# SLT usage 
> 每天学习一点STL 的用法，记录于此


## universal
size()


for(atuo itr=v.begin();v!=v.end();v++){
    cout<<v[i];
}

## stack queue
size() 
empyt()
push() // 压入
pop() // 不返回

## stack 
top() // 返回栈顶元素

## queue
front() //返回队头元素
back() //返回队尾

## vetctor 
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

### insert erase




## map 
> sorted by key , unique key  
> implemented by binary search tree

### init
typedef map<int,int> mpii;

mpii m;
mpii m(itr first,itr last);
mpii m(mp2);
//initialization list

### fun
max_size()
[]
at()
swap 交换两个map
clear 
count(k) //1 find 0 not find 
itr Lower_bound & Upperbound // not find if equal

### insert
// return pair;it.first: itr , it.second :true false
pair<> insert (pair<k,v>(..)) //insert(pair<int, int>(1, 1)); 
itr insert (value_type)    //map<int, string>::value_type (1, “student_one”)
mp[k]=v     //nnlike the previous, this causes overwriting, so requires checking first
void insert(mpitr,mpitr)
void insert(initialization list)
pair empalce(k,v) //effective insert


#earse 
mp.erase(mapStudent.find(k));
mp.erase(1);
mapStudent.earse(itr,itr);

