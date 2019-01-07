#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int maxint=0x7fffffff;
        int l=nums1.size()+nums2.size();
        nums1.push_back(maxint);
        nums2.push_back(maxint);
        
        int mid1,mid2;
        int n1=0,n2=0;
        while((n1+n2)<(l+1)/2)  // 长度向上取整
        {
            if(nums1[n1]<nums2[n2])
            { 
                mid1=nums1[n1++];
            }
            else 
            {
                mid1=nums2[n2++];
            }
            
        }
        if(l&1 == 1) return mid1;
        mid2=min(nums1[n1],nums2[n2]);
        return ((double)mid1+mid2)/2;
    }
};