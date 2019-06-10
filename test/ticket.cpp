#include <map>
#include <string>
#include <iostream>
#include <fstream> // file op

using namespace std;


// 可以使用 map保存 kv信息 ，使用set保存两种set
map<string,string> buyed;
map<string,string> checked;
map<string,int> inkind{{"checkin",1},{"buy",2},{"refund",3}};

void errormsg(const char* s,string id){
    cout<<"error id:"<<id<<","<<s;
}

int main(){
    ifstream fbuy("A.txt", ios::out);
    if(fbuy.is_open()){
        string sname;
        while(fbuy>>sname){
            string id;
            fbuy>>id;
            buyed[id]=sname;
        }
    }
    fbuy.close();

    fstream fcheck("B.txt", ios::in | ios::out);
    if (fcheck.is_open())
    {
        string sname;
        while (fcheck >> sname)
        {
            string id;
            fcheck >> id;
            buyed[id] = sname;
        }
    }

    string skind, sname, sid;
    while (cin >> skind)
    { // 不检查输入的合法性
        cout<<skind<<"...";
        switch (inkind[skind])
        {
        case 1: // checkin
            // 已经买票才能check in
            cin >> sid;
            if (buyed.count(sid) == 0){
                errormsg("not buyed\n", sid);
                break;
            }
            if (checked.count(sid) == 1){
                errormsg("already cheched\n", sid);
                break;
            }
            checked[sid] = buyed[sid];
            fcheck << buyed[sid] << " " << sid << endl;
            cout<< "checkin ok\n";
            break;
        case 2: // buy
            // 没有买票 没有checkin 才能买, 默认不存在 没买票已经check到情况
            cin >> sname;
            cin >> sid;
            if (buyed.count(sid) == 1){
                errormsg("already buyed\n", sid);
                break;
            }
            buyed[sid] = sname;
            cout<<"buy ok\n";
            break;
        case 3: // refund
            cin >> sid;
            if (buyed.count(sid) == 0){
                errormsg("not buyed\n", sid);
                break;
            }
            if (checked.count(sid) == 1){
                errormsg("already cheched\n", sid);
                break;
            }
            //del 两种方式，
            auto itr = buyed.find(sid);
            buyed.erase(itr++);
            cout<<"refund ok\n";
            break;
        }
    }
    fcheck.close();
}