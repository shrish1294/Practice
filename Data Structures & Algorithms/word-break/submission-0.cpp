class Solution {
public:
    map<string, bool>mp;
    vector<int>dp;
    bool fun(string &s, int i){
        if(i>=s.length())
            return true;
        string a = "";
        if(dp[i]!=-1)
            return dp[i];
        bool ans = false;
        for(int j = i; j < s.length(); j++){
            a.push_back(s[j]);
            if(mp.find(a)!=mp.end())
                ans |= fun(s, j+1);
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
        return fun(s, 0);
    }
};
