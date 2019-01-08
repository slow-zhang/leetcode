#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        //  36 -> 9  % 0
        // 37-> 1 % 1
        // so only 0 ->0 lese 0->9
        return (num-1)%9+1;
    }
};