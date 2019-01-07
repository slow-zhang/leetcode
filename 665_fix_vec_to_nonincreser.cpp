class Solution {
public:
    bool checkPossibility(vector<int>& A) {
        int n=A.size();
        if(n<=2) return true;
        bool flg=true;
        for(int i=1;i<n;i++){
               if( A[i-1]>A[i]){
                    // 突出需要特别处理 [4,2,3]
                    if(i+1<n && A[i-1]>A[i+1]) 
                        A[i-1]=A[i];
                    else // 不是突出   [2,3,4,3]
                        A[i]=A[i-1];
                    // 连续突出2  最后才能发现 [3,4,2,3] 
                    if(i>=2 && A[i-2]>A[i]) return false;
                    if(flg) flg=false;
                    else  return false;
               }
        }
      
        return true;
    }
};