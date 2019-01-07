class Solution {
public:
    string convertToTitle(int n) {
        // 26进制转化
        // 26 Z
        // 27 AA 

        int bits[20]={0};
        int num=0;
        do{
            bits[num++]=n%26;
            n/=26;
        }while(n!=0);
        
        //if 0  前一位减1,
        for(int i=0;i<num-1;i++){
            // 可能这一位减过一 小于0
            if(bits[i]<=0){
                bits[i]+=26;
                bits[i+1]--;
            }
        }
        //第一位减掉之后是0  则总位数减一
        if(bits[num-1]==0) num--;
        
        char a[20];
        int i;
        for(i=0;i<num;i++){
            a[i]='A'+bits[num-i-1]-1;   
        }
        a[i]=0;
        return a;
    }
};