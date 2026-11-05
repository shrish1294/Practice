class Solution {
public:
    vector<vector<int>>dp;
    int fun(string &s1, string &s2, int i, int j){
        if(i>=s1.length() || j>=s2.length())
            return 0;
        int a = 0;
        int b = 0;
        int c = 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i] == s2[j])
            a = 1 + fun(s1, s2, i+1, j+1);
        b = fun(s1, s2, i+1, j);
        c = fun(s1, s2, i, j+1);
        return dp[i][j] = max(a, max(b, c));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.clear();
        int m = text1.size();
        int n = text2.size();
        dp.resize(m, vector<int>(n, -1));
        return fun(text1, text2, 0, 0);
    }
};
