#include <string>
#include <map>
#include <stack>
#include <sstream>
#include <iostream>

using namespace std;
typedef long long ll;

typedef struct
{
    const char *name; //中文权位名称
    int value;        //10的倍数
    bool secUnit;     //是否是节权位
} CHN_NAME_VALUE;

map<string, long long> mp{{"十", 10}, {"千", 1000}, {"百", 100}, {"万", 10000}, {"亿", 100000000}, {"一", 1}, {"二", 2}, {"三", 3}, {"四", 4}, {"五", 5}, {"六", 6}, {"七", 7}, {"八", 8}, {"九", 9}};

CHN_NAME_VALUE chnValuePair[] = {
    {"十", 10, false}, {"百", 100, false}, {"千", 1000, false}, {"万", 10000, true}, {"亿", 100000000, true}};
    
int ChinesesToValue(string s)
{
    return (mp[s] <= 9 && mp[s] >= 0) ? mp[s] : -1;
}
int ChineseToUnit(string s, bool &secUnit)
{
    for (int i = 0; i < 5; i++)
    {
        if (chnValuePair[i].name == s)
        {
            secUnit = chnValuePair[i].secUnit;
            return chnValuePair[i].value;
        }
    }
    cout << "toUnit error" << endl;
    return false;
}
unsigned int chineseToNumber(const std::string &chnString)
{
    unsigned int rtn = 0;
    unsigned int section = 0;
    int number = 0;
    bool secUnit = false;
    std::string::size_type pos = 0;
    while (pos < chnString.length())
    {
        int num = ChinesesToValue(chnString.substr(pos, 2));
        if (num >= 0)
        {
            number = num;
            pos += 2;
            if (pos >= chnString.length())
            { //如果到了最后一位直接结束
                section += number;
                rtn += section;
                break;
            }
        }
        else
        {
            int unit = ChineseToUnit(chnString.substr(pos, 2), secUnit);
            if (secUnit)
            {
                section = (section + number) * unit;
                rtn += section;
                section = 0;
            }
            else
            {
                section += (number * unit);
            }
            number = 0;
            pos += 2;
            if (pos >= chnString.length())
            {
                rtn += section;
                break;
            }
        }
    }
    return rtn;
}

int main()
{
    string chinese;
    cin >> chinese;
    cout << chineseToNumber(chinese) << endl;
    return 0;
}