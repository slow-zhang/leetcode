
#include <iostream>
using namespace std;
#include <sstream>
#include <string>

void f(int a)
{
    cout << "f1\n";
}
void f(bool a)
{
    cout << "f2\n";
}
void f(void* a)
{
    cout << "f3\n";
}

int main(){
    f(0);
    // f(NULL);  error: call to 'f' is ambiguous
    f(nullptr);

    {
       
        string s;
        istringstream ss("1 2 3 4");
        while(ss >> s) cout<<s;
    }
    return 0;
}