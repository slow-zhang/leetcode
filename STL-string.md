
## string 

### 初始化 
- string s1;
- string s2(s1);
- string s3("ssss");
- string s4(n,'c'); //n个'c'
- 读取
- cin>>s;
- getline(cin,s);

```c++
string s1="12345";
string s2(5,'1');
cin>>s; // 43
cout>>s1>>" ">>s2>>" ">>s3; // 12345 11111 43
```

### 拼接 切片
- s1+="under flow"连接
- s.append(n,'c') //append 可以像初始化string那样在原str上附加字符串  
- insert // (p,str) (p,str,i,j) (p,"abc",l) (p,"abc") 
           // (p,n,'c') (itr,n,'c') (itr,c) (itr,itr1,itr2)
        可以实现在指定位置删除字符串，需要掌握的是在pos处插入string insert(p,str)
- s.earse(itr) //删除一个，也可以给定为：(itr,itr) / (n1,n2)   区间的话都是[n1,n2)
- s2=s.sbustr(i,j)  // [i,i+j)  ，也可以只给一个参数 那就是pos到最后


```c++
//===============
//去除前导0 s1="000123";
while(s[0]=='0'){
        // 注意与 s1.erase(0) 区别
        s1.erase(s1.begin()); // 这里只删除一个迭代器指向的位置
}
// s2= "1234,1234";
cout<<s2.erase(4); // 1234 
// erase : itr 删除一个， int 删除到最后

// =========
// 处理指定分隔符，例如在树的序列化反序列化中会用到
string s="123,234";
pos=s.find(","); // pos 3
s1=s.substr(0,pos); // s1="123";
s2=s.substr(pos+1); // s2="234"; 


// 插入srting 注意第二个位置上为""
// s1="1234abcd"
s1.insert(4,"5") // 12345abcd

// === sstream
#include <sstream>
istringstream ss(s); // s="1 2 3 4"
while(ss>>s){
    cout<<s<<endl;
}
```

### 修改
- s.replace(i,j,s2)  // [i,i+j) to s2
- s.find("abc") //找第一个abc // 返回a的位置 或者 string::npos
- reverse(itr,itr) [)

### 转换  string 与其他的转换
- std::to_string(TYPE T) // 可以吧基本任何类型转化为string
- std::stoi //转 整数 stol stoul stoll stoull
- std:: stof //转 浮点数  stod stold 
- str.c_str()  // 转 char*

### 转换  char 处理 ，比如大小写不同的编码规则
toupper
tolower

isupper
islower
isalpha
isalnum
isdigit


### 所有用法实例

```c++
#include <string>
#include <iostream>

int main()
{
    using std::string;
    using std::cout;

    {   // erase 两种用法
        string s1;
        s1.append(5,'0');
        s1+="123,456";
        while (s1[0] == '0')
        {
            // 注意与 s1.erase(0) 区别
            s1.erase(s1.begin()); // 这里只删除一个迭代器指向的位置
        }
        cout<<s1<<"\n"; // 123,456
        cout<<s1.erase(3)<<"\n"; //123
    }

    {   // 插入string
        string s1 = "1234abcd";
        cout << s1.insert(4, "5") << "\n"; // 12345abcd
    }

    {   // 对指定位置分割 
        string s1 = "123,234";
        int pos = s1.find(",");      // pos 3
        cout<<s1.substr(0, pos)<<"\n";  // s1="123";
        cout<<s1.substr(pos + 1)<<"\n"; // s2="234";

        {   // while 处理
            string s1 = "a,b,b,d";
            while(true ){
                int pos = s1.find(",");
                string tmp=s1.substr(0,pos);
                cout << tmp << "\n"; // a b c d 分别
                if (pos == string::npos)
                    break;
                s1=s1.substr(pos+1); // 这个位置pos+1会溢出成0 ，所以需要在上面加一个判断
            }
        }
    }

    {   // 替换 所有大写转小写，小写转大写，数字转化为., 其他字符不处理
        string s1="1a2b3c,4D5E6F";
        for(auto& c:s1){
            if(isalpha(c)){
                if(isupper(c)){
                    c=tolower(c);
                }else{
                    c=toupper(c);
                }
            }else if(isalnum(c)){
                // alpha 已经在上面处理了 这里只处理数字
                c='.';
            }
        }
        cout<<s1<<"\n";
    }

    return 0;
}
```