class Solution {
public:
    bool buddyStrings(string A, string B) {
        // 1. find diff pos number n
        // 2. n>2 return false
        // 3. n=2 if swap same  return true ,otherwise false
        // 4. n=1 false
        // 5. n=0  two same return true ,otherwise false
        // 5.1 if(size>26 ) must same
        int pos[3];
        int num=0;
        for(int i=0;i<A.size();i++){
            if(A[i]!=B[i])  pos[num++]=i;
            if(num>2) return false;
        }
        if(num==1) return false;
        if(num==2){
            int a=pos[0],b=pos[1];
            if(A[a]==B[b] && A[b]==B[a]) return true;
            return false;
        }
        if(num==0){
            if(A.size()>26) return true;
            int s=A.size();
            char a[30];
            for(int i=0;i<s;i++){
                a[i]=A[i];
            }
            sort(a,a+s);
            for(int i=1;i<s;i++){
                if(a[i]==a[i-1]) return true;
            }
            return false;
        }
        return false;
    }
};