#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <iostream>
#include <tuple>

using namespace std;

int main(){

    {
        // std::relational operators: Performs the appropriate comparison operation between the tuple objects lhs and rhs
        std::tuple<int, char> a(10, 'x');
        std::tuple<char, char> b(10, 'x');
        std::tuple<char, char> c(10, 'y');

        if (a == b)
            std::cout << "a and b are equal\n";
        if (b != c)
            std::cout << "b and c are not equal\n";
        if (b < c)
            std::cout << "b is less than c\n";
        if (c > a)
            std::cout << "c is greater than a\n";
        if (a <= c)
            std::cout << "a is less than or equal to c\n";
        if (c >= b)
            std::cout << "c is greater than or equal to b\n";
    }
    {
        map<int,int> mp;
        mp[1]++;
        cout<<mp.count(1);
        mp[1]--;
        cout<<mp.count(1)<<endl;
    }
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
        cout<<"map null output test\n";
        unordered_map<int,int> mp;
        cout<<mp[0]<<","<<mp[1]<<endl;
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