#include <string>
#include <stack>
#include <map>
#include <iostream>

using namespace std;
map<char, int> mp{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0}, {')', 3}};
stack<int> val;
stack<char> op;

int cal_op(){
    int v1=val.top(); val.pop();
    int v2=val.top(); val.pop();
    cout<<v2<<op.top()<<v1<<endl;
    switch (op.top())
    {
    case '+':
        val.push(v2 + v1);
        break;
    case '-':
        val.push(v2 - v1);
        break;
    case '*':
        val.push(v2 * v1);
        break;
    case '/':
        val.push(v2 / v1);
        break;
    }
    op.pop();
}

int get_value(string &s, int &i)
{
    int v = 0;
    while( i < s.size() &&  isdigit(s[i])) {
        v = v * 10 + s[i++] - '0';
        // cout << i << ",，，" << s << endl;
    }
    return v;
}

int cal_val(string &s)
{
    while(!val.empty()) val.pop();
    while(!op.empty()) op.pop();
    val.push(-1);

    int len = s.size();
    int i = 0;
    int v;
    // cout<<s;
    while (i < len)
    {
        // cout << i <<","<<val.top()<< "," << s << endl;
        if(isdigit(s[i])){
            v = get_value(s, i);
            // cout<<v<<endl;
            val.push(v);
        }if(mp.count(s[i]) == 1) {
            // cout<<s[i]<<endl;
            if(s[i] == '(') {
                op.push(s[i++]); continue;
            }
            else if (s[i] == ')')
            {
                while (!op.empty() && '(' != op.top())
                {
                    cal_op();
                }
                if (op.top() == '(')
                {
                    op.pop();
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                while (!op.empty() && mp[s[i]] <= mp[op.top()])
                {
                    cal_op();
                    // cout << i << ",，" << s << endl;
                }
                op.push(s[i]);
            }
            
            
        }
        i++;
    }
    while(!op.empty()){
        cal_op();
    }
    return val.top();
}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*????????????
*1??>,0??=,-1??<
*c1??????c2?????
*/
int Judge(char c1, char c2)
{
    int a1, a2;
    if ('+' == c1 || '-' == c1)
        a1 = 3;
    if ('*' == c1 || '/' == c1)
        a1 = 5;
    if ('(' == c1)
        a1 = 1;
    if (')' == c1)
        a1 = 7;
    if ('#' == c1)
        a1 = 0;

    if ('+' == c2 || '-' == c2)
        a2 = 2;
    if ('*' == c2 || '/' == c2)
        a2 = 4;
    if ('(' == c2)
        a2 = 6;
    if (')' == c2)
        a2 = 1;
    if ('#' == c2)
        a2 = 0;
    if (a1 > a2)
        return 1;
    if (a1 == a2)
        return 0;
    if (a1 < a2)
        return -1;
}
//??????
double run(char c, double d1, double d2)
{
    switch (c)
    {
    case '+':
        return d1 + d2;
        break;
    case '-':
        return d1 - d2;
        break;
    case '*':
        return d1 * d2;
        break;
    case '/':
        return d1 / d2;
        break;
    default:
        return 0.0;
        break;
    }
}
int testing_it(string str)
{
    char *op = "+-*/()#";
    //???????str??'#'?????
    str.append(1, '#');
    stack<char> OPTR;   //????
    stack<double> OPND; //????
    int a = -1;
    //??#????
    OPTR.push('#');
    while (true)
    {
        int b = a + 1;
        a = str.find_first_of(op, a + 1);
        if (a == string::npos)
            break;
        if (a != b)
        {
            string ss(str, b, a - b);
            double d = atof(ss.c_str());
            //?????
            OPND.push(d);
        }
        //????????
        int ju = Judge(OPTR.top(), str[a]);
        if (-1 == ju) //??????????
        {
            OPTR.push(str[a]);
        }
        if (0 == ju) //???????????
        {
            OPTR.pop();
        }
        if (1 == ju) //??????,??????
        {
            double d1 = OPND.top();
            OPND.pop();
            double d2 = OPND.top();
            OPND.pop();
            d1 = run(OPTR.top(), d2, d1);
            //??????
            OPND.push(d1);
            OPTR.pop();
            a--;
        }
    }
    //????????'#'?????
    str.erase(str.length() - 1, 1);
    cout << str << " = " << OPND.top() << endl;
}

map<char,int> mymp{{'#',0},{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 3}, {')', 4}};

string ops="+-*/()#";

// 0 pop
// 1 push
// -1 cal
// 2 error
// opcmp[tmpop][sop.top()]
int opcmp[][]={
   // #  +-  */  (  )
     {0, 1,  1, 1,  2},// # // cannot meet )
     {-1, -1, 1, 1, -1},// +-
     {-1, -1, -1, 1, -1},// */
     {2,  1,  1, 1, 0},// ( // cannot meet #
     {2,2,2,2,2},// )  // stack on have )
};

int my_test(string s) {
    if(s.size() == 0) return 0;
    s += "#";
    stack<double> sv;
    stack<char> sop;
}

int main()
{
    string s;
    while (cin >> s)
    {
        testing_it(s);
        // cout<<s<<endl;
        cout << "value:" << cal_val(s) << endl;
        
    }
}