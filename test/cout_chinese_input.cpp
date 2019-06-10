#include <string>
#include <iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    while(s.size()){
        cout<<s.substr(0,2)<<endl;
        s=s.substr(2);
    }
}