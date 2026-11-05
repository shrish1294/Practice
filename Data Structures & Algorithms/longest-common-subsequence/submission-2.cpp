class Solution {
public:

    vector<vector<int>>dp;
    int helper(int i, int j, string& s, string &t){
        if(i >= s.length() || j >=t.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int a = 0, b = 0, c = 0;
        if(s[i] == t[j])
            a  = 1 + helper(i + 1, j + 1, s, t);
        b = helper(i+1, j, s, t);
        c = helper(i, j + 1, s, t);
        return dp[i][j]  = max(a, max(b, c));
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        dp.clear();
        dp.resize(text1.size(), vector<int>(text2.size(), -1));
        return helper(0, 0, text1, text2);
    }
};
