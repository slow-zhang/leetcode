#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return  a < b;
}

int main()
{
    vector<int> myvec{ 3, 2, 5, 7, 3, 2 };
    vector<int> lbvec(myvec);

    sort(myvec.begin(), myvec.end(), cmp); // 旧式做法
    cout << "predicate function:" << endl;
    for (int it : myvec)
        cout << it << ' ';
    cout << endl;

    sort(lbvec.begin(), lbvec.end(), [](int a, int b) -> bool { return a < b; });   // Lambda表达式
    cout << "lambda expression:" << endl;
    for (int it : lbvec)
        cout << it << ' ';

    {
　　　　 int m = [](int x) { return [](int y) { return y * 2; }(x)+6; }(5);
        std::cout << "m:" << m << std::endl;            　　//输出m:16
        
        int j= [](int x){
            return [](int y){
                return y*2;
            }(x) + 6;   
        }(5);
        cout<<j<<endl;

        std::cout << "n:" << [](int x, int y) { return x + y; }(5, 4) << std::endl;            //输出n:9
        
        auto gFunc = [](int x) -> function<int(int)> {
             return 
                [=](int y) { return x + y; }; 
            };
        auto lFunc = gFunc(4);
        std::cout << lFunc(5) << std::endl;

        auto hFunc = [](const function<int(int)>& f, int z) { return f(z) + 1; };
        auto mi = hFunc(gFunc(7), 8);

        int a = 111, b = 222;
        auto func = [=, &b]()mutable { a = 22; b = 333; std::cout << "a:" << a << " b:" << b << std::endl; };

        func();
        std::cout << "a:" << a << " b:" << b << std::endl;

        a = 333;
        auto func2 = [=, &a] { a = 444; std::cout << "a:" << a << " b:" << b << std::endl; };
        func2();

        auto func3 = [](int x) ->function<int(int)> { return [=](int y) { return x + y; }; };

    　　
　　　　 std::function<void(int x)> f_display_42 = [](int x) { std::cout<<(x); };
	f_display_42(44);
　　}
}