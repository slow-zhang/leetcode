
```c++
class Solution {
public:
    
    void sort1(vector<int> &a){
        int len=a.size();
        if(a.size()<=1) return ;
        for(int i=0;i<len-1;i++){
            for(int j=0;j<len-1-i;j++){
                if(a[j]>a[j+1]) swap(a[j],a[j+1]);
            }
        }
    }
    
    void adjust(vector<int> &a,int len,int root){
            while(root<=len/2){
                int max=root;
                if(root*2<=len && a[root*2] > a[root] )
                    max=root*2;
                if(root*2+1 <=len && a[root*2+1] > a[max])
                    max=root*2+1;
                if(max==root) break;
                swap(a[max],a[root]);
                root=max;
           }
    }
    /*
     * heap sort: 1. for every non-leaf ,adjust
     *            2. swap 1,least , than adjust 1
     * adjust: left and right are heap, only need to sink root
     */
    
    // [1,len] 
    void heap_sort(vector<int> &a){
        int len=a.size();
        a.insert(a.begin(),-1);
        for(int i=len/2;i>=1;i--){
            adjust(a,len,i);   
        }
        
        for(int i=len;i>1;i--){
            swap(a[i],a[1]);
            adjust(a,i-1,1);
        }
        a.erase(a.begin());
        return ;
    }   
    
    void sortColors(vector<int>& nums) {
        if(nums.size()<2) return ;
        heap_sort(nums);
    }
};
```