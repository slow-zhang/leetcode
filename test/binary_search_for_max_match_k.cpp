#include <vector>
#include <iostream>

using namespace std;

int binary_search_10(vector<int>& height){
    int l = 0, r = height.size();
    if(height[l] > 10) return -1;
    if(height[r-1] < 10) return r-1;
    int tmp=0;
    while (l < r)
    {
        int mid = (l + r) / 2;
        cout<<l<<" "<<mid<<" "<<r<<endl;
        if (height[mid] < 10)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l ;
}

int main(){
    int num;
    cin>>num;
    vector<int> height(num);
    for(auto& n:height){
        cin>>n;
    }
    // for(auto n:height)
    //     cout<<n;
    int pos = binary_search_10(height);
    cout<<pos<<endl;
    return 0;
}