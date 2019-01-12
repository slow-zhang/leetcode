
class Solution {
public:
    bool isnum(char c){
        return (c<='9'&&c>='0');   
    }
    bool isflg(char c){
        return (c=='-' || c=='+');
    }
    int myAtoi(string str) {
        // 移除空格
        while(str[0]==' '){
            str.erase(str.begin());   
        }
        
        // 判断- + 
        int flg=1;
        if(isnum(str[0]) || isflg(str[0])){
            if(isflg(str[0])){
                if(str[0]=='-')
                    flg=-1;
                str.erase(str.begin());
            }
        }
        else{ // first non-whitespace  invalid 
            return 0;   
        }
        
        // 可能有效，但是-e3种情况，使用numn记录长度
        cout<<str<<":";
        int numn=0;
        long long ans=0;
        // 配合46 移除0
        while(str[0]=='0'){
            str.erase(str.begin());   
        }
        for(int i=0;i<str.size();i++){
            if(isnum(str[i])){
                numn++;
                ans=ans*10+str[i]-'0';
            }else{
                // 发现不是数字，舍弃后买呢的部分
                break;   
            }
        }
        // 处理超过longlong 长度的数，但是000000000098767会造成混淆，需要先移除0
        if(numn>=14)
            return flg==1? 0x7fffffff:0x80000000;
        
        // cout<<ans<<" "<< (ans> 0x80000000LL)<<" "<<flg;
        // 对超过int范围数处理
        if(flg==1){
            if(ans > 0x7fffffffLL){
                return 0x7fffffff;
            }
        }else{
            if(ans> 0x80000000LL)
                return 0x80000000;
        }
        // 加上符号返回
        ans*=flg;
        return ans;//numn==0 ? 0:ans 不必须
    }
};