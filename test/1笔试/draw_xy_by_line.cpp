#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>


using namespace std;
int main()
{
    int m, n;
    cin >> m;
    cin >> n;
    int ans = 0;
    m++;
    n++;
    if (m > n)
        swap(m, n);
    float k = (float)m / (float)n;
    for (int i = 0; i < n; i++)
    {
        int offset = ceil((float)(i + 1) * k) - floor((float)i * k);
        ans += offset;
    }
    cout << ans << endl;
    return 0;
}