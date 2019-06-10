class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<unsigned> vals(s.size()+1, 0);
        vals[0] = 1;
        
        for (unsigned i = 0; i < s.size(); ++i) {
            unsigned idx = i+1;
            for (const string& word : wordDict) {
                int start_idx = idx - word.size();
                if (start_idx < 0 || !vals[start_idx]) {
                    continue;
                }
                unsigned j = 0;
                for (; j < word.size(); ++j) {
                    if (s[start_idx + j] != word[j]) {
                        break;
                    }
                }
                vals[idx] = j == word.size();
                if (j == word.size()) {
                    break;
                }
            }
        }
        return vals[s.size()];
    }
    
    bool wordBreak4(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break; //next i
                }
            }
        }
        
        return dp[s.size()];
    }
    
    bool wordBreak1(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); ++ i) {
            for (int j = 0; j < i; ++ j) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
    
    bool wordBreakHelper(string s, const unordered_set<string>& dict, int start, vector<int>& memo) {
        if (start == s.length())
            return true;
        
        if (memo[start] != -1)
            return memo[start];
        
        for (int end = start + 1; end <= s.length(); ++ end) {
            if (dict.find(s.substr(start, end - start)) != dict.end() &&
                wordBreakHelper(s, dict, end, memo)) {
                memo[start] = true;
                return true;
            }
        }
        
        memo[start] = false;
        return false;
    }
    
    bool wordBreak2(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.length(), -1);
        return wordBreakHelper(s, dict, 0, memo);
    }
};