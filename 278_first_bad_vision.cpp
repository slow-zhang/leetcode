// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long i=1,j=n;
        //i j bad
        //mid=bad j=mid else i=mid+1
        //
        while(i<j){
            long mid=(j-i)/2+i;
            // cout<<mid<<" "<<i<<" "<<j<<endl;
            if(isBadVersion(mid)){
                j=mid;
            }else{
                i=mid+1;
            }
        }
        return i;
    }
};