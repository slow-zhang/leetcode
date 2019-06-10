leetcode
=======
leetcode刷题记录与总结。

<!-- TOC -->
autoauto- [比较难的题](#比较难的题)auto- [常用概念](#常用概念)auto- [算法](#算法)auto    - [二分](#二分)auto    - [组合数、快速](#组合数快速)auto- [数据结构](#数据结构)auto    - [并查集](#并查集)auto    - [TODO](#todo)auto        - [树状数组](#树状数组)auto        - [线段树](#线段树)auto- [其他](#其他)auto    - [加速io](#加速io)auto- [参考](#参考)autoauto
<!-- /TOC -->


###  比较难的题

- tree: 124、894
- 状态压缩dp
https://www.cnblogs.com/ibilllee/p/7651971.html

###  常用概念

1. int 最大最小 0x7fffffff 0x80000000
2. 将最低位设置为0  x&(x-1) 、 返回最低位包括：x^(x&(x-1)) 后者 x^(-x)
3. 




###  算法

####   二分
注意这里使用前开后闭的写法
```c++
// 函数返回版本
int start=0,end=size;
// [start,end)
while (start < end) {
    int mid = start + (end - start) / 2;
    if (array[mid] > k)
        end = mid;
    else if (array[mid] < k)
        start = mid + 1;
    else
        return mid;
}
return -1;

// 记录位置版本
int pos=-1;
int start=0,end=size;
// [start,end)
while (start < end) {
    int mid = start + (end - start) / 2;
    if (array[mid] > k)
        end = mid;
    else if (array[mid] < k)
        start = mid + 1;
    else
        pos=mid;
}
if(pos!=-1){
    //...
}
```
#### 组合数、快速
杨辉三角


### 数据结构
  
####  并查集
```c++
int father[Size]; // init to self father[a]=a
int findf(int t){
    while(father[t]!=t){
        father[t]=father[father[t]];
        t=father[t];
    }
    return t;
}

void Union(int a,int b){
    int fa=findf(a);
    int fb=findf(b);
    father[fa]=fb;
}
```
#### TODO
##### 树状数组

```c++
int lowbit(int x) // 只有最低位1代表的值
{
	return x&(-x);
}
void add(int x) // 向上更新
{
	while(x<100005){
		c[x]+=1;
		x+=lowbit(x);
	}
}
int summ(int x)
{
	int sum=0;
	while(x>0){ // 向下就和 范围不能从0开始
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
```

##### 线段树


### 其他

#### 加速io

```c++
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
```

### 参考
- [io accelerate](https://blog.csdn.net/qq_32320399/article/details/81518476)
