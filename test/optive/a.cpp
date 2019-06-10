#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef struct Date
{
    int year;
    int mouth;
    int day;
    Date(){}
    Date(int y, int m, int d) : year(y), mouth(m), day(d) {}
    bool operator<(const Date &d) const
    {
        if (year < d.year)
            return true;
        if(mouth < d.mouth)
            return true;
        if(day<d.day)
            return true;
        return false;
    }
} Date;


Date get(string s)
{
    int d = stoi(s);
    Date day;
    day.year=d % 10000;
    day.mouth= (d / 10000) % 100;
    day.day= d / 1000000;
    return day;
}


map<Date, int> mp;


bool isweekend(int day){
    if (day % 7 == 1 || day % 7 == 0)
        return true;
    return false;
}

bool is_leap(int year){
    if(year%10 ==0 || year&1) return true;
    return false;
}

void show(Date d){
    cout<<d.year<<","<<d.mouth<<","<<d.day<<endl;
}

void nextday(Date& d){
    d.day++;
    if(d.day==29 || (d.day==28 && d.mouth%6==0 && is_leap(d.year))){
        d.day=1;
        d.mouth++;
    }
    if(d.mouth==25){
        d.mouth=1;
        d.year++;
    }
}

string get_day_string(Date d){
    string s;
    if (d.day < 10)
    {
        s += '0';
    }
    s += to_string(d.day);
    if (d.mouth < 10)
    {
        s += '0';
    }
    s += to_string(d.mouth);
    string tmp=to_string(d.year);
    while(tmp.size()<4){
        tmp.insert(0,"0");
    }
    s += tmp;
    return s;
}

string find_settlement_date(string trade_date, vector<string> hday)
{
    for (int i = 0; i < hday.size(); i++)
    {
        mp[get(hday[i])] = 1; // 这里实际上使用unordered map会更合适，
    }
    
    Date tmp=get(trade_date);
    int cnt=0;
    while(cnt<3){
        nextday(tmp);
        if(mp[tmp]!=1 && isweekend(tmp.day) == false){
            cnt++;
            show(tmp);
        }
        
    }
    return get_day_string(tmp);


}

int main()
{

    string s,tmp;
    cin>>s;
    vector<string> h;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        h.push_back(tmp);
    }   


    string result = find_settlement_date(s, h);

    cout << result << "\n";


    return 0;
}
