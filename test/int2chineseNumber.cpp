#include <string>
#include <iostream>

using namespace std;

const char* val_of_int[]={"零","一","二","三","四","五","六","七","八","九"};
const char* part_of_int[]={"","十","百","千"};
const char* part_of_section[]={"","万","亿","万亿","亿亿","万亿亿"};

string section2chinses(int sec){
    bool p_zero=false;
    string ans,tmp;
    int part=0;

    while(sec) {
        int v=sec % 10;
        if(v==0){
            if(p_zero){
                p_zero=false;  // continuous only output one 
                ans.insert(0,"零");
            }
        }else{
            p_zero=true;  // only after first 0, we need output 0
            tmp = val_of_int[v];
            tmp+=part_of_int[part];
            ans.insert(0,tmp);
        }
        part++;
        sec/=10;
    }
    return ans;
}

string int2chinsesNumber(long long input){
    string ans;
    string tmp;
    int part=0;
    while(input) {
        int v=input%10000;
        input /= 10000;
        tmp=section2chinses(v);
        if(v>0 && v <1000 && input) tmp.insert(0,"零"); // 全零也要加
        tmp+=part_of_section[part];
        ans.insert(0,tmp);

        part++;
    }
    return ans;
}

int main(){
    string s;
    
    while(cin>>s){
        cout<<int2chinsesNumber(stol(s))<<endl;
    }
}