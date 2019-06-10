#include <iostream>
#include <string>

using namespace std;

struct ab
{
    int va;
    int vb;
    int sum;

    bool operator<(ab rhs)
    {
        return sum > rhs.sum;
    }

    void setvalue(int _va, int _vb)
    {
        va = _va;
        vb = _vb;
        sum = _va + _vb;
    }
};

// b is next
double count_angle(double a, double b)
{
    return (b + 360 - a) % 360;  // double cannot mod
}

// TODO
int findTriangleCount(vector<double> coords)
{
    if (coords.size() < 3)
        return 0;

    sort(coords.begin(), coords.end()); // increase

    int len = coords.size();
    int head = 1;
    int count = 0;
    long long ans = 0; // may overflow
    for (int pos = 0; pos < len; pos++)
    {
        // head
        while (count_angle(coords[pos], coords[head % len]) < 180)
        {
            count++;
            head++;
        }
        int crs = (head + len - pos) % len;
        if (crs >= 2)
        {
            ans += crs * (crs - 1) / 2;
        }
    }
    return ans;
}

int max_diff(vector<int> a, vector<int> b)
{
    if (a.size() != b.size())
        return -1;
    if (a.size() == 0)
        return 0;

    int len = a.size();
    vector<ab> sumab(len, 0); // diff is a[i]-b[i] , x get from len-1, y from 0
    for (int i = 0; i < len; ++i)
    {
        sumab[i].setvalue(a[i], b[i]);
    }

    sort(sumab.begin(), sumab.end());

    int pos = 0;
    int ans = 0;

    while (pos < len)
    {
        if (pos & 1)
        { // odd y get
            ans -= sumab[pos++].vb;
        }
        else
        {
            ans += sumab[pos++].va;
        }
    }

    return ans;
}