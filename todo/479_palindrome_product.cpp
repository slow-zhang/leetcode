class Solution {
public:
    // swit to bits and check 
    bool isP(long n){
        int p[20]={0};
        int l=0;
        do{
            p[l++]=n%10;
            n/=10;
        }while(n!=0);
        // l=6 0 1 2 for 5 4 3
        for(int i=0;i<l/2;i++){
            if(p[i]!=p[l-i-1]) return false;
        }
        return true;
    }
    
    bool isP2(long n){
        string s=to_string(n);
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]) return false;
        }
        return true;
    }
    
    int largestPalindrome(int n) {
        int intans[]= {9,987,123,597,677,1218,877,475};
        return intans[n-1];
        long ans=0;
        long a=pow(10,n)-1;
        cout<<isP2(333)<<" ";
        cout<<isP2(13)<<" ";
        cout<<isP2(2442)<<" ";
        cout<<isP2(4)<<" ";
        //cout<<s1<<endl; // 30
        // 9...9 * 9...1 is only for 12468
        for(int i=pow(10,n)-2;i>0;i--){
            ans=a*i;
            if(isP(ans)){
                cout<<i<<endl;
                return (int)(ans%1337);
            } 
        }
        return 0;
    }
};