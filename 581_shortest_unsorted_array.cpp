class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int ii=0,jj=a.size()-1;
        // find min i
        int tmp;
        int i;
        for(i=0;i<jj;i++){
            // 找到第一个乱序的
            if(a[i]>a[i+1]){
                
                tmp=a[i+1];
                // 取最小
                for(int k=i+1;k<a.size();k++)
                    tmp=min(tmp,a[k]);
                // 找到他应该在的pos
                while(i>=0){
                    if(a[i]<=tmp ){
                        break;   
                    }
                    i--; 
                }
                ii=i+1;
                break;
            }
        }
        if(i==a.size()-1) return 0;
        
        for(int j=jj;j>ii;j--){
            if(a[j] <a[j-1]) {
                tmp=a[j-1];
                for(int i=0;i<j-1;i++){
                    tmp=max(tmp,a[i]);   
                }
                while(j<a.size()){
                    if(a[j]>=tmp) break;
                    j++; 
                }
                jj=j-1;
                break;
            }
        }
        cout<<ii<<","<<jj;
        return jj-ii+1;
    }
};
//[1,3,2,3,3]
//[8,6,5,7,9]
//[1,3,2,3,3]