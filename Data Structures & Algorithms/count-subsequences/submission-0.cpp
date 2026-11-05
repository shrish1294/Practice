class Solution {
public:

    vector<vector<int>>dp;

    int m , n;

    int helper(int i, int j, string &s1, string &s2){
        if(j >= n)
            return 1;
        if(i >=m)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int a = 0, b = 0;
        if(s1[i] == s2[j])
            a = helper(i + 1, j + 1, s1 ,s2);
        b = helper(i + 1, j, s1, s2);

        return dp[i][j] = a + b;

    }

    int numDistinct(string s, string t) {
        
        m = s.length();
        n = t.length();
        dp.clear();
        dp.resize(m, vector<int>(n, -1));

        return helper(0, 0, s, t);
    }
};
