# 1. SLT usage 

<!-- TOC -->autoauto- [1. SLT usage](#1-slt-usage)auto    - [1.1. universal](#11-universal)auto    - [1.2. stack queue](#12-stack-queue)auto        - [1.2.1. common](#121-common)auto        - [1.2.2. stack](#122-stack)auto        - [1.2.3. queue](#123-queue)auto    - [1.3. vetctor](#13-vetctor)auto        - [1.3.1. init :](#131-init-)auto        - [1.3.2. 查询函数](#132-查询函数)auto    - [1.4. map](#14-map)auto        - [1.4.1. init](#141-init)auto        - [1.4.2. function](#142-function)auto        - [1.4.3. insert](#143-insert)auto    - [1.5. string](#15-string)auto        - [1.5.1. init](#151-init)auto        - [1.5.2. fun](#152-fun)auto        - [1.5.3. 修改](#153-修改)auto        - [1.5.4. 转换](#154-转换)auto    - [1.6. set](#16-set)auto        - [1.6.1. 常用](#161-常用)auto    - [1.7. bitset](#17-bitset)auto        - [1.7.1. 初始化](#171-初始化)auto        - [1.7.2. bit 操作](#172-bit-操作)auto        - [1.7.3. 查询](#173-查询)auto        - [1.7.4. bitset 操作](#174-bitset-操作)auto    - [1.8. 参考](#18-参考)autoauto<!-- /TOC -->
普通  != mp.end()

## 1.1. universal
- size() begin() end() 
- itr 遍历
    // itr 是一个指针，数组: *itr  mp: itr->first 
    for(atuo itr=v.begin();v!=v.end();v++){
        cout<<*itr;  // for map: itr->first , itr->second
    }
- empty 
- erase(itr) erase(itr1,itr2) 
- erase(xx.find())
- 输出 copy(roots.begin(), roots.end(),
ostream_iterator<int >(cout, " "));

## 1.2. stack queue 
### 1.2.1. common
size() 
empyt()
push() // 压入
pop() // 不返回

### 1.2.2. stack 
top() // 返回栈顶元素

### 1.2.3. queue
front() //返回队头元素
back() //返回队尾

## 1.3. vetctor 
### 1.3.1. init :
typedef vector<int>  vint;
vint v1;//空
vint v2(v1); // 赋值构造 可以使用数组或者vector初始化
vint v3(n,i); // n个 值为i
vint v4(n); // n个 0
vector<vint> v(n,vint(m,0));  nr*ml 0

### 1.3.2. 查询函数
max_size() //返回最大的能存储的数据量
push_back()
pop_back()
//查询最大值、最小值 `*itr` 可以得到值，`itr-begin()` 也可以得到差值
auto positr=max_element(nums.begin()+l, nums.begin()+r);
int pos=distance(nums.begin()+l, positr);



## 1.5. string 

### 1.5.1. init 
- string s1;
- string s2(s1);
- string s3("ssss");
- string s4(n,'c'); //n个'c'

### 1.5.2. fun
- s1+="under flow"连接
- s.earse(itr) / (itr,itr) / (n1,n2)   区间的话都是[n1,n2)
- s.find("abc") //找第一个abc
- reverse(itr,itr) [)
### 1.5.3. 修改
- s.append(s2) 
- s2=s.sbustr(i,j)  // [i,i+j)
- s.replace(i,j,s2)  // [i,i+j) to s2
- assign // (s2) (s2,l) (s2,i,j) (n,'c')
- insert // (p,str) (p,str,i,j) (p,"abc",l) (p,"abc") 
        (p,n,'c') (itr,n,'c') (itr,c) (itr,itr1,itr2)

### 1.5.4. 转换 
- std::to_string(TYPE T) // 可以吧基本任何类型转化为string
- std::stoi //转 整数 stol stoul stoll stoull
- std:: stof //转 浮点数  stod stold 
- str.c_str()  // 转 char*


## 1.6. set

### 1.6.1. 常用
1. count

## 1.7. bitset

### 1.7.1. 初始化
bitset<size> b;
b.set() // 全1

### 1.7.2. bit 操作

test()
set() // 不带参数全置1   带参数某位置1  也可以某位置0 set(3,0)
flip
### 1.7.3. 查询
count
size
any
none
all
### 1.7.4. bitset 操作
set
a |=b

## initializer_list

{}
auto itr=il.begin();
a=*itr++;
b=*itr++;

```c++

struct Foo
{
	int x;
	int y;
	int z;
	Foo(std::initializer_list<int> list)
	{
		auto it= list.begin();
		x = *it++;
		y = *it++;
		z = *it++;
	}
```

### 不能初始化的：非 聚合类

```c++
（1）无用户自定义构造函数。

（2）无私有或者受保护的非静态数据成员

（3）无基类

（4）无虚函数

（5）无{}和=直接初始化的非静态数据成员。下面我们逐个对上述进行分析。
```


## 1.8. 参考
- [vector](https://www.cnblogs.com/shrimp-can/p/5280566.html)
- [vector-官方文档](http://www.cplusplus.com/reference/vector/vector/)
- [c++ bitset](https://www.cnblogs.com/magisk/p/8809922.html)
- [string example](http://www.cnblogs.com/gvlthu23061/p/7315722.html)
- [stl usage](https://github.com/fengbingchun/Messy_Test)