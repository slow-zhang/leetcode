class Solution {
public:
    // int mp[128];
    // void init(){
    //     mp['I']=1;
    //     mp['V']=5;
    //     mp['X']=10;
    //     mp['L']=50;
    //     mp['C']=100;
    //     mp['D']=500;
    //     mp['M']=1000;
    // }
     map<char,int> mp;
    void init(){
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
    }
    
    int romanToInt(string s) {
        init();
        int ss=s.size();
        int ans=0;
        for(int i=0;i<ss;i++){
            if(i!=ss-1){
                if(mp[s[i]] < mp[s[i+1]]){
                    ans-=mp[s[i]];
                    continue;
                }
            }
            ans+=mp[s[i]];
        }
        return ans;
    }
};
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();