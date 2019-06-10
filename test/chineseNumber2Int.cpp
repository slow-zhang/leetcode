#include <string>
#include <map>
#include <stack>
#include <sstream>
#include <iostream>

using namespace std;
typedef long long ll;

map<string, int> mp{{"十", 10}, {"千", 1000}, {"百", 100}, {"万", 10000}, {"亿", 100000000}, 
                    {"一", 1}, {"二", 2}, {"三", 3}, {"四", 4}, {"五", 5}, {"六", 6}, {"七", 7}, {"八", 8}, {"九", 9}};

int main(){
    // map<string,int> mp{{"shi",10},{"qian",1000},{"bai",100},{"wan",10000},{"yi",100000000},
    //                     {"1",1},{"2",2},{"3",3},{"4",4},{"5",5},{"6",6},{"7",7},{"8",8},{"9",9}};
    
    string cn,s;
    cin>>cn;
    vector<string> vs;


    istringstream scn(cn);
    while(scn>>s) {
        ll val=mp[s];
        if(!stck.empty()) {
            auto tp = stck.top();
            if(tp.second > val){ // 1000 xia  100 push
                stck.push({val,val});
            }else{ // 100 xia 10000 *
                ll tmp=0;
                while (!stck.empty()) // get all smaller
                {
                    auto tp = stck.top();
                    if(tp.second > val) break;
                    tmp += tp.first;
                    stck.pop();
                }
                val = tmp * val;
                stck.push({val,val});
            }
        }else{
            cout << "" << val << endl;
            stck.push({val,val});
        }
    }
    while(!stck.empty()) { // add all
        auto tp=stck.top();
        ans+= tp.first;
        stck.pop();
    }
    printf("%lld",ans);
}