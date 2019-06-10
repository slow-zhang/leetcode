#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    using std::string;
    using std::cout;

    {
        string tests = "1 2 3 4";

        istringstream teststream(tests);
        string tmpstring;
        while (teststream >> tmpstring)
        {
            cout << tmpstring << endl;
        }

        cout << "ending..." << endl;
    }
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