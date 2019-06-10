###  在本地跑的一些设置
<!-- TOC -->

- [在本地跑的一些设置](#在本地跑的一些设置)
    - [普通：](#普通)
    - [树：](#树)
    - [图：](#图)

<!-- /TOC -->
####  普通：
- 将leetcode白板中的内容copy到一个文件中，
- 修改main.cpp 中的最后一个include 内容为刚刚的文件，
- 输入
```bash
g++ main.cpp -std=c++11
./a.out 
```
-  将TestCase按行输入

#### 树：
区别是不适用main.cpp 改而使用main_tree.cpp,其中树节点的定义在util.h 中。

#### 图： 
暂未涉及。