
### 合并
```c++
class Solution {
public:
    // [s,m] [m+1,e]
    void merge(vector<int> &a,int s,int m,int e, vector<int>& tmp ){
        int len=e-s+1;
        int i=s,j=m+1;
        //  如果采用合并链表式的循环，需要注意再调用过程中m初始值过大，需要调整到e
        for(int k=0;k<len;k++){
            if(i>m)
                tmp[k]=a[j++];
            else if(j>e)
                tmp[k]=a[i++];
            else{
                if(a[i]>a[j])
                    tmp[k]=a[j++];
                else
                    tmp[k]=a[i++];
            }
        }
        
        for(int i=0;i<len;i++)
            a[s+i]=tmp[i];
        return ;
    }
    
    void merge_sort(vector<int> &a,vector<int>& tmp){ 
        int len=a.size();
        int range=1;
        while(range<len){
            for(int i=0;i+range<len ;i+=range*2){
                int e=min(len-1,i+2*range-1);
                merge(a,i,i+range-1,e,tmp);
            }
            range*=2;
        }
        
        return ;
    }
    
    void sortColors(vector<int>& nums) {
        // if(nums.size()<2) return ;
        vector<int> tmp(nums.size()+1);
        merge_sort(nums,tmp);
    }
};
```
### 递归sort 
```c++
class Solution {
public:
    // [s,m] [m+1,e]
    void merge(vector<int> &a,int s,int m,int e, vector<int>& tmp ){
        int len=e-s+1;
        int i=s,j=m+1;
        for(int k=0;k<len;k++){
            if(i>m)
                tmp[k]=a[j++];
            else if(j>e)
                tmp[k]=a[i++];
            else{
                if(a[i]>a[j])
                    tmp[k]=a[j++];
                else
                    tmp[k]=a[i++];
            }
        }
        
        for(int i=0;i<len;i++)
            a[s+i]=tmp[i];
        return ;
    }
    
    // [s,e]
    void merge_sort(vector<int> &a,int s,int e ,vector<int>& tmp){
        if(s>=e) 
            return ;   
        int m=(e-s)/2+s;
        
        merge_sort(a,s,m,tmp);
        merge_sort(a,m+1,e,tmp);
        merge(a,s,m,e,tmp);
        
        return ;
    }
    
    void sortColors(vector<int>& nums) {
        // if(nums.size()<2) return ;
        vector<int> tmp(nums.size()+1);
        merge_sort(nums,0,nums.size()-1,tmp);
    }
};
```