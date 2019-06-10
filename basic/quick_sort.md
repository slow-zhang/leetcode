
```c++
class Solution {
public:
    
    int partition(vector<int> &a,int s,int e){
        int i=s,j=e;
        
        int p=i; // 可以优化选点
        int v=a[p];
        // [s,e]
        while(i<j){ // 相等时退出
            while( i<j && a[j]>v )
                j--;
            if(i<j) a[i]=a[j];
            while(i<j && a[i]<= v)
                i++;
            if(i<j) a[j]=a[i];
        }
        a[i]=v;
        return i;
    }
    
    // [i,j]
    void quick_sort(vector<int> &a,int i,int j){
        if( i>=j) return ;
        int p=partition(a,i,j);
        quick_sort(a,i,p-1);
        quick_sort(a,p+1,j);
        return ;
    }
    
    void sortColors(vector<int>& nums) {
        // if(nums.size()<2) return ;
        quick_sort(nums,0,nums.size()-1);
    }
};
```