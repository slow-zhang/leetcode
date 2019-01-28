class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int s=d.size();
        if(s==0){
            d.push_back(1);
            return d;
        }
        d[s-1]++;
        int pls=0;
        for(int i=s-1;i>=0;i--){
            d[i]+=pls;
            pls=0;
            if(d[i]==10){
                d[i]=0;
                pls=1;
            }else{
                break;
            }
        }
        if(pls==1) d.insert(d.begin(),1);
        return d;
         
    }
};