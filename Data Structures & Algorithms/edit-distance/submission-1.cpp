class Solution {
public:

    vector<vector<int>>dp; 
    int helper(int i, int j, string &s1, string &s2){
        if(j >= s2.length())
            return s1.length() - i;
        if(i >=s1.length())
            return s2.length() - j; 
        if(dp[i][j]!=-1)
            return dp[i][j];
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        if(s1[i] == s2[j])
            a = helper(i + 1, j + 1, s1, s2);
        b = 1 + helper(i + 1, j + 1, s1, s2);
        c = 1 + helper(i + 1, j, s1, s2);
        int d = 1 + helper(i, j+1, s1, s2);

        return dp[i][j] = min(a, min(b, min(c, d)));
        
    }
    int minDistance(string word1, string word2) {

        dp.clear();
        dp.resize(word1.length(), vector<int>(word2.length(), -1));
     return  helper(0, 0, word1, word2);   
    }
};
