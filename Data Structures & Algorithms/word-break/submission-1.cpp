class Solution {
public:

    map<string, bool>mp;
    vector<int>dp;
    bool helper(string &s, int i){
        if(i >=s.length())
            return true; 
        string tmp = "";
        if(dp[i]!=-1)
            return dp[i];
        bool ans = false;
        for(int j = i;  j < s.length(); j++){
            tmp.push_back(s[j]);
            if(mp.count(tmp))
                ans |= helper(s, j + 1);
            if(ans)
                return dp[i] = ans; 
        }
        return dp[i] = ans; 
        
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        mp.clear();
        dp.clear();
        dp.resize(s.length(), -1);
        for(auto a: wordDict)
            mp[a] = true; 
        return helper(s, 0);
    }
};
