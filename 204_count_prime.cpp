class Solution {
public:
    int countPrimes(const int n) {
        if(n<=2) return 0;
        bool isPrime[n];
        for(int i=2;i<n;i++)
            isPrime[i]=true;
        isPrime[2]=true;
        for(int i=2;i*i<=n;i++){
            // another solution is counting here ,but the upper need change or need next continue count
            if(isPrime[i]==false) continue;
            for(int j=i+i;j<n;j+=i){
                isPrime[j]=false;
            }
        }
        int ans=0;
        for(int i=2;i<n;i++){
            if(isPrime[i]) ans++;
        }
        
        return ans;
    }
};